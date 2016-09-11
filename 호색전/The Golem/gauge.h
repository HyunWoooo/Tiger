#pragma once


class CE_gauge
{
public:
	CSprite*			g_DxSprite;
	LPD3DXSPRITE		g_Sprite;
	CTexture			g_Texture;
	D3DXVECTOR3			g_vPos;
	D3DXVECTOR3			g_vPos2;
	RECT				g_rect;

public:
	void				Render(bool slide);
	void				Init(CTexture Texture, D3DXVECTOR3 vPos);
	void				Move(D3DXVECTOR3 vPos);
};

class CF_gauge
{
public:
	CSprite*			g_DxSprite;
	LPD3DXSPRITE		g_Sprite;
	CTexture			g_Texture;
	D3DXVECTOR3			g_vPos;
	RECT				g_rect;

	DWORD				g_dTimeBegin;
	DWORD				g_dTimeEnd;

	bool				c_booster;

public:
	CF_gauge();

	void				Render(bool slide);
	void				Charge(bool charge);
	void				Init(CTexture Texture, D3DXVECTOR3 vPos);
	void				Move(D3DXVECTOR3 vPos);
	void				Key_Act();
};


class CT_gauge
{
public:
	CT_gauge();

	CSprite*			g_DxSprite;
	LPD3DXSPRITE		g_Sprite;
	CTexture			g_Texture;
	D3DXVECTOR3			g_vPos;
	RECT				g_rect;

	DWORD				g_dTimeBegin;
	DWORD				g_dTimeEnd;

	bool				c_trigger;

public:
	void				Render(bool slide);
	void				Charge(bool charge);
	void				Init(CTexture Texture, D3DXVECTOR3 vPos);
	void				Move(D3DXVECTOR3 vPos);
	void				Key_Act();
};