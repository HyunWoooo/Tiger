#include "stdafx.h"
#include "character.h"


CCharacter::CCharacter()
{
	c_dTimeBegin = timeGetTime();
	cs_dTimeBegin = timeGetTime();
	csm_dTimeBegin = timeGetTime();

	c_Jump = false;
	c_Jump_Max = 0;
	c_Jump_Speed = 0;

	for(int i=0 ; i<22 ; i++)
		cg_Crash[i] = false;
	for(int i=0 ; i<6 ; i++)
		cl_Crash[i] = false;
	cl_Crash2 = false;
	cig_Crash = false;
	ct2_Crash = false;
	ct4_Crash = false;

	for(int i=0 ; i<10 ; i++)
	{
		ig_Delete[i] = false;
		i_Effect[i] = false;
	}
	for(int i=0 ; i<2 ; i++)
		ib_Delete[i] = false;

	c_Speed = 1;
	cb_Speed = 5;

	c_boost = false;
	c_trigger = false;
	
	ca_State = 0;
	end = false;
	stop = false;
}


void CCharacter::Init(CTexture Texture, CTexture Texture2, CTexture Texture3, CTexture Texture4, D3DXVECTOR3 vPos)
{
	c_DxSprite = new CSprite;
	c_DxSprite->Create(CDevice::GetSprite());

	c_Texture = Texture;
	c_Texture2 = Texture2;
	c_Texture3 = Texture3;
	
	c_vPos = vPos;
	c_vPos_Shadow = c_vPos + D3DXVECTOR3(0,177,0);
	c_Line[0] = c_vPos + D3DXVECTOR3(0,118,0);
	c_Line[1] = c_Line[0] + D3DXVECTOR3(200,0,0);
	
	c_rect.left = 0;
	c_rect.top = 0;
	c_rect.right  = 200;
	c_rect.bottom = 118;

	ca_rect = c_rect;
}


