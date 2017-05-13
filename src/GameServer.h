#ifndef __DX_GAMESERVER_H__
#define __DX_GAMESERVER_H__

#include "asio.hpp"
#include "NetTypes.h"
#include "objects/GameObject.h"
#include "objects/PlayerObject.h"
#include "ClientProxy.h"
#include "UDPSocket.h"
#include "utils/WeightedTimedMovingAverage.h"
#include "Scene.h"

#include "scripting/LuaState.h"
#include "utils/FileUtils.h"
#include "objects/ObjectManager.h"

#include <unordered_map>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <functional>

typedef asio::ip::udp::endpoint endpoint_t;
struct endpoint_hash {
    size_t operator()(const endpoint_t &e) const {
        size_t res = 17;
        res = res * 31 + m_ipHash(e.address().to_string());
        res = res * 31 + m_portHash(e.port());
        return res;
    }
    std::hash<std::string> m_ipHash;
    std::hash<unsigned short> m_portHash;
};

typedef std::function<PlayerObjectPtr()> OnNewClientCbT;

class GameServer {
public:
    static GameServer* getInstance();
    static void releaseInstance();
    static float getTimestamp();
    FileUtils* getFileUtils();
    LuaState* getLuaState();
    ObjectManager* getObjectManager();
    //
    void setOnNewClientCb(const OnNewClientCbT& cb);
    ScenePtr getScene();
    //
    void start();
    void run();
    void pushPacket(const Packet& packet);
    bool popPacket(Packet& packet);
    GameObjectPtr getGameObject(net_id_t netId);
    void addGameObject(const GameObjectPtr& obj);
    void removeGameObject(const GameObjectPtr& obj);
    void registerGameObject(GameObjectPtr obj);
    void unregisterGameObject(GameObjectPtr& obj);
    ClientProxyPtr getClientProxy(player_id_t pid) const;
    void setStateDirty(net_id_t netId, state_mask_t dirtyState);
    void sendOutgoingPackets();
    void checkForDisconnects();
    void processPacket(uint8_t* &p, const endpoint_t& remoteAddr);
    void sendPacket(const bytes_t& buf, const endpoint_t& remoteAddr);
private:
    GameServer();
    void updateTimestamp();
    //
    net_id_t getNextNetId();
    void processPacket(ClientProxyPtr client, uint8_t* &p);
    void onInputPacket(ClientProxyPtr client, uint8_t* &p);
    void onConnectionReset(const endpoint_t& remoteAddr);
    void onNewClient(uint8_t* &p, const endpoint_t& remoteAddr);
    void sendWelcomePacket(ClientProxyPtr client);
    void sendStatePacket(ClientProxyPtr client);
    void processQueuedPackets();
    void onClientDisconnect(ClientProxyPtr& client);
    void updateAllClients();
    void writeLastInputTimestampIfDirty(bytes_t& buf, ClientProxyPtr client);
    //
    static bool m_released;
    static GameServer* m_instance;
    float m_delta;
    float m_lastTimesmap;
    static std::chrono::high_resolution_clock::time_point m_startTime;
    std::unordered_map<net_id_t, GameObjectPtr> m_netId2GameObjectMap;
    std::unordered_map<player_id_t, ClientProxyPtr> m_playerId2ClientMap;
    std::unordered_map<endpoint_t, ClientProxyPtr, endpoint_hash> m_address2ClientMap;
    short m_localPort = 33333;
    std::unique_ptr<UDPSocket> m_socket;
    bool m_stopNetThread = false;
    asio::io_service m_io;
    std::thread m_netThread;
    std::mutex m_mutex;
    std::queue<Packet> m_packets;
    size_t m_maxPacketsPerFrame = 16;
    WeightedTimedMovingAverage m_bytesReceivedPerSec;
    WeightedTimedMovingAverage m_bytesSentPerSec;
    size_t m_bytesSentThisFrame;
    //
    net_id_t m_currNetId = 0;
    player_id_t m_currPlayerId = 0;
    //
    LuaState m_luaState;
    FileUtils m_fileUtils;
    ObjectManager m_objectManager;
    //
    ScenePtr m_scene;
    //
    OnNewClientCbT m_onNewClientCb;
};

#endif /* __DX_GAMESERVER_H__ */
