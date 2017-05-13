#include "LuaRef.h"

LuaRef::LuaRef() {
    static int refID = 1;
    ID = refID++;
}
