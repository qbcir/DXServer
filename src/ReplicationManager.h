#ifndef __dx_REPLICATIONMANAGER_H__
#define __dx_REPLICATIONMANAGER_H__

#include <unordered_map>
#include "NetTypes.h"
#include "ReplicationCommand.h"
#include "ReplicationManagerTransmissionData.h"

class ReplicationManager {
public:
    void replicateCreate(net_id_t netId, state_mask_t initDirtyState);
    void replicateDestroy(net_id_t netId);
    void addDirtyState(net_id_t netId, state_mask_t dirtyState);
    void handleCreateAckd(net_id_t netId);
    void removeFromReplication(net_id_t netId);
    void writeData(bytes_t &buf, ReplicationManagerTransmissionData* tdata);
private:
    state_mask_t writeBytesCreateAction(bytes_t &buf, net_id_t netId, state_mask_t dirtyState);
    state_mask_t writeBytesUpdateAction(bytes_t &buf, net_id_t netId, state_mask_t dirtyState);
    state_mask_t writeBytesDestroyAction(bytes_t &buf, net_id_t netId, state_mask_t dirtyState);
    std::unordered_map<net_id_t, ReplicaCommand> m_netId2RepCmd;
};

#endif /* __dx_REPLICATIONMANAGER_H__ */
