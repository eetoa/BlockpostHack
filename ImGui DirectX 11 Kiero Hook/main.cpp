#include "includes.h"
#include "Settings.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "framework/il2cpp-init.h"
#include "WallHack.h"
#include "Freecam.h";
#include "framework/il2cpp-appdata.h"
#include "Cross.h"
#include "Crash.h"
#include "Skeleton.h"
#include "Tracer.h"
#define WIN32_LEAN_AND_MEAN
#define EntListBase 0xB35C3C
#define EntListBase2 0xB35CA8


Tracer tracer;
Skeleton skelet;
Crash crash;
CrossH cros;
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
USettings Settings;
Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
bool show = true;
bool initOnce = false;
AimBot aim;
WallHack wall;
FreeCam freeca;
const char* config1 = "config1";
const char* config2 = "config2";
const char* config3 = "config3";
static int tab = 3;
static int tabb = 4;
bool init = false;
bool DrawWatermark = true;
static const char* Croshairs[8]{ "DEFOLT", "WITH A DOT","DOT","WITHOUT LINE UP","DA","2 LINE","SACK","STRENG DOT" };
static const char* Figure[4]{ "Circle", "Rect","RectFilled","Rect (Regular)" };
static const char* cfg[3]{ config1, config2,config3 };
static int selectiedCfg = 0;


void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}
BOOL __stdcall StartThread(HMODULE hModule, LPTHREAD_START_ROUTINE StartAddress)
{
	return CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, hModule, 0, 0));
}
app::PlayerData* GetPlayerDataSSS(UINT32 i)
{

	offsetsM offsets;
	uintptr_t baseModule = reinterpret_cast<uintptr_t>(GetModuleHandle(TEXT("GameAssembly.dll")));
	app::PlayerData* anus = (app::PlayerData*)offsets.GetPointerAddress(baseModule + EntListBase2, { 0x5C,0x0C, 0x10 + i * 0x4,0x0 });
	return anus;
}
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	if (GetAsyncKeyState(KEYMENY) & 1)
	{
		show = !show;
	}
	if (show)
	{

		ImGui::Begin("BLOCKPOST-US");
		if (ImGui::Button((u8"Aim"), ImVec2(100.f, 0.f)))
			tabb = 0;
		ImGui::SameLine(0.f, 2.f);
		if (ImGui::Button((u8"Visuals"), ImVec2(100.f, 0.f)))
			tabb = 1;
		ImGui::SameLine(0.f, 2.f);
		if (ImGui::Button((u8"Misc"), ImVec2(100.f, 0.f)))
			tabb = 2;
		ImGui::SameLine(0.f, 2.f);
		if (ImGui::Button((u8"Info"), ImVec2(100.f, 0.f)))
			tabb = 3;
		ImGui::SameLine(0.f, 2.f);
		if (ImGui::Button((u8"CFG"), ImVec2(100.f, 0.f)))
			tabb = 4;
		if (tabb == 0) {
			ImGui::Checkbox("AimBot", &Settings.AimActive);
			ImGui::Checkbox("AimBotKey", &Settings.AimKeyActive);
			ImGui::Checkbox("TeamCheck", &Settings.TeamCheck);
			ImGui::SliderFloat("Distance", &Settings.Dinstace, 1, 250);
			ImGui::SliderFloat("Fov", &Settings.fov, 2.8, 360);
		}
		else if (tabb == 1) {
			ImGui::Checkbox("WallHack", &Settings.Wallhack);
			ImGui::Checkbox("TeamCheck", &Settings.TeamCheck);
			ImGui::ColorEdit3("WallHackColor", wall.colorWh);
			ImGui::ColorEdit3("WallHackColorInSpawnProtect", wall.colorWhS);
			ImGui::Checkbox("Tracer", &Settings.Tracer);
			ImGui::SliderFloat("LineSize", &Settings.LineSize, 0, 10);
			ImGui::ColorEdit3("ColorTracer", tracer.colorTracer);
			ImGui::Combo("figure", &wall.selectiedFigure, Figure, 4);
			ImGui::Checkbox("Skelet", &Settings.Skelet);
			ImGui::ColorEdit3("ColorSkelet", skelet.colorSkelet);
			ImGui::ColorEdit3("ColorSkeletSpawnProtect", skelet.colorSkeletS);


		}
		else if (tabb == 2) {
			ImGui::Checkbox("AntiCrash", &Settings.AntiCrash);
			ImGui::Checkbox("Crash  (BUTTON 4)", &Settings.Crash);
			ImGui::Checkbox("Freecam  ", &Settings.FreeCam);
			ImGui::Checkbox("FackeDuck  ", &Settings.Duck);
			ImGui::Checkbox("SpeedBoost  ", &Settings.SpeedBoost);
			ImGui::Checkbox("NoFreez  ", &Settings.NoFreez);
			ImGui::Checkbox("NoReload ", &Settings.NoReload);
			ImGui::ListBox("CrossHair", &cros.selectItemDa, Croshairs, 8, 2);
		}
		else if (tabb == 3)
		{
			ImGui::Checkbox("Discord", &Settings.Discord);
			ImGui::Checkbox("YouTube", &Settings.YouTube);
		}
		else if (tabb == 4)
		{
			ImGui::Combo("CFG", &selectiedCfg, cfg, 3);
			if (ImGui::Button("Save", ImVec2(100.f, 0.f)))
				Settings.saveconfig = true;
			ImGui::SameLine(0.f, 2.f);
			if (ImGui::Button("Load", ImVec2(100.f, 0.f)))
				Settings.LoadConfig = true;
			ImGui::SameLine(0.f, 2.f);
			if (ImGui::Button("Delete", ImVec2(100.f, 0.f)))
				Settings.DeleteConfig = true;
		}
		if (Settings.Wallhack)
			wall.Render();
		if (Settings.Skelet)
			skelet.Render();
		if (Settings.Tracer)
			tracer.Render();

		ImGui::End();

		ImGui::Render();
	}
	else
	{
		ImGui::Begin("dasdas", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse |
			ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar);
		if (Settings.Wallhack)
			wall.Render();
		if (Settings.Skelet)
			skelet.Render();
		if (Settings.Tracer)
			tracer.Render();


		ImGui::End();
		ImGui::Render();
	}


	ImGui::EndFrame();
	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}


