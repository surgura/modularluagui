#include <Modular/Modular.h>
#include <Mlugu/Mlugu.h>

int main()
{
    Mdr_Factory factory;
    Mdr_Initialize(&factory);

    Mdr_ModuleId luaguiId;
    Mdr_Register(&factory, &luaguiId, sizeof(Mlugu_LuaGui), sizeof(Mlugu_LuaGuiInstance), Mlugu_Construct, Mlugu_Destruct);

    Mdr_InstanceId instance;
    Mdr_Instantiate(&factory, &instance);

    Mdr_Destroy(&factory, instance);

    Mdr_Cleanup(&factory);

    while(1){}

    return 0;
}
