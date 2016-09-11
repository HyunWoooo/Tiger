#include "stdafx.h"
#include "loading.h"


CLoading::CLoading()
{
	l_dTimeBegin = timeGetTime();
}


void CLoading::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos, D3DXVECTOR3 vPos2)
{
	l_DxSprite = new CSprite;
	l_DxSprite->Create(CDevice::GetSprite());
	
	l_Texture = Texture;
	l_Texture2 = Texture2;
	
	l_vPos = vPos;
	l_vPos2 = vPos2;
	
	l_rect.left = 0;
	l_rect.top = 0;
	l_rect.right  = 1024;
	l_rect.bottom = 768;

	l_rect2.left = 0;
	l_rect2.top = 0;
	l_rect2.right  = 0;
	l_rect2.bottom = 768;
}


void CLoading::Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	l_dTimeEnd = timeGetTime();

	if((l_dTimeEnd - l_dTimeBegin) > 10)
	{
		l_rect2.right= l_rect2.right + 20;

		l_dTimeBegin = l_dTimeEnd;
	}

	l_DxSprite->Draw(l_Texture.GetTexture(), &l_rect, NULL, NULL, 0, &l_vPos, color);
	l_DxSprite->Draw(l_Texture2.GetTexture(), &l_rect2, NULL, NULL, 0, &l_vPos2, color);
}