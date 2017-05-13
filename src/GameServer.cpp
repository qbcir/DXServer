#include "GameServer.h"
#include "Packet.h"
#include "objects/PlayerObject.h"
#include <iostream>

GameServer::GameServer()
{}

bool GameServer::m_released = false;
GameServer* GameServer::m_instance = nullptr;
std::chrono::high_resolution_clock::time_point GameServer::m_startTime;

float GameServer::getTimestamp() {
    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> ts = now - m_startTime;
    return ts.count();
}

void GameServer::updateTimestamp() {
    float currTimestamp = getTimestamp();
    m_delta = currTimestamp - m_lastTimesmap;
    m_lastTimesmap = currTimestamp;
}

GameServer* GameServer::getInstance() {
    if (!m_instance) {
        m_instance = new GameServer();
    }
    return m_instance;
}

void GameServer::releaseInstance() {
    if (m_instance) {
        delete m_instance;
    }
    m_released = true;
}

FileUtils* GameServer::getFileUtils() {
    return &m_fileUtils;
}

LuaState* GameServer::getLuaState() {
    return &m_luaState;
}

ObjectManager* GameServer::getObjectManager() {
    return &m_objectManager;
}

ScenePtr GameServer::getScene() {
    return m_scene;
}

void GameServer::pushPacket(const Packet& packet) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_packets.push(packet);
}

bool GameServer::popPacket(Packet& packet) {
    std::unique_lock<std::mutex> lock(m_mutex);
    if (m_packets.empty()) {
        return false;
    }
    packet = m_packets.front();
    m_packets.pop();
    return true;
}

GameObjectPtr GameServer::getGameObject(net_id_t netId) {
    auto it = m_netId2GameObjectMap.find(netId);
    if (it == std::end(m_netId2GameObjectMap)) {
        return nullptr;
    }
    return it->second;
}

void GameServer::addGameObject(const GameObjectPtr& obj) {
    m_netId2GameObjectMap[obj->getNetId()] = obj;
}

void GameServer::removeGameObject(const GameObjectPtr& obj) {
    m_netId2GameObjectMap.erase(obj->getNetId());
}

net_id_t GameServer::getNextNetId() {
    net_id_t res = m_currNetId++;
    if (m_currNetId < res) {
        std::cerr << "Impossiburu!" << std::endl;
    }
    return res;
}

void GameServer::registerGameObject(GameObjectPtr obj) {
    net_id_t netId = getNextNetId();
    obj->setNetId(netId);
    addGameObject(obj);
    for (const auto&p : m_address2ClientMap) {
        ReplicationManager& rm = p.second->getReplicationManager();
        rm.replicateCreate(netId, obj->getFullStateMask());
    }
}

void GameServer::unregisterGameObject(GameObjectPtr &obj) {
    auto netId = obj->getNetId();
    removeGameObject(obj);
    for (const auto& p : m_address2ClientMap) {
        ReplicationManager& rm = p.second->getReplicationManager();
        rm.replicateDestroy(netId);
    }
}

ClientProxyPtr GameServer::getClientProxy(player_id_t pid) const {
    auto it = m_playerId2ClientMap.find(pid);
    return it != std::end(m_playerId2ClientMap) ? it->second : nullptr;
}

void GameServer::setStateDirty(
        net_id_t netId,
        state_mask_t dirtyState) {
    for(const auto& p: m_address2ClientMap) {
        p.second->addDirtyState(netId, dirtyState);
    }
}

void GameServer::onConnectionReset(const endpoint_t& remoteAddr) {
    //just dc the client right away...
    auto it = m_address2ClientMap.find(remoteAddr);
    if (it != std::end(m_address2ClientMap)) {
        onClientDisconnect(it->second);
    }
}

void GameServer::onClientDisconnect(ClientProxyPtr& client) {
    m_playerId2ClientMap.erase(client->getPlayerId());
    m_address2ClientMap.erase(client->getAddress());
    // handle lost client
}

void GameServer::processQueuedPackets() {
    size_t np = 0;
    Packet packet;
    while (np < 100) {
        if (!popPacket(packet)) {
            break;
        }
        auto datap = packet.getDataPtr();
        processPacket(datap, packet.getEndpoint());
    }
}

void GameServer::checkForDisconnects() {
    std::vector<ClientProxyPtr> clientsToDC;
    for (const auto& p : m_address2ClientMap) {

    }
    //float m
    for (auto& client : clientsToDC) {
        onClientDisconnect(client);
    }
}

void GameServer::sendOutgoingPackets() {
    auto end_it = std::end(m_address2ClientMap);
    for (auto it = std::begin(m_address2ClientMap); it != end_it; ++it) {
        ClientProxyPtr& client = it->second;
        DeliveryNotifier& dnm = client->getDeliveryNotifier();
        dnm.processTimedOutPackets();
        if (client->isLastInputTimestampDirty()) {
            sendStatePacket(client);
        }
    }
}

void GameServer::start() {
    m_scene = Scene::create();
    m_fileUtils.init();
    m_fileUtils.addSearchPath("lua/", false);
    m_luaState.init();
    m_luaState.executeScriptFile("lua/global.lua");
    m_luaState.executeScriptFile("lua/level.lua");
    m_startTime = std::chrono::high_resolution_clock::now();
    m_lastTimesmap = getTimestamp();
    auto sock = new UDPSocket(m_io, 33333, m_stopNetThread);
    m_socket = std::unique_ptr<UDPSocket>(sock);
    m_netThread = std::thread(&UDPSocket::run, sock);
    m_netThread.detach();
    run();
}

