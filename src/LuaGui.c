#include "Mlugu/LuaGui.h"
#include "Mlua/Mlua.h"
#include "Mgui/Mgui.h"

int NewWindow(lua_State* luaState)
{
    Mgui_GuiInstance* guiInstance = lua_touserdata(luaState, lua_upvalueindex(1));
    Mgui_NewWindow(guiInstance);

    return 0;
}

void Mlugu_Construct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId)
{
    Mlugu_LuaGui* luaGui = Mdr_GetModuleCommonData(moduleId);
    Mlua_LuaInstance* luaInstance = Mdr_GetModuleInstanceData(luaGui->luaId, instanceId);
    lua_State* luaState = Mlua_GetLuaState(luaInstance);
    Mgui_GuiInstance* guiInstance = Mdr_GetModuleInstanceData(luaGui->guiId, instanceId);

    // create gui table
    lua_createtable(luaState, 0, 1);

    // create NewWindow function
    lua_pushstring(luaState, "NewWindow");
    lua_pushlightuserdata(luaState, guiInstance);
    lua_pushcclosure(luaState, NewWindow, 1);
    lua_settable(luaState, -3);

    // set gui table as global
    lua_setglobal(luaState, "GUI");
}

void Mlugu_Destruct(Mdr_ModuleId module, Mdr_InstanceId instance)
{

}

void Mlugu_Initialize(Mlugu_LuaGui* luaGui, Mdr_ModuleId luaId, Mdr_ModuleId guiId)
{
    luaGui->luaId = luaId;
    luaGui->guiId = guiId;
}
