#ifndef __DX_OBJECTMANAGER_H__
#define __DX_OBJECTMANAGER_H__

#include "GameObject.h"
#include "../desc/GameObjectDesc.h"
#include "../desc/BulletDesc.h"
#include "../desc/VehicleDesc.h"
#include "../desc/PlayerDesc.h"
#include "../behaviours/ActionDesc.h"

#define DX_OM_DEF_DESC_MAP(klass, member) std::unordered_map<std::string, klass##Ptr> member
#define DX_OM_DEF_GET_DESC_FUNC(klass) klass##Ptr get##klass (const std::string& label) const
#define DX_OM_DEF_ADD_DESC_FUNC(klass) klass##Ptr add##klass (const klass##Ptr& obj)
#define DX_OM_DEF_REMOVE_DESC_FUNC(klass) klass##Ptr remove##klass (const klass##Ptr& obj)
#define DX_OM_DEF_CLEAR_DESC_FUNC(klass) void clear##klass##s ()
#define DX_OM_DEF_DESC_FUNCS(klass) \
    DX_OM_DEF_GET_DESC_FUNC(klass); \
    DX_OM_DEF_ADD_DESC_FUNC(klass); \
    DX_OM_DEF_REMOVE_DESC_FUNC(klass); \
    DX_OM_DEF_CLEAR_DESC_FUNC(klass);

class ObjectManager {
public:
    static ObjectManager* getInstance();
    GameObjectPtr createObject(
            const std::string& key,
            GameObjectType objType);
    DX_OM_DEF_DESC_FUNCS(GameObjectDesc)
    DX_OM_DEF_DESC_FUNCS(BulletDesc)
    DX_OM_DEF_DESC_FUNCS(VehicleDesc)
    DX_OM_DEF_DESC_FUNCS(PlayerDesc)
    DX_OM_DEF_DESC_FUNCS(ActionDesc)
protected:
    DX_OM_DEF_DESC_MAP(ActionDesc, m_actionDescs);
    DX_OM_DEF_DESC_MAP(BulletDesc, m_bulletDescs);
    DX_OM_DEF_DESC_MAP(VehicleDesc, m_vehicleDescs);
    DX_OM_DEF_DESC_MAP(GameObjectDesc, m_objDescs);
    DX_OM_DEF_DESC_MAP(PlayerDesc, m_playerDescs);
};

#endif /* __DX_OBJECTMANAGER_H__ */
