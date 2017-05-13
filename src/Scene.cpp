#include "Scene.h"
#include "ObjectManager.h"
#include <iostream>

std::shared_ptr<Scene> Scene::create() {
    auto scene = new Scene();
    return ScenePtr(scene);
}

Scene::Scene() :
    m_world(b2Vec2(0.f, 0.f))
{}

void Scene::update(float dt) {
    m_world.Step(dt, 8, 3);
    for (auto obj : m_objects) {
        obj->update(dt);
    }
}

void Scene::addGameObject(GameObjectPtr go) {
    m_objects.emplace_back(go);
    go->setIdxInScene(m_objects.size()-1);
}

void Scene::removeGameObject(GameObjectPtr go) {
    int idx = go->getIdxInScene();
    int lastIdx = m_objects.size()-1;
    if (idx != lastIdx) {
        m_objects[idx] = m_objects[lastIdx];
        m_objects[idx]->setIdxInScene(idx);
    }
    go->setIdxInScene(-1);
    m_objects.pop_back();
}

GameObjectPtr Scene::createGameObject(std::string& key, GameObjectType objType) {
    auto om = ObjectManager::getInstance();
    auto obj = om->createObject(key, objType);
    b2BodyDef objectBodyDef;
    objectBodyDef.type = b2_dynamicBody;
    b2Body* phyBody = m_world.CreateBody(&objectBodyDef);
    phyBody->SetAngularVelocity(0.f);
    obj->setBody(phyBody);
    return obj;
}
