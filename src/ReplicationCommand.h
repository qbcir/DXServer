#ifndef __dx_REPLICATIONCOMMAND_H__
#define __dx_REPLICATIONCOMMAND_H__

#include "NetTypes.h"

enum class ReplicaActionType : uint8_t {
    CREATE,
    UPDATE,
    DESTROY,
    RPC,
    INVALID
};

class ReplicationManagerTransmissionData;
class ReplicaCommand {
public:
    ReplicaCommand();
    ReplicaCommand(state_mask_t dirtyState);
    void handleCreateAckd();
    void addDirtyState(state_mask_t dirtyState);
    void setDestroy();
    bool hasDirtyState() const;
    ReplicaActionType getActionType() const;
    state_mask_t getDirtyState() const;
    void clearDirtyState(state_mask_t stateToClear);
    void writeBytes(bytes_t& buf, net_id_t netId,
                    ReplicationManagerTransmissionData* tdata);
    void readBytes(uint8_t* &p, net_id_t netId);
private:
    ReplicaActionType m_action;
    state_mask_t m_dirtyState;
};

#endif // __dx_REPLICATIONCOMMAND_H__
