#pragma once

class CTexture
{
private:
	LPDIRECT3DTEXTURE9	m_pTexture;
	D3DXIMAGE_INFO		m_Img;

public:
	CTexture();
	virtual ~CTexture();

	virtual void		CleanUp();

	LPDIRECT3DTEXTURE9	GetTexture() {return m_pTexture;} 
	INT					Init(LPCTSTR lpszFileName); 
	INT					GetImageHeight();
};