#pragma once


class CCharacter
{
public:
	CSprite*			c_DxSprite;
	LPD3DXSPRITE		c_Sprite;
	CTexture			c_Texture;
	CTexture			c_Texture2;
	CTexture			c_Texture3;
	CTexture			c_Texture4;
	D3DXVECTOR3			c_vPos;
	D3DXVECTOR3			c_vPos_Shadow;
	D3DXVECTOR3			c_Line[2];
	RECT				c_rect;
	RECT				ca_rect;

	LPDIRECT3DTEXTURE9	m_pTexAniS;

	DWORD				c_dTimeBegin;
	DWORD				c_dTimeEnd;

	DWORD				cs_dTimeBegin;
	DWORD				cs_dTimeEnd;

	DWORD				csm_dTimeBegin;
	DWORD				csm_dTimeEnd;

	DWORD				ct_dTimeBegin;
	DWORD				ct_dTimeEnd;

	bool				c_Jump;
	int					c_Jump_Max;
	bool				c_double_Jump;
	float				c_Jump_Speed;

	bool				cg_Crash[22];
	bool				cl_Crash[6];
	bool				cl_Crash2;
	bool				cig_Crash;
	bool				ct2_Crash;
	bool				ct4_Crash;
	bool				ig_Delete[10];
	bool				ib_Delete[2];
	bool				e_Delete[3];
	bool				t1_Delete[5];
	bool				t2_Delete[5];
	bool				t3_Delete[5];
	bool				t4_Delete[5];
	bool				i_Effect[10];

	int					c_Speed;
	int					cb_Speed;
	float				Speed_y;
	float				Boost_Speed_y;

	bool				c_boost;
	bool				c_trigger;

	int					ca_State;

	bool				end;
	bool				stop;

public:
	CCharacter();	

	void				Render();
	void				Init(CTexture Texture, CTexture Texture2, CTexture Texture3, CTexture Texture4, D3DXVECTOR3 vPos);
	void				Frame();

	void				Jump(bool boost, bool trigger);

	void				Ground_Crash(D3DXVECTOR3 vPos, RECT rect, int i);
	void				Line_Crash(D3DXVECTOR3* vPos, int i);
	void				Garlic_Crash(D3DXVECTOR3 vPos, RECT rect, int i);
	void				Beef_Crash(D3DXVECTOR3 vPos, RECT rect, int i);
	void				Thron1_Crash(D3DXVECTOR3 vPos, RECT rect, int i, bool trigger);
	void				Thron2_Crash(D3DXVECTOR3 vPos, RECT rect, int i, int trap, bool trigger);
	void				Snare_Crash(D3DXVECTOR3 vPos, RECT rect, RECT rect2, int i, bool trigger);
	void				Enemy_Crash(D3DXVECTOR3 vPos, RECT rect, int i, bool trigger);
	void				End(D3DXVECTOR3 vPos, RECT rect);
	void				Ig_Check();
	void				Ib_Check();
	void				End_Check();
	void				Stop();

	void				McColor_TransColorMono(DWORD* pOut, DWORD* pIn, INT iImgW, INT iImgH);
	void				Shadow();
};