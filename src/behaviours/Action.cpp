#include "Action.h"

void Action::stop() {
    m_target = nullptr;
}

bool Action::isDone() const {
    return true;
}

void Action::step(float /*dt*/) {
}

void Action::update(float /*time*/) {
}

GameObject* Action::getTarget() const {
    return m_target;
}

void Action::setTarget(GameObject* target) {
    m_target = target;
}

void Action::startWithTarget(GameObject *target) {
    m_target = target;
}

float FiniteTimeAction::getDuration() const {
    return m_duration;
}

void FiniteTimeAction::setDuration(float duration) {
    m_duration = duration;
}

bool ActionInstant::isDone() const
{
    return true;
}

void ActionInstant::step(float /*dt*/) {
    float updateDt = 1.0f;
    update(updateDt);
}

void ActionInstant::update(float /*time*/) {
    // nothing
}

ActionPtr CallFuncN::create(const FuncT& func) {
    auto ret = new (std::nothrow) CallFuncN();
    if (ret && ret->initWithFunction(func) ) {
        return ActionPtr(ret);
    }
    if (ret) delete ret;
    return nullptr;
}

bool CallFuncN::initWithFunction(const FuncT& func) {
    m_func = func;
    return true;
}

void CallFuncN::update(float /*time*/) {
    this->execute();
}

void CallFuncN::execute() {
    if (m_func) {
        m_func(m_target);
    }
}

bool ActionInterval::isDone() const {
    return m_elapsed >= m_duration;
}

void ActionInterval::step(float dt) {
    if (m_firstTick) {
        m_firstTick = false;
        m_elapsed = 0;
    } else {
        m_elapsed += dt;
    }
    float updateDt;
    if (m_duration == 0) {
        updateDt = 1;
    } else {
        // needed for rewind. elapsed could be negative
        updateDt = std::max (0.f, std::min(1.f, m_elapsed / m_duration));
    }
    this->update(updateDt);
}

void ActionInterval::startWithTarget(GameObject* target) {
    FiniteTimeAction::startWithTarget(target);
    m_elapsed = 0.0f;
    m_firstTick = true;
}


FiniteTimeActionPtr DelayTime::create(float d) {

}

void DelayTime::update(float time) {

}

ActionPtr Spawn::create(const std::vector<ActionPtr>& arrayOfActions) {
    auto a = new (std::nothrow) Spawn();
    if (a && a->init(arrayOfActions)) {
        return ActionPtr(a);
    }
    if (a) delete a;
    return nullptr;
}

bool Spawn::init(const std::vector<ActionPtr>& arrayOfActions) {
    m_actions = arrayOfActions;
    return true;
}

void Spawn::startWithTarget(GameObject *target) {
    ActionInterval::startWithTarget(target);
    for (auto& action : m_actions) {
        action->startWithTarget(target);
    }
}

void Spawn::stop(void) {
    for (auto& action : m_actions) {
        action->stop();
    }
    ActionInterval::stop();
}

void Spawn::update(float time) {
    for (auto& action : m_actions) {
        if (!action->isDone()) {
            action->update(time);
        }
    }
}

ActionPtr Sequence::create(const std::vector<ActionPtr>& arrayOfActions) {
    auto a = new (std::nothrow) Sequence();
    if (a && a->init(arrayOfActions)) {
        return ActionPtr(a);
    }
    if (a) delete a;
    return nullptr;
}

bool Sequence::init(const std::vector<ActionPtr>& arrayOfActions) {
    m_actions = arrayOfActions;
    return true;
}

void Sequence::stop(void) {
}

void Sequence::update(float t) {
    auto& curr = m_actions[m_currIdx];
    curr->update(t);
    if (curr->isDone()) {
        ++m_currIdx;
    }
}
