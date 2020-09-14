#pragma once
#include "MenuClasses.h"
#include "Includes.h"
#pragma region bools
//==========================
void BBMenu(LPDIRECT3DDEVICE9 pD3D9)
{
	if (MV.Bouton.Silhouettes)
	{
		SelfBools.Silhouettes = true;
	}
	else
	{
		SelfBools.Silhouettes = false;
	}
}
#pragma endregion