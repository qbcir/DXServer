#ifndef __dx_CLIENTPROXY_H__
#define __dx_CLIENTPROXY_H__

#include "asio.hpp"
#include "DeliveryNotifier.h"
#include "ReplicationManager.h"
#include "InputPacketList.h"
#include "scripting/LuaRef.h"
#include <memory>

class ClientProxy : public LuaRef {
public:
    ClientProxy(const asio::ip::udp::endpoint& endpoint,
            player_id_t playerId);
    InputPacketList& getInputPacketList();
    DeliveryNotifier& getDeliveryNotifier();
    ReplicationManager& getReplicationManager();
    void updateLastPacketTimestamp();
    void setIsLastInputTimestampDirty(bool v);
    bool isLastInputTimestampDirty() const;
    player_id_t getPlayerId() const;
    const asio::ip::udp::endpoint& getAddress() const;
    //Replication
    void replicateCreate(net_id_t netId, state_mask_t initDirtyState);
    void replicateDestroy(net_id_t netId);
    void addDirtyState(net_id_t netId, state_mask_t dirtyState);
    void handleCreateAckd(net_id_t netId);
    void removeFromReplication(net_id_t netId);
protected:
    asio::ip::udp::endpoint m_endpoint;
    player_id_t m_playerId;
    float m_lastClientPacketTimestamp;
    bool m_isLastInputTimestampDirty;
    //
    InputPacketList m_unprocessedInputPackets;
    DeliveryNotifier m_delNotMgr;
    ReplicationManager m_repMgr;
};
typedef std::shared_ptr<ClientProxy> ClientProxyPtr;

#endif /* __dx_CLIENTPROXY_H__ */