void CCharacter::Frame()
{
	c_dTimeEnd = timeGetTime();
	cs_dTimeEnd = timeGetTime();
	csm_dTimeBegin = timeGetTime();

	switch(ca_State)
	{
	case 0:
		if((c_dTimeEnd - c_dTimeBegin) > 84)
		{
			ca_rect.left = ca_rect.left + 200;

			if(ca_rect.left + 200 >= 1800)
				ca_rect.left = 400;

			ca_rect.right = ca_rect.left +200;
			c_dTimeBegin = c_dTimeEnd;
		}
		break;
	case 1:
		if(c_Jump == true && c_Jump_Speed >= 5)
		{
			ca_rect.left = 200;
			ca_rect.right  = 400;
		}
		else if(c_Jump == true && c_Jump_Speed < 5)
		{
			ca_rect.left = 400;
			ca_rect.right  = 600;
		}
		else if(c_Jump == false && c_Jump_Speed < 5)
		{
			ca_rect.left = 600;
			ca_rect.right  = 800;
		}
		else if(c_Jump == false && c_Jump_Speed >= 5)
		{
			ca_rect.left = 800;
			ca_rect.right  = 1000;
		}
		break;
	case 2:
		if((c_dTimeEnd - c_dTimeBegin) > 56)
		{
			ca_rect.left = ca_rect.left + 200;

			if(ca_rect.left + 200 >= 1800)
				ca_rect.left = 400;

			ca_rect.right = ca_rect.left +200;
			c_dTimeBegin = c_dTimeEnd;
		}
		break;
	case 3:
		if(c_Jump == true && c_Jump_Speed >= 5)
		{
			ca_rect.left = 200;
			ca_rect.right  = 400;
		}
		else if(c_Jump == true && c_Jump_Speed < 5)
		{
			ca_rect.left = 400;
			ca_rect.right  = 600;
		}
		else if(c_Jump == false && c_Jump_Speed < 5)
		{
			ca_rect.left = 600;
			ca_rect.right  = 800;
		}
		else if(c_Jump == false && c_Jump_Speed >= 5)
		{
			ca_rect.left = 800;
			ca_rect.right  = 1000;
		}
		break;
	case 4:
		if((c_dTimeEnd - c_dTimeBegin) > 56)
		{
			ca_rect.left = ca_rect.left + 200;

			if(ca_rect.left + 200 >= 3200)
				ca_rect.left = 200;

			ca_rect.right = ca_rect.left +200;
			c_dTimeBegin = c_dTimeEnd;
		}
		break;
	case 5:
		ca_rect.left = 0;
		ca_rect.right = 200;

		if(ct4_Crash == true)
		{
			if((c_dTimeEnd - c_dTimeBegin) > 1000)
			{
				ct4_Crash = false;
				ca_State = 0;
				c_dTimeBegin = c_dTimeEnd;
			}
		break;
		}
	}

	if((cs_dTimeEnd - cs_dTimeBegin) > 200)
	{
		if(end == true)
		{
			if(c_Speed == 0)
				ca_State = 5;
			else
				c_Speed = c_Speed - 2;
		}
		else if(ct4_Crash == true)
		{
			c_Speed = 0;
			ca_State = 5;
		}
		else if(stop == false)
		{
			if(ct2_Crash == true)
			{
				cb_Speed--;
				if(cb_Speed <= 0)
				{
					ct2_Crash = false;
					cb_Speed = 5;
					c_Speed = 5;
				}
			}
			if(ct4_Crash == true)
			{
				if(c_Speed == 0)
					ct4_Crash = false;
				else
					c_Speed = 0;
			}
			else
			{
				if(c_Speed == 14)
					c_Speed = c_Speed;
				else
					c_Speed = c_Speed + 1;
			}
		}

		cs_dTimeBegin = cs_dTimeEnd;
	}

	if((csm_dTimeEnd - cs_dTimeBegin) > 200)
	{
		if(end == true)
		{
			if(c_vPos.x >= 300)
					;
			else
			{
				c_vPos.x = c_vPos.x + c_Speed;
				c_vPos_Shadow.x = c_vPos.x;
			}
		}
		else
		{
			if(ct2_Crash == true)
			{
				c_vPos.x = c_vPos.x - cb_Speed;
				c_vPos_Shadow.x = c_vPos.x;
			}
			else
			{
				if(c_vPos.x >= 300)
					;
				else
				{
					c_vPos.x = c_vPos.x + c_Speed;
					c_vPos_Shadow.x = c_vPos.x;
				}
			}
		}

		csm_dTimeBegin = csm_dTimeEnd;
	}

	c_Line[0] = c_vPos + D3DXVECTOR3(0,120,0);
	c_Line[1] = c_Line[0] + D3DXVECTOR3(200,0,0);
}


void CCharacter::Jump(bool boost, bool trigger)
{
	if(c_Jump_Speed == 0)
	{
		c_Jump = false;
		c_Jump_Max++;
	}

	if(c_Jump == false && c_Jump_Max < 2 && end == false)
	{
		if((GetAsyncKeyState(VK_SPACE) & 0x8000))
		{
			c_Jump = true;
			c_Jump_Speed = 18;
			c_Jump_Max++;
			c_double_Jump = true;
		}
	}

	if(cg_Crash[0] == true || cg_Crash[1] == true || cg_Crash[2] == true || cg_Crash[3] == true || cg_Crash[4] == true || 
		cg_Crash[5] == true || cg_Crash[6] == true || cg_Crash[7] == true || cg_Crash[8] == true || cg_Crash[9] == true ||
		cg_Crash[10] == true || cg_Crash[11] == true || cg_Crash[12] == true || cg_Crash[13] == true || cg_Crash[14] == true || 
		cg_Crash[15] == true || cg_Crash[16] == true || cg_Crash[17] == true || cg_Crash[18] == true || cg_Crash[19] == true || 
		cg_Crash[20] == true || cg_Crash[21] == true || cl_Crash[0] == true || cl_Crash[1] == true || cl_Crash[2] == true ||
		cl_Crash[3] == true || cl_Crash[4] == true || cl_Crash[5] == true)
	{
		if(boost == true && trigger == false && ca_State != 5)
		{
			ca_State = 2;
			c_boost = true;
		}
		else if(trigger == true && ca_State != 5)
		{
			ca_State = 4;
		}
		else if(ca_State != 5)
		{
			ca_State = 0;
			c_boost = false;
		}

		c_Jump_Max = false;
		c_Jump_Speed = 18;
		c_vPos_Shadow.y = c_vPos.y + 133;
	}

	if(c_Jump == true)									
	{
		if(boost == true && trigger == false && ca_State != 5)
			ca_State = 3;
		else if(trigger == true && ca_State != 5)
			ca_State = 4;
		else if(ca_State != 5)
			ca_State = 1;

		c_vPos.y = c_vPos.y - c_Jump_Speed;
		c_vPos_Shadow.y = c_vPos_Shadow.y;
		c_Jump_Speed--;
	}

	else if(cg_Crash[0] == false && cg_Crash[1] == false && cg_Crash[2] == false && cg_Crash[3] == false && cg_Crash[4] == false && 
			cg_Crash[5] == false && cg_Crash[6] == false && cg_Crash[7] == false && cg_Crash[8] == false && cg_Crash[9] == false &&
			cg_Crash[10] == false && cg_Crash[11] == false && cg_Crash[12] == false && cg_Crash[13] == false && cg_Crash[14] == false && 
			cg_Crash[15] == false && cg_Crash[16] == false && cg_Crash[17] == false && cg_Crash[18] == false && cg_Crash[19] == false && 
			cg_Crash[20] == false && cg_Crash[21] == false && cl_Crash[0] == false && cl_Crash[1] == false && cl_Crash[2] == false &&
			cl_Crash[3] == false && cl_Crash[4] == false && cl_Crash[5] == false)
	{
		if(c_Jump_Speed == 20)
			;
		else
			c_Jump_Speed++;

		c_vPos.y = c_vPos.y + c_Jump_Speed;
		c_vPos_Shadow.y = c_vPos_Shadow.y + 1;
	}
}


