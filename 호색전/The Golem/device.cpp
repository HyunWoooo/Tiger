#include "stdafx.h"


CDevice::~CDevice()
{
	SAFE_RELEASE(m_pd3dDevice);
	SAFE_RELEASE(m_pD3D);
}


CDevice* CDevice::GetInstance()
{
	static CDevice Instance;
	return &Instance;
}


int CDevice::Init(HWND hWnd, UINT Width, UINT Height)
{
	m_hWnd = hWnd;
	m_Width = Width;
	m_Height = Height;

	if( NULL == ( m_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
		return -1;

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory( &d3dpp, sizeof(d3dpp) );

	d3dpp.Windowed				 = m_bWindow;
	d3dpp.SwapEffect			 = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat		 = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth		 = Width;
	d3dpp.BackBufferHeight		 = Height;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	if( FAILED( m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT
		, D3DDEVTYPE_HAL
		, m_hWnd
		, D3DCREATE_SOFTWARE_VERTEXPROCESSING
		, &d3dpp
		, &m_pd3dDevice)))
	{
		SAFE_RELEASE(m_pd3dDevice);
		SAFE_RELEASE(m_pD3D);
		return -1;
	}

	if(FAILED(D3DXCreateSprite(m_pd3dDevice, &m_pd3dSprite)))
	{
		SAFE_RELEASE(m_pd3dDevice);
		SAFE_RELEASE(m_pD3D);
		return -1;
	}

	m_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	return 0;
}