#include "stdafx.h"
#include "gameover.h"


void CGameOver::Init(CTexture Texture, D3DXVECTOR3 vPos)
{
	g_DxSprite = new CSprite;
	g_DxSprite->Create(CDevice::GetSprite());
	
	g_Texture = Texture;
	
	g_vPos = vPos;
	
	g_rect.left = 0;
	g_rect.top = 0;
	g_rect.right  = 1024;
	g_rect.bottom = 768;
}


void CGameOver::Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	g_DxSprite->Draw(g_Texture.GetTexture(), &g_rect, NULL, NULL, 0, &g_vPos, color);
}