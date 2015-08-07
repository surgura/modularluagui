/**
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

    @author Aart Stuurman
**/

/**
    Header guard
**/
#ifndef MLUGU_LUA_GUI_H
#define MLUGU_LUA_GUI_H

/**
    Include files
**/

#include <stdio.h>

typedef struct
{

} Mlugu_LuaGui;

typedef struct
{
} Mlugu_LuaGuiInstance;

/**
    Construct function for the lua gui module
    @param  module          The id of this module.
    @param  instance        The id of the instance being created.
**/
void Mlugu_Construct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId)
{
    printf("created lua gui state");
}

/**
    Destruct function for the lua gui module
    @param  module          The id of this module.
    @param  instance        The id of the instance being destroyed.
**/
void Mlugu_Destruct(Mdr_ModuleId module, Mdr_InstanceId instance)
{
}

#endif // MLUGU_LUA_GUI_H
