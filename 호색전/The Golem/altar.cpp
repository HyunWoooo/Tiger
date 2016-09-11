#include "stdafx.h"
#include "altar.h"


CAltar::CAltar()
{
	a_dTimeBegin = timeGetTime();
}


void CAltar::Init(CTexture Texture, D3DXVECTOR3 vPos)
{
	a_DxSprite = new CSprite;
	a_DxSprite->Create(CDevice::GetSprite());
	
	a_Texture = Texture;

	a_vPos = vPos;

	a_rect.left = 0;
	a_rect.top = 0;
	a_rect.right  = 1000;
	a_rect.bottom = 888;
}


void CAltar::Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide, bool jump, float jump_speed)
{
	a_dTimeEnd = timeGetTime();

	if((a_dTimeEnd - a_dTimeBegin) > 28)
	{
		if(c_vPos.x >= 300)
		{
			if(booster == true )
			{
				a_vPos.x = a_vPos.x - (speed * 2);

				if(slide == true)
					a_vPos.y = a_vPos.y - booster_speed_y;
			}
			else
			{
				a_vPos.x = a_vPos.x - speed;

				if(slide == true)
					a_vPos.y = a_vPos.y - speed_y;
			}

			a_dTimeBegin = a_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
		a_vPos.x = a_vPos.x + 5;

	if(c_vPos.y < 495)
	{
		if(c_vPos.y >= 495)
			;
		else
			a_vPos.y = a_vPos.y + 1;
	}

	else if(c_vPos.y > 505)
	{
		if(c_vPos.y <= 505)
			;
		else
			a_vPos.y = a_vPos.y - 3;
	}
}


void CAltar::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CAltar::Render(bool boost)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);
	
	a_DxSprite->Draw(a_Texture.GetTexture(), &a_rect, NULL, NULL, 0, &a_vPos, color);
}