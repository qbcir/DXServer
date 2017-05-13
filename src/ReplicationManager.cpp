#include "ReplicationManager.h"
#include "data/DataParser.h"
#include "GameServer.h"

void ReplicationManager::replicateCreate(net_id_t netId, state_mask_t initDirtyState) {
    m_netId2RepCmd[netId] = ReplicaCommand(initDirtyState);
}

void ReplicationManager::replicateDestroy(net_id_t netId) {
    m_netId2RepCmd[netId].setDestroy();
}

void ReplicationManager::addDirtyState(net_id_t netId, state_mask_t dirtyState) {
    m_netId2RepCmd[netId].addDirtyState(dirtyState);
}

void ReplicationManager::handleCreateAckd(net_id_t netId) {
    m_netId2RepCmd[netId].handleCreateAckd();
}

void ReplicationManager::removeFromReplication(net_id_t netId) {
    m_netId2RepCmd.erase(netId);
}

void ReplicationManager::writeData(
        bytes_t& buf, ReplicationManagerTransmissionData* tdata) {
    //run through each replication command and do something...
    for(auto& p: m_netId2RepCmd) {
        ReplicaCommand& rc = p.second;
        if (rc.hasDirtyState()) {
            net_id_t netId = p.first;
            //well, first write the network id...
            dx_write_bytes<net_id_t>(buf, netId);
            auto action = rc.getActionType();
            // then, action...
            dx_write_bytes<ReplicaActionType>(buf, action);
            state_mask_t writtenState = 0;
            state_mask_t dirtyState = rc.getDirtyState();
            switch (action) {
            case ReplicaActionType::CREATE:
                writtenState = writeBytesCreateAction(buf, netId, dirtyState);
                break;
            case ReplicaActionType::UPDATE :
                writtenState = writeBytesUpdateAction(buf, netId, dirtyState);
                break;
            case ReplicaActionType::DESTROY :
                writtenState = writeBytesDestroyAction(buf, netId, dirtyState);
                break;
            default:;
            }
            tdata->addTransmission(netId, action, writtenState);
            rc.clearDirtyState(writtenState);
        }
    }
}

state_mask_t ReplicationManager::writeBytesCreateAction(
        bytes_t &buf, net_id_t netId, state_mask_t dirtyState) {
    auto gs = GameServer::getInstance();
    auto go = gs->getGameObject(netId);
    go->writeTypeInfoBytes(buf);
    return go->writeStateBytes(buf, dirtyState);
}

state_mask_t ReplicationManager::writeBytesUpdateAction(bytes_t &buf, net_id_t netId, state_mask_t dirtyState) {
    auto gs = GameServer::getInstance();
    auto go = gs->getGameObject(netId);
    return go->writeStateBytes(buf, dirtyState);
}

state_mask_t ReplicationManager::writeBytesDestroyAction(bytes_t &buf, net_id_t netId, state_mask_t dirtyState) {
    return dirtyState;
}
