#ifndef __dx_REPLICATIONMANAGERTRANSMISSIONDATA_H__
#define __dx_REPLICATIONMANAGERTRANSMISSIONDATA_H__

#include "TransmissionData.h"
#include "NetTypes.h"
#include "ReplicationCommand.h"

class ReplicationTransmission {
public:
    ReplicationTransmission(
            net_id_t netId,
            ReplicaActionType action,
            state_mask_t state);
    net_id_t getNetId() const;
    ReplicaActionType getActionType() const;
    state_mask_t getState() const;
private:
    net_id_t m_netId;
    ReplicaActionType m_action;
    state_mask_t m_state;
};

class ReplicationManager;
class ReplicationManagerTransmissionData : public TransmissionData
{
public:
    ReplicationManagerTransmissionData(ReplicationManager* rm);
    void addTransmission(net_id_t netId,
        ReplicaActionType action, state_mask_t state);
    void onDeliveryFail(DeliveryNotifier*dnm) const;
    void onDeliverySucc(DeliveryNotifier*dnm) const;
private:
    void onCreateDeliveryFail(net_id_t netId) const;
    void onUpdateStateDeliveryFail(net_id_t netId, state_mask_t state,
            DeliveryNotifier* dnm) const;
    void onDestroyDeliveryFail(net_id_t netId) const;
    void onCreateDeliverySucc(net_id_t netId) const;
    void onDestroyDeliverySucc(net_id_t netId) const;
    ReplicationManager* m_replicationMgr = nullptr;
    std::vector<ReplicationTransmission> m_transmissions;
};

#endif // __dx_REPLICATIONMANAGERTRANSMISSIONDATA_H__
