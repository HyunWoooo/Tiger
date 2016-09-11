#include "stdafx.h"
#include "trap.h"


///////////////////////////////////////////////////////////////
//						CThorn1								 //
///////////////////////////////////////////////////////////////


CThorn1::CThorn1()
{
	t_dTimeBegin = timeGetTime();
}


void CThorn1::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos)
{
	t_DxSprite = new CSprite;
	t_DxSprite->Create(CDevice::GetSprite());

	t_Texture = Texture;
	t_Texture2 = Texture2;
	
	t_vPos = vPos;
	
	t_rect.left = 0;
	t_rect.top = 0;
	t_rect.right  = 111;
	t_rect.bottom = 68;
}


void CThorn1::Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide)
{
	t_dTimeEnd = timeGetTime();

	if(c_vPos.x >= 300)
	{
		if((t_dTimeEnd - t_dTimeBegin) > 28)
		{
			if(booster == true)
			{
				t_vPos.x = t_vPos.x - (speed * 2);
				if(slide ==true)
					t_vPos.y = t_vPos.y - booster_speed_y;
			}
			else
			{
				t_vPos.x = t_vPos.x - speed;
				if(slide ==true)
					t_vPos.y = t_vPos.y - speed_y;
			}

			t_dTimeBegin = t_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		t_vPos.x = t_vPos.x + 5;
	}

	if(c_vPos.y < 495)
	{
		if(c_vPos.y >= 495)
			;
		else
			t_vPos.y = t_vPos.y + 1;
	}

	else if(c_vPos.y > 505)
	{
		if(c_vPos.y <= 505)
			;
		else
			t_vPos.y = t_vPos.y - 3;
	}
}


void CThorn1::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CThorn1::Render(bool boost)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(boost == true)
		t_DxSprite->Draw(t_Texture2.GetTexture(), &t_rect, NULL, NULL, 0, &t_vPos, color);
	else
		t_DxSprite->Draw(t_Texture.GetTexture(), &t_rect, NULL, NULL, 0, &t_vPos, color);
}


///////////////////////////////////////////////////////////////
//						CThorn2								 //
///////////////////////////////////////////////////////////////


CThorn2::CThorn2()
{
	t_dTimeBegin = timeGetTime();
}


void CThorn2::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos)
{
	t_DxSprite = new CSprite;
	t_DxSprite->Create(CDevice::GetSprite());

	t_Texture = Texture;
	t_Texture2 = Texture2;
	
	t_vPos = vPos;
	
	t_rect.left = 0;
	t_rect.top = 0;
	t_rect.right  = 90;
	t_rect.bottom = 81;
}


void CThorn2::Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide)
{
	t_dTimeEnd = timeGetTime();

	if(c_vPos.x >= 300)
	{
		if((t_dTimeEnd - t_dTimeBegin) > 28)
		{
			if(booster == true)
			{
				t_vPos.x = t_vPos.x - (speed * 2);
				if(slide ==true)
					t_vPos.y = t_vPos.y - booster_speed_y;
			}
			else
			{
				t_vPos.x = t_vPos.x - speed;
				if(slide ==true)
					t_vPos.y = t_vPos.y - speed_y;
			}

			t_dTimeBegin = t_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		t_vPos.x = t_vPos.x + 5;
	}

	if(c_vPos.y < 495)
	{
		if(c_vPos.y >= 495)
			;
		else
			t_vPos.y = t_vPos.y + 1;
	}

	else if(c_vPos.y > 505)
	{
		if(c_vPos.y <= 505)
			;
		else
			t_vPos.y = t_vPos.y - 3;
	}
}


void CThorn2::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CThorn2::Render(bool boost)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(boost == true)
		t_DxSprite->Draw(t_Texture2.GetTexture(), &t_rect, NULL, NULL, 0, &t_vPos, color);
	else
		t_DxSprite->Draw(t_Texture.GetTexture(), &t_rect, NULL, NULL, 0, &t_vPos, color);
}


///////////////////////////////////////////////////////////////
//						CThorn3								 //
///////////////////////////////////////////////////////////////


CThorn3::CThorn3()
{
	t_dTimeBegin = timeGetTime();
	ta_dTimeBegin = timeGetTime();
	appear = false;
}


void CThorn3::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos)
{
	t_DxSprite = new CSprite;
	t_DxSprite->Create(CDevice::GetSprite());

	t_Texture = Texture;
	t_Texture2 = Texture2;
	
	t_vPos = vPos;
	
	t_rect.left = 0;
	t_rect.top = 0;
	t_rect.right  = 64;
	t_rect.bottom = 128;

	ta_rect.left = 0;
	ta_rect.top = 0;
	ta_rect.right  = 64;
	ta_rect.bottom = 128;
}


