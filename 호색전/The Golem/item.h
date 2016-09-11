#pragma once


class CItem
{
public:
	CSprite*			i_DxSprite;
	CTexture			i_Texture;
	D3DXVECTOR3			i_vPos;
	RECT				i_rect;

	DWORD				i_dTimeBegin;
	DWORD				i_dTimeEnd;

	D3DXVECTOR3			c_vPos;

public:
	virtual void		Render() = 0;
	virtual void		Init(CTexture Texture, D3DXVECTOR3 vPos) = 0;
	virtual void		Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide) = 0;
	virtual void		Move(D3DXVECTOR3 vPos) = 0;
};


class CGarlic : public CItem
{
public:
	CGarlic();

	void				Render();
	void				Init(CTexture Texture, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide);
	void				Move(D3DXVECTOR3 vPos);
};


class CBeef : public CItem
{
public:
	CBeef();

	void				Render();
	void				Init(CTexture Texture, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide);
	void				Move(D3DXVECTOR3 vPos);
};


class CEat
{
public:
	CSprite*			e_DxSprite;
	CTexture			e_Texture;
	D3DXVECTOR3			e_vPos;
	RECT				e_rect;
						
	DWORD				e_dTimeBegin;
	DWORD				e_dTimeEnd;

	bool				e_Eat;

public:
	CEat();

	void				Render();
	void				Init(CTexture Texture);
	void				Frame();
	void				Move(D3DXVECTOR3 vPos);
};