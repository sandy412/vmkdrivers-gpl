/*
 * Copyright (c) 2007-2013 Mellanox Technologies. All rights reserved.
 *
 * This software is available to you under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */

#include <linux/kernel.h>
#include <linux/ethtool.h>
#include <linux/netdevice.h>

#include "mlx4_en.h"
#include "en_port.h"


static void
mlx4_en_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *drvinfo)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	struct mlx4_en_dev *mdev = priv->mdev;

	strlcpy(drvinfo->driver, DRV_NAME, sizeof(drvinfo->driver));
	strlcpy(drvinfo->version, DRV_VERSION " (" DRV_RELDATE ")",
		sizeof(drvinfo->version));
	snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version),
		"%d.%d.%d",
		(u16) (mdev->dev->caps.fw_ver >> 32),
		(u16) ((mdev->dev->caps.fw_ver >> 16) & 0xffff),
		(u16) (mdev->dev->caps.fw_ver & 0xffff));
	strlcpy(drvinfo->bus_info, pci_name(mdev->dev->pdev),
		sizeof(drvinfo->bus_info));
	drvinfo->n_stats = 0;
	drvinfo->regdump_len = 0;
	drvinfo->eedump_len = 0;
}

static const char main_strings[][ETH_GSTRING_LEN] = {
	"rx_packets", "tx_packets", "rx_bytes", "tx_bytes", "rx_errors",
	"tx_errors", "rx_dropped", "tx_dropped", "multicast", "collisions",
	"rx_length_errors", "rx_over_errors", "rx_crc_errors",
	"rx_frame_errors", "rx_fifo_errors", "rx_missed_errors",
	"tx_aborted_errors", "tx_carrier_errors", "tx_fifo_errors",
	"tx_heartbeat_errors", "tx_window_errors",

	/* port statistics */
	"tso_packets",
	"queue_stopped", "wake_queue", "tx_timeout", "rx_alloc_failed",
	"rx_csum_good", "rx_csum_none", "tx_chksum_offload",

	/* packet statistics */
	"broadcast", "rx_prio_0", "rx_prio_1", "rx_prio_2", "rx_prio_3",
	"rx_prio_4", "rx_prio_5", "rx_prio_6", "rx_prio_7", "tx_prio_0",
	"tx_prio_1", "tx_prio_2", "tx_prio_3", "tx_prio_4", "tx_prio_5",
	"tx_prio_6", "tx_prio_7",
};
#define NUM_MAIN_STATS	21
#define NUM_ALL_STATS	(NUM_MAIN_STATS + NUM_PORT_STATS + NUM_PKT_STATS + NUM_PERF_STATS)

static const char mlx4_en_test_names[][ETH_GSTRING_LEN]= {
	"Interupt Test",
	"Link Test",
	"Speed Test",
	"Register Test",
	"Loopback Test",
};

static u32 mlx4_en_get_msglevel(struct net_device *dev)
{
	return ((struct mlx4_en_priv *) netdev_priv(dev))->msg_enable;
}

static void mlx4_en_set_msglevel(struct net_device *dev, u32 val)
{
	((struct mlx4_en_priv *) netdev_priv(dev))->msg_enable = val;
}

static void mlx4_en_get_wol(struct net_device *netdev,
			    struct ethtool_wolinfo *wol)
{
	struct mlx4_en_priv *priv = netdev_priv(netdev);
	int err = 0;
	u64 config = 0;
	u64 mask;

	if ((priv->port < 1) || (priv->port > 2)) {
		en_err(priv, "Failed to get WoL information\n");
		return;
	}

	mask = (priv->port == 1) ? MLX4_DEV_CAP_FLAG_WOL_PORT1 :
		MLX4_DEV_CAP_FLAG_WOL_PORT2;

	if (!(priv->mdev->dev->caps.flags & mask)) {
		wol->supported = 0;
		wol->wolopts = 0;
		return;
	}

