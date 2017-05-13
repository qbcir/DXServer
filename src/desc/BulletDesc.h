#ifndef __DX_BULLETDESC_H__
#define __DX_BULLETDESC_H__

#include "GameObjectDesc.h"
#include "../data/DataMacros.h"

class GameObject;
class BulletDesc : public GameObjectDesc {
public:
    typedef std::shared_ptr<BulletDesc> BulletDescPtr;
    DX_CREATE_FROM_JSON_FUNC(BulletDescPtr, BulletDesc)
    DX_CREATE_FROM_LUA_FUNC(BulletDescPtr, BulletDesc)
    bool isEnemy() const;
    void setEnemy(float enemy);
    float getDamage() const;
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State *L, int idx);
    bool m_enemy = true;
    float m_damage = 0;
};
typedef BulletDesc::BulletDescPtr BulletDescPtr;

#endif /* __DX_BULLETDESC_H__ */