void CCharacter::Ground_Crash(D3DXVECTOR3 vPos, RECT rect, int i)
{
	RECT rcCol1;
	RECT rcCol2;

	SetRect(&rcCol1, int(c_vPos.x)
				   , int(c_vPos.y)					
				   , int(c_vPos.x) + c_rect.right		
				   , int(c_vPos.y) + c_rect.bottom	
			);

	SetRect(&rcCol2, int(vPos.x)
				   , int(vPos.y)
				   , int(vPos.x) + rect.right
				   , int(vPos.y) + rect.bottom
			);

	if(rcCol1.left <= rcCol2.right &&
		rcCol1.right >= rcCol2.left &&
		rcCol1.top <= rcCol2.bottom &&
		rcCol1.bottom >= rcCol2.top)
	{
		cg_Crash[i] = true;
		cl_Crash2 = false;
	}
	else
		cg_Crash[i] = false;

	if(c_vPos.y < 495 && cg_Crash[i] == true)
	{
		if(c_vPos.y >= 495)
			;
		else
			c_vPos.y = c_vPos.y + 1;
	}

	else if(c_vPos.y > 505 && cg_Crash[i] == true)
	{
		if(c_vPos.y <= 505)
			;
		else
			c_vPos.y = c_vPos.y - 3;
	}
}


void CCharacter::Line_Crash(D3DXVECTOR3* vPos, int i)
{
	float Line_x = vPos[1].x - vPos[0].x;
	float Line_y = vPos[1].y - vPos[0].y;

	Speed_y = c_Speed / Line_x * Line_y;
	Boost_Speed_y = (c_Speed * 2) / Line_x * Line_y;

	D3DXVECTOR2 L0 = vPos[0] - c_Line[0];
	D3DXVECTOR2 L1 = c_Line[1] - c_Line[0];
	D3DXVECTOR2 L2 = vPos[1] - c_Line[0];

	D3DXVECTOR2 L4 = vPos[0] - vPos[1];
	D3DXVECTOR2 L5 = vPos[0] - c_Line[1];

	float D1 = (L0.x * L1.y - L0.y * L1.x) * (L1.x * L2.y - L1.y * L2.x);
	float D2 = (L0.x * L4.y - L0.y * L4.x) * (L4.x * L5.y - L4.y * L5.x);

	if(D1>0 && D2 >0)
	{
		cl_Crash[i] = true;
		cl_Crash2 = true;
	}
	else
		cl_Crash[i] = false;

	if(c_vPos.y < 495 && cl_Crash[i] == true)
	{
		if(c_vPos.y >= 495)
			;
		else
			c_vPos.y = c_vPos.y + 1;
	}

	else if(c_vPos.y > 505 && cl_Crash[i] == true)
	{
		if(c_vPos.y <= 505)
			;
		else
			c_vPos.y = c_vPos.y - 3;
	}
}


