#include "ClientProxy.h"
#include "GameServer.h"

ClientProxy::ClientProxy(const asio::ip::udp::endpoint &endpoint,
        player_id_t playerId) :
    m_endpoint(endpoint),
    m_playerId(playerId),
    m_isLastInputTimestampDirty(false),
    m_delNotMgr(false, true)
{}

InputPacketList& ClientProxy::getInputPacketList() {
    return m_unprocessedInputPackets;
}

DeliveryNotifier& ClientProxy::getDeliveryNotifier() {
    return m_delNotMgr;
}

ReplicationManager& ClientProxy::getReplicationManager() {
    return m_repMgr;
}

void ClientProxy::updateLastPacketTimestamp() {
    m_lastClientPacketTimestamp = GameServer::getTimestamp();
}

void ClientProxy::setIsLastInputTimestampDirty(bool v) {
    m_isLastInputTimestampDirty = v;
}

bool ClientProxy::isLastInputTimestampDirty() const {
    return m_isLastInputTimestampDirty;
}

player_id_t ClientProxy::getPlayerId() const {
    return m_playerId;
}

const asio::ip::udp::endpoint& ClientProxy::getAddress() const {
    return m_endpoint;
}

// Replication

void ClientProxy::replicateCreate(net_id_t netId, state_mask_t initDirtyState) {
    m_repMgr.replicateCreate(netId, initDirtyState);
}

void ClientProxy::replicateDestroy(net_id_t netId) {
    m_repMgr.replicateDestroy(netId);
}

void ClientProxy::addDirtyState(net_id_t netId, state_mask_t dirtyState) {
    m_repMgr.addDirtyState(netId, dirtyState);
}

void ClientProxy::handleCreateAckd(net_id_t netId) {
    m_repMgr.handleCreateAckd(netId);
}

void ClientProxy::removeFromReplication(net_id_t netId) {
    m_repMgr.removeFromReplication(netId);
}
