#pragma once


class CRoad_Flatland 
{
public:
	CSprite*			r_DxSprite;
	LPD3DXSPRITE		r_Sprite;
	CTexture			r_Texture;
	CTexture			r_Texture2;
	D3DXVECTOR3			r_vPos;
	RECT				r_rect;

	D3DXVECTOR3			rc_vPos;
	RECT				rc_rect;

	DWORD				r_dTimeBegin;
	DWORD				r_dTimeEnd;

	D3DXVECTOR3			c_vPos;

public:
	CRoad_Flatland();

	void				Render(bool boost);
	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos, D3DXVECTOR3 vPos2);
	void				Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide);
	void				Move(D3DXVECTOR3 vPos);
};


class CRoad_Slope1
{
public:
	CSprite*			r_DxSprite;
	LPD3DXSPRITE		r_Sprite;
	CTexture			r_Texture;
	CTexture			r_Texture2;
	D3DXVECTOR3			r_vPos;
	RECT				r_rect;

	LPDIRECT3DTEXTURE9	r_Mono;

	D3DXVECTOR3			rc_vPos;
	D3DXVECTOR3			rc_Line[2];
	RECT				rc_rect;

	DWORD				r_dTimeBegin;
	DWORD				r_dTimeEnd;

	D3DXVECTOR3			c_vPos;

public:
	CRoad_Slope1();

	void				Render(bool boost);
	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos, D3DXVECTOR3 Line1, D3DXVECTOR3 Line2);
	void				Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide);
	void				Move(D3DXVECTOR3 vPos);
};