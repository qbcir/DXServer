#ifndef __DX_BULLET_H__
#define __DX_BULLET_H__

#include "GameObject.h"
#include "../desc/BulletDesc.h"

class Bullet : public GameObject {
public:
    static GameObjectPtr createFromDesc(const BulletDescPtr& desc);
    virtual size_t writeTypeInfoBytes(bytes_t& buf);
protected:
    bool initFromDesc(const BulletDescPtr& desc);
    BulletDescPtr m_bulletDesc;
};

#endif /* __DX_BULLET_H__ */
