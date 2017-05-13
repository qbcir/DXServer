#ifndef __dx_DELIVERYNOTIFICATIONMANAGER_H__
#define __dx_DELIVERYNOTIFICATIONMANAGER_H__

#include "Packet.h"
#include "AckRange.h"
#include "InFlightPacket.h"
#include <deque>

class InFlightPacket;
class DeliveryNotifier
{
public:
    DeliveryNotifier() {}
    DeliveryNotifier(
            bool shouldSendAcks,
            bool shouldProcessAcks);
    InFlightPacket*	writeState(BytesT& buf);
    bool readAndProcessState(uint8_t* &p);
    void processTimedOutPackets();
protected:
    void onDeliveryFail(const InFlightPacket& inFlightPacket);
    void onDeliverySucc(const InFlightPacket& inFlightPacket);
    InFlightPacket* writeSeqNum(BytesT& buf);
    void writeAckData(BytesT& buf);
    bool processSeqNumber(uint8_t* &p);
    void processAcks(uint8_t* &p);
    void addPendingAck(packet_seq_num_t seqNum);
    bool m_shouldSendAcks = false;
    bool m_shouldProcessAcks = true;
    packet_seq_num_t m_nextOutgoingSeqNum = 0;
    packet_seq_num_t m_nextExpectedSeqNum = 0;
    uint32_t m_deliveredPacketCnt = 0;
    uint32_t m_droppedPacketCnt = 0;
    uint32_t m_dispatchedPacketCnt = 0;
    std::deque<InFlightPacket> m_inFlightPackets;
    std::deque<AckRange> m_pendingAcks;
};

#endif /* __dx_DELIVERYNOTIFICATIONMANAGER_H__ */
