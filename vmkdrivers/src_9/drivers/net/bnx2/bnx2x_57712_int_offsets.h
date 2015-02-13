struct iro e2_iro_arr[333] = {
	{   0x18,    0x0,    0x0,    0x0,    0x0},	// COMMON_SB_SIZE
	{   0x40,    0x0,    0x0,    0x0,    0x0},	// COMMON_SB_DATA_SIZE
	{   0x28,    0x0,    0x0,    0x0,    0x0},	// COMMON_SP_SB_SIZE
	{   0x10,    0x0,    0x0,    0x0,    0x0},	// COMMON_SP_SB_DATA_SIZE
	{   0x20,    0x0,    0x0,    0x0,    0x0},	// COMMON_DYNAMIC_HC_CONFIG_SIZE
	{   0x10,    0x0,    0x0,    0x0,    0x0},	// COMMON_ASM_ASSERT_MSG_SIZE
	{    0x8,    0x0,    0x0,    0x0,    0x0},	// COMMON_ASM_ASSERT_INDEX_SIZE
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// COMMON_ASM_INVALID_ASSERT_OPCODE
	{   0x39,    0x0,    0x0,    0x0,    0x0},	// COMMON_RAM1_TEST_EVENT_ID
	{   0x38,    0x0,    0x0,    0x0,    0x0},	// COMMON_INBOUND_INTERRUPT_TEST_AGG_INT_EVENT_ID
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// COMMON_INBOUND_INTERRUPT_TEST_AGG_INT_1_OFFSET
	{    0x8,    0x0,    0x0,    0x0,    0x0},	// COMMON_INBOUND_INTERRUPT_TEST_AGG_INT_2_OFFSET
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// COMMON_INBOUND_INTERRUPT_TEST_AGG_INT_3_OFFSET
	{    0xc,    0x0,    0x0,    0x0,    0x0},	// COMMON_INBOUND_INTERRUPT_TEST_AGG_INT_1_RESULT_OFFSET
	{    0xe,    0x0,    0x0,    0x0,    0x0},	// COMMON_INBOUND_INTERRUPT_TEST_AGG_INT_2_RESULT_OFFSET
	{    0x4,    0x0,    0x0,    0x0,    0x0},	// COMMON_INBOUND_INTERRUPT_TEST_AGG_INT_3_RESULT_OFFSET
	{   0x18,    0x0,    0x0,    0x0,    0x0},	// COMMON_INBOUND_INTERRUPT_TEST_AGG_INT_1_MASK
	{   0x1c,    0x0,    0x0,    0x0,    0x0},	// COMMON_INBOUND_INTERRUPT_TEST_AGG_INT_2_MASK
	{   0x1c,    0x0,    0x0,    0x0,    0x0},	// COMMON_INBOUND_INTERRUPT_TEST_AGG_INT_3_MASK
	{   0x13,    0x0,    0x0,    0x0,    0x0},	// COMMON_KUKU_TEST_AGG_INT
	{   0x3a,    0x0,    0x0,    0x0,    0x0},	// COMMON_KUKU_TEST_EVENTID
	{    0x1,    0x0,    0x0,    0x0,    0x0},	// COMMON_KUKU_PCI_READ_OPCODE
	{    0x2,    0x0,    0x0,    0x0,    0x0},	// COMMON_KUKU_LOAD_CONTEXT_OPCODE
	{    0x1,    0x0,    0x0,    0x0,    0x0},	// COMMON_KUKU_LOAD_CONTEXT_INCVAL
	{   0x10,    0x0,    0x0,    0x0,    0x0},	// COMMON_KUKU_LOAD_CONTEXT_REGION
	{   0x50,    0x0,    0x0,    0x0,    0x0},	// COMMON_KUKU_LOAD_CONTEXT_CID
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// COMMON_KUKU_LOAD_CONTEXT_RUN_PBF_ECHO_TEST
	{    0x3,    0x0,    0x0,    0x0,    0x0},	// COMMON_KUKU_QM_PAUSE_OPCODE
	{   0xab,    0x0,    0x0,    0x0,    0x0},	// COMMON_KUKU_TEST_UNUSED_FOCS_SUCCESS_OPCODE_VALUE
	{    0x8,    0x0,    0x0,    0x0,    0x0},	// COMMON_KUKU_TEST_UNUSED_FOCS_OPCODE_VALUE
	{ 0xc000,   0x10,    0x0,    0x0,    0x8},	// XSTORM_SPQ_PAGE_BASE_OFFSET(funcId)
	{ 0xc008,   0x10,    0x0,    0x0,    0x2},	// XSTORM_SPQ_PROD_OFFSET(funcId)
	{ 0xc000,   0x10,    0x0,    0x0,   0x10},	// XSTORM_SPQ_DATA_OFFSET(funcId)
	{ 0x9fa8,    0x0,    0x0,    0x0,    0x8},	// XSTORM_DCB_VERSION_OFFSET
	{ 0xc080,   0x10,    0x0,    0x0,    0x4},	// XSTORM_VF_SPQ_PAGE_BASE_OFFSET(vfId)
	{ 0xc088,   0x10,    0x0,    0x0,    0x2},	// XSTORM_VF_SPQ_PROD_OFFSET(vfId)
	{ 0xc080,   0x10,    0x0,    0x0,   0x10},	// XSTORM_VF_SPQ_DATA_OFFSET(vfId)
	{ 0x9120,    0x0,    0x0,    0x0,    0x8},	// XSTORM_VIRTUALIZATION_MODE_OFFSET
	{ 0x9340,    0x1,    0x4,    0x0,    0x1},	// XSTORM_JUMBO_SUPPORT_OFFSET(pfId)
	{ 0x9348,    0x0,    0x0,    0x0,    0x2},	// XSTORM_COMMON_IP_ID_MASK_OFFSET
	{ 0x9350,    0x0,    0x0,    0x0,    0x8},	// XSTORM_COMMON_RTC_PARAMS_OFFSET
	{ 0x9354,    0x0,    0x0,    0x0,    0x2},	// XSTORM_COMMON_RTC_RESOLUTION_OFFSET
	{ 0x9418,    0x0,    0x0,    0x0,    0x8},	// XSTORM_FW_VERSION_OFFSET
	{ 0x9358,    0x8,    0x0,    0x0,    0x8},	// XSTORM_STATS_FLAGS_OFFSET(pfId)
	{ 0x9ab0,   0x40,    0x0,    0x0,   0x40},	// XSTORM_LICENSE_VALUES_OFFSET(pfId)
	{ 0x9398,    0x8,    0x0,    0x0,    0x8},	// XSTORM_ETH_STATS_QUERY_ADDR_OFFSET(pfId)
	{ 0x93d8,    0x8,    0x0,    0x0,    0x8},	// XSTORM_TOE_STATS_QUERY_ADDR_OFFSET(pfId)
	{ 0x9420,   0xc8,    0x0,    0x0,   0x98},	// XSTORM_CMNG_PER_PORT_VARS_OFFSET(portId)
	{ 0x95b0,   0x98,    0x0,    0x0,   0x28},	// XSTORM_RATE_SHAPING_PER_VN_VARS_OFFSET(pfId)
	{ 0x95f0,   0x98,    0x0,    0x0,   0x28},	// XSTORM_FAIRNESS_PER_VN_VARS_OFFSET(pfId)
	{ 0xc480,  0x540,   0x30,    0x0,  0x540},	// XSTORM_PER_COUNTER_ID_STATS_OFFSET(portId,xStatCntId)
	{ 0x9d20,    0x8,    0x0,    0x0,    0x1},	// XSTORM_FUNC_EN_OFFSET(funcId)
	{ 0x9d21,    0x8,    0x0,    0x0,    0x1},	// XSTORM_VF_TO_PF_OFFSET(funcId)
	{ 0x2008,   0x10,    0x0,    0x0,   0x10},	// XSTORM_ASSERT_LIST_OFFSET(assertListEntry)
	{ 0x2000,    0x0,    0x0,    0x0,    0x8},	// XSTORM_ASSERT_LIST_INDEX_OFFSET
	{ 0x9cd8,    0x8,    0x0,    0x0,    0x2},	// XSTORM_E1HOV_OFFSET(pfId)
	{ 0x9d18,    0x0,    0x0,    0x0,    0x1},	// XSTORM_FUNCTION_MODE_OFFSET
	{    0x1,    0x0,    0x0,    0x0,    0x0},	// XSTORM_AGG_INT_INITIAL_CLEANUP_INDEX
	{    0x9,    0x0,    0x0,    0x0,    0x0},	// XSTORM_AGG_INT_FINAL_CLEANUP_INDEX
	{    0x2,    0x0,    0x0,    0x0,    0x0},	// XSTORM_AGG_INT_FINAL_CLEANUP_COMP_TYPE
	{ 0xcf20,    0x0,    0x0,    0x0,   0x20},	// XSTORM_ERROR_HANDLER_STATISTICS_RAM_OFFSET
	{ 0xcf46,    0x0,    0x0,    0x0,    0x1},	// XSTORM_LB_PHYSICAL_QUEUES_INFO_OFFSET
	{ 0x6000,   0x20,    0x0,    0x0,   0x20},	// XSTORM_QUEUE_ZONE_OFFSET(queueId)
	{ 0x7300,    0x8,    0x0,    0x0,    0x8},	// XSTORM_VF_ZONE_OFFSET(vfId)
	{ 0x9f98,    0x0,    0x0,    0x0,    0x1},	// XSTORM_FIVE_TUPLE_SRC_EN_OFFSET
	{ 0x9fa0,    0x0,    0x0,    0x0,    0x1},	// XSTORM_PATH_ID_OFFSET
	{ 0x9f60,    0x0,    0x0,    0x0,    0x8},	// XSTORM_E2_INTEG_RAM_OFFSET
	{ 0x9f63,    0x0,    0x0,    0x0,    0x1},	// XSTORM_QM_OPPORTUNISTIC_RAM_OFFSET
	{ 0x9f61,    0x0,    0x0,    0x0,    0x1},	// XSTORM_SIDE_INFO_INPUT_LSB_OFFSET
	{ 0x9f66,    0x0,    0x0,    0x0,    0x1},	// XSTORM_E2_INTEG_VLAN_ID_OFFSET
	{ 0x9f67,    0x0,    0x0,    0x0,    0x0},	// XSTORM_E2_INTEG_VLAN_ID_EN_OFFSET
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// XSTORM_VFC_TEST_LINE_OFFSET
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// XSTORM_VFC_TEST_RESULT_OFFSET
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// XSTORM_VFC_OP_GEN_VALUE
	{    0x3,    0x0,    0x0,    0x0,    0x0},	// XSTORM_INBOUND_INTERRUPT_TEST_VF_INFO_SIZE_IN_BYTES
	{    0x3,    0x0,    0x0,    0x0,    0x0},	// XSTORM_INBOUND_INTERRUPT_TEST_AGG_INT_1_INDEX
	{    0x5,    0x0,    0x0,    0x0,    0x0},	// XSTORM_INBOUND_INTERRUPT_TEST_AGG_INT_2_INDEX
	{    0xf,    0x0,    0x0,    0x0,    0x0},	// XSTORM_INBOUND_INTERRUPT_TEST_AGG_INT_3_INDEX
	{0x60000,    0x0,    0x0,    0x0,   0x20},	// XSTORM_DPM_BUFFER_OFFSET
	{ 0x9f68,    0x0,    0x0,    0x0,    0x1},	// XSTORM_KUKU_TEST_OPCODE_OFFSET
	{ 0x9f88,    0x0,    0x0,    0x0,    0x8},	// XSTORM_KUKU_LOAD_CONTEXT_TEST_OFFSET
	{   0x53,    0x0,    0x0,    0x0,    0x0},	// XSTORM_KUKU_OP_GEN_VALUE
	{ 0x9f90,    0x0,    0x0,    0x0,    0x2},	// XSTORM_QM_PAUSE_TEST_QUEUE_MASK_OFFSET
	{ 0x9f94,    0x0,    0x0,    0x0,    0x1},	// XSTORM_QM_PAUSE_TEST_GROUP_OFFSET
	{ 0x9f95,    0x0,    0x0,    0x0,    0x1},	// XSTORM_QM_PAUSE_TEST_PORT_OFFSET
	{    0x9,    0x0,    0x0,    0x0,    0x0},	// XSTORM_KUKU_PBF_ECHO_OPCODE
	{    0x1,    0x0,    0x0,    0x0,    0x0},	// XSTORM_KUKU_PBF_ECHO_INCVAL
	{   0x44,    0x0,    0x0,    0x0,    0x0},	// XSTORM_KUKU_PBF_ECHO_REGION
	{    0x1,    0x0,    0x0,    0x0,    0x0},	// XSTORM_KUKU_PBF_ECHO_RUN_PBF_ECHO_TEST
	{   0x50,    0x0,    0x0,    0x0,    0x0},	// XSTORM_KUKU_PBF_ECHO_CID
	{   0x89,    0x0,    0x0,    0x0,    0x0},	// XSTORM_KUKU_PBF_ECHO_SUCCESS_VALUE
	{ 0x12c8,   0x80,    0x0,    0x0,   0x80},	// TSTORM_INDIRECTION_TABLE_OFFSET(pfId)
	{    0x1,    0x0,    0x0,    0x0,    0x0},	// TSTORM_INDIRECTION_TABLE_ENTRY_SIZE
	{ 0xa000,  0x718,    0x0,    0x0,  0x718},	// TSTORM_STATISTICS_OFFSET(portId)
	{ 0x1ac8,    0x0,    0x0,    0x0,    0x8},	// TSTORM_COMMON_RTC_PARAMS_OFFSET
	{ 0xaed0,    0x8,    0x0,    0x0,    0x8},	// TSTORM_STATS_FLAGS_OFFSET(pfId)
	{ 0xae50,    0x8,    0x0,    0x0,    0x8},	// TSTORM_ETH_STATS_QUERY_ADDR_OFFSET(pfId)
	{ 0xae90,    0x8,    0x0,    0x0,    0x8},	// TSTORM_TOE_STATS_QUERY_ADDR_OFFSET(pfId)
	{ 0x2008,   0x10,    0x0,    0x0,   0x10},	// TSTORM_ASSERT_LIST_OFFSET(assertListEntry)
	{ 0x2000,    0x0,    0x0,    0x0,    0x8},	// TSTORM_ASSERT_LIST_INDEX_OFFSET
	{ 0xa018,  0x718,   0x40,    0x0,   0x40},	// TSTORM_PER_COUNTER_ID_STATS_OFFSET(portId,tStatCntId)
	{ 0x1ba0,    0x8,    0x0,    0x0,    0x1},	// TSTORM_FUNC_EN_OFFSET(funcId)
	{ 0x1ba1,    0x8,    0x0,    0x0,    0x1},	// TSTORM_VF_TO_PF_OFFSET(funcId)
	{ 0x1ad0,    0x0,    0x0,    0x0,    0x1},	// TSTORM_FUNCTION_MODE_OFFSET
	{ 0x1ad8,    0x0,    0x0,    0x0,    0x2},	// TSTORM_COMMON_SAFC_WORKAROUND_ENABLE_OFFSET
	{ 0x1ada,    0x0,    0x0,    0x0,    0x2},	// TSTORM_COMMON_SAFC_WORKAROUND_TIMEOUT_10USEC_OFFSET
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// CSTORM_PFC_STRUCT_PER_PORT_OFFSET(portId)
	{ 0xaf10,    0x0,    0x0,    0x0,   0x20},	// TSTORM_ERROR_HANDLER_STATISTICS_RAM_OFFSET
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// TSTORM_VFC_TEST_RSS_KEY_OFFSET(portId)
	{ 0xe000,   0x20,    0x0,    0x0,   0x20},	// TSTORM_QUEUE_ZONE_OFFSET(queueId)
	{ 0xf300,    0x8,    0x0,    0x0,    0x8},	// TSTORM_VF_ZONE_OFFSET(vfId)
	{ 0x1af0,    0x0,    0x0,    0x0,   0xb0},	// TSTORM_E2_INTEG_RAM_OFFSET
	{ 0x1b37,    0x0,    0x0,    0x0,    0x1},	// TSTORM_LSB_SIDE_BAND_INFO_OFFSET
	{ 0x1b0f,    0x0,    0x0,    0x0,    0x1},	// TSTORM_MSB_SIDE_BAND_INFO_OFFSET
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// TSTORM_VFC_TEST_LINE_OFFSET
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// TSTORM_VFC_TEST_RESULT_OFFSET
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// TSTORM_VFC_OP_GEN_VALUE
	{    0x3,    0x0,    0x0,    0x0,    0x0},	// TSTORM_INBOUND_INTERRUPT_TEST_VF_INFO_SIZE_IN_BYTES
	{    0x5,    0x0,    0x0,    0x0,    0x0},	// TSTORM_INBOUND_INTERRUPT_TEST_AGG_INT_1_INDEX
	{    0x6,    0x0,    0x0,    0x0,    0x0},	// TSTORM_INBOUND_INTERRUPT_TEST_AGG_INT_2_INDEX
	{    0xd,    0x0,    0x0,    0x0,    0x0},	// TSTORM_INBOUND_INTERRUPT_TEST_AGG_INT_3_INDEX
	{ 0x1b70,    0x0,    0x0,    0x0,    0x1},	// TSTORM_KUKU_TEST_OPCODE_OFFSET
	{ 0x1b90,    0x0,    0x0,    0x0,    0x8},	// TSTORM_KUKU_LOAD_CONTEXT_TEST_OFFSET
	{   0x51,    0x0,    0x0,    0x0,    0x0},	// TSTORM_KUKU_OP_GEN_VALUE
	{ 0x1b78,    0x0,    0x0,    0x0,    0x4},	// TSTORM_PCI_READ_TEST_ADDRESS_LO_OFFSET
	{ 0x1b7c,    0x0,    0x0,    0x0,    0x4},	// TSTORM_PCI_READ_TEST_ADDRESS_HI_OFFSET
	{ 0x1b80,    0x0,    0x0,    0x0,    0x4},	// TSTORM_PCI_READ_TEST_RAM_ADDRESS_OFFSET
	{ 0x1b84,    0x0,    0x0,    0x0,    0x8},	// TSTORM_PCI_READ_TEST_PCI_ENTITY_OFFSET
	{ 0xb000,   0x18,    0x0,    0x0,   0x18},	// CSTORM_STATUS_BLOCK_OFFSET(sbId)
	{ 0xc000,   0x40,    0x0,    0x0,   0x40},	// CSTORM_STATUS_BLOCK_DATA_OFFSET(sbId)
	{ 0xe200,   0x20,    0x0,    0x0,   0x20},	// CSTORM_SYNC_BLOCK_OFFSET(sbId)
	{ 0xe204,    0x2,    0x8,   0x20,    0x2},	// CSTORM_HC_SYNC_LINE_INDEX_E2_OFFSET(hcIndex,sbId)
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// CSTORM_HC_SYNC_LINE_INDEX_E1X_OFFSET(hcIndex,sbId)
	{ 0xe200,    0x8,   0x20,    0x0,    0x4},	// CSTORM_HC_SYNC_LINE_DHC_OFFSET(hcIndex,sbId)
	{ 0xf400,   0x28,    0x0,    0x0,   0x28},	// CSTORM_SP_STATUS_BLOCK_OFFSET(pfId)
	{ 0xf540,   0x10,    0x0,    0x0,   0x10},	// CSTORM_SP_STATUS_BLOCK_DATA_OFFSET(pfId)
	{ 0xf5c0,   0x20,    0x0,    0x0,   0x20},	// CSTORM_SP_SYNC_BLOCK_OFFSET(pfId)
	{ 0xf5c0,    0x2,   0x20,    0x0,    0x2},	// CSTORM_SP_HC_SYNC_LINE_INDEX_OFFSET(hcSpIndex,pfId)
	{ 0xf300,   0x20,    0x0,    0x0,   0x20},	// CSTORM_DYNAMIC_HC_CONFIG_OFFSET(pfId)
	{ 0x2008,   0x10,    0x0,    0x0,   0x10},	// CSTORM_ASSERT_LIST_OFFSET(assertListEntry)
	{ 0x2000,    0x0,    0x0,    0x0,    0x8},	// CSTORM_ASSERT_LIST_INDEX_OFFSET
	{ 0x1108,    0x8,    0x0,    0x0,    0x8},	// CSTORM_STATS_FLAGS_OFFSET(pfId)
	{ 0x1168,    0x8,    0x0,    0x0,    0x8},	// CSTORM_ETH_STATS_QUERY_ADDR_OFFSET(pfId)
	{ 0x11a8,    0x8,    0x0,    0x0,    0x8},	// CSTORM_TOE_STATS_QUERY_ADDR_OFFSET(pfId)
	{ 0x1240,    0x8,    0x0,    0x0,    0x1},	// CSTORM_FUNC_EN_OFFSET(funcId)
	{ 0x1241,    0x8,    0x0,    0x0,    0x1},	// CSTORM_VF_TO_PF_OFFSET(funcId)
	{ 0x4000,   0x20,    0x4,    0x0,   0x10},	// CSTORM_BYTE_COUNTER_OFFSET(sbId,dhcIndex)
	{ 0x5900,   0x30,   0x18,    0x0,   0x10},	// CSTORM_EVENT_RING_DATA_OFFSET(pfId)
	{ 0x5908,   0x30,   0x18,    0x0,    0x2},	// CSTORM_EVENT_RING_PROD_OFFSET(pfId)
	{ 0x5700,    0x8,    0x0,    0x0,    0x1},	// CSTORM_VF_PF_CHANNEL_STATE_OFFSET(vfId)
	{ 0x5701,    0x8,    0x0,    0x0,    0x1},	// CSTORM_VF_PF_CHANNEL_VALID_OFFSET(vfId)
	{ 0x11e8,    0x0,    0x0,    0x0,    0x1},	// CSTORM_FUNCTION_MODE_OFFSET
	{ 0x11f0,    0x0,    0x0,    0x0,    0x1},	// CSTORM_IGU_MODE_OFFSET
	{ 0x11f8,    0x0,    0x0,    0x0,   0x10},	// CSTORM_ERROR_HANDLER_STATISTICS_RAM_OFFSET
	{ 0x1244,    0x8,    0x0,    0x0,    0x4},	// CSTORM_FINAL_CLEANUP_COMPLETE_OFFSET(funcId)
	{ 0x4000,   0x20,    0x0,    0x0,   0x20},	// CSTORM_QUEUE_ZONE_OFFSET(queueId)
	{ 0x5300,   0x10,    0x0,    0x0,   0x10},	// CSTORM_VF_ZONE_OFFSET(vfId)
	{ 0x1538,    0x0,    0x0,    0x0,    0x1},	// CSTORM_PATH_ID_OFFSET
	{    0x3,    0x0,    0x0,    0x0,    0x0},	// CSTORM_INBOUND_INTERRUPT_TEST_VF_INFO_SIZE_IN_BYTES
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// CSTORM_INBOUND_INTERRUPT_TEST_AGG_INT_1_INDEX
	{    0x1,    0x0,    0x0,    0x0,    0x0},	// CSTORM_INBOUND_INTERRUPT_TEST_AGG_INT_2_INDEX
	{    0xb,    0x0,    0x0,    0x0,    0x0},	// CSTORM_INBOUND_INTERRUPT_TEST_AGG_INT_3_INDEX
	{ 0x1508,    0x0,    0x0,    0x0,    0x1},	// CSTORM_KUKU_TEST_OPCODE_OFFSET
	{ 0x1528,    0x0,    0x0,    0x0,    0x8},	// CSTORM_KUKU_LOAD_CONTEXT_TEST_OFFSET
	{   0x50,    0x0,    0x0,    0x0,    0x0},	// CSTORM_KUKU_OP_GEN_VALUE
	{ 0x8308,   0x80,    0x0,    0x0,   0x80},	// USTORM_INDIRECTION_TABLE_OFFSET(portId)
	{    0x1,    0x0,    0x0,    0x0,    0x0},	// USTORM_INDIRECTION_TABLE_ENTRY_SIZE
	{ 0x2008,   0x10,    0x0,    0x0,   0x10},	// USTORM_ASSERT_LIST_OFFSET(assertListEntry)
	{ 0x2000,    0x0,    0x0,    0x0,    0x8},	// USTORM_ASSERT_LIST_INDEX_OFFSET
	{ 0x8410,    0x8,    0x0,    0x0,    0x8},	// USTORM_STATS_FLAGS_OFFSET(pfId)
	{ 0x8470,    0x8,    0x0,    0x0,    0x8},	// USTORM_ETH_STATS_QUERY_ADDR_OFFSET(pfId)
	{ 0x1000,  0x460,   0x28,    0x0,  0x460},	// USTORM_PER_COUNTER_ID_STATS_OFFSET(portId,uStatCntId)
	{ 0x8520,    0x8,    0x0,    0x0,    0x1},	// USTORM_FUNC_EN_OFFSET(funcId)
	{ 0x8521,    0x8,    0x0,    0x0,    0x1},	// USTORM_VF_TO_PF_OFFSET(funcId)
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// USTORM_MEM_WORKAROUND_ADDRESS_OFFSET(pfId)
	{ 0x8408,    0x0,    0x0,    0x0,    0x1},	// USTORM_FUNCTION_MODE_OFFSET
	{ 0x84f4,    0x8,    0x0,    0x0,    0x2},	// USTORM_ETH_PAUSE_ENABLED_OFFSET(portId)
	{ 0x84f6,    0x8,    0x0,    0x0,    0x2},	// USTORM_TOE_PAUSE_ENABLED_OFFSET(portId)
	{ 0x8504,   0x10,    0x0,    0x0,    0x4},	// USTORM_MAX_PAUSE_TIME_USEC_OFFSET(portId)
	{ 0x8760,    0x0,    0x0,    0x0,   0x20},	// USTORM_ERROR_HANDLER_STATISTICS_RAM_OFFSET
	{ 0x6000,   0x20,    0x0,    0x0,   0x20},	// USTORM_QUEUE_ZONE_OFFSET(queueId)
	{ 0x7300,    0x8,    0x0,    0x0,    0x8},	// USTORM_VF_ZONE_OFFSET(vfId)
	{    0x3,    0x0,    0x0,    0x0,    0x0},	// USTORM_INBOUND_INTERRUPT_TEST_VF_INFO_SIZE_IN_BYTES
	{    0x5,    0x0,    0x0,    0x0,    0x0},	// USTORM_INBOUND_INTERRUPT_TEST_AGG_INT_1_INDEX
	{    0x6,    0x0,    0x0,    0x0,    0x0},	// USTORM_INBOUND_INTERRUPT_TEST_AGG_INT_2_INDEX
	{    0xd,    0x0,    0x0,    0x0,    0x0},	// USTORM_INBOUND_INTERRUPT_TEST_AGG_INT_3_INDEX
	{ 0x8808,    0x0,    0x0,    0x0,    0x1},	// USTORM_KUKU_TEST_OPCODE_OFFSET
	{ 0x8828,    0x0,    0x0,    0x0,    0x8},	// USTORM_KUKU_LOAD_CONTEXT_TEST_OFFSET
	{   0x50,    0x0,    0x0,    0x0,    0x0},	// USTORM_KUKU_OP_GEN_VALUE
	{ 0x8810,    0x0,    0x0,    0x0,    0x4},	// USTORM_PCI_READ_TEST_ADDRESS_LO_OFFSET
	{ 0x8814,    0x0,    0x0,    0x0,    0x4},	// USTORM_PCI_READ_TEST_ADDRESS_HI_OFFSET
	{ 0x8818,    0x0,    0x0,    0x0,    0x4},	// USTORM_PCI_READ_TEST_RAM_ADDRESS_OFFSET
	{ 0x881c,    0x0,    0x0,    0x0,    0x8},	// USTORM_PCI_READ_TEST_PCI_ENTITY_OFFSET
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// TSTORM_FUNCTION_COMMON_CONFIG_OFFSET(pfId)
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// TSTORM_MAC_FILTER_CONFIG_OFFSET(pfId)
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// TSTORM_APPROXIMATE_MATCH_MULTICAST_FILTERING_OFFSET(pfId)
	{ 0x30a0,    0x0,    0x0,    0x0,    0x8},	// TSTORM_ACCEPT_CLASSIFY_FAILED_OFFSET
	{0x62a20, 0x2600,   0x40,    0x0,    0x8},	// USTORM_CQE_PAGE_NEXT_VMWARE_TEMP_OFFSET(portId,clientId)
	{ 0xa000,    0x0,    0x0,    0x0, 0x2000},	// USTORM_AGG_DATA_OFFSET
	{ 0x30a1,    0x0,    0x0,    0x0,    0x1},	// USTORM_TPA_BTR_OFFSET
	{ 0x30e8,    0x0,    0x0,    0x0,    0x2},	// USTORM_ETH_DYNAMIC_HC_PARAM_OFFSET
	{    0x0,    0x0,    0x0,    0x0,    0x0},	// USTORM_RX_PRODS_E1X_OFFSET(portId,clientId)
	{ 0x6000,   0x20,    0x0,    0x0,    0x8},	// USTORM_RX_PRODS_E2_OFFSET(qzoneId)
	{ 0x4000,    0x8,    0x0,    0x0,    0x1},	// XSTORM_TCP_GLOBAL_DEL_ACK_COUNTER_ENABLED_OFFSET(portId)
	{ 0x4001,    0x8,    0x0,    0x0,    0x1},	// XSTORM_TCP_GLOBAL_DEL_ACK_COUNTER_MAX_COUNT_OFFSET(portId)
	{ 0x4040,    0x8,    0x4,    0x0,    0x2},	// XSTORM_TCP_IPID_OFFSET(pfId)
	{ 0x4060,    0x8,    0x4,    0x0,    0x4},	// XSTORM_TCP_TX_SWS_TIMER_VAL_OFFSET(pfId)
	{ 0x4000,    0x8,    0x0,    0x0,    0x4},	// TSTORM_TCP_DUPLICATE_ACK_THRESHOLD_OFFSET(pfId)
	{ 0x4004,    0x8,    0x0,    0x0,    0x4},	// TSTORM_TCP_MAX_CWND_OFFSET(pfId)
	{ 0x4040,    0x0,    0x0,    0x0,    0x8},	// TSTORM_TCP_GLOBAL_PARAMS_OFFSET
	{ 0x4048,    0x0,    0x0,    0x0,    0x8},	// TSTORM_TCP_ISLES_ARRAY_DESCRIPTOR_OFFSET
	{ 0x8000,    0x0,    0x0,    0x0,   0x10},	// TSTORM_TCP_ISLES_ARRAY_OFFSET
	{ 0x5040,    0x1,    0x4,    0x0,    0x1},	// XSTORM_TOE_LLC_SNAP_ENABLED_OFFSET(pfId)
	{ 0x5000,    0x0,    0x0,    0x0,   0x20},	// XSTORM_OUT_OCTETS_OFFSET
	{ 0x5008,   0x10,    0x0,    0x0,    0x4},	// TSTORM_TOE_MAX_SEG_RETRANSMIT_OFFSET(pfId)
	{ 0x500c,   0x10,    0x0,    0x0,    0x1},	// TSTORM_TOE_DOUBT_REACHABILITY_OFFSET(pfId)
	{ 0x3000,   0x30,   0x18,    0x0,    0x4},	// CSTORM_TOE_CQ_CONS_PTR_LO_OFFSET(rssId,portId)
	{ 0x3004,   0x30,   0x18,    0x0,    0x4},	// CSTORM_TOE_CQ_CONS_PTR_HI_OFFSET(rssId,portId)
	{ 0x3008,   0x30,   0x18,    0x0,    0x2},	// CSTORM_TOE_CQ_PROD_OFFSET(rssId,portId)
	{ 0x300a,   0x30,   0x18,    0x0,    0x2},	// CSTORM_TOE_CQ_CONS_OFFSET(rssId,portId)
	{ 0x300c,   0x30,   0x18,    0x0,    0x1},	// CSTORM_TOE_CQ_NXT_PAGE_ADDR_VALID_OFFSET(rssId,portId)
	{ 0x300d,   0x30,   0x18,    0x0,    0x1},	// CSTORM_TOE_STATUS_BLOCK_ID_OFFSET(rssId,portId)
	{ 0x300e,   0x30,   0x18,    0x0,    0x1},	// CSTORM_TOE_STATUS_BLOCK_INDEX_OFFSET(rssId,portId)
	{ 0x3010,   0x30,   0x18,    0x0,    0x4},	// CSTORM_TOE_CQ_NEXT_PAGE_BASE_ADDR_LO_OFFSET(rssId,portId)
	{ 0x3014,   0x30,   0x18,    0x0,    0x4},	// CSTORM_TOE_CQ_NEXT_PAGE_BASE_ADDR_HI_OFFSET(rssId,portId)
	{ 0x5000,  0x100,   0x80,    0x8,    0x4},	// USTORM_GRQ_CACHE_BD_LO_OFFSET(rssId,portId,grqBdId)
	{ 0x5004,  0x100,   0x80,    0x8,    0x4},	// USTORM_GRQ_CACHE_BD_HI_OFFSET(rssId,portId,grqBdId)
	{    0xa,    0x0,    0x0,    0x0,    0x0},	// USTORM_TOE_GRQ_CACHE_NUM_BDS
	{ 0x5068,  0x100,   0x80,    0x0,    0x1},	// USTORM_TOE_GRQ_LOCAL_PROD_OFFSET(rssId,portId)
	{ 0x5069,  0x100,   0x80,    0x0,    0x1},	// USTORM_TOE_GRQ_LOCAL_CONS_OFFSET(rssId,portId)
	{ 0x506c,  0x100,   0x80,    0x0,    0x2},	// USTORM_TOE_GRQ_CONS_OFFSET(rssId,portId)
	{ 0x506e,  0x100,   0x80,    0x0,    0x2},	// USTORM_TOE_GRQ_PROD_OFFSET(rssId,portId)
	{ 0x5070,  0x100,   0x80,    0x0,    0x4},	// USTORM_TOE_GRQ_CONS_PTR_LO_OFFSET(rssId,portId)
	{ 0x5074,  0x100,   0x80,    0x0,    0x4},	// USTORM_TOE_GRQ_CONS_PTR_HI_OFFSET(rssId,portId)
	{ 0x5066,  0x100,   0x80,    0x0,    0x2},	// USTORM_TOE_GRQ_BUF_SIZE_OFFSET(rssId,portId)
	{ 0x5064,  0x100,   0x80,    0x0,    0x1},	// USTORM_TOE_CQ_NXT_PAGE_ADDR_VALID_OFFSET(rssId,portId)
	{ 0x5060,  0x100,   0x80,    0x0,    0x2},	// USTORM_TOE_CQ_CONS_OFFSET(rssId,portId)
	{ 0x5062,  0x100,   0x80,    0x0,    0x2},	// USTORM_TOE_CQ_PROD_OFFSET(rssId,portId)
	{ 0x5050,  0x100,   0x80,    0x0,    0x4},	// USTORM_TOE_CQ_NEXT_PAGE_BASE_ADDR_LO_OFFSET(rssId,portId)
	{ 0x5054,  0x100,   0x80,    0x0,    0x4},	// USTORM_TOE_CQ_NEXT_PAGE_BASE_ADDR_HI_OFFSET(rssId,portId)
	{ 0x5058,  0x100,   0x80,    0x0,    0x4},	// USTORM_TOE_CQ_CONS_PTR_LO_OFFSET(rssId,portId)
	{ 0x505c,  0x100,   0x80,    0x0,    0x4},	// USTORM_TOE_CQ_CONS_PTR_HI_OFFSET(rssId,portId)
	{ 0x507c,  0x100,   0x80,    0x0,    0x1},	// USTORM_TOE_STATUS_BLOCK_ID_OFFSET(rssId,portId)
	{ 0x507d,  0x100,   0x80,    0x0,    0x1},	// USTORM_TOE_STATUS_BLOCK_INDEX_OFFSET(rssId,portId)
	{ 0x4018,   0x10,    0x0,    0x0,    0x4},	// USTORM_TOE_TCP_PUSH_TIMER_TICKS_OFFSET(pfId)
	{ 0x4090,   0x10,    0x0,    0x0,    0x4},	// USTORM_TOE_GRQ_XOFF_COUNTER_OFFSET(pfId)
	{ 0x4098,   0x10,    0x0,    0x0,    0x4},	// USTORM_TOE_RCQ_XOFF_COUNTER_OFFSET(pfId)
	{ 0x4110,    0x0,    0x0,    0x0,    0x2},	// USTORM_TOE_CQ_THR_LOW_OFFSET
	{ 0x4112,    0x0,    0x0,    0x0,    0x2},	// USTORM_TOE_GRQ_THR_LOW_OFFSET
	{ 0x4114,    0x0,    0x0,    0x0,    0x2},	// USTORM_TOE_CQ_THR_HIGH_OFFSET
	{ 0x4116,    0x0,    0x0,    0x0,    0x2},	// USTORM_TOE_GRQ_THR_HIGH_OFFSET
	{ 0x6040,    0x8,    0x0,    0x0,    0x2},	// TSTORM_ISCSI_TCP_VARS_FLAGS_OFFSET(pfId)
	{ 0x6042,    0x8,    0x0,    0x0,    0x2},	// TSTORM_ISCSI_TCP_VARS_LSB_LOCAL_MAC_ADDR_OFFSET(pfId)
	{ 0x6044,    0x8,    0x0,    0x0,    0x4},	// TSTORM_ISCSI_TCP_VARS_MSB_LOCAL_MAC_ADDR_OFFSET(pfId)
	{ 0x6080,    0x8,    0x0,    0x0,    0x8},	// TSTORM_ISCSI_RQ_SIZE_OFFSET(pfId)
	{ 0x60c0,   0x40,    0x8,    0x0,    0x8},	// TSTORM_ISCSI_CONN_BUF_PBL_OFFSET(pfId,iscsiConBufPblEntry)
	{ 0x6000,    0x8,    0x0,    0x0,    0x2},	// TSTORM_ISCSI_PAGE_SIZE_OFFSET(pfId)
	{ 0x6002,    0x8,    0x0,    0x0,    0x1},	// TSTORM_ISCSI_PAGE_SIZE_LOG_OFFSET(pfId)
	{ 0x6004,    0x8,    0x0,    0x0,    0x2},	// TSTORM_ISCSI_NUM_OF_TASKS_OFFSET(pfId)
	{ 0x6340,    0x8,    0x0,    0x0,    0x8},	// TSTORM_ISCSI_ERROR_BITMAP_OFFSET(pfId)
	{ 0x6380,    0x8,    0x0,    0x0,    0x4},	// TSTORM_ISCSI_L2_ISCSI_OOO_CID_TABLE_OFFSET(pfId)
	{ 0x6384,    0x8,    0x0,    0x0,    0x1},	// TSTORM_ISCSI_L2_ISCSI_OOO_CLIENT_ID_TABLE_OFFSET(pfId)
	{ 0x63c0,    0x8,    0x0,    0x0,    0x2},	// TSTORM_ISCSI_L2_ISCSI_OOO_PROD_OFFSET(pfId)
	{ 0x63c4,    0x8,    0x0,    0x0,    0x2},	// TSTORM_ISCSI_L2_ISCSI_OOO_RX_BDS_THRSHLD_OFFSET(pfId)
	{ 0x6400,    0x8,    0x0,    0x0,    0x4},	// TSTORM_ISCSI_TCP_LOCAL_ADV_WND_OFFSET(pfId)
	{ 0x9000,    0x8,    0x0,    0x0,    0x2},	// USTORM_ISCSI_PAGE_SIZE_OFFSET(pfId)
	{ 0x9002,    0x8,    0x0,    0x0,    0x1},	// USTORM_ISCSI_PAGE_SIZE_LOG_OFFSET(pfId)
	{ 0x9004,    0x8,    0x0,    0x0,    0x2},	// USTORM_ISCSI_NUM_OF_TASKS_OFFSET(pfId)
	{ 0x9040,    0x8,    0x0,    0x0,    0x2},	// USTORM_ISCSI_R2TQ_SIZE_OFFSET(pfId)
	{ 0x9044,    0x8,    0x0,    0x0,    0x2},	// USTORM_ISCSI_CQ_SIZE_OFFSET(pfId)
	{ 0x9046,    0x8,    0x0,    0x0,    0x2},	// USTORM_ISCSI_CQ_SQN_SIZE_OFFSET(pfId)
	{ 0x9648,    0x8,    0x0,    0x0,    0x8},	// USTORM_ISCSI_GLOBAL_BUF_PHYS_ADDR_OFFSET(pfId)
	{ 0x9080,    0x8,    0x0,    0x0,    0x2},	// USTORM_ISCSI_RQ_BUFFER_SIZE_OFFSET(pfId)
	{ 0x9084,    0x8,    0x0,    0x0,    0x2},	// USTORM_ISCSI_RQ_SIZE_OFFSET(pfId)
	{ 0x9688,    0x8,    0x0,    0x0,    0x8},	// USTORM_ISCSI_ERROR_BITMAP_OFFSET(pfId)
	{ 0x8040,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_TCP_VARS_TTL_OFFSET(pfId)
	{ 0x8041,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_TCP_VARS_TOS_OFFSET(pfId)
	{ 0x8042,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_TCP_VARS_FLAGS_OFFSET(pfId)
	{ 0x8043,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_TCP_VARS_ADV_WND_SCL_OFFSET(pfId)
	{ 0x8000,    0x8,    0x0,    0x0,    0x2},	// XSTORM_ISCSI_PAGE_SIZE_OFFSET(pfId)
	{ 0x8002,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_PAGE_SIZE_LOG_OFFSET(pfId)
	{ 0x8004,    0x8,    0x0,    0x0,    0x2},	// XSTORM_ISCSI_NUM_OF_TASKS_OFFSET(pfId)
	{ 0x80c0,    0x8,    0x0,    0x0,    0x2},	// XSTORM_ISCSI_HQ_SIZE_OFFSET(pfId)
	{ 0x80c2,    0x8,    0x0,    0x0,    0x2},	// XSTORM_ISCSI_SQ_SIZE_OFFSET(pfId)
	{ 0x80c4,    0x8,    0x0,    0x0,    0x2},	// XSTORM_ISCSI_R2TQ_SIZE_OFFSET(pfId)
	{ 0x8080,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_LOCAL_MAC_ADDR0_OFFSET(pfId)
	{ 0x8081,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_LOCAL_MAC_ADDR1_OFFSET(pfId)
	{ 0x8082,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_LOCAL_MAC_ADDR2_OFFSET(pfId)
	{ 0x8083,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_LOCAL_MAC_ADDR3_OFFSET(pfId)
	{ 0x8084,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_LOCAL_MAC_ADDR4_OFFSET(pfId)
	{ 0x8085,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_LOCAL_MAC_ADDR5_OFFSET(pfId)
	{ 0x8086,    0x8,    0x0,    0x0,    0x1},	// XSTORM_ISCSI_LOCAL_VLAN_OFFSET(pfId)
	{ 0x6000,    0x8,    0x0,    0x0,    0x2},	// CSTORM_ISCSI_PAGE_SIZE_OFFSET(pfId)
	{ 0x6002,    0x8,    0x0,    0x0,    0x1},	// CSTORM_ISCSI_PAGE_SIZE_LOG_OFFSET(pfId)
	{ 0x6004,    0x8,    0x0,    0x0,    0x2},	// CSTORM_ISCSI_NUM_OF_TASKS_OFFSET(pfId)
	{ 0x6042,   0xc0,   0x18,    0x0,    0x2},	// CSTORM_ISCSI_EQ_PROD_OFFSET(pfId,iscsiEqId)
	{ 0x6040,   0xc0,   0x18,    0x0,    0x2},	// CSTORM_ISCSI_EQ_CONS_OFFSET(pfId,iscsiEqId)
	{ 0x604c,   0xc0,   0x18,    0x0,    0x8},	// CSTORM_ISCSI_EQ_NEXT_PAGE_ADDR_OFFSET(pfId,iscsiEqId)
	{ 0x6044,   0xc0,   0x18,    0x0,    0x8},	// CSTORM_ISCSI_EQ_NEXT_EQE_ADDR_OFFSET(pfId,iscsiEqId)
	{ 0x6057,   0xc0,   0x18,    0x0,    0x1},	// CSTORM_ISCSI_EQ_NEXT_PAGE_ADDR_VALID_OFFSET(pfId,iscsiEqId)
	{ 0x6054,   0xc0,   0x18,    0x0,    0x2},	// CSTORM_ISCSI_EQ_SB_NUM_OFFSET(pfId,iscsiEqId)
	{ 0x6056,   0xc0,   0x18,    0x0,    0x1},	// CSTORM_ISCSI_EQ_SB_INDEX_OFFSET(pfId,iscsiEqId)
	{ 0x6640,    0x8,    0x0,    0x0,    0x8},	// CSTORM_ISCSI_HQ_SIZE_OFFSET(pfId)
	{ 0x6680,    0x8,    0x0,    0x0,    0x8},	// CSTORM_ISCSI_CQ_SIZE_OFFSET(pfId)
	{ 0x66c0,    0x8,    0x0,    0x0,    0x8},	// CSTORM_ISCSI_CQ_SQN_SIZE_OFFSET(pfId)
	{ 0xda42,   0x18,    0x0,    0x0,    0x2},	// USTORM_FCOE_EQ_PROD_OFFSET(pfId)
	{ 0xde40,    0x0,    0x0,    0x0,    0x0},	// USTORM_FCOE_TIMER_PARAM_OFFSET
	{ 0xe000,    0x0,    0x0,    0x0,    0x4},	// USTORM_TIMER_ARRAY_OFFSET
	{ 0xd0c0,    0x0,    0x0,    0x0,    0x4},	// USTORM_STAT_FC_CRC_CNT_OFFSET
	{ 0xd0c4,    0x0,    0x0,    0x0,    0x4},	// USTORM_STAT_EOFA_DEL_CNT_OFFSET
	{ 0xd0c8,    0x0,    0x0,    0x0,    0x4},	// USTORM_STAT_MISS_FRAME_CNT_OFFSET
	{ 0xd0cc,    0x0,    0x0,    0x0,    0x4},	// USTORM_STAT_SEQ_TIMEOUT_CNT_OFFSET
	{ 0xd0d0,    0x0,    0x0,    0x0,    0x4},	// USTORM_STAT_DROP_SEQ_CNT_OFFSET
	{ 0xd0d4,    0x0,    0x0,    0x0,    0x4},	// USTORM_STAT_FCOE_RX_DROP_PKT_CNT_OFFSET
	{ 0xd0d8,    0x0,    0x0,    0x0,    0x4},	// USTORM_STAT_FCP_RX_PKT_CNT_OFFSET
	{ 0xd0c0,    0x0,    0x0,    0x0,   0x20},	// USTORM_STAT_OFFSET
	{ 0xdb00,    0x0,    0x0,    0x0,    0x4},	// USTORM_DEBUG_DROP_PKT_CNT_OFFSET
	{ 0xdb00,    0x0,    0x0,    0x0,   0x68},	// USTORM_DEBUG_OFFSET
	{ 0xb948,    0x0,    0x0,    0x0,    0x0},	// XSTORM_FCOE_TIMER_PARAM_OFFSET
	{ 0xd000,    0x0,    0x0,    0x0,    0x4},	// XSTORM_TIMER_ARRAY_OFFSET
	{ 0xb0c0,    0x0,    0x0,    0x0,    0x4},	// XSTORM_STAT_FCOE_TX_PKT_CNT_OFFSET
	{ 0xb0c4,    0x0,    0x0,    0x0,    0x4},	// XSTORM_STAT_FCOE_TX_BYTE_CNT_OFFSET
	{ 0xb0c8,    0x0,    0x0,    0x0,    0x4},	// XSTORM_STAT_FCP_TX_PKT_CNT_OFFSET
	{ 0xb0c0,    0x0,    0x0,    0x0,   0x10},	// XSTORM_STAT_OFFSET
	{ 0xd6b0,    0x0,    0x0,    0x0,    0x4},	// TSTORM_STAT_FCOE_VER_CNT_OFFSET
	{ 0xd6b4,    0x0,    0x0,    0x0,    0x4},	// TSTORM_STAT_FCOE_RX_PKT_CNT_OFFSET
	{ 0xd6b8,    0x0,    0x0,    0x0,    0x4},	// TSTORM_STAT_FCOE_RX_BYTE_CNT_OFFSET
	{ 0xd6bc,    0x0,    0x0,    0x0,    0x4},	// TSTORM_STAT_FCOE_RX_DROP_PKT_CNT_OFFSET
	{ 0xd6b0,    0x0,    0x0,    0x0,   0x10},	// TSTORM_STAT_OFFSET
	{ 0xd348,    0x0,    0x0,    0x0,    0x8},	// TSTORM_REORDER_DATA_OFFSET
	{ 0xd358,    0x0,    0x0,    0x0,   0x80},	// TSTORM_REORDER_WAITING_TABLE_OFFSET
	{   0x10,    0x0,    0x0,    0x0,    0x0},	// TSTORM_WAITING_LIST_SIZE
	{ 0xd358,    0x0,    0x0,    0x0,    0x8},	// TSTORM_REORDER_WAITING_ENTRY_OFFSET
};