#include "ReplicationManagerTransmissionData.h"
#include "ReplicationManager.h"
#include "GameServer.h"

ReplicationTransmission::ReplicationTransmission(
        net_id_t netId,
        ReplicaActionType action,
        state_mask_t state) :
    m_netId(netId),
    m_action(action),
    m_state(state)
{}

net_id_t ReplicationTransmission::getNetId() const {
    return m_netId;
}

ReplicaActionType ReplicationTransmission::getActionType() const {
    return m_action;
}

state_mask_t ReplicationTransmission::getState() const {
    return m_state;
}

ReplicationManagerTransmissionData::ReplicationManagerTransmissionData(
        ReplicationManager *rm) :
    m_replicationMgr(rm)
{}

void ReplicationManagerTransmissionData::addTransmission(
        net_id_t netId,
        ReplicaActionType action,
        state_mask_t state) {
    m_transmissions.emplace_back(
        ReplicationTransmission(netId, action, state));
}

void ReplicationManagerTransmissionData::onDeliveryFail(
        DeliveryNotifier* dnm) const {
    for (const auto& rt : m_transmissions) {
        auto netId = rt.getNetId();
        switch(rt.getActionType()) {
            case ReplicaActionType::CREATE:
                onCreateDeliveryFail(netId);
                break;
            case ReplicaActionType::UPDATE:
                onUpdateStateDeliveryFail(netId, rt.getState(), dnm);
                break;
            case ReplicaActionType::DESTROY:
                onDestroyDeliveryFail(netId);
                break;
            default:;
        }
    }
}

void ReplicationManagerTransmissionData::onDeliverySucc(
        DeliveryNotifier* dnm) const {
    for (const auto& rt : m_transmissions) {
        auto netId = rt.getNetId();
        switch(rt.getActionType()) {
            case ReplicaActionType::CREATE:
                onCreateDeliverySucc(netId);
                break;
            case ReplicaActionType::DESTROY:
                onDestroyDeliverySucc(netId);
                break;
            default:;
        }
    }
}

void ReplicationManagerTransmissionData::onCreateDeliveryFail(
        net_id_t netId) const {
    auto nm = GameServer::getInstance();
    auto go = nm->getGameObject(netId);
    if (go) {
        m_replicationMgr->replicateCreate(netId, go->getFullStateMask());
    }
}

void ReplicationManagerTransmissionData::onUpdateStateDeliveryFail(
        net_id_t netId, state_mask_t state,
        DeliveryNotifier* dnm) const {
    auto nm = GameServer::getInstance();
    auto go = nm->getGameObject(netId);
    if (go) {
        // FIXME
        if (state) {
            m_replicationMgr->addDirtyState(netId, state);
        }
    }
}

void ReplicationManagerTransmissionData::onDestroyDeliveryFail(net_id_t netId) const {
    m_replicationMgr->replicateDestroy(netId);
}

void ReplicationManagerTransmissionData::onCreateDeliverySucc(net_id_t netId) const {
    m_replicationMgr->handleCreateAckd(netId);
}

void ReplicationManagerTransmissionData::onDestroyDeliverySucc(net_id_t netId) const {
    m_replicationMgr->removeFromReplication(netId);
}