DWORD WINAPI FreeCamThread(HMODULE hMod)
{
	
	int i = 0;
	FreeCam free;
	while (true)
	{
		
		tracer.LineSize = Settings.LineSize;
		cros.Render();		
		app::Controll__StaticFields* da = (*app::Controll__TypeInfo)->static_fields; // saksak 
		app::Crosshair__StaticFields* cross = (*app::Crosshair__TypeInfo)->static_fields; // saksak
		
	
		
		cross->crosshair_attack = 0;
		
		if (Settings.Duck)
		{
			da->inDuck = true;
			da->boxheight = 1.89;
		}
		if (Settings.NoFreez)
		{
			da->inStuck = false;
			da->inFreeze = false;
		}
		if (Settings.SpeedBoost)
			da->default_speed = 0.55f;	
		else
		{
			da->default_speed = 0.5f;
		}
		if (Settings.NoReload)
			da->inReload = false;
	
		
		
		

		if (Settings.Crash)
		{
			crash.Render();
			crash.active = true;
		}
		else
		{			
			crash.Render();
			crash.active = false;
		}
		if (Settings.FreeCam)
		{
			if(GetAsyncKeyState(0x58) & 1)
			free.Render();
		}
		if (Settings.Discord)
		{
			ShellExecute(NULL, "open", "https://discord.gg/QwYW3vMN", NULL, NULL, SW_SHOW);
			Settings.Discord = false;
		}
		if (Settings.YouTube)
		{
			ShellExecute(NULL, "open", "www.youtube.com/channel/UC-jF6GNJZiaNY4SFKfjrNGw?sub_confirmation=1", NULL, NULL, SW_SHOW);
			Settings.YouTube = false;
		}
	}
	
	FreeLibraryAndExitThread(hMod, 0);
}
DWORD WINAPI FunctTread(HMODULE hMod)
{
	
	app::Main__StaticFields* main = (*app::Main__TypeInfo)->static_fields;
	AutomaticW asdddd; 
	asdddd.Render();
	
	
	main->winter = true;
	main->winter = 1;
	while (true)
	{
		
		
		aim.fov = 2+atan(aim.dist) * Settings.fov;
		aim.distanceFov = Settings.Dinstace;
		
		if (Settings.AimActive)
		{
			
			aim.Render();
		}
		if (Settings.AimKeyActive)
		{
			
			aim.toggle = true;
		}
		else
		{
			
			aim.toggle = false;
		}
		if (Settings.TeamCheck)
		{
			aim.teamcheck = true;
			wall.teamcheck = true;
			skelet.teamcheck = true;
			tracer.teamcheck = true;
		}
		else
		{
			aim.teamcheck = false;
			wall.teamcheck = false;
			skelet.teamcheck = false;
			tracer.teamcheck = false;
		}
		if (Settings.AntiCrash)
		{
			DWORD OldProtection;
			uintptr_t baseModule = reinterpret_cast<uintptr_t>(GetModuleHandle(TEXT("GameAssembly.dll")));
			uintptr_t RsolverCrash = baseModule + 0x157100;
			VirtualProtect((LPVOID)RsolverCrash, 4, 0x40, &OldProtection);
			BYTE* antcrash = reinterpret_cast<BYTE*>(RsolverCrash);
			*antcrash = 0xC3;
		}
		else
		{
			DWORD OldProtection;
			uintptr_t baseModule = reinterpret_cast<uintptr_t>(GetModuleHandle(TEXT("GameAssembly.dll")));
			uintptr_t RsolverCrash = baseModule + 0x157100;
			VirtualProtect((LPVOID)RsolverCrash, 4, 0x40, &OldProtection);
			BYTE* antcrash = reinterpret_cast<BYTE*>(RsolverCrash);
			*antcrash = 0x80,0x3D,0x9F,0xAA,0x69,0x7A,0x00;
		}
	
		Sleep(100);
	}

	

	FreeLibraryAndExitThread(hMod, 0);
}