	err = mlx4_wol_read(priv->mdev->dev, &config, priv->port);
	if (err) {
		en_err(priv, "Failed to get WoL information\n");
		return;
	}

	if (config & MLX4_EN_WOL_MAGIC)
		wol->supported = WAKE_MAGIC;
	else
		wol->supported = 0;

	if (config & MLX4_EN_WOL_ENABLED)
		wol->wolopts = WAKE_MAGIC;
	else
		wol->wolopts = 0;
}

static int mlx4_en_set_wol(struct net_device *netdev,
			    struct ethtool_wolinfo *wol)
{
	struct mlx4_en_priv *priv = netdev_priv(netdev);
	u64 config = 0;
	int err = 0;
	u64 mask;

	if ((priv->port < 1) || (priv->port > 2))
		return -EOPNOTSUPP;

	mask = (priv->port == 1) ? MLX4_DEV_CAP_FLAG_WOL_PORT1 :
		MLX4_DEV_CAP_FLAG_WOL_PORT2;

	if (!(priv->mdev->dev->caps.flags & mask))
		return -EOPNOTSUPP;

	if (wol->supported & ~WAKE_MAGIC)
		return -EINVAL;

	err = mlx4_wol_read(priv->mdev->dev, &config, priv->port);
	if (err) {
		en_err(priv, "Failed to get WoL info, unable to modify\n");
		return err;
	}

	if (wol->wolopts & WAKE_MAGIC) {
		config |= MLX4_EN_WOL_DO_MODIFY | MLX4_EN_WOL_ENABLED |
				MLX4_EN_WOL_MAGIC;
	} else {
		config &= ~(MLX4_EN_WOL_ENABLED | MLX4_EN_WOL_MAGIC);
		config |= MLX4_EN_WOL_DO_MODIFY;
	}

	err = mlx4_wol_write(priv->mdev->dev, config, priv->port);
	if (err)
		en_err(priv, "Failed to set WoL information\n");

	return err;
}

static int mlx4_en_get_sset_count(struct net_device *dev, int sset)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	int bit_count = hweight64(priv->stats_bitmap);

	switch (sset) {
	case ETH_SS_STATS:
		return (priv->stats_bitmap ? bit_count : NUM_ALL_STATS) +
			(priv->tx_ring_num + priv->rx_ring_num) * 2;
#ifdef __VMKERNEL_ETHTOOL_SELF_TEST_SUPPORT__
	case ETH_SS_TEST:
		return MLX4_EN_NUM_SELF_TEST - !(priv->mdev->dev->caps.flags
					& MLX4_DEV_CAP_FLAG_UC_LOOPBACK) * 2;
#endif	/* __VMKERNEL_ETHTOOL_SELF_TEST_SUPPORT__ */
	default:
		return -EOPNOTSUPP;
	}
}

static void mlx4_en_get_ethtool_stats(struct net_device *dev,
		struct ethtool_stats *stats, uint64_t *data)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	int index = 0;
	int i, j = 0;

	spin_lock_bh(&priv->stats_lock);

	if (!(priv->stats_bitmap)) {
		for (i = 0; i < NUM_MAIN_STATS; i++)
			data[index++] =
				((unsigned long *) &priv->stats)[i];
		for (i = 0; i < NUM_PORT_STATS; i++)
			data[index++] =
				((unsigned long *) &priv->port_stats)[i];
		for (i = 0; i < NUM_PKT_STATS; i++)
			data[index++] =
				((unsigned long *) &priv->pkstats)[i];
	} else {
		for (i = 0; i < NUM_MAIN_STATS; i++) {
			if ((priv->stats_bitmap >> j) & 1)
				data[index++] =
				((unsigned long *) &priv->stats)[i];
			j++;
		}
		for (i = 0; i < NUM_PORT_STATS; i++) {
			if ((priv->stats_bitmap >> j) & 1)
				data[index++] =
				((unsigned long *) &priv->port_stats)[i];
			j++;
		}
	}
	for (i = 0; i < priv->tx_ring_num; i++) {
		data[index++] = priv->tx_ring[i].packets;
		data[index++] = priv->tx_ring[i].bytes;
	}
	for (i = 0; i < priv->rx_ring_num; i++) {
		data[index++] = priv->rx_ring[i].packets;
		data[index++] = priv->rx_ring[i].bytes;
	}
	spin_unlock_bh(&priv->stats_lock);

}

