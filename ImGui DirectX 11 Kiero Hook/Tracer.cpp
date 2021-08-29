#include "Tracer.h"
#include "WallHack.h"
#include "framework/il2cpp-appdata.h"
#include <iostream>
#include "includes.h"


void Tracer::Render()
{
	WallHack wall;
	for (int i = 0; i < 40; i++)
	{
		Vector2 Temper = wall.GetPlayerPos(i);
		if (Temper.x == -1)
			continue;
		if (Temper.d == -1)
			continue;
		ImGui::GetBackgroundDrawList()->AddLine({ (float)app::Screen_get_width(nullptr) / 2,(float)app::Screen_get_height(nullptr) / 2 + 500 }, { Temper.x,Temper.y }, ImColor{ colorTracer[0], colorTracer[1], colorTracer[2], colorTracer[3] }, LineSize);
	}
}