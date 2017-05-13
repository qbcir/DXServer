#ifndef __DX_SCENE_H__
#define __DX_SCENE_H__

#include "objects/GameObject.h"
#include <vector>

class Scene : public LuaRef {
public:
    static std::shared_ptr<Scene> create();
    GameObjectPtr createGameObject(std::string& key, GameObjectType objType);
    void update(float dt);
    void addGameObject(GameObjectPtr go);
    void removeGameObject(GameObjectPtr go);
protected:
    Scene();
private:
    void resolveCollisions();
    void removeDeadObjects();
    std::vector<GameObjectPtr> m_objects;
    b2World m_world;
};
typedef std::shared_ptr<Scene> ScenePtr;

#endif /* __DX_SCENE_H__ */
