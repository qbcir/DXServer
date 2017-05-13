#ifndef __dx_INFLIGHTPACKET_H__
#define __dx_INFLIGHTPACKET_H__

#include "TransmissionData.h"
#include "NetTypes.h"
#include <unordered_map>

class DeliveryNotifier;
class InFlightPacket {
public:
    InFlightPacket(packet_seq_num_t seqNum);
    packet_seq_num_t getSeqNum() const;
    float getTimeDispatched() const;
    const TransmissionDataPtr getTransmissionData(int key);
    void setTransmissionData(int key, TransmissionDataPtr transmissionData);
    void onDeliveryFail(DeliveryNotifier* dnMgr) const;
    void onDeliverySucc(DeliveryNotifier* dnMgr) const;
private:
    packet_seq_num_t m_seqNum;
    float m_timeDispatched;
    std::unordered_map<int, TransmissionDataPtr> m_transmissionDataMap;
};

#endif /* __dx_INFLIGHTPACKET_H__ */
