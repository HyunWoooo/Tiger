#include "stdafx.h"
#include "menu.h"


CMenu::CMenu()
{
	SelectNum = 1;
	WorldNum = 0;
}


void CMenu::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos, D3DXVECTOR3 vPos2)
{
	m_DxSprite = new CSprite;
	m_DxSprite->Create(CDevice::GetSprite());

	m_Texture = Texture;
	m_Texture2 = Texture2;
	
	m_vPos = vPos;
	m_vPos2 = vPos2;
	
	m_rect.left	= 0;
	m_rect.top = 0;
	m_rect.right = 200;
	m_rect.bottom = 100;

	m_rect2.left = 0;
	m_rect2.top = 0;
	m_rect2.right = 1024;
	m_rect2.bottom = 768;
}


void CMenu::Render(int left, int top, int right, int bottom, D3DXVECTOR3 vPos)
{
	m_rect.left	= left;
	m_rect.top	= top;
	m_rect.right = right;
	m_rect.bottom = bottom;

	m_vPos = vPos;

	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	m_DxSprite->Draw(m_Texture.GetTexture(), &m_rect, NULL, NULL, 0, &m_vPos, color);
}


void CMenu::B_Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	m_DxSprite->Draw(m_Texture2.GetTexture(), &m_rect2, NULL, NULL, 0, &m_vPos2, color);
}


void CMenu::Check()
{
	WorldNum = 0;
}


void CMenu::KeyDown()
{
	if((GetAsyncKeyState(VK_DOWN) & 0x8000) && SelectNum == 1)
		SelectNum++;

	if((GetAsyncKeyState(VK_UP) & 0x8000) && SelectNum == 2)
		SelectNum--;
	
	if(GetAsyncKeyState('Z') & 0x8000)
	{
		switch(SelectNum) {
		case 1:
			WorldNum = 1;
			break;
		case 2:
			PostQuitMessage(0);
			break;
		}
	}
}