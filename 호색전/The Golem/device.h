#pragma once

class CDevice
{
public:
	HWND					m_hWnd;
	UINT					m_Width, m_Height;
	BOOL					m_bWindow;

	LPDIRECT3D9             m_pD3D;
	LPDIRECT3DDEVICE9       m_pd3dDevice;
	LPD3DXSPRITE			m_pd3dSprite;

public:	
	static CDevice* GetInstance();

	CDevice() : m_pD3D(NULL), m_pd3dDevice(NULL), m_pd3dSprite(NULL), m_bWindow(TRUE){};
	~CDevice();

	INT Init(HWND hWnd, UINT Width, UINT Height);

	static HWND GetHWND() {return GetInstance()->m_hWnd;};
	static LPDIRECT3DDEVICE9 GetDevice() {return GetInstance()->m_pd3dDevice;};
	static LPD3DXSPRITE GetSprite() {return GetInstance()->m_pd3dSprite;};
};