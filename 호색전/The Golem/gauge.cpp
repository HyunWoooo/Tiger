#include "stdafx.h"
#include "gauge.h"


///////////////////////////////////////////////////////////////
//							CE_gauge						 //
///////////////////////////////////////////////////////////////


void CE_gauge::Init(CTexture Texture, D3DXVECTOR3 vPos)
{
	g_DxSprite = new CSprite;
	g_DxSprite->Create(CDevice::GetSprite());

	g_Texture = Texture;
	
	g_vPos = vPos;
	
	g_rect.left = 0;
	g_rect.top = 0;
	g_rect.right  = 134;
	g_rect.bottom = 17;
}


void CE_gauge::Move(D3DXVECTOR3 vPos)
{
	g_vPos = vPos + D3DXVECTOR3(57,-23,0);
	g_vPos2 = vPos + D3DXVECTOR3(57,-46,0);
}


void CE_gauge::Render(bool slide)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(slide == true)
	{
		g_DxSprite->Draw(g_Texture.GetTexture(), &g_rect, NULL, &D3DXVECTOR3(67,8,0), -10, &g_vPos, color);
		g_DxSprite->Draw(g_Texture.GetTexture(), &g_rect, NULL, &D3DXVECTOR3(67,8,0), -10, &g_vPos2, color);
	}
	else
	{
		g_DxSprite->Draw(g_Texture.GetTexture(), &g_rect, NULL, NULL, 0, &g_vPos, color);
		g_DxSprite->Draw(g_Texture.GetTexture(), &g_rect, NULL, NULL, 0, &g_vPos2, color);
	}
}


///////////////////////////////////////////////////////////////
//							CF_gauge						 //
///////////////////////////////////////////////////////////////


CF_gauge::CF_gauge()
{
	g_dTimeBegin = timeGetTime();
}



void CF_gauge::Init(CTexture Texture, D3DXVECTOR3 vPos)
{
	g_DxSprite = new CSprite;
	g_DxSprite->Create(CDevice::GetSprite());

	g_Texture = Texture;
	
	g_vPos = vPos;
	
	g_rect.left = 0;
	g_rect.top = 0;
	g_rect.right  = 0;
	g_rect.bottom = 11;
}


void CF_gauge::Charge(bool charge)
{
	g_dTimeEnd = timeGetTime();
	if(charge == true)
	{
		g_rect.right+=32;
	}

	if(g_rect.right >=128) // 부스터가 다 찼을때 게이지 초기화,부스터 조건 만족
	{
		g_rect.right = 128;
	}

	if(c_booster == true)
	{
		if((g_dTimeEnd - g_dTimeBegin) > 30)
		{
			g_rect.right = g_rect.right - 1;
			g_dTimeBegin = g_dTimeEnd;
		}
		if(g_rect.right <=0)
		{
			g_rect.right = 0;
			c_booster = false;
		}
	}
}


void CF_gauge::Move(D3DXVECTOR3 vPos)
{
	g_vPos = vPos + D3DXVECTOR3(60,-20,0);
}


void CF_gauge::Key_Act()
{
	if(GetAsyncKeyState('Z') & 0x8000)
		c_booster = true;
	if((GetAsyncKeyState('Z') & 0x8000) == 0)
		c_booster = false;
}


void CF_gauge::Render(bool slide)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(slide == true)
		g_DxSprite->Draw(g_Texture.GetTexture(), &g_rect, NULL, &D3DXVECTOR3(67,8,0), -10, &g_vPos, color);
	else
		g_DxSprite->Draw(g_Texture.GetTexture(), &g_rect, NULL, NULL, 0, &g_vPos, color);
}


///////////////////////////////////////////////////////////////
//							CT_gauge						 //
///////////////////////////////////////////////////////////////


CT_gauge::CT_gauge()
{
	g_dTimeBegin = timeGetTime();
}


void CT_gauge::Init(CTexture Texture, D3DXVECTOR3 vPos)
{
	g_DxSprite = new CSprite;
	g_DxSprite->Create(CDevice::GetSprite());

	g_Texture = Texture;
	
	g_vPos = vPos;
	
	g_rect.left = 0;
	g_rect.top = 0;
	g_rect.right  = 0;
	g_rect.bottom = 11;
}


void CT_gauge::Charge(bool charge)
{
	g_dTimeEnd = timeGetTime();

	if(charge == true)
	{
		g_rect.right = 128;
	}

	if(c_trigger == true)
	{
		if((g_dTimeEnd - g_dTimeBegin) > 30)
		{
			g_rect.right = g_rect.right - 1;
			g_dTimeBegin = g_dTimeEnd;
		}
		if(g_rect.right <=0)
		{
			g_rect.right = 0;
			c_trigger = false;
		}
	}
}


void CT_gauge::Move(D3DXVECTOR3 vPos)
{
	g_vPos = vPos + D3DXVECTOR3(60,-43,0);
}


void CT_gauge::Key_Act()
{
	if(g_rect.right == 128)
	{
		if(GetAsyncKeyState('X') & 0x8000)
			c_trigger = true;
	}
}


void CT_gauge::Render(bool slide)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(slide == true)
		g_DxSprite->Draw(g_Texture.GetTexture(), &g_rect, NULL, &D3DXVECTOR3(67,8,0), -10, &g_vPos, color);
	else
		g_DxSprite->Draw(g_Texture.GetTexture(), &g_rect, NULL, NULL, 0, &g_vPos, color);
}