#ifndef __VMKERNEL_MODULE__
static void mlx4_en_self_test(struct net_device *dev,
			      struct ethtool_test *etest, u64 *buf)
{
	mlx4_en_ex_selftest(dev, &etest->flags, buf);
}
#endif  /* __VMKERNEL_MODULE__ */

static u32 mlx4_en_get_link(struct net_device *dev)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	return priv->port_state.link_state;
}

static void mlx4_en_get_strings(struct net_device *dev,
				uint32_t stringset, uint8_t *data)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	int index = 0;
	int i;

	switch (stringset) {
#ifdef __VMKERNEL_ETHTOOL_SELF_TEST_SUPPORT__
	case ETH_SS_TEST:
		for (i = 0; i < MLX4_EN_NUM_SELF_TEST - 2; i++)
			strcpy(data + i * ETH_GSTRING_LEN, mlx4_en_test_names[i]);
		if (priv->mdev->dev->caps.flags & MLX4_DEV_CAP_FLAG_UC_LOOPBACK)
			for (; i < MLX4_EN_NUM_SELF_TEST; i++)
				strcpy(data + i * ETH_GSTRING_LEN, mlx4_en_test_names[i]);
		break;
#endif	/* __VMKERNEL_ETHTOOL_SELF_TEST_SUPPORT__ */

	case ETH_SS_STATS:
		/* Add main counters */
		if (!priv->stats_bitmap) {
			for (i = 0; i < NUM_MAIN_STATS; i++)
				strcpy(data + (index++) * ETH_GSTRING_LEN,
					main_strings[i]);
			for (i = 0; i < NUM_PORT_STATS; i++)
				strcpy(data + (index++) * ETH_GSTRING_LEN,
					main_strings[i +
					NUM_MAIN_STATS]);
			for (i = 0; i < NUM_PKT_STATS; i++)
				strcpy(data + (index++) * ETH_GSTRING_LEN,
					main_strings[i +
					NUM_MAIN_STATS +
					NUM_PORT_STATS]);
		} else
			for (i = 0; i < NUM_MAIN_STATS + NUM_PORT_STATS; i++) {
				if ((priv->stats_bitmap >> i) & 1) {
					strcpy(data +
					       (index++) * ETH_GSTRING_LEN,
					       main_strings[i]);
				}
				if (!(priv->stats_bitmap >> i))
					break;
			}
		for (i = 0; i < priv->tx_ring_num; i++) {
			sprintf(data + (index++) * ETH_GSTRING_LEN,
				"tx%d_packets", i);
			sprintf(data + (index++) * ETH_GSTRING_LEN,
				"tx%d_bytes", i);
		}
		for (i = 0; i < priv->rx_ring_num; i++) {
			sprintf(data + (index++) * ETH_GSTRING_LEN,
				"rx%d_packets", i);
			sprintf(data + (index++) * ETH_GSTRING_LEN,
				"rx%d_bytes", i);
		}
		break;
	}
}

static int mlx4_en_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	int trans_type;

	cmd->autoneg = AUTONEG_DISABLE;

	cmd->supported = SUPPORTED_1000baseT_Full
			|SUPPORTED_10000baseT_Full;

	cmd->advertising = ADVERTISED_1000baseT_Full
			|ADVERTISED_10000baseT_Full;