void CCharacter::Garlic_Crash(D3DXVECTOR3 vPos, RECT rect, int i)
{
	RECT rcCol1;
	RECT rcCol2;

	SetRect(&rcCol1, int(c_vPos.x) + 180				
				   , int(c_vPos.y)				
				   , int(c_vPos.x) + c_rect.right
				   , int(c_vPos.y) + c_rect.bottom	
			);

	SetRect(&rcCol2, int(vPos.x)
				   , int(vPos.y)
				   , int(vPos.x) + rect.right
				   , int(vPos.y) + rect.bottom
			);

	if(rcCol1.left <= rcCol2.right &&
		rcCol1.right >= rcCol2.left &&
		rcCol1.top <= rcCol2.bottom &&
		rcCol1.bottom >= rcCol2.top)
	{
		ig_Delete[i] = true;
		cig_Crash = true;
	}
}


void CCharacter::Beef_Crash(D3DXVECTOR3 vPos, RECT rect, int i)
{
	RECT rcCol1;
	RECT rcCol2;
	
	SetRect(&rcCol1, int(c_vPos.x) + 180				
				   , int(c_vPos.y)				
				   , int(c_vPos.x) + c_rect.right
				   , int(c_vPos.y) + c_rect.bottom	
			);

	SetRect(&rcCol2, int(vPos.x)
				   , int(vPos.y)
				   , int(vPos.x) + rect.right
				   , int(vPos.y) + rect.bottom
			);

	if(rcCol1.left <= rcCol2.right &&
		rcCol1.right >= rcCol2.left &&
		rcCol1.top <= rcCol2.bottom &&
		rcCol1.bottom >= rcCol2.top)
	{
		ib_Delete[i] = true;
		c_trigger = true;
		ct_dTimeBegin = timeGetTime();
	}
}


void CCharacter::Thron1_Crash(D3DXVECTOR3 vPos, RECT rect, int i, bool trigger)
{
	RECT rcCol1;
	RECT rcCol2;

	SetRect(&rcCol1, int(c_vPos.x) + 150				
				   , int(c_vPos.y)			
				   , int(c_vPos.x) + c_rect.right
				   , int(c_vPos.y) + c_rect.bottom	
			);

	SetRect(&rcCol2, int(vPos.x)
				   , int(vPos.y)
				   , int(vPos.x) + rect.right
				   , int(vPos.y) + rect.bottom
			);

	if(rcCol1.left <= rcCol2.right &&
		rcCol1.right >= rcCol2.left &&
		rcCol1.top <= rcCol2.bottom &&
		rcCol1.bottom >= rcCol2.top)
	{
		if(c_boost == false && c_Speed < 5)
			;
		else if(c_Speed < 10)
			;
		else
			c_Speed = c_Speed - 5;

		if(trigger == true)
			t1_Delete[i] = true;
	}
}


void CCharacter::Thron2_Crash(D3DXVECTOR3 vPos, RECT rect, int i, int trap, bool trigger)
{
	RECT rcCol1;
	RECT rcCol2;

	SetRect(&rcCol1, int(c_vPos.x) + 150				
				   , int(c_vPos.y)	
				   , int(c_vPos.x) + c_rect.right
				   , int(c_vPos.y) + c_rect.bottom	
			);

	SetRect(&rcCol2, int(vPos.x)
				   , int(vPos.y)
				   , int(vPos.x) + rect.right
				   , int(vPos.y) + rect.bottom
			);

	if(rcCol1.left <= rcCol2.right &&
		rcCol1.right >= rcCol2.left &&
		rcCol1.top <= rcCol2.bottom &&
		rcCol1.bottom >= rcCol2.top)
	{
		if(trigger == true && trap == 1)
			t2_Delete[i] = true;
		else if(trigger == true && trap == 2)
			t3_Delete[i] = true;
		else
			ct2_Crash = true;
	}
}


