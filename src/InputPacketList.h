#ifndef __dx_INPUTPACKETLIST_H__
#define __dx_INPUTPACKETLIST_H__

#include "InputPacket.h"
#include <deque>

class InputPacketList {
public:
    void clear();
    bool add(const InputPacket& p);
    void removeProcessedInputs(float serverTimestamp);
    std::deque<InputPacket> &getInputPackets();
    float getLastInputTimestamp() const;
    void setLastInputTimestamp(float ts);
private:
    float m_lastInputTimestamp = -1.0f;
    std::deque<InputPacket> m_inputs;
};

#endif /* __dx_INPUTPACKETLIST_H__ */
