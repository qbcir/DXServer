#ifndef __danmakuxnet_NETWORKMANAGERSERVER_H__
#define __danmakuxnet_NETWORKMANAGERSERVER_H__

#include "ClientProxy.h"
#include <unordered_map>

class EndpointHasher {
public:
    size_t operator() (const asio::ip::udp::endpoint& e) const {
        size_t h = 17;
        h = h * 31 + m_addrH(e.address().to_string());
        h = h * 31 + m_portH(e.port());
        return h;
    }
private:
    std::hash<std::string> m_addrH;
    std::hash<short> m_portH;
};

class GameServerServer {
public:
    GameServerServer();
private:
    std::unordered_map<int, ClientProxyPtr> m_id2ClientMap;
    std::unordered_map<asio::ip::udp::endpoint,
        ClientProxyPtr, EndpointHasher> m_addr2ClientMap;
};

#endif // __danmakuxnet_NETWORKMANAGERSERVER_H__
