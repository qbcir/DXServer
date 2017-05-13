#include "SpriteDesc.h"
#include "../data/DataParser.h"

DX_DEF_STRUCT_P(SpriteDesc)
DX_ADD_FIELD_P(SpriteDesc, filename)
DX_ADD_FIELD_P(SpriteDesc, name)
DX_ADD_OPT_FIELD_P(SpriteDesc, zOrder)
DX_ADD_OPT_FIELD_P(SpriteDesc, position)
DX_ADD_OPT_FIELD_P(SpriteDesc, anchorPoint)

DX_DEF_STRUCT_P(b2Vec2)
DX_ADD_FIELD_P(b2Vec2, x)
DX_ADD_FIELD_P(b2Vec2, y)

