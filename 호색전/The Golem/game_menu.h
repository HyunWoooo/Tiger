#pragma once
#include "menu.h"

class CGame_Menu
{
public:
	CTexture		g_Menufile;
	CTexture		g_Background;

	CMenu			g_Menu;

public:
	int				Render();
	int				UpDate();
	int				Check();
	void			Destroy();
	int				Stage_State(int state);

	HRESULT			InitD3D();

	int				STAGESTATE;
};