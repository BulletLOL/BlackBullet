/*#pragma once
#include "Windows.h"
#include <assert.h> 
#include <vector> 
#include "intrin.h"
#include <cstdlib> 
#include <iostream>
#include <assert.h> 
#include <d3d9.h>
#include <d3dx9.h>
#include <map> 
#include <list>
#include <string>
#include <array>
#include <cstdarg>
#include <utility>
#include <random>
#include <string>
#include "cMath.h"
#include "cClasses.h"
#include "Vmt.h"

ptHook cHookUpdater;

bool __stdcall p_hook_enabled(ISystem* iSsystem, int itns, int rega)
{

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
BOOL APIENTRY DllMains(HMODULE hInst, DWORD pReason, LPVOID lPereset)
{
	if (pReason == DLL_PROCESS_ATTACH)
	{
		CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)sStarting, 0, 0, 0));

	}
	return TRUE;
}*/