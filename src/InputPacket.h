#ifndef __DX_INPUTPACKET_H__
#define __DX_INPUTPACKET_H__

#include <cstdint>

enum class InputKey {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    FIRE,
    PREV_WEAPON,
    NEXT_WEAPON,
    PAUSE,
    MAX,
    INVALID = -1
};

enum class Direction {
    N, S, E, W,
    NE, NW, SE, SW,
    INVALID = -1
};

struct InputPacket {
    InputPacket() {}
    InputPacket(
        uint64_t keyboardState_,
        uint64_t mouseState_,
        float timestamp_,
        float delta_);
    uint64_t keyboardState = 0;
    uint64_t mouseState = 0;
    float timestamp = 0;
    float delta = 0;
    //
    Direction getDirection() const;
    bool isKeyPressed(InputKey key) const;
};

#endif /* __DX_INPUTPACKET_H__ */
