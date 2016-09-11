#pragma once


class CMenu
{
public:
	CSprite*			m_DxSprite;
	LPD3DXSPRITE		m_Sprite;
	CTexture			m_Texture;
	D3DXVECTOR3			m_vPos;
	RECT				m_rect;

	CTexture			m_Texture2;
	D3DXVECTOR3			m_vPos2;
	RECT				m_rect2;

	int					SelectNum;
	int					WorldNum;

public:
	CMenu();

	void				Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos, D3DXVECTOR3 vPos2);
	void				Render(int left, int top, int right, int bottom, D3DXVECTOR3 vPos);
	void				B_Render();
	void				Move();
	void				KeyDown();
	void				Check();
};