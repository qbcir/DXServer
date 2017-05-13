#ifndef __DX_DXSERVERLUALOADER_H__
#define __DX_DXSERVERLUALOADER_H__

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

extern int dx_server_lua_loader(lua_State *L);
}

#endif /* __DX_DXSERVERLUALOADER_H__ */
