#include <Windows.h>
#include "min_hook/include/MinHook.h"

DWORD WINAPI DirectXInit(__in  LPVOID lpParameter);
unsigned WINAPI sStarting(LPVOID lpParam);

void c_imgui_halt(void);

void c_imgui_unhook(void)
{
	c_imgui_halt();
}

BOOL WINAPI DllMain(const HINSTANCE instance, const DWORD reason, const LPVOID reserved) {
	switch (reason) {
	case DLL_PROCESS_ATTACH: 
	{
		DisableThreadLibraryCalls(instance); // disable unwanted thread notifications to reduce overhead
		CreateThread(0, 0, DirectXInit, 0, 0, 0); //init our hooks
		CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)sStarting, 0, 0, 0));
	} break;

	case DLL_PROCESS_DETACH: {
		if (!reserved)
			if (MH_Uninitialize() != MH_OK) { return 1; }
		c_imgui_unhook();
	} break;

	default: break;
	}

	return TRUE;
}