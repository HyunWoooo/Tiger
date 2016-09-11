#pragma once
#include "character.h"
#include "distant_view.h"
#include "item.h"
#include "gauge.h"
#include "road.h"
#include "trap.h"
#include "enemy.h"
#include "mid_view.h"
#include "loading.h"
#include "storyboard.h"
#include "altar.h"
#include "LimitTime.h"
#include "clear.h"
#include "gameover.h"


class CStage1
{
public:
	CTexture		g_Footprint;
	CTexture		g_Loading_Back;
	CLoading		g_Loading;

	CTexture		g_Storyboard;

	CTexture		g_Tiger;
	CTexture		g_Tiger_Boost;
	CTexture		g_Trigger;
	CTexture		g_Dust;
	CTexture		g_Lake;
	CTexture		g_Vegetable;
	CTexture		g_Meat;
	CTexture		g_Gauge_e;
	CTexture		g_Gauge_f;
	CTexture		g_Gauge_t;
	CTexture		g_Flatland;
	CTexture		g_Slope1;
	CTexture		g_Thorn1;
	CTexture		g_Thorn2;
	CTexture		g_Thorn3;
	CTexture		g_Stone;
	CTexture		g_Bear_Normal;
	CTexture		g_Bear_Stand;
	CTexture		g_Eating;
	CTexture		g_Smoke;
	CTexture		g_Mid_Tree1;
	CTexture		g_Mid_Tree2;
	CTexture		g_Mid_Tree3;
	CTexture		g_Saint_Tree;
	CTexture		g_LimitTime;
	CTexture		g_Success;
	CTexture		g_Fail;

	CTexture		g_Lake_Mono;
	CTexture		g_Flatland_Mono;
	CTexture		g_Slope1_Mono;
	CTexture		g_Thorn1_Mono;
	CTexture		g_Thorn2_Mono;
	CTexture		g_Thorn3_Mono;
	CTexture		g_Stone_Mono;
	CTexture		g_Mid_Tree1_Mono;
	CTexture		g_Mid_Tree2_Mono;
	CTexture		g_Mid_Tree3_Mono;

	CCharacter		g_Character;
	CBackGround		g_BackGround;
	CGarlic*		g_Garlic[10];
	CBeef*			g_Beef[2];
	CE_gauge		g_Gauge_E;
	CF_gauge		g_Gauge_F;
	CT_gauge		g_Gauge_T;
	CRoad_Flatland	g_Road_F[22];
	CRoad_Slope1	g_Road_S1[6];
	CThorn1*		g_Trap1[5];
	CThorn2*		g_Trap2[5];
	CThorn3*		g_Trap3[5];
	CSnare*			g_Trap4[5];
	CBear_Stand*	g_Enemy[3];
	CSounds*		g_BGM;
	CSounds*		g_EFF[10];
	CEat			g_Eat;
	CKill			g_Kill;
	CMid_View1		g_Mid_View1;
	CMid_View2		g_Mid_View2;
	CMid_View3		g_Mid_View3;
	CAltar			g_End;
	CStoryboard		g_Story;
	CLimittime		g_Limittime;
	CClear			g_Clear;
	CGameOver		g_GameOver;

	int				state;
	int				loading_count;
	bool			end;

public:
	CStage1();
	~CStage1();

	int				Render();
	int				FrameMove();
	int				UpDate();

	HRESULT			InitD3D();

	int				Loading();
	HRESULT			Loading_InitD3D();

	int				Story();
	HRESULT			Story_InitD3D();
};