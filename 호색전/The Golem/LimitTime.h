#pragma once


class CLimittime
{
private:
	LPD3DXSPRITE		m_Sprite;
	CTexture			m_Texture;
	D3DXVECTOR3			m_vPos;
	
	RECT				m_rect;
	RECT				m_rect2;

	DWORD				TimeBegin;
	DWORD				TimeEnd;

	bool				TEnd;
	
	//���Ǵ���
	D3DXVECTOR3			m_vPos2;
	LPD3DXSPRITE		m_Sprite2;
	CTexture			m_Texture2;	
	RECT				m_rect3;
	RECT				m_rect4;

	BOOL				nc;// 1�� �ڸ��� 0�Ǵ��� Ȯ��
	int					norc;

public:
	CLimittime();


	void				tRender();
	void				oRender();
	void				tInit(CTexture Texture, D3DXVECTOR3 vPos);
	void				oInit(CTexture Texture, D3DXVECTOR3 vPos2);
	bool				everyEnd;
	
	
};