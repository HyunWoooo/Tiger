#pragma once


class CAltar
{
public:
	CSprite*			a_DxSprite;
	LPD3DXSPRITE		a_Sprite;
	CTexture			a_Texture;
	D3DXVECTOR3			a_vPos;
	RECT				a_rect;

	DWORD				a_dTimeBegin;
	DWORD				a_dTimeEnd;

	D3DXVECTOR3			c_vPos;

public:
	CAltar();

	void				Render(bool slide);
	void				Init(CTexture Texture, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide, bool jump, float jump_speed);
	void				Move(D3DXVECTOR3 vPos);
};