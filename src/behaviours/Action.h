#ifndef __DX_ACTION_H__
#define __DX_ACTION_H__

#include "../scripting/LuaRef.h"
#include <memory>
#include <vector>

class GameObject;
class Action : public LuaRef {
public:
    virtual ~Action() {}
    virtual bool isDone() const;
    virtual void stop();
    virtual void step(float dt);
    virtual void update(float time);
    virtual void startWithTarget(GameObject* target);
    GameObject* getTarget() const;
    void setTarget(GameObject* target);
protected:
    GameObject* m_target;
};
typedef std::shared_ptr<Action> ActionPtr;
typedef std::shared_ptr<GameObject> GameObjectPtr;

class FiniteTimeAction : public Action {
public:
    float getDuration() const;
    void setDuration(float duration);
protected:
    float m_duration;
};
typedef std::shared_ptr<FiniteTimeAction> FiniteTimeActionPtr;

class ActionInstant : public FiniteTimeAction {
public:
    virtual bool isDone() const override;
    virtual void step(float dt) override;
    virtual void update(float time) override;
};

class CallFuncN : public ActionInstant {
public:
    typedef std::function<void(GameObject*)> FuncT;
    static ActionPtr create(const FuncT& func);
    virtual void update(float time) override;
    virtual void execute();
protected:
    bool initWithFunction(const FuncT& func);
    FuncT m_func;
};

class ActionInterval : public FiniteTimeAction {
public:
    float getElapsed();
    virtual bool isDone() const override;
    virtual void step(float dt) override;
    virtual void startWithTarget(GameObject* target) override;
protected:
    bool initWithDuration(float d);
    float m_elapsed;
    bool m_firstTick;
};

class DelayTime : public ActionInterval {
public:
    static FiniteTimeActionPtr create(float d);
    virtual void update(float time) override;
};

class Sequence : public ActionInterval {
public:
    static ActionPtr create(const std::vector<ActionPtr>& arrayOfActions);
    virtual void stop(void) override;
    virtual void update(float t) override;
protected:
    bool init(const std::vector<ActionPtr>& arrayOfActions);
    size_t m_currIdx = 0;
    std::vector<ActionPtr> m_actions;
};

class Spawn : public ActionInterval {
public:
    static ActionPtr create(const std::vector<ActionPtr>& arrayOfActions);
    virtual void startWithTarget(GameObject* target) override;
    virtual void stop(void) override;
    virtual void update(float t) override;
protected:
    bool init(const std::vector<ActionPtr>& arrayOfActions);
    std::vector<ActionPtr> m_actions;
};

#endif /* __DX_ACTION_H__ */