void CCharacter::Snare_Crash(D3DXVECTOR3 vPos, RECT rect, RECT rect2, int i, bool trigger)
{
	RECT rcCol1;
	RECT rcCol2;

	SetRect(&rcCol1, int(c_vPos.x) + 150				
				   , int(c_vPos.y)			
				   , int(c_vPos.x) + c_rect.right
				   , int(c_vPos.y) + c_rect.bottom	
			);

	SetRect(&rcCol2, int(vPos.x) + 40
				   , int(vPos.y) + 20
				   , int(vPos.x) + rect.right
				   , int(vPos.y) + rect.bottom
			);

	if(rcCol1.left <= rcCol2.right &&
		rcCol1.right >= rcCol2.left &&
		rcCol1.top <= rcCol2.bottom &&
		rcCol1.bottom >= rcCol2.top)
	{
		if(trigger == true)
			t4_Delete[i] = true;
		else if(rect2.left == 768)
			ct4_Crash = true;
	}
}


void CCharacter::Enemy_Crash(D3DXVECTOR3 vPos, RECT rect, int i, bool trigger)
{
	RECT rcCol1;
	RECT rcCol2;
	RECT rcCol3;

	SetRect(&rcCol1, int(c_vPos.x)  + 50				
				   , int(c_vPos.y)  				
				   , int(c_vPos.x) + c_rect.right		
				   , int(c_vPos.y) + c_rect.bottom	
			);
	SetRect(&rcCol2, int(vPos.x) 
				   , int(vPos.y) + 110
				   , int(vPos.x) + rect.right
				   , int(vPos.y) + rect.bottom
			);
	SetRect(&rcCol3, int(vPos.x) + 20
				   , int(vPos.y) 
				   , int(vPos.x) + rect.right
				   , int(vPos.y) + rect.bottom
			);

	if(rcCol1.left <= rcCol2.right &&
		rcCol1.right >= rcCol2.left &&
		rcCol1.top <= rcCol2.bottom &&
		rcCol1.bottom >= rcCol2.top)
	{
		if(trigger == true)
			e_Delete[i] = true;
		else
			ct2_Crash = true;
	}

	if(rcCol1.left <= rcCol3.right &&
		rcCol1.right >= rcCol3.left &&
		rcCol1.top <= rcCol3.bottom &&
		rcCol1.bottom >= rcCol3.top)
	{
		c_Jump_Max = false;
		c_Jump = true;
		c_Jump_Speed = 10;

		e_Delete[i] = true;
	}
}


void CCharacter::End(D3DXVECTOR3 vPos, RECT rect)
{
	RECT rcCol1;
	RECT rcCol2;

	SetRect(&rcCol1, int(c_vPos.x)			
				   , int(c_vPos.y)			
				   , int(c_vPos.x) + c_rect.right
				   , int(c_vPos.y) + c_rect.bottom	
			);

	SetRect(&rcCol2, int(vPos.x)
				   , int(vPos.y)
				   , int(vPos.x) + rect.right
				   , int(vPos.y) + rect.bottom
			);

	if(rcCol1.left <= rcCol2.right &&
		rcCol1.right >= rcCol2.left &&
		rcCol1.top <= rcCol2.bottom &&
		rcCol1.bottom >= rcCol2.top)
	{
		end = true;
	}
}


void CCharacter::Ig_Check()
{
	cig_Crash = false;
}


void CCharacter::Ib_Check()
{
	c_trigger = false;
}


void CCharacter::End_Check()
{
	end = false;
}


void CCharacter::Stop()
{
	stop = true;
	c_Speed = 0;
	cb_Speed = 0;
	ca_State = 5;
}


void CCharacter::McColor_TransColorMono(DWORD* pOut, DWORD* pIn, INT iImgW, INT iImgH)
{
	for(int y=0; y<iImgH; ++y)
	{
		for(int x=0; x<iImgW; ++x)
		{
			int nIdx = y*iImgW + x;

			D3DXCOLOR xclr = pIn[nIdx];

			float fclr =0.f;

			fclr = 0.f;

			pOut[nIdx] = D3DXCOLOR(fclr, fclr, fclr, xclr.a);
		}
	}
}


