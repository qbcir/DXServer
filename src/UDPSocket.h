#ifndef __dx_UDPSOCKET_H__
#define __dx_UDPSOCKET_H__

#include "asio.hpp"
#include "Packet.h"
#include "utils/WeightedTimedMovingAverage.h"

class GameServer;
class UDPSocket {
public:
    UDPSocket(asio::io_service& io, unsigned short port, bool& stopFlag);
    void run();
    void send(const bytes_t& buf, const asio::ip::udp::endpoint& endpoint);
protected:
    void do_resolve();
    void do_receive();
    bool& m_stopFlag;
    asio::io_service& m_io;
    asio::ip::udp::endpoint m_endpoint;
    asio::ip::udp::socket m_socket;
    std::vector<uint8_t> m_buf;
    GameServer* m_networkManager = nullptr;
    //
    WeightedTimedMovingAverage m_nbytesReceivedPerSec;
    WeightedTimedMovingAverage m_nbytesSentPerSec;
};

#endif /* __dx_UDPSOCKET_H__ */
