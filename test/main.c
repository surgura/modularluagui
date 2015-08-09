#include <Modular/Modular.h>
#include <Mlua/Mlua.h>
#include <Mgui/Mgui.h>
#include <Mlugu/Mlugu.h>
#include <lauxlib.h>
#include <stdio.h>

int main()
{
    Mdr_Factory factory;
    Mdr_Initialize(&factory);

    Mdr_ModuleId luaId;
    Mdr_Register(&factory, &luaId, sizeof(Mlua_Lua), sizeof(Mlua_LuaInstance), Mlua_Construct, Mlua_Destruct);

    Mdr_ModuleId guiId;
    Mdr_Register(&factory, &guiId, sizeof(Mgui_Gui), sizeof(Mgui_GuiInstance), Mgui_Construct, Mgui_Destruct);

    Mdr_ModuleId luaguiId;
    Mdr_Register(&factory, &luaguiId, sizeof(Mlugu_LuaGui), sizeof(Mlugu_LuaGuiInstance), Mlugu_Construct, Mlugu_Destruct);
    Mlugu_LuaGui* luaGui = Mdr_GetModuleCommonData(luaguiId);
    luaGui->luaId = luaId;
    luaGui->guiId = guiId;

    Mdr_InstanceId instanceId;
    Mdr_Instantiate(&factory, &instanceId);

    Mlua_LuaInstance* luaInstance = Mdr_GetModuleInstanceData(luaId, instanceId);
    lua_State* luaState = Mlua_GetLuaState(luaInstance);

    if (luaL_dostring(luaState, "GUI.NewWindow()"))
    {
        printf("%s", luaL_checkstring (luaState, -1));
    }

    Mdr_Destroy(&factory, instanceId);

    Mdr_Cleanup(&factory);

    while(1){}
}
