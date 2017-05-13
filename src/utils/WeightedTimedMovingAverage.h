#ifndef __dxs_WEIGHTEDTIMEDMOVINGAVERAGE_H__
#define __dxs_WEIGHTEDTIMEDMOVINGAVERAGE_H__

class WeightedTimedMovingAverage {
public:
    void updatePerSec(float dt);
    void update(float dt);
private:
    float m_lastEntryTime;
    float m_value;
    float m_duration;
};

#endif /* __dxs_WEIGHTEDTIMEDMOVINGAVERAGE_H__ */