#ifdef __MLNX_VMKERNEL_40G_SPEED_SUPPORT__
	/* SUPPORTED_1000baseT_Half isn't supported */
	cmd->supported |= SUPPORTED_1000baseKX_Full
			|SUPPORTED_10000baseKX4_Full
			|SUPPORTED_10000baseKR_Full
			|SUPPORTED_10000baseR_FEC
			|SUPPORTED_40000baseKR4_Full
			|SUPPORTED_40000baseCR4_Full
			|SUPPORTED_40000baseSR4_Full
			|SUPPORTED_40000baseLR4_Full;

	/* ADVERTISED_1000baseT_Half isn't advertised */
	cmd->advertising |= ADVERTISED_1000baseKX_Full
			|ADVERTISED_10000baseKX4_Full
			|ADVERTISED_10000baseKR_Full
			|ADVERTISED_10000baseR_FEC
			|ADVERTISED_40000baseKR4_Full
			|ADVERTISED_40000baseCR4_Full
			|ADVERTISED_40000baseSR4_Full
			|ADVERTISED_40000baseLR4_Full;
#endif /* __MLNX_VMKERNEL_40G_SPEED_SUPPORT__ */

	trans_type = priv->port_state.transciver;
	if (priv->port_state.link_state) {
		ethtool_cmd_speed_set(cmd, priv->port_state.link_speed);
		cmd->duplex = DUPLEX_FULL;
	} else {
		ethtool_cmd_speed_set(cmd, -1);
		cmd->duplex = -1;
	}

	if (trans_type > 0 && trans_type <= 0xC) {
		cmd->port = PORT_FIBRE;
		cmd->transceiver = XCVR_EXTERNAL;
		cmd->supported |= SUPPORTED_FIBRE;
		cmd->advertising |= ADVERTISED_FIBRE;
	} else if (trans_type == 0x80 || trans_type == 0) {
		cmd->port = PORT_TP;
		cmd->transceiver = XCVR_INTERNAL;
		cmd->supported |= SUPPORTED_TP;
		cmd->advertising |= ADVERTISED_TP;
	} else  {
		cmd->port = -1;
		cmd->transceiver = -1;
	}
	return 0;
}

static int mlx4_en_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
#ifndef __VMKERNEL_MODULE__
	if ((cmd->autoneg == AUTONEG_ENABLE) ||
	    (ethtool_cmd_speed(cmd) != SPEED_10000) ||
	    (cmd->duplex != DUPLEX_FULL))
		return -EINVAL;
#endif	/* NOT __VMKERNEL_MODULE__ */

	/* Nothing to change */
	return 0;
}

#ifdef __VMKERNEL_MODULE__
static u32 mlx4_en_get_tso(struct net_device *dev)
{
	return (dev->features & NETIF_F_TSO) != 0;
}

static u32 mlx4_en_get_rx_csum(struct net_device *dev)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	return priv->rx_csum;
}

static int mlx4_en_set_rx_csum(struct net_device *dev, u32 data)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	priv->rx_csum = !!data;
	return 0;
}
#endif  /* __VMKERNEL_MODULE__ */

static int mlx4_en_get_coalesce(struct net_device *dev,
			      struct ethtool_coalesce *coal)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);

	coal->tx_coalesce_usecs = priv->tx_usecs;
	coal->tx_max_coalesced_frames = priv->tx_frames;
	coal->rx_coalesce_usecs = priv->rx_usecs;
	coal->rx_max_coalesced_frames = priv->rx_frames;

	coal->pkt_rate_low = priv->pkt_rate_low;
	coal->rx_coalesce_usecs_low = priv->rx_usecs_low;
	coal->pkt_rate_high = priv->pkt_rate_high;
	coal->rx_coalesce_usecs_high = priv->rx_usecs_high;
	coal->rate_sample_interval = priv->sample_interval;
	coal->use_adaptive_rx_coalesce = priv->adaptive_rx_coal;
	return 0;
}

