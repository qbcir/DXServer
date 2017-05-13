#ifndef __dx_SPRITEDESC_H__
#define __dx_SPRITEDESC_H__

#include "Box2D/Common/b2Math.h"
#include <string>

struct SpriteDesc {
    std::string filename;
    std::string name;
    int zOrder;
    b2Vec2 position;
    b2Vec2 anchorPoint { 0.5, 0.5 };
};

#endif /* __dx_SPRITEDESC_H__ */
