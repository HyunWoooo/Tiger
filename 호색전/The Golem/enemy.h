#pragma once


class CBear
{
public:
	CSprite*			e_DxSprite;
	LPD3DXSPRITE		e_Sprite;
	CTexture			e_Texture;
	D3DXVECTOR3			e_vPos;
	RECT				e_rect;

	DWORD				e_dTimeBegin;
	DWORD				e_dTimeEnd;

	D3DXVECTOR3			c_vPos;

public:
	virtual void		Move(D3DXVECTOR3 vPos) = 0;
	virtual void		Render() = 0;
	virtual void		Init(CTexture Texture, D3DXVECTOR3 vPos) = 0;
	virtual void		Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide) = 0;

};


class CBear_Stand : public CBear
{
public:
	CBear_Stand();

	void				Move(D3DXVECTOR3 vPos);
	void				Render();
	void				Init(CTexture Texture, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide);
};


class CBear_Seat : public CBear
{
public:
	CBear_Seat();

	void				Move(D3DXVECTOR3 vPos);
	void				Render();
	void				Init(CTexture Texture, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide);
};


class CKill
{
public:
	CSprite*			e_DxSprite;
	CTexture			e_Texture;
	D3DXVECTOR3			e_vPos;
	RECT				e_rect;
						
	DWORD				e_dTimeBegin;
	DWORD				e_dTimeEnd;

	bool				e_Kill;
	

public:
	CKill();

	void				Render();
	void				Init(CTexture Texture);
	void				Frame();
	void				Move(D3DXVECTOR3 vPos);
};