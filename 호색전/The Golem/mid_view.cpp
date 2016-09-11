#include "stdafx.h"
#include "mid_view.h"


///////////////////////////////////////////////////////////////
//						CMid_View1							 //
///////////////////////////////////////////////////////////////


CMid_View1::CMid_View1()
{
	v_dTimeBegin = timeGetTime();
}


void CMid_View1::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos)
{
	v_DxSprite = new CSprite;
	v_DxSprite->Create(CDevice::GetSprite());
	
	v_Texture = Texture;
	v_Texture2 = Texture2;
	
	v_vPos = vPos;
	v_vPos2 = v_vPos + (3072 * D3DXVECTOR3(1,0,0));
	
	v_rect.left = 0;
	v_rect.top = 0;
	v_rect.right  = 3072;
	v_rect.bottom = 1169;
}


void CMid_View1::Frame(bool booster, int speed, bool slide, bool jump, float jump_speed, bool end)
{
	v_dTimeEnd = timeGetTime();

	if(c_vPos.x >= 300 && end == false)
	{
		if((v_dTimeEnd - v_dTimeBegin) > 28)
		{
			if(booster == true)
			{
				v_vPos.x = v_vPos.x - 8;
				v_vPos2.x = v_vPos2.x - 8;
			}

			else
			{
				v_vPos.x = v_vPos.x - 6;
				v_vPos2.x = v_vPos2.x - 6;
			}

			if(v_vPos.x <= -3072)
				v_vPos.x = v_vPos2.x + 3072;

			else if(v_vPos2.x <= -3072)
				v_vPos2.x = v_vPos.x + 3072;

			v_dTimeBegin = v_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		v_vPos.x = v_vPos.x + 5;
		v_vPos2.x = v_vPos2.x + 5;
	}

	if(jump == true)
	{
		v_vPos.y = v_vPos.y + (jump_speed/3);
		v_vPos2.y = v_vPos2.y + (jump_speed/3);
	}
	else if(slide = true && v_vPos.y >= -100)
	{
		v_vPos.y = v_vPos.y - (jump_speed/3);
		v_vPos2.y = v_vPos2.y - (jump_speed/3);
	}
}


void CMid_View1::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CMid_View1::Render(bool boost)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(boost == true)
	{
		v_DxSprite->Draw(v_Texture2.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos, color);
		v_DxSprite->Draw(v_Texture2.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos2, color);
	}
	else
	{
		v_DxSprite->Draw(v_Texture.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos, color);
		v_DxSprite->Draw(v_Texture.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos2, color);
	}
}


///////////////////////////////////////////////////////////////
//						CMid_View2							 //
///////////////////////////////////////////////////////////////


CMid_View2::CMid_View2()
{
	v_dTimeBegin = timeGetTime();
}


void CMid_View2::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos)
{
	v_DxSprite = new CSprite;
	v_DxSprite->Create(CDevice::GetSprite());
	
	v_Texture = Texture;
	v_Texture2 = Texture2;
	
	v_vPos = vPos;
	v_vPos2 = v_vPos + (3072 * D3DXVECTOR3(1,0,0));
	
	v_rect.left = 0;
	v_rect.top = 0;
	v_rect.right  = 3072;
	v_rect.bottom = 1169;
}


void CMid_View2::Frame(bool booster, int speed, bool slide, bool jump, float jump_speed, bool end)
{
	v_dTimeEnd = timeGetTime();

	if(c_vPos.x >= 300 && end == false)
	{
		if((v_dTimeEnd - v_dTimeBegin) > 28)
		{
			if(booster == true)
			{
				v_vPos.x = v_vPos.x - 6;
				v_vPos2.x = v_vPos2.x - 6;
			}

			else
			{
				v_vPos.x = v_vPos.x - 4;
				v_vPos2.x = v_vPos2.x - 4;
			}

			if(v_vPos.x <= -3072)
				v_vPos.x = v_vPos2.x + 3072;

			else if(v_vPos2.x <= -3072)
				v_vPos2.x = v_vPos.x + 3072;

			v_dTimeBegin = v_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		v_vPos.x = v_vPos.x + 3;
		v_vPos2.x = v_vPos2.x + 3;
	}

	if(jump == true)
	{
		v_vPos.y = v_vPos.y + (jump_speed/5);
		v_vPos2.y = v_vPos2.y + (jump_speed/5);
	}
	else if(slide = true && v_vPos.y >= -100)
	{
		v_vPos.y = v_vPos.y - (jump_speed/5);
		v_vPos2.y = v_vPos2.y - (jump_speed/5);
	}
}


void CMid_View2::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CMid_View2::Render(bool boost)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(boost == true)
	{
		v_DxSprite->Draw(v_Texture2.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos, color);
		v_DxSprite->Draw(v_Texture2.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos2, color);
	}
	else
	{
		v_DxSprite->Draw(v_Texture.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos, color);
		v_DxSprite->Draw(v_Texture.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos2, color);
	}
}


///////////////////////////////////////////////////////////////
//						CMid_View3							 //
///////////////////////////////////////////////////////////////


CMid_View3::CMid_View3()
{
	v_dTimeBegin = timeGetTime();
}


void CMid_View3::Init(CTexture Texture, CTexture Texture2, D3DXVECTOR3 vPos)
{
	v_DxSprite = new CSprite;
	v_DxSprite->Create(CDevice::GetSprite());
	
	v_Texture = Texture;
	v_Texture2 = Texture2;
	
	v_vPos = vPos;
	v_vPos2 = v_vPos + (3072 * D3DXVECTOR3(1,0,0));
	
	v_rect.left = 0;
	v_rect.top = 0;
	v_rect.right  = 3072;
	v_rect.bottom = 1169;
}


void CMid_View3::Frame(bool booster, int speed, bool slide, bool jump, float jump_speed, bool end)
{
	v_dTimeEnd = timeGetTime();

	if(c_vPos.x >= 300 && end == false)
	{
		if((v_dTimeEnd - v_dTimeBegin) > 28)
		{
			if(booster == true)
			{
				v_vPos.x = v_vPos.x - 4;
				v_vPos2.x = v_vPos2.x - 4;
			}

			else
			{
				v_vPos.x = v_vPos.x - 2;
				v_vPos2.x = v_vPos2.x - 2;
			}

			if(v_vPos.x <= -3072)
				v_vPos.x = v_vPos2.x + 3072;

			else if(v_vPos2.x <= -3072)
				v_vPos2.x = v_vPos.x + 3072;

			v_dTimeBegin = v_dTimeEnd;
		}
	}

	if(c_vPos.x <= 0)
	{
		v_vPos.x = v_vPos.x + 1;
		v_vPos2.x = v_vPos2.x + 1;
	}

	if(jump == true)
	{
		v_vPos.y = v_vPos.y + (jump_speed/7);
		v_vPos2.y = v_vPos2.y + (jump_speed/7);
	}
	else if(slide = true && v_vPos.y >= -100)
	{
		v_vPos.y = v_vPos.y - (jump_speed/7);
		v_vPos2.y = v_vPos2.y - (jump_speed/7);
	}
}


void CMid_View3::Move(D3DXVECTOR3 vPos)
{
	c_vPos = vPos;
}


void CMid_View3::Render(bool boost)
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(boost == true)
	{
		v_DxSprite->Draw(v_Texture2.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos, color);
		v_DxSprite->Draw(v_Texture2.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos2, color);
	}
	else
	{
		v_DxSprite->Draw(v_Texture.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos, color);
		v_DxSprite->Draw(v_Texture.GetTexture(), &v_rect, NULL, NULL, 0, &v_vPos2, color);
	}
}