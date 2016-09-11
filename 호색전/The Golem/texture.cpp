#include "stdafx.h"


CTexture::CTexture()
{
}


CTexture::~CTexture()
{
}



INT	CTexture::Init(LPCTSTR	lpszFileName)
{
	D3DXIMAGE_INFO	pImgInf;

	if( FAILED( D3DXCreateTextureFromFileEx(
		CDevice::GetDevice()
		, lpszFileName
		, D3DX_DEFAULT
		, D3DX_DEFAULT
		, 1
		, 0
		, D3DFMT_UNKNOWN
		, D3DPOOL_MANAGED
		, 0x0000001
		, 0x0000001
		, 0xFFCC00CC
		, &pImgInf
		, NULL
		, &m_pTexture
		)) )
	{
		MessageBox(NULL, "Texture file Could not find", "Err", 0);
		m_pTexture = NULL;
		return -1;
	}
	return 0;
}


INT CTexture::GetImageHeight()
{
	return m_Img.Height;
}


void	CTexture::CleanUp()
{
	SAFE_RELEASE(m_pTexture);
}