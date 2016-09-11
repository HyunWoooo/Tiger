#pragma once


class CStoryboard
{
public:
	CSprite*			l_DxSprite;
	CTexture			l_Texture;
	D3DXVECTOR3			l_vPos;
	RECT				l_rect;
						
	DWORD				l_dTimeBegin;
	DWORD				l_dTimeEnd;
	bool				storyend;


public:
	CStoryboard();

	void				Render();
	void				Init(CTexture Texture, D3DXVECTOR3 vPos);
};