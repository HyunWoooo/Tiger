#include "stdafx.h"
#include "game_menu.h"


void CGame_Menu::Destroy()
{
	g_Menufile.CleanUp();
	STAGESTATE = 0;
}


int CGame_Menu::Render()
{
	STAGESTATE = g_Menu.WorldNum;

	if( NULL == CDevice::GetDevice() )
		return -1;

	CDevice::GetDevice()->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 0, 0 ), 1.0f, 0 );

	if( SUCCEEDED( CDevice::GetDevice()->BeginScene() ) )
	{
		g_Menu.B_Render();

		if(g_Menu.SelectNum == 1)
		{
			g_Menu.Render(0,60,190,120,D3DXVECTOR3(400,500,0));
			g_Menu.Render(210,0,400,60,D3DXVECTOR3(400,600,0));
		}

		else if(g_Menu.SelectNum == 2)
		{
			g_Menu.Render(0,0,190,60,D3DXVECTOR3(400,500,0));
			g_Menu.Render(210,60,400,120,D3DXVECTOR3(400,600,0));
		}
	}
	CDevice::GetDevice()->EndScene();
	CDevice::GetDevice()->Present( NULL, NULL, NULL, NULL );

	return 0;
}


int CGame_Menu::UpDate()
{
	g_Menu.KeyDown();

	return 0;
}


int CGame_Menu::Check()
{
	g_Menu.Check();

	return 0;
}


int CGame_Menu::Stage_State(int state)
{
	STAGESTATE = state;
	return 0;
}


HRESULT CGame_Menu::InitD3D()
{
	g_Menufile.Init("Texture/Button/Button.png");
	g_Background.Init("Texture/start_screen.png");
	g_Menu.Init(g_Menufile, g_Background, D3DXVECTOR3(0,0,0), D3DXVECTOR3(0,0,0));

	SetCursor(false);
	return S_OK;
}