#ifndef STEAM_PEER_CONFIG
#define STEAM_PEER_CONFIG

#include "steam/steam_api.h"
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;

class SteamPeerConfig : public RefCounted {
	GDCLASS(SteamPeerConfig, RefCounted)

private:
	Dictionary options;
	SteamNetworkingConfigValue_t *option_array;

public:
	// Networking Sockets enums
	enum SteamNetworkingConfig {
		NETWORKING_CONFIG_INVALID = k_ESteamNetworkingConfig_Invalid,
		NETWORKING_CONFIG_FAKE_PACKET_LOSS_SEND = k_ESteamNetworkingConfig_FakePacketLoss_Send,
		NETWORKING_CONFIG_FAKE_PACKET_LOSS_RECV = k_ESteamNetworkingConfig_FakePacketLoss_Recv,
		NETWORKING_CONFIG_FAKE_PACKET_LAG_SEND = k_ESteamNetworkingConfig_FakePacketLag_Send,
		NETWORKING_CONFIG_FAKE_PACKET_LAG_RECV = k_ESteamNetworkingConfig_FakePacketLag_Recv,
		NETWORKING_CONFIG_FAKE_PACKET_REORDER_SEND = k_ESteamNetworkingConfig_FakePacketReorder_Send,
		NETWORKING_CONFIG_FAKE_PACKET_REORDER_RECV = k_ESteamNetworkingConfig_FakePacketReorder_Recv,
		NETWORKING_CONFIG_FAKE_PACKET_REORDER_TIME = k_ESteamNetworkingConfig_FakePacketReorder_Time,
		NETWORKING_CONFIG_FAKE_PACKET_DUP_SEND = k_ESteamNetworkingConfig_FakePacketDup_Send,
		NETWORKING_CONFIG_FAKE_PACKET_DUP_REVC = k_ESteamNetworkingConfig_FakePacketDup_Recv,
		NETWORKING_CONFIG_FAKE_PACKET_DUP_TIME_MAX = k_ESteamNetworkingConfig_FakePacketDup_TimeMax,
		NETWORKING_CONFIG_PACKET_TRACE_MAX_BYTES = k_ESteamNetworkingConfig_PacketTraceMaxBytes,
		NETWORKING_CONFIG_FAKE_RATE_LIMIT_SEND_RATE = k_ESteamNetworkingConfig_FakeRateLimit_Send_Rate,
		NETWORKING_CONFIG_FAKE_RATE_LIMIT_SEND_BURST = k_ESteamNetworkingConfig_FakeRateLimit_Send_Burst,
		NETWORKING_CONFIG_FAKE_RATE_LIMIT_RECV_RATE = k_ESteamNetworkingConfig_FakeRateLimit_Recv_Rate,
		NETWORKING_CONFIG_FAKE_RATE_LIMIT_RECV_BURST = k_ESteamNetworkingConfig_FakeRateLimit_Recv_Burst,
		NETWORKING_CONFIG_OUT_OF_ORDER_CORRECTION_WINDOW_MICROSECONDS = k_ESteamNetworkingConfig_OutOfOrderCorrectionWindowMicroseconds,
		NETWORKING_CONFIG_CONNECTION_USER_DATA = k_ESteamNetworkingConfig_ConnectionUserData,
		NETWORKING_CONFIG_TIMEOUT_INITIAL = k_ESteamNetworkingConfig_TimeoutInitial,
		NETWORKING_CONFIG_TIMEOUT_CONNECTED = k_ESteamNetworkingConfig_TimeoutConnected,
		NETWORKING_CONFIG_SEND_BUFFER_SIZE = k_ESteamNetworkingConfig_SendBufferSize,
		NETWORKING_CONFIG_RECV_BUFFER_SIZE = k_ESteamNetworkingConfig_RecvBufferSize,
		NETWORKING_CONFIG_RECV_BUFFER_MESSAGES = k_ESteamNetworkingConfig_RecvBufferMessages,
		NETWORKING_CONFIG_RECV_MAX_MESSAGE_SIZE = k_ESteamNetworkingConfig_RecvMaxMessageSize,
		NETWORKING_CONFIG_RECV_MAX_SEGMENTS_PER_PACKET = k_ESteamNetworkingConfig_RecvMaxSegmentsPerPacket,
		NETWORKING_CONFIG_SEND_RATE_MIN = k_ESteamNetworkingConfig_SendRateMin,
		NETWORKING_CONFIG_SEND_RATE_MAX = k_ESteamNetworkingConfig_SendRateMax,
		NETWORKING_CONFIG_NAGLE_TIME = k_ESteamNetworkingConfig_NagleTime,
		NETWORKING_CONFIG_IP_ALLOW_WITHOUT_AUTH = k_ESteamNetworkingConfig_IP_AllowWithoutAuth,
		NETWORKING_CONFIG_IP_LOCAL_HOST_ALLOW_WITHOUT_AUTH = k_ESteamNetworkingConfig_IPLocalHost_AllowWithoutAuth,
		NETWORKING_CONFIG_MTU_PACKET_SIZE = k_ESteamNetworkingConfig_MTU_PacketSize,
		NETWORKING_CONFIG_MTU_DATA_SIZE = k_ESteamNetworkingConfig_MTU_DataSize,
		NETWORKING_CONFIG_UNENCRYPTED = k_ESteamNetworkingConfig_Unencrypted,
		NETWORKING_CONFIG_SYMMETRIC_CONNECT = k_ESteamNetworkingConfig_SymmetricConnect,
		NETWORKING_CONFIG_LOCAL_VIRTUAL_PORT = k_ESteamNetworkingConfig_LocalVirtualPort,
		NETWORKING_CONFIG_DUAL_WIFI_ENABLE = k_ESteamNetworkingConfig_DualWifi_Enable,
		NETWORKING_CONFIG_ENABLE_DIAGNOSTICS_UI = k_ESteamNetworkingConfig_EnableDiagnosticsUI,
		NETWORKING_CONFIG_SDR_CLIENT_CONSEC_PING_TIMEOUT_FAIL_INITIAL = k_ESteamNetworkingConfig_SDRClient_ConsecutitivePingTimeoutsFailInitial,
		NETWORKING_CONFIG_SDR_CLIENT_CONSEC_PING_TIMEOUT_FAIL = k_ESteamNetworkingConfig_SDRClient_ConsecutitivePingTimeoutsFail,
		NETWORKING_CONFIG_SDR_CLIENT_MIN_PINGS_BEFORE_PING_ACCURATE = k_ESteamNetworkingConfig_SDRClient_MinPingsBeforePingAccurate,
		NETWORKING_CONFIG_SDR_CLIENT_SINGLE_SOCKET = k_ESteamNetworkingConfig_SDRClient_SingleSocket,
		NETWORKING_CONFIG_SDR_CLIENT_FORCE_RELAY_CLUSTER = k_ESteamNetworkingConfig_SDRClient_ForceRelayCluster,
		NETWORKING_CONFIG_SDR_CLIENT_DEV_TICKET = k_ESteamNetworkingConfig_SDRClient_DevTicket,
		NETWORKING_CONFIG_SDR_CLIENT_FORCE_PROXY_ADDR = k_ESteamNetworkingConfig_SDRClient_ForceProxyAddr,
		NETWORKING_CONFIG_SDR_CLIENT_FAKE_CLUSTER_PING = k_ESteamNetworkingConfig_SDRClient_FakeClusterPing,
		NETWORKING_CONFIG_SDR_CLIENT_LIMIT_PING_PROBES_TO_NEAREST_N = k_ESteamNetworkingConfig_SDRClient_LimitPingProbesToNearestN,
		NETWORKING_CONFIG_LOG_LEVEL_ACK_RTT = k_ESteamNetworkingConfig_LogLevel_AckRTT,
		NETWORKING_CONFIG_LOG_LEVEL_PACKET_DECODE = k_ESteamNetworkingConfig_LogLevel_PacketDecode,
		NETWORKING_CONFIG_LOG_LEVEL_MESSAGE = k_ESteamNetworkingConfig_LogLevel_Message,
		NETWORKING_CONFIG_LOG_LEVEL_PACKET_GAPS = k_ESteamNetworkingConfig_LogLevel_PacketGaps,
		NETWORKING_CONFIG_LOG_LEVEL_P2P_RENDEZVOUS = k_ESteamNetworkingConfig_LogLevel_P2PRendezvous,
		NETWORKING_CONFIG_LOG_LEVEL_SRD_RELAY_PINGS = k_ESteamNetworkingConfig_LogLevel_SDRRelayPings,
		NETWORKING_CONFIG_CALLBACK_CONNECTION_STATUS_CHANGED = k_ESteamNetworkingConfig_Callback_ConnectionStatusChanged,
		NETWORKING_CONFIG_CALLBACK_AUTH_STATUS_CHANGED = k_ESteamNetworkingConfig_Callback_AuthStatusChanged,
		NETWORKING_CONFIG_CALLBACK_RELAY_NETWORK_STATUS_CHANGED = k_ESteamNetworkingConfig_Callback_RelayNetworkStatusChanged,
		NETWORKING_CONFIG_CALLBACK_MESSAGE_SESSION_REQUEST = k_ESteamNetworkingConfig_Callback_MessagesSessionRequest,
		NETWORKING_CONFIG_CALLBACK_MESSAGES_SESSION_FAILED = k_ESteamNetworkingConfig_Callback_MessagesSessionFailed,
		NETWORKING_CONFIG_CALLBACK_CREATE_CONNECTION_SIGNALING = k_ESteamNetworkingConfig_Callback_CreateConnectionSignaling,
		NETWORKING_CONFIG_CALLBACK_FAKE_IP_RESULT = k_ESteamNetworkingConfig_Callback_FakeIPResult,
		NETWORKING_CONFIG_P2P_STUN_SERVER_LIST = k_ESteamNetworkingConfig_P2P_STUN_ServerList,
		NETWORKING_CONFIG_P2P_TRANSPORT_ICE_ENABLE = k_ESteamNetworkingConfig_P2P_Transport_ICE_Enable,
		NETWORKING_CONFIG_P2P_TRANSPORT_ICE_PENALTY = k_ESteamNetworkingConfig_P2P_Transport_ICE_Penalty,
		NETWORKING_CONFIG_P2P_TRANSPORT_SDR_PENALTY = k_ESteamNetworkingConfig_P2P_Transport_SDR_Penalty,
		NETWORKING_CONFIG_P2P_TURN_SERVER_LIST = k_ESteamNetworkingConfig_P2P_TURN_ServerList,
		NETWORKING_CONFIG_P2P_TURN_USER_LIST = k_ESteamNetworkingConfig_P2P_TURN_UserList,
		NETWORKING_CONFIG_P2P_TURN_PASS_LIST = k_ESteamNetworkingConfig_P2P_TURN_PassList,
		//			NETWORKING_CONFIG_P2P_TRANSPORT_LAN_BEACON_PENALTY = k_ESteamNetworkingConfig_P2P_Transport_LANBeacon_Penalty,
		NETWORKING_CONFIG_P2P_TRANSPORT_ICE_IMPLEMENTATION = k_ESteamNetworkingConfig_P2P_Transport_ICE_Implementation,
		NETWORKING_CONFIG_ECN = k_ESteamNetworkingConfig_ECN,
		NETWORKING_CONFIG_VALUE_FORCE32BIT = k_ESteamNetworkingConfigValue__Force32Bit
	};
	SteamPeerConfig() {}
	Dictionary get_options() const;
	int size() const;
	SteamNetworkingConfigValue_t *get_convert_options() const;
	void set_options(const Dictionary new_options);
	void set_config(const SteamNetworkingConfig config, Variant value);
	void clear_config(const SteamNetworkingConfig config);
	void clear_all_configs();

protected:
	static void _bind_methods();
};

VARIANT_ENUM_CAST(SteamPeerConfig::SteamNetworkingConfig);

#endif // STEAM_PEER_CONFIG