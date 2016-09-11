#pragma once


class CLoading
{
public:
	CSprite*			l_DxSprite;
	CTexture			l_Texture;
	D3DXVECTOR3			l_vPos;
	RECT				l_rect;

	CTexture			l_Texture2;
	D3DXVECTOR3			l_vPos2;
	RECT				l_rect2;
						
	DWORD				l_dTimeBegin;
	DWORD				l_dTimeEnd;

public:
	CLoading();

	void				Render();
	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos, D3DXVECTOR3 vPos2);
};