static int mlx4_en_set_coalesce(struct net_device *dev,
			      struct ethtool_coalesce *coal)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	struct mlx4_en_dev *mdev = priv->mdev;
	int i, err = 0;

	mutex_lock(&mdev->state_lock);
	if (!(mdev->device_up && priv->port_up))
		goto out;

#ifdef __VMKERNEL_MODULE__
	priv->rx_frames = (coal->rx_max_coalesced_frames ==
			   MLX4_EN_AUTO_CONF) ?
				MLX4_EN_RX_COAL_TARGET /
				dev->mtu + 1:
				coal->rx_max_coalesced_frames;
#else
	priv->rx_frames = (coal->rx_max_coalesced_frames ==
			   MLX4_EN_AUTO_CONF) ?
				MLX4_EN_RX_COAL_TARGET :
				coal->rx_max_coalesced_frames;
#endif  /* __VMKERNEL_MODULE__ */
	priv->rx_usecs = (coal->rx_coalesce_usecs ==
			  MLX4_EN_AUTO_CONF) ?
				MLX4_EN_RX_COAL_TIME :
				coal->rx_coalesce_usecs;

	/* Setting TX coalescing parameters */
	if (coal->tx_coalesce_usecs != priv->tx_usecs ||
	    coal->tx_max_coalesced_frames != priv->tx_frames) {
		priv->tx_usecs = coal->tx_coalesce_usecs;
		priv->tx_frames = coal->tx_max_coalesced_frames;
		for (i = 0; i < priv->tx_ring_num; i++) {
			priv->tx_cq[i].moder_cnt = priv->tx_frames;
			priv->tx_cq[i].moder_time = priv->tx_usecs;
			if (mlx4_en_set_cq_moder(priv, &priv->tx_cq[i])) {
				en_warn(priv, "Failed changing moderation "
					      "for TX cq %d\n", i);
			}
		}
	}

	/* Set adaptive coalescing params */
	priv->pkt_rate_low = coal->pkt_rate_low;
	priv->rx_usecs_low = coal->rx_coalesce_usecs_low;
	priv->pkt_rate_high = coal->pkt_rate_high;
	priv->rx_usecs_high = coal->rx_coalesce_usecs_high;
	priv->sample_interval = coal->rate_sample_interval;
	priv->adaptive_rx_coal = coal->use_adaptive_rx_coalesce;
	if (priv->adaptive_rx_coal)
		goto out;

	for (i = 0; i < priv->rx_ring_num; i++) {
		priv->rx_cq[i].moder_cnt = priv->rx_frames;
		priv->rx_cq[i].moder_time = priv->rx_usecs;
		priv->last_moder_time[i] = MLX4_EN_AUTO_CONF;
		err = mlx4_en_set_cq_moder(priv, &priv->rx_cq[i]);
		if (err)
			goto out;
	}

out:
	mutex_unlock(&mdev->state_lock);
	return err;
}

static int mlx4_en_set_pauseparam(struct net_device *dev,
				struct ethtool_pauseparam *pause)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	struct mlx4_en_dev *mdev = priv->mdev;
	int err;

	priv->prof->tx_pause = pause->tx_pause != 0;
	priv->prof->rx_pause = pause->rx_pause != 0;
	err = mlx4_SET_PORT_general(mdev->dev, priv->port,
				    priv->rx_skb_size + ETH_FCS_LEN,
				    priv->prof->tx_pause,
				    priv->prof->tx_ppp,
				    priv->prof->rx_pause,
				    priv->prof->rx_ppp);
	if (err)
		en_err(priv, "Failed setting pause params\n");

	return err;
}

static void mlx4_en_get_pauseparam(struct net_device *dev,
				 struct ethtool_pauseparam *pause)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);

	pause->tx_pause = priv->prof->tx_pause;
	pause->rx_pause = priv->prof->rx_pause;
}

