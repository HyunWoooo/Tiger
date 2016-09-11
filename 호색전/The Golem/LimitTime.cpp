#include "stdafx.h"
#include "limittime.h"

CLimittime::CLimittime()
{
	TimeEnd = timeGetTime();
	nc= false;
	TEnd=false;
	norc= 0;
	everyEnd=false;
}

void CLimittime::tInit(CTexture Texture, D3DXVECTOR3 vPos)
{
	m_Sprite = CDevice::GetSprite();
	m_Texture = Texture;

	m_vPos = vPos;
	m_rect.left = 0;
	m_rect.top = 720;
	m_rect.right  =80;
	m_rect.bottom =800;

	m_rect2= m_rect;
}
void CLimittime::oInit(CTexture Texture, D3DXVECTOR3 vPos)
{
	m_Sprite2 = CDevice::GetSprite();
	m_Texture2 = Texture;

	m_vPos2 = vPos;
	m_rect3.left = 0;
	m_rect3.top = 720;
	m_rect3.right  =80;
	m_rect3.bottom =800;

	m_rect4= m_rect3;
}
 
void CLimittime::tRender()
{
	if(m_rect2.top>0)
	{

	if(nc==true && norc<=39)
	{
		m_rect2.bottom=m_rect2.bottom-2;
		norc++;
	}

	if(norc>=40 && nc==true)
	{
		norc=0;
		nc=false;
	}


	m_rect2.top = m_rect2.bottom -80;
	
	}
	else
	{
		m_rect2.top=0;
		m_rect2.bottom=80;
		everyEnd=true;
	}

	
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	m_Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	m_Sprite->Draw(m_Texture.GetTexture(),&m_rect2,NULL,&m_vPos,color);//
	m_Sprite->End();
}

void CLimittime::oRender()
{
	if(everyEnd==false && m_rect4.top!=0)
	{
		m_rect4.bottom=m_rect4.bottom-1;

		if(m_rect4.bottom  <=80){
			m_rect4.bottom = 800;
			nc= true;
		}
	}

	else
		m_rect4.bottom=80;


		m_rect4.top = m_rect4.bottom -80;
		

	
	D3DCOLOR color;
	color = D3DCOLOR_ARGB(255,255,255,255);

	m_Sprite2->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	m_Sprite2->Draw(m_Texture2.GetTexture(),&m_rect4,NULL,&m_vPos2,color);//
	m_Sprite2->End();
}