DWORD WINAPI ConfigThread(HMODULE hMod)
{
	while (true)
	{
		if (Settings.saveconfig)
		{
			std::ofstream out1("cfg1.txt");
			out1 << Settings.AimActive << std::endl << Settings.AimKeyActive << std::endl << Settings.Crash << std::endl << Settings.Dinstace << std::endl << Settings.espTeamCheck << std::endl << Settings.fov << std::endl << Settings.FreeCam << std::endl << Settings.LineSize << std::endl << Settings.TeamCheck << std::endl << Settings.Tracer << std::endl << Settings.Wallhack << std::endl << tracer.colorTracer[0] << std::endl << tracer.colorTracer[1] << std::endl  << tracer.colorTracer[2] << std::endl  << tracer.colorTracer[3] << std::endl << wall.colorWh[0] << std::endl << wall.colorWh[1] << std::endl << wall.colorWh[2] << std::endl << wall.colorWh[3] << std::endl << wall.colorWhS[0] << std::endl << wall.colorWhS[1] << std::endl << wall.colorWhS[2] << std::endl << wall.colorWhS[3]   << std::endl << cros.selectItemDa << std::endl << Settings.Duck << std::endl << Settings.NoFreez << std::endl << Settings.NoReload << std::endl << Settings.SpeedBoost << std::endl << wall.selectiedFigure << std::endl << Settings.Skelet;
			out1.close();
			Settings.saveconfig = false;
		}
		if (Settings.LoadConfig)
		{

			
			
			std::string index[29];
			std::size_t count = 0;
			for (std::ifstream input("cfg1.txt"); (count < 29) && std::getline(input, index[count]); ++count)
			{
				// this space intentionally blank
			}
			for (std::size_t i = 0; i < count; ++i)
			{
				
				
			}
		
			Settings.AimActive = std::stoi(index[0]);
			Settings.AimKeyActive = std::stoi(index[1]);
			Settings.Crash = std::stoi(index[2]);
			Settings.Dinstace = std::stoi(index[3]);
			Settings.espTeamCheck = std::stoi(index[4]);
			Settings.fov = std::stoi(index[5]);
			Settings.FreeCam = std::stoi(index[6]);
			Settings.LineSize = std::stoi(index[7]);
			Settings.TeamCheck = std::stoi(index[8]);
			Settings.Tracer = std::stoi(index[9]);
			Settings.Wallhack = std::stoi(index[10]);
			tracer.colorTracer[0] = std::stof(index[11]);
			tracer.colorTracer[1] = std::stof(index[12]);
			tracer.colorTracer[2] = std::stof(index[13]);
			tracer.colorTracer[3] = std::stof(index[14]);
			wall.colorWh[0] = std::stof(index[15]);
			wall.colorWh[1] = std::stof(index[16]);
			wall.colorWh[2] = std::stof(index[17]);
			wall.colorWh[3] = std::stof(index[18]);
			wall.colorWhS[0] = std::stof(index[19]);
			wall.colorWhS[1] = std::stof(index[20]);
			wall.colorWhS[2] = std::stof(index[21]);
			wall.colorWhS[3] = std::stof(index[22]);
			cros.selectItemDa = std::stof(index[23]);
			Settings.Duck = std::stof(index[24]);
			Settings.NoFreez = std::stof(index[25]);
			Settings.NoReload = std::stof(index[26]);
			Settings.SpeedBoost = std::stof(index[27]);
			wall.selectiedFigure = std::stof(index[28]);
			Settings.Skelet = std::stof(index[29]);
			Settings.LoadConfig = false;
		}
	}
	FreeLibraryAndExitThread(hMod, 0);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)& oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}


BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		init_il2cpp();
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		StartThread(nullptr, (LPTHREAD_START_ROUTINE)FunctTread);
		StartThread(nullptr, (LPTHREAD_START_ROUTINE)FreeCamThread);
		StartThread(nullptr, (LPTHREAD_START_ROUTINE)ConfigThread);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
} 