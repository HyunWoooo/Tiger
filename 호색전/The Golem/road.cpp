#include "stdafx.h"
#include "road.h"


///////////////////////////////////////////////////////////////
//						CRoad_Flatland						 //
///////////////////////////////////////////////////////////////


CRoad_Flatland::CRoad_Flatland()
{
	r_dTimeBegin = timeGetTime();
}


void CRoad_Flatland::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos, D3DXVECTOR3 vPos2)
{
	r_DxSprite = new CSprite;
	r_DxSprite->Create(CDevice::GetSprite());

	r_Texture = Texture;
	r_Texture2 = Texture2;

	r_vPos = vPos;
	rc_vPos = vPos2;

	r_rect.left = 0;
	r_rect.top = 0;
	r_rect.right  = 1024;
	r_rect.bottom = 768;

	rc_rect.left = 0;
	rc_rect.top = 0;
	rc_rect.right  = 1024;
	rc_rect.bottom = 1;
}


void CRoad_Flatland::Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide)
{
	r_dTimeEnd = timeGetTime();

	if((r_dTimeEnd - r_dTimeBegin) > 28)
	{
		if(c_vPos.x >= 300)
		{
			if(booster == true )
			{
				r_vPos.x = r_vPos.x - (speed * 2);
				rc_vPos.x = rc_vPos.x - (speed * 2);

				if(slide == true)
				{
					r_vPos.y = r_vPos.y - booster_speed_y;
					rc_vPos.y = rc_vPos.y - booster_speed_y;
				}
			}
			else
			{
				r_vPos.x = r_vPos.x - speed;
				rc_vPos.x = rc_vPos.x - speed;

				if(slide == true)
				{
					r_vPos.y = r_vPos.y - speed_y;
					rc_vPos.y = rc_vPos.y - speed_y;
				}
			}

			r_dTimeBegin = r_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		r_vPos.x = r_vPos.x + 5;
		rc_vPos.x = rc_vPos.x + 5;
	}

	if(c_vPos.y < 495)
	{
		if(c_vPos.y >= 495)
			;
		else
		{
			r_vPos.y = r_vPos.y + 1;
			rc_vPos.y = rc_vPos.y + 1;
		}
	}

	else if(c_vPos.y > 505)
	{
		if(c_vPos.y <= 505)
			;
		else
		{
			r_vPos.y = r_vPos.y - 3;
			rc_vPos.y = rc_vPos.y - 3;
		}
	}
}


void CRoad_Flatland::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CRoad_Flatland::Render(bool boost)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(boost == true)
		r_DxSprite->Draw(r_Texture2.GetTexture(), &r_rect, NULL, NULL, 0, &r_vPos, color);
	else
		r_DxSprite->Draw(r_Texture.GetTexture(), &r_rect, NULL, NULL, 0, &r_vPos, color);
}


///////////////////////////////////////////////////////////////
//						CRoad_Slope							 //
///////////////////////////////////////////////////////////////


CRoad_Slope1::CRoad_Slope1()
{
	r_dTimeBegin = timeGetTime();
}


void CRoad_Slope1::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos, D3DXVECTOR3 Line1, D3DXVECTOR3 Line2)
{
	r_DxSprite = new CSprite;
	r_DxSprite->Create(CDevice::GetSprite());

	r_Texture = Texture;
	r_Texture2 = Texture2;

	r_vPos = vPos;

	rc_Line[0] = Line1;
	rc_Line[1] = Line2;

	r_rect.left = 0;
	r_rect.top = 0;
	r_rect.right  = 1024;
	r_rect.bottom = 768;
}


void CRoad_Slope1::Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide)
{
	r_dTimeEnd = timeGetTime();

	if((r_dTimeEnd - r_dTimeBegin) > 28)
	{
		if(c_vPos.x >= 300)
		{
			if(booster == true)
			{
				r_vPos.x = r_vPos.x - (speed * 2);
				rc_Line[0].x = rc_Line[0].x - (speed * 2);
				rc_Line[1].x = rc_Line[1].x - (speed * 2);

				if(slide == true)
				{
					r_vPos.y = r_vPos.y - booster_speed_y ;
					rc_Line[0].y = rc_Line[0].y - booster_speed_y ;
					rc_Line[1].y = rc_Line[1].y - booster_speed_y ;
				}
			}
			else
			{
				r_vPos.x = r_vPos.x - speed;
				rc_Line[0].x = rc_Line[0].x - speed;
				rc_Line[1].x = rc_Line[1].x - speed;

				if(slide == true)
				{
					r_vPos.y = r_vPos.y - speed_y;
					rc_Line[0].y = rc_Line[0].y - speed_y;
					rc_Line[1].y = rc_Line[1].y - speed_y;
				}
			}

			r_dTimeBegin = r_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		r_vPos.x = r_vPos.x + 5;
		rc_Line[0].x = rc_Line[0].x + 5;
		rc_Line[1].x = rc_Line[1].x + 5;
	}

	if(c_vPos.y < 495)
	{
		if(c_vPos.y >= 495)
			;
		else
		{
			r_vPos.y = r_vPos.y + 1;
			rc_Line[0].y = rc_Line[0].y + 1;
			rc_Line[1].y = rc_Line[1].y + 1;
		}
	}

	else if(c_vPos.y > 505)
	{
		if(c_vPos.y <= 505)
			;
		else
		{
			r_vPos.y = r_vPos.y - 3;
			rc_Line[0].y = rc_Line[0].y - 3;
			rc_Line[1].y = rc_Line[1].y - 3;
		}
	}
}


void CRoad_Slope1::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CRoad_Slope1::Render(bool boost)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);
	
	if(boost == true)
		r_DxSprite->Draw(r_Texture2.GetTexture(), &r_rect, NULL, NULL, 0, &r_vPos, color);
	else
		r_DxSprite->Draw(r_Texture.GetTexture(), &r_rect, NULL, NULL, 0, &r_vPos, color);
}