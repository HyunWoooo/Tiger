#include "stdafx.h"
#include "distant_view.h"


CBackGround::CBackGround()
{
	b_dTimeBegin = timeGetTime();
}


void CBackGround::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos)
{
	b_DxSprite = new CSprite;
	b_DxSprite->Create(CDevice::GetSprite());
	
	b_Texture = Texture;
	b_Texture2 = Texture2;
	
	b_vPos = vPos;
	b_vPos2 = b_vPos + (1024 * D3DXVECTOR3(1,0,0));
	
	b_rect.left = 0;
	b_rect.top = 0;
	b_rect.right  = 1024;
	b_rect.bottom = 1169;
}


void CBackGround::Frame(D3DXVECTOR3 vPos, bool end)
{
	b_dTimeEnd = timeGetTime();

	if(vPos.x >= 300 && end == false)
	{
		if((b_dTimeEnd - b_dTimeBegin) > 14)
		{
			b_vPos.x = b_vPos.x - 0.2f;
			b_vPos2.x = b_vPos2.x - 0.2f;
			
			if(b_vPos.x <= -1024)
				b_vPos.x = b_vPos2.x + 1024;

			else if(b_vPos2.x <= -1024)
				b_vPos2.x = b_vPos.x + 1024;

			b_dTimeBegin = b_dTimeEnd;
		}
	}
}


void CBackGround::Render(bool boost)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);


	if(boost == true)
	{
		b_DxSprite->Draw(b_Texture2.GetTexture(), &b_rect, NULL, NULL, 0, &b_vPos, color);
		b_DxSprite->Draw(b_Texture2.GetTexture(), &b_rect, NULL, NULL, 0, &b_vPos2, color);
	}
	else
	{
		b_DxSprite->Draw(b_Texture.GetTexture(), &b_rect, NULL, NULL, 0, &b_vPos, color);
		b_DxSprite->Draw(b_Texture.GetTexture(), &b_rect, NULL, NULL, 0, &b_vPos2, color);
	}
}