void CThorn3::Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide)
{
	t_dTimeEnd = timeGetTime();

	if(c_vPos.x >= 300)
	{
		if((t_dTimeEnd - t_dTimeBegin) > 28)
		{
			if(booster == true)
			{
				t_vPos.x = t_vPos.x - (speed * 2);
				if(slide ==true)
					t_vPos.y = t_vPos.y - booster_speed_y;
			}
			else
			{
				t_vPos.x = t_vPos.x - speed;
				if(slide ==true)
					t_vPos.y = t_vPos.y - speed_y;
			}

			t_dTimeBegin = t_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		t_vPos.x = t_vPos.x + 5;
	}

	if(c_vPos.y < 495)
	{
		if(c_vPos.y >= 495)
			;
		else
			t_vPos.y = t_vPos.y + 1;
	}

	else if(c_vPos.y > 505)
	{
		if(c_vPos.y <= 505)
			;
		else
			t_vPos.y = t_vPos.y - 3;
	}
}


void CThorn3::Appear(RECT rect)
{
	RECT rcCol1;
	RECT rcCol2;

	ta_dTimeEnd = timeGetTime();

	SetRect(&rcCol1, int(t_vPos.x) - 200
				   , int(t_vPos.y) - 400
				   , int(t_vPos.x) + t_rect.right		
				   , int(t_vPos.y) + t_rect.bottom	
			);

	SetRect(&rcCol2, int(c_vPos.x)
				   , int(c_vPos.y)
				   , int(c_vPos.x) + rect.right
				   , int(c_vPos.y) + rect.bottom
			);

	if(rcCol1.left <= rcCol2.right &&
		rcCol1.right >= rcCol2.left &&
		rcCol1.top <= rcCol2.bottom &&
		rcCol1.bottom >= rcCol2.top)
	{
		appear = true;
	}

	if(appear == true)
	{
		if((ta_dTimeEnd - ta_dTimeBegin) > 42)
		{
			ta_rect.left = ta_rect.left + 64;
			ta_rect.right = ta_rect.left + 64;

			if(ta_rect.left >= 512)
			{
				ta_rect.left = 448;
				ta_rect.right = 512;
			}
			
			ta_dTimeBegin = ta_dTimeEnd;
		}
	}
}


void CThorn3::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CThorn3::Render(bool boost)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(boost == true)
		t_DxSprite->Draw(t_Texture2.GetTexture(), &ta_rect, NULL, NULL, 0, &t_vPos, color);
	else
		t_DxSprite->Draw(t_Texture.GetTexture(), &ta_rect, NULL, NULL, 0, &t_vPos, color);
}


///////////////////////////////////////////////////////////////
//						CSnare								 //
///////////////////////////////////////////////////////////////


CSnare::CSnare()
{
	t_dTimeBegin = timeGetTime();
	ta_dTimeBegin = timeGetTime();
	operate = false;
}


void CSnare::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos)
{
	t_DxSprite = new CSprite;
	t_DxSprite->Create(CDevice::GetSprite());

	t_Texture = Texture;
	t_Texture2 = Texture2;
	
	t_vPos = vPos;
	
	t_rect.left = 0;
	t_rect.top = 0;
	t_rect.right  = 128;
	t_rect.bottom = 64;

	ta_rect.left = 0;
	ta_rect.top = 0;
	ta_rect.right  = 128;
	ta_rect.bottom = 64;
}


void CSnare::Frame(bool booster, int speed, float speed_y, float booster_speed_y, bool slide)
{
	t_dTimeEnd = timeGetTime();

	if(c_vPos.x >= 300)
	{
		if((t_dTimeEnd - t_dTimeBegin) > 28)
		{
			if(booster == true)
			{
				t_vPos.x = t_vPos.x - (speed * 2);
				if(slide ==true)
					t_vPos.y = t_vPos.y - booster_speed_y;
			}
			else
			{
				t_vPos.x = t_vPos.x - speed;
				if(slide ==true)
					t_vPos.y = t_vPos.y - speed_y;
			}

			t_dTimeBegin = t_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		t_vPos.x = t_vPos.x + 5;
	}

	if(c_vPos.y < 495)
	{
		if(c_vPos.y >= 495)
			;
		else
			t_vPos.y = t_vPos.y + 1;
	}

	else if(c_vPos.y > 505)
	{
		if(c_vPos.y <= 505)
			;
		else
			t_vPos.y = t_vPos.y - 3;
	}
}


void CSnare::Operate(RECT rect)
{
	RECT rcCol1;
	RECT rcCol2;

	ta_dTimeEnd = timeGetTime();

	SetRect(&rcCol1, int(t_vPos.x) + 40
				   , int(t_vPos.y)
				   , int(t_vPos.x) + t_rect.right		
				   , int(t_vPos.y) + t_rect.bottom	
			);

	SetRect(&rcCol2, int(c_vPos.x)
				   , int(c_vPos.y)
				   , int(c_vPos.x) + rect.right
				   , int(c_vPos.y) + rect.bottom
			);

	if(rcCol1.left <= rcCol2.right &&
		rcCol1.right >= rcCol2.left &&
		rcCol1.top <= rcCol2.bottom &&
		rcCol1.bottom >= rcCol2.top)
	{
		operate = true;
	}

	if(operate == true)
	{
		if((ta_dTimeEnd - ta_dTimeBegin) > 10)
		{
			ta_rect.left = ta_rect.left + 128;
			ta_rect.right = ta_rect.left + 128;

			if(ta_rect.left + 128 >= 1024)
			{
				ta_rect.left = 896;
				ta_rect.right = 1024;
			}
			
			ta_dTimeBegin = ta_dTimeEnd;
		}
	}
}


void CSnare::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CSnare::Render(bool boost)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(boost == true)
		t_DxSprite->Draw(t_Texture2.GetTexture(), &ta_rect, NULL, NULL, 0, &t_vPos, color);
	else
		t_DxSprite->Draw(t_Texture.GetTexture(), &ta_rect, NULL, NULL, 0, &t_vPos, color);
}