void CCharacter::Shadow()
{
	D3DSURFACE_DESC dsc;
	D3DLOCKED_RECT	drc;
	DWORD*	pColorSrc = NULL;
	DWORD*	pColorDst = NULL;

	LPDIRECT3DTEXTURE9	pTexAni = c_Texture.GetTexture();

	pTexAni->GetLevelDesc(0, &dsc);

	INT ImgW	= dsc.Width;
	INT	ImgH	= dsc.Height;
	m_pTexAniS	= NULL;

	pColorSrc	= new DWORD[ImgW * ImgH];

	pTexAni->LockRect(0, &drc, NULL, 0);
	{
		memcpy(pColorSrc, drc.pBits, ImgW * ImgH * sizeof(DWORD));
	}
	pTexAni->UnlockRect(0);

	D3DXCreateTexture(CDevice::GetDevice(), ImgW, ImgH, 1, 0, dsc.Format, D3DPOOL_MANAGED, &m_pTexAniS);

	m_pTexAniS->LockRect(0, &drc, NULL, 0);
	{
		pColorDst = (DWORD*)drc.pBits;
		McColor_TransColorMono(pColorDst, pColorSrc, ImgW, ImgH);
	}
	m_pTexAniS->UnlockRect(0);

	delete [] pColorSrc;
}


void CCharacter::Render()
{
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	if(ca_State == 5)
	{
		c_DxSprite->Draw(c_Texture.GetTexture(), &ca_rect, NULL, &D3DXVECTOR3(100,59,0), 0, &c_vPos, color);
		c_DxSprite->Draw(m_pTexAniS, &ca_rect, &D3DXVECTOR3(1,-0.2f,0), &D3DXVECTOR3(100,59,0), 0, &c_vPos_Shadow, D3DXCOLOR(1,1,1,0.5f));
	}

	else if(cl_Crash2 == true && ca_State == 0)
	{
		c_DxSprite->Draw(c_Texture.GetTexture(), &ca_rect, NULL, &D3DXVECTOR3(100,59,0), -13, &c_vPos, color);
		c_DxSprite->Draw(m_pTexAniS, &ca_rect, &D3DXVECTOR3(1,-0.2f,0), &D3DXVECTOR3(100,59,0), -13, &c_vPos_Shadow, D3DXCOLOR(1,1,1,0.5f));
	}

	else if(cl_Crash2 == true && ca_State == 2)
	{
		c_DxSprite->Draw(c_Texture2.GetTexture(), &ca_rect, NULL, &D3DXVECTOR3(100,59,0), -13, &c_vPos, color);
		c_DxSprite->Draw(m_pTexAniS, &ca_rect, &D3DXVECTOR3(1,-0.2f,0), &D3DXVECTOR3(100,59,0), -13, &c_vPos_Shadow, D3DXCOLOR(1,1,1,0.5f));
	}

	else if(cl_Crash2 == true && ca_State == 4)
	{
		c_DxSprite->Draw(c_Texture3.GetTexture(), &ca_rect, NULL, &D3DXVECTOR3(100,59,0), -13, &c_vPos, color);
		c_DxSprite->Draw(m_pTexAniS, &ca_rect, &D3DXVECTOR3(1,-0.2f,0), &D3DXVECTOR3(100,59,0), -13, &c_vPos_Shadow, D3DXCOLOR(1,1,1,0.5f));
	}

	else if(ca_State == 2 || ca_State == 3)
	{
		c_DxSprite->Draw(c_Texture2.GetTexture(), &ca_rect, NULL, NULL, 0, &c_vPos, color);
		c_DxSprite->Draw(m_pTexAniS, &ca_rect, &D3DXVECTOR3(1,-0.2f,0), NULL, 0, &c_vPos_Shadow, D3DXCOLOR(1,1,1,0.5f));
	}

	else if(ca_State == 4)
	{
		c_DxSprite->Draw(c_Texture3.GetTexture(), &ca_rect, NULL, NULL, 0, &c_vPos, color);
		c_DxSprite->Draw(m_pTexAniS, &ca_rect, &D3DXVECTOR3(1,-0.2f,0), NULL, 0, &c_vPos_Shadow, D3DXCOLOR(1,1,1,0.5f));
	}

	else
	{
		c_DxSprite->Draw(c_Texture.GetTexture(), &ca_rect, NULL, NULL, 0, &c_vPos, color);
		c_DxSprite->Draw(m_pTexAniS, &ca_rect, &D3DXVECTOR3(1,-0.2,0), NULL, 0, &c_vPos_Shadow, D3DXCOLOR(1,1,1,0.5f));
	}
}