#include "../GameServer.h"
#include "GameObject.h"
#include "Vehicle.h"
#include "Bullet.h"
#include "PlayerObject.h"

ObjectManager* ObjectManager::getInstance() {
    GameServer::getInstance()->getObjectManager();
}

#define DX_CREATE_GET_DESC_FUNC(klass, member) \
    klass##Ptr ObjectManager::get##klass(const std::string& label) const { \
        auto it = member.find(label); \
        return it == member.end() ? nullptr : it->second; \
    }

#define DX_CREATE_ADD_DESC_FUNC(klass, member) \
    klass##Ptr ObjectManager::add##klass(const klass##Ptr& obj) {\
        klass##Ptr prev(nullptr); \
        auto prev_it = member.find(obj->getLabel()); \
        if (prev_it != member.end()) {\
            prev = prev_it->second; \
        } \
        member[obj->getLabel()] = obj; \
        return prev; \
    }

#define DX_CREATE_REMOVE_DESC_FUNC(klass, member) \
    klass##Ptr ObjectManager::remove##klass(const klass##Ptr& obj) {\
        klass##Ptr prev(nullptr); \
        auto prev_it = member.find(obj->getLabel()); \
        if (prev_it != member.end()) {\
            prev = prev_it->second; \
            member.erase(prev_it); \
        } \
        return prev; \
    }

#define DX_CREATE_CLEAR_DESC_FUNC(klass, member) \
    void ObjectManager::clear##klass##s() {\
        member.clear(); \
    }

#define DX_CREATE_DESC_FUNCS(klass, member) \
    DX_CREATE_GET_DESC_FUNC(klass, member) \
    DX_CREATE_ADD_DESC_FUNC(klass, member) \
    DX_CREATE_REMOVE_DESC_FUNC(klass, member) \
    DX_CREATE_CLEAR_DESC_FUNC(klass, member)

DX_CREATE_DESC_FUNCS(BulletDesc, m_bulletDescs)
DX_CREATE_DESC_FUNCS(VehicleDesc, m_vehicleDescs)
DX_CREATE_DESC_FUNCS(PlayerDesc, m_playerDescs)
DX_CREATE_DESC_FUNCS(GameObjectDesc, m_objDescs)
DX_CREATE_DESC_FUNCS(ActionDesc, m_actionDescs)

GameObjectPtr ObjectManager::createObject(
    const std::string& key, GameObjectType objType) {
    switch (objType) {
        case GameObjectType::GENERIC: {
            auto desc = getGameObjectDesc(key);
            return desc ? GameObject::createFromDesc(desc) : nullptr;
        }
        case GameObjectType::VEHICLE: {
            auto desc = getVehicleDesc(key);
            return desc ? Vehicle::createFromDesc(desc) : nullptr;
        }
        case GameObjectType::BULLET: {
            auto desc = getBulletDesc(key);
            return desc ? Bullet::createFromDesc(desc) : nullptr;
        }
        case GameObjectType::PLAYER: {
            auto desc = getPlayerDesc(key);
            return desc ? PlayerObject::createFromDesc(desc) : nullptr;
        }
        default:;
    }
    return nullptr;
}
