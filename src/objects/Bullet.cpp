#include "Bullet.h"

GameObjectPtr Bullet::createFromDesc(const BulletDescPtr& desc) {
    auto b = new (std::nothrow) Bullet();
    if (b && b->initFromDesc(desc)) {
        return GameObjectPtr(b);
    }
    if (b) delete b;
    return nullptr;
}

bool Bullet::initFromDesc(const BulletDescPtr& desc) {
    if (!GameObject::initFromDesc(desc)) {
        return false;
    }
    /*
    if (desc->isEnemy()) {
        this->setCollisionClass(COLLISION_CLASS_ENEMY_BULLET);
        this->enableCollisionsWith(COLLISION_CLASS_PLAYER);
    } else {
        this->setCollisionClass(COLLISION_CLASS_PLAYER_BULLET);
        this->enableCollisionsWith(COLLISION_CLASS_ENEMY);
    }
    */
    m_bulletDesc = desc;
    return true;
}

size_t Bullet::writeTypeInfoBytes(bytes_t& buf) {
    size_t nb = 0;
    nb += dx_write_bytes<GameObjectType>(buf, GameObjectType::BULLET);
    nb += dx_write_bytes<std::string>(buf, m_bulletDesc->getLabel());
    return nb;
}
