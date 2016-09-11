#pragma once


class CGameOver
{
public:
	CSprite*			g_DxSprite;
	LPD3DXSPRITE		g_Sprite;
	CTexture			g_Texture;
	D3DXVECTOR3			g_vPos;
	RECT				g_rect;
						
	DWORD				g_dTimeBegin;
	DWORD				g_dTimeEnd;

	bool				Back;

public:
	void				Init(CTexture Texture, D3DXVECTOR3 vPos);
	void				Render();
	bool				Key();
};