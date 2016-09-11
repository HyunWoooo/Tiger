#include "stdafx.h"
#include "stage1.h"
#include "game_menu.h"
#include "storyboard.h"


CGame_Menu	Menu;
CStage1*	Stage1;


LPSTR				lpszClass	 = "The Golem";
HINSTANCE			m_hInst		 = NULL;
HWND				m_hWnd		 = NULL;
DWORD				m_dWinStyle	 = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE;
DWORD				m_dScnX		 = 1024;
DWORD				m_dScnY		 = 768;
BOOL				m_bShowCusor = TRUE;


INT		Create(HINSTANCE hInst);
INT		Run();


LRESULT MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


LRESULT MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg )
	{
	case WM_DESTROY:
		PostQuitMessage( 0 );
		return 0;
	}
	return DefWindowProc( hWnd, msg, wParam, lParam );
}


INT Create(HINSTANCE hInst)
{
	WNDCLASS wc =
	{
		CS_CLASSDC
		, WndProc
		, 0L
		, 0L
		, m_hInst
		, NULL
		, LoadCursor(NULL,IDC_ARROW)
		, (HBRUSH)GetStockObject(LTGRAY_BRUSH)
		, NULL
		, lpszClass
	};

	RegisterClass(&wc);

	RECT rc;

	SetRect( &rc, 0, 0, m_dScnX, m_dScnY);
	AdjustWindowRect( &rc, m_dWinStyle, FALSE );

	int iScnSysW = ::GetSystemMetrics(SM_CXSCREEN);
	int iScnSysH = ::GetSystemMetrics(SM_CYSCREEN);

	m_hWnd = CreateWindow(lpszClass
		, lpszClass
		, m_dWinStyle
		, (iScnSysW - (rc.right - rc.left))/2
		, (iScnSysH - (rc.bottom - rc.top))/2
		, (rc.right - rc.left)
		, (rc.bottom - rc.top)
		, GetDesktopWindow()
		, NULL
		, m_hInst
		, NULL );

	CDevice::GetInstance()->Init(m_hWnd, m_dScnX, m_dScnY);
	CDirect_Sound::GetInstance()->CreateDirectSound(m_hWnd);

	return 0;
}


INT Run()
{
	Menu.InitD3D();

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
	::ShowCursor(m_bShowCusor);

	MSG msg;
	memset(&msg, 0, sizeof(msg));

	while(msg.message != WM_QUIT)
	{
		if(Stage1 == NULL)
		{
			Stage1 = new CStage1;
			Stage1->Loading_InitD3D();
			Stage1->Story_InitD3D();
		}

		if(PeekMessage(&msg, NULL,0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			switch(Menu.STAGESTATE)
			{
			case 0:
				if(FAILED(Menu.Render()))
					SendMessage(m_hWnd, WM_QUIT,0,0);

				if(FAILED(Menu.UpDate()))
					SendMessage(m_hWnd, WM_QUIT,0,0);

				if(Menu.STAGESTATE == 1)
					Menu.Check();
				break;
			case 1:
				if(FAILED(Menu.Stage_State(Stage1->state)))
					SendMessage(m_hWnd, WM_QUIT,0,0);

				if(FAILED(Stage1->Loading()))
					SendMessage(m_hWnd, WM_QUIT,0,0);
				break;
			case 2:
				if(FAILED(Menu.Stage_State(Stage1->state)))
					SendMessage(m_hWnd, WM_QUIT,0,0);

				if(FAILED(Stage1->Story()))
					SendMessage(m_hWnd, WM_QUIT,0,0);
					break;
			case 3:
				if(FAILED(Stage1->FrameMove()))
					SendMessage(m_hWnd, WM_QUIT,0,0);

				if(FAILED(Stage1->UpDate()))
					SendMessage(m_hWnd, WM_QUIT,0,0);

				if(FAILED(Menu.Stage_State(Stage1->state)))
					SendMessage(m_hWnd, WM_QUIT,0,0);

				if(FAILED(Stage1->Render()))
					SendMessage(m_hWnd, WM_QUIT,0,0);

				if(Stage1->end == true)
					SAFE_DELETE(Stage1);
				break;
			}
		}
	}

	UnregisterClass( lpszClass, m_hInst);
	return 0;
}


LRESULT WINAPI WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	return MsgProc(hWnd, msg, wParam, lParam);
}


INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR, INT )
{
	if(FAILED(Create(hInst)))
		return -1;

	return Run();
}