static int mlx4_en_set_ringparam(struct net_device *dev,
				 struct ethtool_ringparam *param)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	struct mlx4_en_dev *mdev = priv->mdev;
	u32 rx_size, tx_size;
	int port_up = 0;
	int err = 0;
	int i;

	if (param->rx_jumbo_pending || param->rx_mini_pending)
		return -EINVAL;

	rx_size = roundup_pow_of_two(param->rx_pending);
	rx_size = max_t(u32, rx_size, MLX4_EN_MIN_RX_SIZE);
	rx_size = min_t(u32, rx_size, MLX4_EN_MAX_RX_SIZE);
	tx_size = roundup_pow_of_two(param->tx_pending);
	tx_size = max_t(u32, tx_size, MLX4_EN_MIN_TX_SIZE);
	tx_size = min_t(u32, tx_size, MLX4_EN_MAX_TX_SIZE);

	mutex_lock(&mdev->state_lock);
	if (rx_size == (priv->port_up ? priv->rx_ring[0].actual_size :
					priv->rx_ring[0].size) &&
	    tx_size == priv->tx_ring[0].size)
		goto out;

	if (priv->port_up) {
		port_up = 1;
		mlx4_en_stop_port(dev);
	}

	mlx4_en_free_resources(priv);

	priv->prof->tx_ring_size = tx_size;
	priv->prof->rx_ring_size = rx_size;

	err = mlx4_en_alloc_resources(priv);
	if (err) {
		en_err(priv, "Failed reallocating port resources\n");
		goto out;
	}
	if (port_up) {
		err = mlx4_en_start_port(dev);
		if (err) {
			en_err(priv, "Failed starting port\n");
			goto out;
		}

		for (i = 0; i < priv->rx_ring_num; i++) {
			priv->rx_cq[i].moder_cnt = priv->rx_frames;
			priv->rx_cq[i].moder_time = priv->rx_usecs;
			priv->last_moder_time[i] = MLX4_EN_AUTO_CONF;
			err = mlx4_en_set_cq_moder(priv, &priv->rx_cq[i]);
			if (err)
				goto out;
		}
	}
out:
	mutex_unlock(&mdev->state_lock);
	return err;
}

static void mlx4_en_get_ringparam(struct net_device *dev,
				  struct ethtool_ringparam *param)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);

	memset(param, 0, sizeof(*param));
	param->rx_max_pending = MLX4_EN_MAX_RX_SIZE;
	param->tx_max_pending = MLX4_EN_MAX_TX_SIZE;
	param->rx_pending = priv->port_up ?
		priv->rx_ring[0].actual_size : priv->rx_ring[0].size;
	param->tx_pending = priv->tx_ring[0].size;
}

#ifdef __VMKERNEL_ETHTOOL_RSS_NUM_RINGS_SUPPORT__
static u32 mlx4_en_get_rxfh_indir_size(struct net_device *dev)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);

	return priv->rx_ring_num;
}

static int mlx4_en_get_rxfh_indir(struct net_device *dev, u32 *ring_index)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	struct mlx4_en_rss_map *rss_map = &priv->rss_map;
	int rss_rings;
	size_t n = priv->rx_ring_num;
	int err = 0;

	rss_rings = priv->prof->rss_rings ?: priv->rx_ring_num;

	while (n--) {
		ring_index[n] = rss_map->qps[n % rss_rings].qpn -
			rss_map->base_qpn;
	}

	return err;
}

