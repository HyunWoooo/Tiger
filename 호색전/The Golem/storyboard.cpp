#include "stdafx.h"
#include "storyboard.h"

CStoryboard::CStoryboard()
{
	l_dTimeBegin = timeGetTime();
}

void CStoryboard::Init(CTexture Texture, D3DXVECTOR3 vPos)
{
	l_DxSprite = new CSprite;
	l_DxSprite->Create(CDevice::GetSprite());
	
	l_Texture = Texture;
	
	l_vPos = vPos;
	
	l_rect.left = -1024;
	l_rect.top = 0;
	l_rect.right  = 0;
	l_rect.bottom = 768;
}


void CStoryboard::Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	l_dTimeEnd = timeGetTime();
	
	if((l_dTimeEnd - l_dTimeBegin) > 1500)
	{
		l_rect.left = l_rect.left + 1024;
	
		if(l_rect.left >= 8192)
		{
			l_rect.left=0;
			l_rect.bottom= l_rect.bottom + 768;
			l_rect.top=l_rect.top + 768;
		}

		l_rect.right = l_rect.left +1024;

		if(l_rect.bottom == 3072)
			storyend = true;
		
		l_dTimeBegin = l_dTimeEnd;
	}
	

	l_DxSprite->Draw(l_Texture.GetTexture(), &l_rect, NULL, NULL, 0, &l_vPos, color);
}