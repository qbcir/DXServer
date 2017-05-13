#ifndef __DX_LUAREF_H__
#define __DX_LUAREF_H__

#include <memory>

struct LuaRef {
    LuaRef();
    virtual ~LuaRef() {}
    int ID;
    int luaID = 0;
};
typedef std::shared_ptr<LuaRef> LuaRefPtr;

#endif // __DX_LUAREF_H__
