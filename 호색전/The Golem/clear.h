#pragma once


class CClear
{
public:
	CSprite*			c_DxSprite;
	LPD3DXSPRITE		c_Sprite;
	CTexture			c_Texture;
	D3DXVECTOR3			c_vPos;
	RECT				c_rect;

	DWORD				c_dTimeBegin;
	DWORD				c_dTimeEnd;

	bool				Back;

public:
	void				Init(CTexture Texture, D3DXVECTOR3 vPos);
	void				Render();
	bool				Key();
};