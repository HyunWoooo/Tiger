#include "stdafx.h"
#include "item.h"


///////////////////////////////////////////////////////////////
//							CGarlic							 //
///////////////////////////////////////////////////////////////



CGarlic::CGarlic()
{
	i_dTimeBegin = timeGetTime();
}


void CGarlic::Init(CTexture Texture, D3DXVECTOR3 vPos)
{
	i_DxSprite = new CSprite;
	i_DxSprite->Create(CDevice::GetSprite());

	i_Texture = Texture;
	
	i_vPos = vPos;
	
	i_rect.left = 0;
	i_rect.top = 0;
	i_rect.right  = 100;
	i_rect.bottom = 100;
}


void CGarlic::Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide)
{
	i_dTimeEnd = timeGetTime();

	if(c_vPos.x >= 300)
	{
		if((i_dTimeEnd - i_dTimeBegin) > 28)
		{
			if(booster == true)
			{
				i_vPos.x = i_vPos.x - (speed * 2);
				if(slide ==true)
					i_vPos.y = i_vPos.y - booster_speed_y;
			}
			else
			{
				i_vPos.x = i_vPos.x - speed;
				if(slide ==true)
					i_vPos.y = i_vPos.y - speed_y;
			}

			i_dTimeBegin = i_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		i_vPos.x = i_vPos.x + 5;
	}

	if(c_vPos.y < 495)
	{
		if(c_vPos.y >= 495)
			;
		else
			i_vPos.y = i_vPos.y + 1;
	}

	else if(c_vPos.y > 505)
	{
		if(c_vPos.y <= 505)
			;
		else
			i_vPos.y = i_vPos.y - 3;
	}
}


void CGarlic::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CGarlic::Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	i_DxSprite->Draw(i_Texture.GetTexture(), &i_rect, NULL, NULL, 0, &i_vPos, color);
}


///////////////////////////////////////////////////////////////
//							CBeef							 //
///////////////////////////////////////////////////////////////



CBeef::CBeef()
{
	i_dTimeBegin = timeGetTime();
}


void CBeef::Init(CTexture Texture, D3DXVECTOR3 vPos)
{
	i_DxSprite = new CSprite;
	i_DxSprite->Create(CDevice::GetSprite());

	i_Texture = Texture;
	
	i_vPos = vPos;
	
	i_rect.left = 0;
	i_rect.top = 0;
	i_rect.right  = 100;
	i_rect.bottom = 100;
}


void CBeef::Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide)
{
	i_dTimeEnd = timeGetTime();

	if(c_vPos.x >= 300)
	{
		if((i_dTimeEnd - i_dTimeBegin) > 28)
		{
			if(booster == true)
			{
				i_vPos.x = i_vPos.x - (speed * 2);
				if(slide ==true)
					i_vPos.y = i_vPos.y - booster_speed_y;
			}
			else
			{
				i_vPos.x = i_vPos.x - speed;
				if(slide ==true)
					i_vPos.y = i_vPos.y - speed_y;
			}

			i_dTimeBegin = i_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		i_vPos.x = i_vPos.x + 5;
	}

	if(c_vPos.y < 495)
	{
		if(c_vPos.y >= 495)
			;
		else
			i_vPos.y = i_vPos.y + 1;
	}

	else if(c_vPos.y > 505)
	{
		if(c_vPos.y <= 505)
			;
		else
			i_vPos.y = i_vPos.y - 3;
	}
}


void CBeef::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CBeef::Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	i_DxSprite->Draw(i_Texture.GetTexture(), &i_rect, NULL, NULL, 0, &i_vPos, color);
}


///////////////////////////////////////////////////////////////
//							CEat							 //
///////////////////////////////////////////////////////////////


CEat::CEat()
{
	e_dTimeBegin = timeGetTime();
	e_Eat = false;
}


void CEat::Init(CTexture Texture)
{
	e_DxSprite = new CSprite;
	e_DxSprite->Create(CDevice::GetSprite());
	
	e_Texture = Texture;
	
	e_rect.left = 0;
	e_rect.top = 0;
	e_rect.right  = 128;
	e_rect.bottom = 128;
}


void CEat::Frame()
{
	e_dTimeEnd = timeGetTime();

	if((e_dTimeEnd - e_dTimeBegin) > 50 && e_Eat == true)
	{
		e_rect.left = e_rect.left + 128;

		if(e_rect.left + 128 >= 1024)
		{
			e_rect.left = 0;
			e_Eat = false;
		}

		e_rect.right = e_rect.left +128;
		e_dTimeBegin = e_dTimeEnd;
	}
}


void CEat::Move(D3DXVECTOR3 vPos)
{
	e_vPos = vPos;
	e_Eat = true;
}


void CEat::Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(e_Eat == true)
		e_DxSprite->Draw(e_Texture.GetTexture(), &e_rect, NULL, NULL, 0, &e_vPos, color);
}