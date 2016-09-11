#include "stdafx.h"
#include "clear.h"


void CClear::Init(CTexture Texture, D3DXVECTOR3 vPos)
{
	c_DxSprite = new CSprite;
	c_DxSprite->Create(CDevice::GetSprite());
	
	c_Texture = Texture;
	
	c_vPos = vPos;
	
	c_rect.left = 0;
	c_rect.top = 0;
	c_rect.right  = 1024;
	c_rect.bottom = 768;
}


bool CClear::Key()
{
	if((GetAsyncKeyState('Z') & 0x8000))
	{
		Back = true;
	}

	return Back;
}


void CClear::Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	c_DxSprite->Draw(c_Texture.GetTexture(), &c_rect, NULL, NULL, 0, &c_vPos, color);
}