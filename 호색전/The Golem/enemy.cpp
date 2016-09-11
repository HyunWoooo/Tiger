#include "stdafx.h"
#include "enemy.h"


///////////////////////////////////////////////////////////////
//						CBear_Stand							 //
///////////////////////////////////////////////////////////////


CBear_Stand::CBear_Stand()
{
}


void CBear_Stand::Init(CTexture Texture, D3DXVECTOR3 vPos)
{
	e_DxSprite = new CSprite;
	e_DxSprite->Create(CDevice::GetSprite());

	e_Texture = Texture;
	
	e_vPos = vPos;
	
	e_rect.left = 0;
	e_rect.top = 0;
	e_rect.right  = 89;
	e_rect.bottom = 157;
}


void CBear_Stand::Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide)
{
	e_dTimeEnd = timeGetTime();

	if((e_dTimeEnd - e_dTimeBegin) > 28)
	{
		if(c_vPos.x >= 300)
		{
			if(booster == true)
			{
				e_vPos.x = e_vPos.x - (speed * 2);

				if(slide == true)
				{
					e_vPos.y = e_vPos.y - booster_speed_y ;
				}
			}
			else
			{
				e_vPos.x = e_vPos.x - speed;

				if(slide == true)
					e_vPos.y = e_vPos.y - speed_y;
			}

			e_dTimeBegin = e_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		e_vPos.x = e_vPos.x + 5;
	}

	if(c_vPos.y < 495)
	{
		if(c_vPos.y >= 495)
			;
		else
			e_vPos.y = e_vPos.y + 1;
	}

	else if(c_vPos.y > 505)
	{
		if(c_vPos.y <= 505)
			;
		else
			e_vPos.y = e_vPos.y - 3;
	}
}


void CBear_Stand::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CBear_Stand::Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	e_DxSprite->Draw(e_Texture.GetTexture(), &e_rect, NULL, NULL, 0, &e_vPos, color);
}


///////////////////////////////////////////////////////////////
//						CBear_Seat							 //
///////////////////////////////////////////////////////////////


CBear_Seat::CBear_Seat()
{
}


void CBear_Seat::Init(CTexture Texture, D3DXVECTOR3 vPos)
{
	e_DxSprite = new CSprite;
	e_DxSprite->Create(CDevice::GetSprite());

	e_Texture = Texture;
	
	e_vPos = vPos;
	
	e_rect.left = 0;
	e_rect.top = 0;
	e_rect.right  = 89;
	e_rect.bottom = 157;
}


void CBear_Seat::Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide)
{
	e_dTimeEnd = timeGetTime();

	if((e_dTimeEnd - e_dTimeBegin) > 28)
	{
		if(c_vPos.x >= 400)
		{
			if(booster == true)
			{
				e_vPos.x = e_vPos.x - (speed * 2);

				if(slide == true)
				{
					e_vPos.y = e_vPos.y - booster_speed_y ;
				}
			}
			else
			{
				e_vPos.x = e_vPos.x - speed;

				if(slide == true)
					e_vPos.y = e_vPos.y - speed_y;
			}

			e_dTimeBegin = e_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		e_vPos.x = e_vPos.x + 5;
	}

	if(c_vPos.y < 495)
	{
		if(c_vPos.y >= 495)
			;
		else
			e_vPos.y = e_vPos.y + 1;
	}

	else if(c_vPos.y > 505)
	{
		if(c_vPos.y <= 505)
			;
		else
			e_vPos.y = e_vPos.y - 3;
	}
}


void CBear_Seat::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CBear_Seat::Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	e_DxSprite->Draw(e_Texture.GetTexture(), &e_rect, NULL, NULL, 0, &e_vPos, color);
}


///////////////////////////////////////////////////////////////
//							CKill							 //
///////////////////////////////////////////////////////////////


CKill::CKill()
{
	e_dTimeBegin = timeGetTime();
	e_Kill = false;
}


void CKill::Init(CTexture Texture)
{
	e_DxSprite = new CSprite;
	e_DxSprite->Create(CDevice::GetSprite());
	
	e_Texture = Texture;
	
	e_rect.left = 0;
	e_rect.top = 0;
	e_rect.right  = 200;
	e_rect.bottom = 200;
}


void CKill::Frame()
{
	e_dTimeEnd = timeGetTime();

	if((e_dTimeEnd - e_dTimeBegin) > 50 && e_Kill == true)
	{
		e_rect.left = e_rect.left + 200;

		if(e_rect.left + 200 >= 1600)
		{
			e_rect.left = 0;
			e_Kill = false;
		}

		e_rect.right = e_rect.left +200;
		e_dTimeBegin = e_dTimeEnd;
	}
}


void CKill::Move(D3DXVECTOR3 vPos)
{
	e_vPos = vPos;
	e_Kill = true;
}


void CKill::Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(e_Kill == true)
		e_DxSprite->Draw(e_Texture.GetTexture(), &e_rect, NULL, NULL, 0, &e_vPos, color);
}