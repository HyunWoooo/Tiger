#pragma once
#include "stdafx.h"


class CSprite
{
protected:
	LPD3DXSPRITE	m_pDxSprite;			// 2D DX Sprite

public:
	CSprite();
	virtual ~CSprite();

	INT		Create(LPD3DXSPRITE);

	INT		Draw(LPDIRECT3DTEXTURE9 pTex
					, const RECT* pSrcRect
					, const D3DXVECTOR3* pScaling		// Scaling
					, const D3DXVECTOR3* pCenter		// Rotation Center
					, FLOAT	fAngle						// Degree.
					, const D3DXVECTOR3* pPosition		// Translation
					, D3DCOLOR Color
					);
};