#include "WallHack.h"
#include "framework/il2cpp-appdata.h"
#include <iostream>
#include "Vector.h"
#include "offsetsM.h"
#include "includes.h"
#include "GetPlayerPosition.h"

void WallHack::Render()
{
			GPP GetPlayerPos;
			ImGui::GetBackgroundDrawList()->AddText({ 0,0 }, ImColor{ 10, 63, 255,255 }, "EZHACKBYSCUB");

			for (int i = 0; i < 40; i++)
			{

				Vector2 Temper = GetPlayerPos.Get(i);


				if (Temper.d == -1)
					continue;
				if (Temper.x == -1)
					continue;

				char aaa[16] = { Temper.str[0], Temper.str[2],Temper.str[4], Temper.str[6], Temper.str[8] ,Temper.str[10], Temper.str[12], Temper.str[14], Temper.str[16], Temper.str[18], Temper.str[20], Temper.str[22], Temper.str[24], Temper.str[26], Temper.str[28], Temper.str[30] };


				if (Temper.d == 3)
				{

					ImGui::GetBackgroundDrawList()->AddText({ Temper.x - 30,Temper.y - 20 }, ImColor{ 255, 255, 222, 255 }, aaa);
					if (selectiedFigure == 0)
						ImGui::GetBackgroundDrawList()->AddCircle({ Temper.x,Temper.y }, 10, ImColor{ colorWhS[0],colorWhS[1],colorWhS[2],colorWhS[3] }, 12, 2);
					if (selectiedFigure == 1)
						ImGui::GetBackgroundDrawList()->AddRect({ Temper.x - 10,Temper.y + 15 }, { Temper.x + 10,Temper.y - 15 }, ImColor{ colorWhS[0],colorWhS[1],colorWhS[2],colorWhS[3] });
					if (selectiedFigure == 2)
						ImGui::GetBackgroundDrawList()->AddRectFilled({ Temper.x - 10,Temper.y + 15 }, { Temper.x + 10,Temper.y - 15 }, ImColor{ colorWhS[0],colorWhS[1],colorWhS[2],colorWhS[3] });

				}
				else if (Temper.d == 44)
				{
					ImGui::GetBackgroundDrawList()->AddText({ Temper.x - 30,Temper.y - 20 }, ImColor{ 255, 255, 222, 255 }, aaa);
					if (selectiedFigure == 0)
						ImGui::GetBackgroundDrawList()->AddCircle({ Temper.x,Temper.y }, 10, ImColor{ 255, 255, 222, 255 }, 12, 2);
					if (selectiedFigure == 1)
						ImGui::GetBackgroundDrawList()->AddRect({ Temper.x - 10,Temper.y + 15 }, { Temper.x + 10,Temper.y - 15 }, ImColor{ 255, 255, 222, 255 });
					if (selectiedFigure == 2)
						ImGui::GetBackgroundDrawList()->AddRectFilled({ Temper.x - 10,Temper.y + 15 }, { Temper.x + 10,Temper.y - 15 }, ImColor{ 255, 255, 222, 255 });

				}
				else
				{
					ImGui::GetBackgroundDrawList()->AddText({ Temper.x - 30,Temper.y - 20 }, ImColor{ 255, 255, 222, 255 }, aaa);
					if (selectiedFigure == 0)
						ImGui::GetBackgroundDrawList()->AddCircle({ Temper.x,Temper.y }, 10, ImColor{ colorWh[0],colorWh[1],colorWh[2],colorWh[3] }, 12, 2);
					if (selectiedFigure == 1)
						ImGui::GetBackgroundDrawList()->AddRect({ Temper.x - 10,Temper.y + 15 }, { Temper.x + 10,Temper.y - 15 }, ImColor{ colorWh[0],colorWh[1],colorWh[2],colorWh[3] });
					if (selectiedFigure == 2)
						ImGui::GetBackgroundDrawList()->AddRectFilled({ Temper.x - 10,Temper.y + 15 }, { Temper.x + 10,Temper.y - 15 }, ImColor{ colorWh[0],colorWh[1],colorWh[2],colorWh[3] });

				}				
				
		}
		
}