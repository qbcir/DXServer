#ifndef __DX_LUASTATE_H__
#define __DX_LUASTATE_H__

class lua_State;
class LuaState {
public:
    ~LuaState();
    static LuaState* getInstance();
    static lua_State* get();
    void init();
    void addSearchPath(const char* path);
    void addLuaLoader(lua_CFunction func);
    int executeScriptFile(const char* filename);
    int executeFunction(int numArgs);
protected:
    int m_callFromLua = 0;
    lua_State* m_state = nullptr;
};

#endif /* __DX_LUASTATE_H__ */
