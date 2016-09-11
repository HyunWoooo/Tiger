#pragma once


class CTrap
{
public:
	CSprite*			t_DxSprite;
	LPD3DXSPRITE		t_Sprite;
	CTexture			t_Texture;
	CTexture			t_Texture2;
	D3DXVECTOR3			t_vPos;
	RECT				t_rect;

	DWORD				t_dTimeBegin;
	DWORD				t_dTimeEnd;

	D3DXVECTOR3			c_vPos;

public:
	virtual void		Move(D3DXVECTOR3 vPos) = 0;
	virtual void		Render(bool boost) = 0;
	virtual void		Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos) = 0;
	virtual void		Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide) = 0;
};


class CThorn1 : public CTrap
{
public:
	CThorn1();
	
	void				Move(D3DXVECTOR3 vPos);
	void				Render(bool boost);
	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide);
};


class CThorn2 : public CTrap
{
public:
	CThorn2();
	
	void				Move(D3DXVECTOR3 vPos);
	void				Render(bool boost);
	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide);
};


class CThorn3 : public CTrap
{
public:
	bool				appear;
	RECT				ta_rect;
	DWORD				ta_dTimeBegin;
	DWORD				ta_dTimeEnd;

public:
	CThorn3();
	
	void				Move(D3DXVECTOR3 vPos);
	void				Appear(RECT rect);
	void				Render(bool boost);
	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide);
};


class CSnare : public CTrap
{
public:
	bool				operate;
	RECT				ta_rect;
	DWORD				ta_dTimeBegin;
	DWORD				ta_dTimeEnd;

public:
	CSnare();
	
	void				Move(D3DXVECTOR3 vPos);
	void				Operate(RECT rect);
	void				Render(bool boost);
	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide);
};