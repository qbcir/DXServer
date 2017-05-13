#include "NumericDesc.h"
#include "../data/LuaParser.h"

bool NumericExpr::initFromJson(const rapidjson::Value& el) {
    if (el.IsInt()) {
        m_value = float(el.GetInt());
        m_type = NumericExprType::FLOAT;
    } else if (el.IsDouble()) {
        m_type = NumericExprType::FLOAT;
        m_value = float(el.GetDouble());
    } else {
        return false;
    }
    return true;
}

bool NumericExpr::initFromLua(lua_State *L, int idx) {
    if (lua_isfunction(L, idx)) {
        m_type = NumericExprType::FUNC;
        int fidx = (idx < 0 ? lua_gettop(L) + idx + 1 : idx);
        int handler = toluafix_ref_function(L,fidx,0);
        m_func = dx_lua_func_wrapper<std::function<float()>>(handler);
        //cocos2d::ScriptHandlerMgr::getInstance()->addCustomHandler((void*)this, handler);
        return true;
    } else if (lua_isnumber(L, idx)) {
        m_type = NumericExprType::FLOAT;
        m_value = lua_tonumber(L, idx);
        return true;
    }
    return false;
}

float NumericExpr::eval() const {
    switch (m_type) {
        case NumericExprType::FLOAT :
            return m_value;
        case NumericExprType::FUNC :
            return m_func();
        default:
            return 0;
    }
}

std::unordered_map<std::string, NumericDescType> str2ndt {
    { "absolute", NumericDescType::ABSOLUTE },
    { "relative", NumericDescType::RELATIVE },
    { "aim", NumericDescType::AIM }
};

bool NumericDesc::initFromJson(const rapidjson::Value& el) {
    auto type_it = el.FindMember("type");
    if (type_it == el.MemberEnd()) {
        m_type = NumericDescType::RELATIVE;
    } else {
        auto type = std::string(type_it->value.GetString());
        auto it = str2ndt.find(type);
        if (it != std::end(str2ndt)) {
            m_type = it->second;
        }
        //CCASSERT(m_type != NumericDescType::INVALID, "");
    }
    DX_DESC_GET_REF_MEMBER(el, NumericExpr, expr);
    return true;
}

bool NumericDesc::initFromLua(lua_State* L, int idx) {
    lua_pushstring(L, "type");
    lua_gettable(L, (idx < 0 ? idx - 1 : idx));
    if (lua_isnil(L, lua_gettop(L))) {
        m_type = NumericDescType::RELATIVE;
    } else {
        auto type = std::string(lua_tostring(L, lua_gettop(L)));
        auto it = str2ndt.find(type);
        if (it != std::end(str2ndt)) {
            m_type = it->second;
        }
        //CCASSERT(m_type != NumericDescType::INVALID, "");
    }
    lua_pop(L, 1);
    DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, NumericExpr, expr);
    return true;
}

float NumericDesc::eval() {
    return m_expr->eval();
}

NumericDescType NumericDesc::getType() const {
    return m_type;
}

std::unordered_map<std::string, PositionDescType> str2pdt {
    { "absolute", PositionDescType::ABSOLUTE },
    { "absolute-percent", PositionDescType::ABSOLUTE_PERCENT },
    { "random", PositionDescType::RANDOM_ABSOLUTE },
    { "random-top", PositionDescType::RANDOM_TOP }
};

bool PositionDesc::initFromJson(const rapidjson::Value& el) {
    auto type_it = el.FindMember("type");
    if (type_it == el.MemberEnd()) {
        m_type = PositionDescType::INVALID;
    } else {
        auto type = std::string(type_it->value.GetString());
        auto it = str2pdt.find(type);
        if (it != std::end(str2pdt)) {
            m_type = it->second;
        }
        //CCASSERT(m_type != PositionDescType::INVALID, "");
    }
    DX_DESC_GET_OPT_REF_MEMBER(el, NumericExpr, x);
    DX_DESC_GET_OPT_REF_MEMBER(el, NumericExpr, y);
    return true;
}

bool PositionDesc::initFromLua(lua_State* L, int idx) {
    lua_pushstring(L, "type");
    lua_gettable(L, (idx < 0 ? idx - 1 : idx));
    if (lua_isnil(L, -1)) {
        m_type = PositionDescType::INVALID;
    } else {
        auto type = std::string(lua_tostring(L, -1));
        auto it = str2pdt.find(type);
        if (it != std::end(str2pdt)) {
            m_type = it->second;
        }
        //CCASSERT(m_type != PositionDescType::INVALID, "");
    }
    lua_pop(L, 1);
    DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, NumericExpr, x);
    DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, NumericExpr, y);
    return true;
}

Eigen::Vector2f PositionDesc::eval() {
    Eigen::Vector2f res;
    //cocos2d::Size size = cocos2d::Director::getInstance()->getWinSize();
    float x = m_x ? m_x->eval() : 0;
    float y = m_y ? m_y->eval() : 0;
    switch (m_type) {
        case PositionDescType::ABSOLUTE :
        case PositionDescType::RELATIVE :
            res[0] = x;
            res[1] = y;
            break;
        case PositionDescType::ABSOLUTE_PERCENT :
            res[0] = 0;//x * size.width;
            res[1] = 0;//y * size.height;
            break;
        case PositionDescType::RANDOM_TOP :
            res[0] = 0;//cocos2d::RandomHelper::random_int(0, int(size.width));
            res[1] = 0;//size.height;
        default:;
    }
    return res;
}

