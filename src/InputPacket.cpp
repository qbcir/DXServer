#include "InputPacket.h"
#include "data/DataParser.h"

InputPacket::InputPacket(
        uint64_t keyboardState_,
        uint64_t mouseState_,
        float timestamp_,
        float delta_) :
    keyboardState(keyboardState_),
    mouseState(mouseState_),
    timestamp(timestamp_),
    delta(delta_)
{}

Direction InputPacket::getDirection() const {
    switch (keyboardState & 0xF) {
        case 0x1 : return Direction::N;
        case 0x2 : return Direction::S;
        case 0x4 : return Direction::W;
        case 0x5 : return Direction::NW;
        case 0x6 : return Direction::SW;
        case 0x8 : return Direction::E;
        case 0x9 : return Direction::NE;
        case 0xa : return Direction::SE;
        default: return Direction::INVALID;
    }
}

bool InputPacket::isKeyPressed(InputKey key) const {
    return (keyboardState >> static_cast<uint8_t>(key)) & 1;
}

DX_DEF_STRUCT_P(InputPacket)
DX_ADD_FIELD_P(InputPacket, keyboardState)
DX_ADD_FIELD_P(InputPacket, mouseState)
DX_ADD_FIELD_P(InputPacket, timestamp)
DX_ADD_FIELD_P(InputPacket, delta)
