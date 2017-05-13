#include "UDPSocket.h"
#include "GameServer.h"
#include <iostream>

UDPSocket::UDPSocket(asio::io_service& io,
    unsigned short port,
    bool& stopFlag) :
    m_io(io),
    m_endpoint(asio::ip::udp::v4(), port),
    m_socket(m_io, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)),
    m_buf(4096),
    m_stopFlag(stopFlag)
{
    m_networkManager = GameServer::getInstance();
    do_receive();
}

void UDPSocket::run() {
    m_io.run();
}

void UDPSocket::do_receive() {
    if (m_stopFlag) {
        return;
    }
    m_socket.async_receive_from(
        asio::buffer(m_buf.data(), m_buf.size()), m_endpoint,
        [this](std::error_code ec, std::size_t length) {
            if (ec) {
                std::cerr << __func__ << " error:" << ec.message() << std::endl;
            } else {
                //std::cerr << "received packet from "
                //          << m_endpoint.address().to_string() << " nbytes=" << length << std::endl;
                auto packet = Packet(m_buf.data(), length, m_endpoint);
                m_networkManager->pushPacket(packet);
            }
            do_receive();
        }
    );
}

void UDPSocket::send(
        const bytes_t& buf,
        const asio::ip::udp::endpoint& endpoint) {
    m_socket.async_send_to(
        asio::buffer(buf.data(), buf.size()), endpoint,
        [this](std::error_code ec, std::size_t nbytes) {
            if (ec) {
                std::cerr << __func__ << " error!" << std::endl;
            } else {
                //std::cerr << __func__ << " sent " << nbytes << " bytes" << std::endl;
            }
        }
    );
}
