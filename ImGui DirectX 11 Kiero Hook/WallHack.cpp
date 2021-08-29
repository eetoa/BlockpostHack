#include "WallHack.h"
#include "framework/il2cpp-appdata.h"
#include <iostream>
#include "Vector.h"
#include "offsetsM.h"
#include "includes.h"


app::PlayerData* GetPlayerData(UINT32 i)
{

    offsetsM offsets;
    PlayerDataArray* pdataA = (PlayerDataArray*)(*app::PLH__TypeInfo)->static_fields->player;
    DWORD CHECK = (DWORD)pdataA->Player[i];
    if (CHECK < 0xfffff || CHECK == NULL || &CHECK == nullptr)
        return NULL;
    return pdataA->Player[i];
}


Vector2 WallHack::Renders(int i)
{
    offsetsM offsets;
    ImVec2 posInScreenTrue;
    uintptr_t baseModule = reinterpret_cast<uintptr_t>(GetModuleHandle("GameAssembly.dll"));
    if (offsets.GetPointerAddress(baseModule + 0xB35CA8, { 0x5C,0x0C, (UINT)0x10 + i * 4,  0x28 }) == baseModule + 0xB35CA8)
        return { -1, -1,-1 };/// vec 0
    app::PlayerData* enemy = GetPlayerData(i);
    app::String* asdz = (enemy->fields.name);
    WallHackNames* chars = (WallHackNames*)asdz;

    if (teamcheck == true)
    {

        if ((*app::Controll__TypeInfo)->static_fields->pl->fields.team == enemy->fields.team)
        {
            return { -1, -1,-1 };/// vec 07
        }
    }
    if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, enemy->fields.currPos, app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
        return { -1, -1,-1 };/// vec 0
    if (enemy->fields.bstate == 5)
        return { -1,-1,-1 };
    posInScreenTrue.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, enemy->fields.currPos, app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;

    if (enemy->fields.leg_limit == 46)
        return { posInScreenTrue.x ,posInScreenTrue.y,44,chars->Pname };
    if (enemy->fields.spawnprotect)
    {
        return { app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, enemy->fields.currPos, app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x ,posInScreenTrue.y,3,chars->Pname };/// vec 07
    }
    return { app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, enemy->fields.currPos, app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x ,posInScreenTrue.y,0,chars->Pname };
}