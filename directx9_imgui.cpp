#include "directx9_imgui.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"
#include "min_hook/include/MinHook.h"
#include "MenuClasses.h"
#include "Function.h"
#include "BBMenu.h"

#pragma comment(lib, "libMinHook.x64.lib")

DWORD64 FindDevice(DWORD Len)
{
	DWORD64 dwObjBase = 0;

	dwObjBase = (DWORD64)LoadLibrary("d3d9.dll");
	while (dwObjBase++ < dwObjBase + Len)
	{
		if ((*(WORD*)(dwObjBase + 0x00)) == 0x06C7 && (*(WORD*)(dwObjBase + 0x06)) == 0x8689 && (*(WORD*)(dwObjBase + 0x0C)) == 0x8689) {
			dwObjBase += 2; break;
		}
	}
	return(dwObjBase);
}

DWORD64 GetDeviceAddress(int VTableIndex)
{
	PDWORD64 VTable;
	*(DWORD64*)&VTable = *(DWORD64*)FindDevice(0x128000);
	return VTable[VTableIndex];
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

DWORD WINAPI DirectXInit(__in  LPVOID lpParameter)
{
	while (GetModuleHandle("d3d9.dll") == 0)
	{
		Sleep(100);
	}

	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 d3ddev = NULL;

	HWND tmpWnd = CreateWindowA("BUTTON", "Temp Window", WS_SYSMENU | WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 300, 300, NULL, NULL, hModule, NULL);
	if (tmpWnd == NULL)
	{
		return 0;
	}

	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (d3d == NULL)
	{
		DestroyWindow(tmpWnd);
		return 0;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = tmpWnd;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	HRESULT result = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, tmpWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);
	if (result != D3D_OK)
	{
		d3d->Release();
		DestroyWindow(tmpWnd);
		return 0;
	}

#if defined _M_X64
	DWORD64* dVtable = (DWORD64*)d3ddev;
	dVtable = (DWORD64*)dVtable[0];
#elif defined _M_IX86
	DWORD* dVtable = (DWORD*)d3ddev;
	dVtable = (DWORD*)dVtable[0]; 
#endif
					
	EndScene_orig = (EndScene)dVtable[42];
	DrawIndexedPrimitive_orig = (DrawIndexedPrimitive)dVtable[82];
	Reset_orig = (Reset)dVtable[16];

	if (MH_Initialize() != MH_OK) { return 1; }
	if (MH_CreateHook((DWORD_PTR*)dVtable[42], &EndScene_hook, reinterpret_cast<void**>(&EndScene_orig)) != MH_OK) { return 1; }
	if (MH_EnableHook((DWORD_PTR*)dVtable[42]) != MH_OK) { return 1; }
	if (MH_CreateHook((DWORD_PTR*)dVtable[82], &DrawIndexedPrimitive_hook, reinterpret_cast<void**>(&DrawIndexedPrimitive_orig)) != MH_OK) { return 1; }
	if (MH_EnableHook((DWORD_PTR*)dVtable[82]) != MH_OK) { return 1; }
	if (MH_CreateHook((DWORD_PTR*)dVtable[16], &Reset_hook, reinterpret_cast<void**>(&Reset_orig)) != MH_OK) { return 1; }
	if (MH_EnableHook((DWORD_PTR*)dVtable[16]) != MH_OK) { return 1; }

#if defined _M_X64
	oWndProc = (WNDPROC)SetWindowLongPtr(FindWindowA(NULL, "Warface"), GWLP_WNDPROC, (LONG_PTR)WndProc);
#elif defined _M_IX86
	oWndProc = (WNDPROC)SetWindowLongPtr(FindWindowA(NULL, "Warface"), GWL_WNDPROC, (LONG_PTR)WndProc);
#endif


	d3ddev->Release();
	d3d->Release();
	DestroyWindow(tmpWnd);

	return 1;
}

HRESULT APIENTRY DrawIndexedPrimitive_hook(LPDIRECT3DDEVICE9 pD3D9, D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
	return DrawIndexedPrimitive_orig(pD3D9, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

bool menu;
uintptr_t gameModule;
bool show = false;
ptHook cHookUpdater;

bool __stdcall p_hook_enabled(ISystem* iSsystem, int itns, int rega) 
{
	ESP();

	return	cHookUpdater.GetOrigFuntion<bool(__stdcall*)(ISystem*, int, int)>(4)(iSsystem, itns, rega);
}


unsigned WINAPI sStarting(LPVOID lpParam)
{
	Beep(500, 1000);
	while (!GetModuleHandle("mrac64.dll")) Sleep(5000);

	cHookUpdater.bInitialize((DWORD64**)SSystemGlobalEnvironment::Singleton()->GetSystem());
	cHookUpdater.dwHookMethod((DWORD64)p_hook_enabled, 4);


	return 0L;

}

HRESULT APIENTRY EndScene_hook(LPDIRECT3DDEVICE9 pD3D9) 
{

	while (!pD3D9) { pD3D9 = pD3D9; }
	static bool init = true;
	if (init)
	{
		gameModule = (DWORD)GetModuleHandle("mrac64.dll");
		init = false;
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();

		ImGui_ImplWin32_Init(FindWindowA(NULL, "Warface"));

		ImGui_ImplDX9_Init(pD3D9);
		SelfBools.Silhouettes = true;
	}

	if (GetAsyncKeyState(VK_HOME) & 1)
	{
		BBMenu(pD3D9);
		show = !show;
	}

	if (show)
	{
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		ImGui::ShowDemoWindow();

		ImGui::GetIO().MouseDrawCursor = menu;

		ImGui::Begin("BlackBullet");
		if (ImGui::CollapsingHeader("ESP"))
		{
			ImGui::Checkbox("Silhouettes", &MV.Bouton.Silhouettes);
		}
		ImGui::End();

		ImGui::EndFrame();
		ImGui::Render();

		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	}
	return EndScene_orig(pD3D9);
}

HRESULT APIENTRY Reset_hook(LPDIRECT3DDEVICE9 pD3D9, D3DPRESENT_PARAMETERS* pPresentationParameters) 
{

	HRESULT ResetReturn = Reset_orig(pD3D9, pPresentationParameters);

	return ResetReturn;
}

void c_imgui_halt(void)
{
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}
