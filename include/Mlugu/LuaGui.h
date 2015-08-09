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
#include <Modular/Modular.h>

#include <stdio.h>

typedef struct
{
    Mdr_ModuleId luaId;
    Mdr_ModuleId guiId;
} Mlugu_LuaGui;

typedef struct
{
} Mlugu_LuaGuiInstance;

/**
    Construct function for the lua gui module
    @param  module          The id of this module.
    @param  instance        The id of the instance being created.
**/
void Mlugu_Construct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId);

/**
    Destruct function for the lua gui module
    @param  module          The id of this module.
    @param  instance        The id of the instance being destroyed.
**/
void Mlugu_Destruct(Mdr_ModuleId module, Mdr_InstanceId instance);

/**
    Initialize the lua gui module.
    @param  luaGui      The module to initialize
    @param  luaId       The id of the lua module
    @param  guiId       The id of the gui module
**/
void Mlugu_Initialize(Mlugu_LuaGui* luaGui, Mdr_ModuleId luaId, Mdr_ModuleId guiId);

#endif // MLUGU_LUA_GUI_H