static int mlx4_en_set_rxfh_indir(struct net_device *dev,
		const u32 *ring_index)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	struct mlx4_en_dev *mdev = priv->mdev;
	int port_up = 0;
	int err = 0;
	int i;
	int rss_rings = 0;

	/* Calculate RSS table size and make sure flows are spread evenly
	 * between rings
	 */
	for (i = 0; i < priv->rx_ring_num; i++) {
		if (i > 0 && !ring_index[i] && !rss_rings)
			rss_rings = i;

		if (ring_index[i] != (i % (rss_rings ?: priv->rx_ring_num)))
			return -EINVAL;
	}

	if (!rss_rings)
		rss_rings = priv->rx_ring_num;

	/* RSS table size must be an order of 2 */
	if (!is_power_of_2(rss_rings))
		return -EINVAL;

	mutex_lock(&mdev->state_lock);
	if (priv->port_up) {
		port_up = 1;
		mlx4_en_stop_port(dev);
	}

	priv->prof->rss_rings = rss_rings;

	if (port_up) {
		err = mlx4_en_start_port(dev);
		if (err)
			en_err(priv, "Failed starting port\n");
	}

	mutex_unlock(&mdev->state_lock);
	return err;
}

static int mlx4_en_get_rxnfc(struct net_device *dev, struct ethtool_rxnfc *cmd,
			     u32 *rule_locs)
{
	struct mlx4_en_priv *priv = netdev_priv(dev);
	int err = 0;

	switch (cmd->cmd) {
	case ETHTOOL_GRXRINGS:
		cmd->data = priv->rx_ring_num;
		break;
	default:
		err = -EOPNOTSUPP;
		break;
	}

	return err;
}
#endif	/* __VMKERNEL_ETHTOOL_RSS_NUM_RINGS_SUPPORT__ */

#ifndef __VMKERNEL_MODULE__
const struct ethtool_ops mlx4_en_ethtool_ops = {
#else
struct ethtool_ops mlx4_en_ethtool_ops = {
#endif	/* NOT __VMKERNEL_MODULE__ */
	.get_drvinfo = mlx4_en_get_drvinfo,
	.get_settings = mlx4_en_get_settings,
	.set_settings = mlx4_en_set_settings,
#ifdef __VMKERNEL_MODULE__
#ifdef NETIF_F_TSO
	.get_tso = mlx4_en_get_tso,
#endif  /* NETIF_F_TSO */
	.get_sg = ethtool_op_get_sg,
	.get_rx_csum = mlx4_en_get_rx_csum,
	.set_rx_csum = mlx4_en_set_rx_csum,
	.get_tx_csum = ethtool_op_get_tx_csum,
#endif  /* __VMKERNEL_MODULE__ */
	.get_link = mlx4_en_get_link,
	.get_strings = mlx4_en_get_strings,
	.get_sset_count = mlx4_en_get_sset_count,
	.get_ethtool_stats = mlx4_en_get_ethtool_stats,
#ifdef __VMKERNEL_ETHTOOL_SELF_TEST_SUPPORT__
	.self_test = mlx4_en_self_test,
#endif	/* __VMKERNEL_ETHTOOL_SELF_TEST_SUPPORT__ */
	.get_wol = mlx4_en_get_wol,
	.set_wol = mlx4_en_set_wol,
	.get_msglevel = mlx4_en_get_msglevel,
	.set_msglevel = mlx4_en_set_msglevel,
	.get_coalesce = mlx4_en_get_coalesce,
	.set_coalesce = mlx4_en_set_coalesce,
	.get_pauseparam = mlx4_en_get_pauseparam,
	.set_pauseparam = mlx4_en_set_pauseparam,
	.get_ringparam = mlx4_en_get_ringparam,
	.set_ringparam = mlx4_en_set_ringparam,
#ifdef __VMKERNEL_ETHTOOL_RSS_NUM_RINGS_SUPPORT__
	.get_rxnfc = mlx4_en_get_rxnfc,
	.get_rxfh_indir_size = mlx4_en_get_rxfh_indir_size,
	.get_rxfh_indir = mlx4_en_get_rxfh_indir,
	.set_rxfh_indir = mlx4_en_set_rxfh_indir,
#endif	/* __VMKERNEL_ETHTOOL_RSS_NUM_RINGS_SUPPORT__ */
};





