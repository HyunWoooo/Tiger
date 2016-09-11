#pragma once


class CMid_View
{
public:
	CSprite*			v_DxSprite;
	LPD3DXSPRITE		v_Sprite;
	CTexture			v_Texture;
	CTexture			v_Texture2;
	D3DXVECTOR3			v_vPos;
	D3DXVECTOR3			v_vPos2;
	RECT				v_rect;
						
	DWORD				v_dTimeBegin;
	DWORD				v_dTimeEnd;

	D3DXVECTOR3			c_vPos;

public:
	virtual void		Render(bool boost) = 0;
	virtual void		Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos) = 0;
	virtual void		Frame(bool booster, int speed, bool slide, bool jump, float jump_speed, bool end) = 0;
	virtual void		Move(D3DXVECTOR3 vPos) = 0;
};


class CMid_View1 : public CMid_View
{
public:
	CMid_View1();

	void				Render(bool boost);
	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, bool slide, bool jump, float jump_speed, bool end);
	void				Move(D3DXVECTOR3 vPos);
};


class CMid_View2 : public CMid_View
{
public:
	CMid_View2();

	void				Render(bool boost);
	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, bool slide, bool jump, float jump_speed, bool end);
	void				Move(D3DXVECTOR3 vPos);
};


class CMid_View3 : public CMid_View
{
public:
	CMid_View3();

	void				Render(bool boost);
	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos);
	void				Frame(bool booster, int speed, bool slide, bool jump, float jump_speed, bool end);
	void				Move(D3DXVECTOR3 vPos);
};