#include "stdafx.h"


CSprite::CSprite()
{
	m_pDxSprite	= NULL;
}

CSprite::~CSprite()
{

}

INT CSprite::Create(LPD3DXSPRITE pSprite)
{
	m_pDxSprite = pSprite;

	return 0;
}

INT CSprite::Draw(LPDIRECT3DTEXTURE9 pTex
					, const RECT* pSrcRect
					, const D3DXVECTOR3* pScaling		// Scaling
					, const D3DXVECTOR3* pCenter		// Rotation Center
					, FLOAT	fAngle						// Degree.
					, const D3DXVECTOR3* pPosition		// Translation
					, D3DCOLOR Color
					)
{
	m_pDxSprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXMATRIX mtW;
	D3DXMatrixIdentity(&mtW);

	FLOAT			fTheta = D3DXToRadian(fAngle);
	D3DXMATRIX		mtScl;		// Scaling Matrix
	D3DXMATRIX		mtRot;		// Rotation Matrix
	D3DXMATRIX		mtTrn;		// Translation Matrix
	D3DXMATRIX		mtRct;		// Rotation Center Matrix
	D3DXMATRIX		mtRctI;		// Rotation Center Matrix Inverse

	D3DXMatrixIdentity(&mtScl);
	D3DXMatrixIdentity(&mtRct);
	D3DXMatrixIdentity(&mtRot);
	D3DXMatrixIdentity(&mtTrn);
	D3DXMatrixIdentity(&mtRctI);

	if(pScaling)
		D3DXMatrixScaling(&mtScl, pScaling->x, pScaling->y, pScaling->z);

	
	D3DXMatrixRotationZ(&mtRot, -fTheta);

	
	if(pCenter)
		D3DXMatrixTranslation(&mtRct, pCenter->x, pCenter->y, pCenter->z);


	if(pCenter)
		D3DXMatrixTranslation(&mtRctI, -pCenter->x, -pCenter->y, -pCenter->z);


	if(pPosition)
	D3DXMatrixTranslation(&mtTrn, pPosition->x, pPosition->y, pPosition->z);

	
	mtW =  mtScl * mtRctI * mtRot * mtRct * mtTrn;

	
	m_pDxSprite->SetTransform(&mtW);
	m_pDxSprite->Draw(pTex, pSrcRect, NULL, NULL, Color);

	D3DXMatrixIdentity(&mtW);
	m_pDxSprite->SetTransform(&mtW);

	m_pDxSprite->End();

	return 0;
}