void GameServer::run() {
    while (true) {
        updateTimestamp();
        processQueuedPackets();
        checkForDisconnects();
        m_scene->update(1.f/256.f);
        sendOutgoingPackets();
        float delta;
        do {
            delta = getTimestamp() - m_lastTimesmap;
        } while (delta < 1.f/256.f);
    }
}

void GameServer::processPacket(
        uint8_t* &p,
        const endpoint_t& remoteAddr) {
    auto it = m_address2ClientMap.find(remoteAddr);
    if (it == std::end(m_address2ClientMap)) {
        onNewClient(p, remoteAddr);
    } else {
        processPacket(it->second, p);
    }
}

void GameServer::processPacket(
        ClientProxyPtr client,
        uint8_t* &p) {
    client->updateLastPacketTimestamp();
    auto packetType = dx_read_bytes<PacketType>(p);
    std::cout << "received packet type=" << int(packetType) << std::endl;
    switch (packetType) {
    case PacketType::HELLO:
        sendWelcomePacket(client);
        break;
    case PacketType::INPUT: {
        DeliveryNotifier& dnm = client->getDeliveryNotifier();
        if (dnm.readAndProcessState(p)) {
            onInputPacket(client, p);
        }
        break;
    }
    default:
        std::cerr << "Unknown packet type" << std::endl;
        break;
    }
}

void GameServer::onNewClient(
        uint8_t *&p,
        const endpoint_t& remoteAddr) {
    auto packetType = dx_read_bytes<PacketType>(p);
    if (packetType != PacketType::HELLO) {
        std::cerr << "Bad packet: " << packet_t(packetType) << std::endl;
        return;
    }
    auto playerId = m_currPlayerId++;
    ClientProxyPtr newClient = std::make_shared<ClientProxy>(remoteAddr, playerId);
    PlayerObjectPtr playerObj = m_onNewClientCb();
    if (!playerObj) {
        std::cerr << "Error creating player!" << std::endl;
        return;
    } else {
        std::cerr << "Create Player" << std::endl;
    }
    playerObj->setClient(newClient);
    playerObj->setPosition(b2Vec2 { 200.f,200.f});
    m_scene->addGameObject(playerObj);
    registerGameObject(playerObj);
    m_address2ClientMap[remoteAddr] = newClient;
    m_playerId2ClientMap[playerId] = newClient;
    sendWelcomePacket(newClient);
    ReplicationManager& rm = newClient->getReplicationManager();
    for (const auto& p : m_netId2GameObjectMap) {
        auto& go = p.second;
        rm.replicateCreate(go->getNetId(), go->getFullStateMask());
    }
    sendStatePacket(newClient);
}

void GameServer::sendWelcomePacket(ClientProxyPtr client) {
    bytes_t buf;
    dx_write_bytes<PacketType>(buf, PacketType::WELCOME);
    dx_write_bytes<player_id_t>(buf, 0); // clientID;
    sendPacket(buf, client->getAddress());
}

void GameServer::updateAllClients() {
    auto end_it = std::end(m_address2ClientMap);
    for (auto it = std::begin(m_address2ClientMap); it != end_it; ++it) {
        DeliveryNotifier& dnm = it->second->getDeliveryNotifier();
        dnm.processTimedOutPackets();
        sendStatePacket(it->second);
    }
}

void GameServer::sendStatePacket(ClientProxyPtr client) {
    bytes_t buf;
    dx_write_bytes<PacketType>(buf, PacketType::STATE);
    DeliveryNotifier& dnm = client->getDeliveryNotifier();
    ReplicationManager& rm = client->getReplicationManager();
    InFlightPacket* ifp = dnm.writeState(buf);
    writeLastInputTimestampIfDirty(buf, client);
    auto rmtd = new ReplicationManagerTransmissionData(&rm);
    rm.writeData(buf, rmtd);
    ifp->setTransmissionData('RPLM', TransmissionDataPtr(rmtd));
    sendPacket(buf, client->getAddress());
}

void GameServer::writeLastInputTimestampIfDirty(
        bytes_t& buf, ClientProxyPtr client) {
    bool isTimestampDirty = client->isLastInputTimestampDirty();
    dx_write_bytes<bool>(buf, isTimestampDirty);
    if (isTimestampDirty) {
        InputPacketList& uipl = client->getInputPacketList();
        std::cout << "send last processed " << uipl.getLastInputTimestamp() << std::endl;
        dx_write_bytes<float>(buf, uipl.getLastInputTimestamp());
        client->setIsLastInputTimestampDirty(false);
    }
}

void GameServer::onInputPacket(ClientProxyPtr client, uint8_t* &p) {
    auto moveCnt = dx_read_bytes<size_t>(p);
    std::cout << "moveCount: " << moveCnt << std::endl;
    InputPacketList& uipl = client->getInputPacketList();
    std::cout << "receiving " << getTimestamp() << std::endl;
    for (; moveCnt > 0; --moveCnt) {
        auto ip = dx_read_bytes<InputPacket>(p);
        std::cout << " received " << ip.timestamp
                  << " dt=" << ip.delta << std::endl;
        if (uipl.add(ip)) {
            client->setIsLastInputTimestampDirty(true);
        }
    }
}

void GameServer::sendPacket(
        const bytes_t& buf,
        const endpoint_t& remoteAddr) {
    m_socket->send(buf, remoteAddr);
}

void GameServer::setOnNewClientCb(const OnNewClientCbT& cb) {
    m_onNewClientCb = cb;
}
