#include "Skeleton.h"
#include "framework/il2cpp-appdata.h"
#include <iostream>
#include "Vector.h"
#include "PlayerDataArray.h"


#define EntListBase 0xB35C3C
#define EntListBase2 0xB35CA8


app::PlayerData* GetPlayerDataS(UINT32 i)
{

    offsetsM offsets;
    PlayerDataArray* pdataA = (PlayerDataArray*)(*app::PLH__TypeInfo)->static_fields->player;
    DWORD CHECK = (DWORD)pdataA->Player[i];
    if (CHECK < 0xfffff || CHECK == NULL || &CHECK  == nullptr)
        return NULL;
    return pdataA->Player[i];

}

VectorSkelet Skeleton::Render(int i)
{
	offsetsM offsets;

	ImVec2 posInScreenTrue1;
	ImVec2 posInScreenTrue2;
	ImVec2 posInScreenTrue3;
	ImVec2 posInScreenTrue4;
	ImVec2 posInScreenTrue5;
	ImVec2 posInScreenTrue6; 
	ImVec2 posInScreenTrue7;
	ImVec2 posInScreenTrue8;
	ImVec2 posInScreenTrue9;
	ImVec2 posInScreenTrue10;
	ImVec2 posInScreenTrue11;
	ImVec2 posInScreenTrue12;
	ImVec2 posInScreenTrue13;
	ImVec2 posInScreenTrue14;
	ImVec2 posInScreenTrue15;
	ImVec2 posInScreenTrue16;
	ImVec2 posInScreenTrue17;

	app::PlayerData* enemy = GetPlayerDataS(i); // saksak 

	app::PlayerData* my = (*app::Controll__TypeInfo)->static_fields->pl; // saksak 
	uintptr_t baseModule = reinterpret_cast<uintptr_t>(GetModuleHandle(TEXT("GameAssembly.dll")));
	float posNe[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };
	if (offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, 0x10 + (UINT)i * 4,  0x28 }) == baseModule + EntListBase2)
		return{ -1,-1,-1 };
	if (enemy->fields.health <= 1)
		return{ -1,-1,-1 };
	if (enemy->fields.bstate == 5)
		return{ -1,-1,-1 };
	if (enemy->fields.currweapon == nullptr)
		return{ -1,-1,-1 };
	if (&enemy->fields.go == nullptr)
		return{ -1,-1,-1 };
	if (&enemy->fields.goBody == nullptr)
		return{ -1,-1,-1 };
	if (&enemy->fields.goBackPack == nullptr)
		return{ -1,-1,-1 };
	if (&enemy->fields.goArmHelp == nullptr)
		return{ -1,-1,-1 };
	if (&enemy->fields.currweapon->fields.goBoneMuzzle == nullptr)
		return{ -1,-1,-1 };
	if (&enemy->fields.currweapon->fields.goBoneRHand == nullptr)
		return{ -1,-1,-1 };
	if (enemy->fields.go == nullptr)
		return{ -1,-1,-1 };
	if (enemy->fields.goBody == nullptr)
		return{ -1,-1,-1 };
	if (enemy->fields.goBackPack == nullptr)
		return{ -1,-1,-1 };
	if (enemy->fields.goArmHelp == nullptr)
		return{ -1,-1,-1 };
	if (enemy->fields.currweapon->fields.goBoneRHand == nullptr)
		return{ -1,-1,-1 };
	if (enemy->fields.currweapon == nullptr)
		return{ -1,-1,-1 };
	if (&enemy->fields.currweapon == nullptr)
		return{ -1,-1,-1 };

	if (enemy->fields.bstate == 5)
	{
		for (int i = enemy->fields.health; i < 90;)
		{

		}
	}
		
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.go, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.goBody, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.goBackPack, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.goArmHelp, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	//if (projected5.z <= 1.0f)
	//	return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC4,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC4,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC8,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC8,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xCC,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xD0,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xCC,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xD0,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xCC,0x18,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xD0,0x18,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).z <= 1.0f)
		return{ -1,-1,-1 };
	if (teamcheck == true)
	{

		if (my->fields.team == enemy->fields.team)
		{
			return { -1, -1,-1 };/// vec 07
		}
	}
	posInScreenTrue1.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.go, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue1.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.go, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue2.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.goBody, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue2.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.goBody, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue3.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.goBackPack, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue3.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.goBackPack, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue4.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.goArmHelp, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue4.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform(enemy->fields.goArmHelp, nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue6.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC4,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue6.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC4,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue7.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC4,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue7.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC4,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue8.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC8,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue8.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC8,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue9.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC8,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue9.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xC8,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue10.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xCC,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue10.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xCC,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue11.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xD0,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue11.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xD0,0x10,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue12.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xCC,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue12.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xCC,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue13.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xD0,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue13.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xD0,0x14,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue14.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xCC,0x18,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue14.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xCC,0x18,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;
	posInScreenTrue15.x = app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xD0,0x18,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).x;
	posInScreenTrue15.y = app::Screen_get_height(nullptr) - app::Camera_WorldToScreenPoint((*app::Controll__TypeInfo)->static_fields->csCam, app::Transform_get_position(app::GameObject_get_transform((app::GameObject*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, (ULONG)0x10 + i * 0x4,0xD0,0x18,0x0 }), nullptr), nullptr), app::Camera_MonoOrStereoscopicEye__Enum::Mono, nullptr).y;

	if (enemy->fields.spawnprotect)
	{
		return { posInScreenTrue1.x,posInScreenTrue1.y,posInScreenTrue2.x,posInScreenTrue2.y,posInScreenTrue3.x,posInScreenTrue3.y,posInScreenTrue4.x,posInScreenTrue4.y,posInScreenTrue6.x ,posInScreenTrue6.y,posInScreenTrue7.x ,posInScreenTrue7.y ,posInScreenTrue8.x ,posInScreenTrue8.y,posInScreenTrue9.x ,posInScreenTrue9.y,posInScreenTrue10.x ,posInScreenTrue10.y ,posInScreenTrue11.x ,posInScreenTrue11.y ,posInScreenTrue12.x ,posInScreenTrue12.y,posInScreenTrue13.x ,posInScreenTrue13.y,posInScreenTrue14.x ,posInScreenTrue14.y,posInScreenTrue15.x ,posInScreenTrue15.y ,3};/// vec 07
	}
	
	return { posInScreenTrue1.x,posInScreenTrue1.y,posInScreenTrue2.x,posInScreenTrue2.y,posInScreenTrue3.x,posInScreenTrue3.y,posInScreenTrue4.x,posInScreenTrue4.y,posInScreenTrue6.x ,posInScreenTrue6.y,posInScreenTrue7.x ,posInScreenTrue7.y ,posInScreenTrue8.x ,posInScreenTrue8.y,posInScreenTrue9.x ,posInScreenTrue9.y,posInScreenTrue10.x ,posInScreenTrue10.y ,posInScreenTrue11.x ,posInScreenTrue11.y ,posInScreenTrue12.x ,posInScreenTrue12.y,posInScreenTrue13.x ,posInScreenTrue13.y,posInScreenTrue14.x ,posInScreenTrue14.y,posInScreenTrue15.x ,posInScreenTrue15.y ,0 };

}



