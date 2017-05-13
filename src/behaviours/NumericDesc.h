#ifndef __DX_NUMERICDESC_H__
#define __DX_NUMERICDESC_H__

#include "../scripting/LuaRef.h"
#include "../data/DataParser.h"
#include "Dense"

enum class NumericExprType {
    FLOAT,
    FUNC,
    INVALID = -1
};

class NumericExpr : public LuaRef {
public:
    typedef std::shared_ptr<NumericExpr> NumericExprPtr;
    typedef std::function<float()> FuncT;
    DX_CREATE_FROM_JSON_FUNC(NumericExprPtr, NumericExpr)
    DX_CREATE_FROM_LUA_FUNC(NumericExprPtr, NumericExpr)
    float eval() const;
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    NumericExprType m_type = NumericExprType::INVALID;
    float m_value;
    FuncT m_func;
};
typedef NumericExpr::NumericExprPtr NumericExprPtr;

enum class NumericDescType {
    AIM,
    ABSOLUTE,
    RELATIVE,
    SEQUENCE,
    INVALID = -1
};

class NumericDesc : public LuaRef {
public:
    virtual float eval();
    NumericDescType getType() const;
protected:
    virtual bool initFromJson(const rapidjson::Value& el);
    virtual bool initFromLua(lua_State* L, int idx);
    NumericDescType m_type = NumericDescType::ABSOLUTE;
    NumericExprPtr m_expr;
};
typedef std::shared_ptr<NumericDesc> NumericDescPtr;

class SpeedDesc : public NumericDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(NumericDescPtr, SpeedDesc)
    DX_CREATE_FROM_LUA_FUNC(NumericDescPtr, SpeedDesc)
};

class DirectionDesc : public NumericDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(NumericDescPtr, DirectionDesc)
    DX_CREATE_FROM_LUA_FUNC(NumericDescPtr, DirectionDesc)
};

class HorizontalDesc : public NumericDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(NumericDescPtr, HorizontalDesc)
    DX_CREATE_FROM_LUA_FUNC(NumericDescPtr, HorizontalDesc)
};

class VerticalDesc : public NumericDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(NumericDescPtr, VerticalDesc)
    DX_CREATE_FROM_LUA_FUNC(NumericDescPtr, VerticalDesc)
};

class OrientationDesc : public NumericDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(NumericDescPtr, OrientationDesc)
    DX_CREATE_FROM_LUA_FUNC(NumericDescPtr, OrientationDesc)
};

class RotationDesc : public NumericDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(NumericDescPtr, RotationDesc)
    DX_CREATE_FROM_LUA_FUNC(NumericDescPtr, RotationDesc)
};

enum PositionDescType {
    ABSOLUTE,
    ABSOLUTE_PERCENT,
    RANDOM_ABSOLUTE,
    RANDOM_TOP,
    RANDOM_BOTTOM,
    RANDOM_LEFT,
    RANDOM_RIGHT,
    TOP_PERCENT,
    BOTTOM_PERCENT,
    LEFT_PERCENT,
    RIGHT_PERCENT,
    RELATIVE,
    INVALID = -1
};

class PositionDesc : public LuaRef {
public:
    typedef std::shared_ptr<PositionDesc> PositionDescPtr;
    DX_CREATE_FROM_JSON_FUNC(PositionDescPtr, PositionDesc)
    DX_CREATE_FROM_LUA_FUNC(PositionDescPtr, PositionDesc)
    Eigen::Vector2f eval();
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    PositionDescType m_type = PositionDescType::INVALID;
    NumericExprPtr m_x = nullptr;
    NumericExprPtr m_y = nullptr;
};
typedef PositionDesc::PositionDescPtr PositionDescPtr;

#endif /* __DX_NUMERICDESC_H__ */
