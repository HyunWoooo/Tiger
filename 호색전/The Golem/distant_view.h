#pragma once
#include "stdafx.h"

class CBackGround
{
public:
	CSprite*			b_DxSprite;
	LPD3DXSPRITE		b_Sprite;
	CTexture			b_Texture;
	CTexture			b_Texture2;
	D3DXVECTOR3			b_vPos;
	D3DXVECTOR3			b_vPos2;
	RECT				b_rect;

	DWORD				b_dTimeBegin;
	DWORD				b_dTimeEnd;

public:
	CBackGround();	

	void				Render(bool boost);
	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos);
	void				Frame(D3DXVECTOR3 vPos, bool end);
};