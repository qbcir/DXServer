#include "InputPacketList.h"
#include <iostream>

bool InputPacketList::add(const InputPacket& p) {
    if(p.timestamp > m_lastInputTimestamp) {
        m_inputs.emplace_back(p);
        return true;
    }
    return false;
}

void InputPacketList::removeProcessedInputs(float serverTimestamp) {
    while(!m_inputs.empty()
          && m_inputs.front().timestamp <= serverTimestamp) {
        m_inputs.pop_front();
    }
}

std::deque<InputPacket>& InputPacketList::getInputPackets() {
    return m_inputs;
}

float InputPacketList::getLastInputTimestamp() const {
    return m_lastInputTimestamp;
}

void InputPacketList::setLastInputTimestamp(float ts) {
    m_lastInputTimestamp = ts;
}

void InputPacketList::clear() {
    std::deque<InputPacket>().swap(m_inputs);
}
