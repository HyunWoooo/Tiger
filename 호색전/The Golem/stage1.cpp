#include "stdafx.h"
#include "stage1.h"


CStage1::CStage1()
{
	for(int i=0 ; i<10 ; i++)
		g_Garlic[i] = new CGarlic;
	for(int i=0 ; i<2 ; i++)
		g_Beef[i] = new CBeef;
	for(int i=0 ; i<5 ; i++)
		g_Trap1[i] = new CThorn1;
	for(int i=0 ; i<5 ; i++)
		g_Trap2[i] = new CThorn2;
	for(int i=0 ; i<5 ; i++)
		g_Trap3[i] = new CThorn3;
	for(int i=0 ; i<5 ; i++)
		g_Trap4[i] = new CSnare;
	for(int i=0 ; i<3 ; i++)
		g_Enemy[i] = new CBear_Stand;
	state = 1;
	loading_count = 0;
}


CStage1::~CStage1()
{
	for(int i=0 ; i<10 ; i++)
	{
		if(g_Garlic[i] != NULL)
			SAFE_DELETE(g_Garlic[i]);
	}
	for(int i=0 ; i<2 ; i++)
	{
		if(g_Beef[i] != NULL)
			SAFE_DELETE(g_Beef[i]);
	}
	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap1[i] != NULL)
			SAFE_DELETE(g_Trap1[i]);
	}
	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap2[i] != NULL)
			SAFE_DELETE(g_Trap2[i]);
	}
	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap3[i] != NULL)
			SAFE_DELETE(g_Trap3[i]);
	}
	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap4[i] != NULL)
			SAFE_DELETE(g_Trap4[i]);
	}
	for(int i=0 ; i<3 ; i++)
	{
		if(g_Enemy[i] != NULL)
			SAFE_DELETE(g_Enemy[i]);
	}
}


int CStage1::Render()
{
	if( NULL == CDevice::GetDevice() )
		return -1;

	CDevice::GetDevice()->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 0, 0 ), 1.0f, 0 );

	if( SUCCEEDED( CDevice::GetDevice()->BeginScene() ) )
	{
		g_BackGround.Render(g_Gauge_T.c_trigger);
		g_Mid_View3.Render(g_Gauge_T.c_trigger);
		g_Mid_View2.Render(g_Gauge_T.c_trigger);
		g_Mid_View1.Render(g_Gauge_T.c_trigger);
		for(int i=0 ; i<22 ; i++)
			g_Road_F[i].Render(g_Gauge_T.c_trigger);
		for(int i=0 ; i<6 ; i++)
			g_Road_S1[i].Render(g_Gauge_T.c_trigger);
		g_End.Render(g_Gauge_T.c_trigger);
		g_Character.Render();
		g_Eat.Render();
		g_Kill.Render();
		g_Gauge_E.Render(g_Character.cl_Crash2);
		g_Gauge_F.Render(g_Character.cl_Crash2);
		g_Gauge_T.Render(g_Character.cl_Crash2);

		for(int i=0 ; i<10 ; i++)
		{
			if(g_Garlic[i] != NULL)
				g_Garlic[i]->Render();
		}

		for(int i=0 ; i<2 ; i++)
		{
			if(g_Beef[i] != NULL)
				g_Beef[i]->Render();
		}

		for(int i=0 ; i<3 ; i++)
		{
			if(g_Enemy[i] != NULL)
				g_Enemy[i]->Render();
		}

		for(int i=0 ; i<5 ; i++)
		{
			if(g_Trap1[i] != NULL)
				g_Trap1[i]->Render(g_Gauge_T.c_trigger);
		}

		for(int i=0 ; i<5 ; i++)
		{
			if(g_Trap2[i] != NULL)
				g_Trap2[i]->Render(g_Gauge_T.c_trigger);
		}

		for(int i=0 ; i<5 ; i++)
		{
			if(g_Trap3[i] != NULL)
				g_Trap3[i]->Render(g_Gauge_T.c_trigger);
		}

		for(int i=0 ; i<5 ; i++)
		{
			if(g_Trap4[i] != NULL)
				g_Trap4[i]->Render(g_Gauge_T.c_trigger);
		}

		g_Limittime.tRender();
		g_Limittime.oRender();

		if(g_Character.end == true && g_Character.c_Speed == 0)
			g_Clear.Render();
		if(g_Limittime.everyEnd == true)
			g_GameOver.Render();
	}
	CDevice::GetDevice()->EndScene();
	CDevice::GetDevice()->Present( NULL, NULL, NULL, NULL );

	return 0;
}


int CStage1::FrameMove()
{
	g_Character.Frame();
	g_Character.Jump(g_Gauge_F.c_booster, g_Gauge_T.c_trigger);
	g_BackGround.Frame(g_Character.c_vPos, g_Character.end);
	g_Mid_View1.Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.cl_Crash2, g_Character.c_Jump, g_Character.c_Jump_Speed, g_Character.end);
	g_Mid_View2.Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.cl_Crash2, g_Character.c_Jump, g_Character.c_Jump_Speed, g_Character.end);
	g_Mid_View3.Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.cl_Crash2, g_Character.c_Jump, g_Character.c_Jump_Speed, g_Character.end);

	for(int i=0 ; i<22 ; i++)
		g_Road_F[i].Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.Speed_y, g_Character.Boost_Speed_y, g_Character.cl_Crash2);
	for(int i=0 ; i<6 ; i++)
		g_Road_S1[i].Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.Speed_y, g_Character.Boost_Speed_y, g_Character.cl_Crash2);

	for(int i=0 ; i<10; i++)
	{
		if(g_Garlic[i] != NULL)
			g_Garlic[i]->Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.Speed_y, g_Character.Boost_Speed_y, g_Character.cl_Crash2);
	}

	for(int i=0 ; i<2; i++)
	{
		if(g_Beef[i] != NULL)
			g_Beef[i]->Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.Speed_y, g_Character.Boost_Speed_y, g_Character.cl_Crash2);
	}

	for(int i=0 ; i<3 ; i++)
	{
		if(g_Enemy[i] != NULL)
			g_Enemy[i]->Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.Speed_y, g_Character.Boost_Speed_y, g_Character.cl_Crash2);
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap1[i] != NULL)
			g_Trap1[i]->Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.Speed_y, g_Character.Boost_Speed_y, g_Character.cl_Crash2);
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap2[i] != NULL)
			g_Trap2[i]->Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.Speed_y, g_Character.Boost_Speed_y, g_Character.cl_Crash2);
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap3[i] != NULL)
			g_Trap3[i]->Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.Speed_y, g_Character.Boost_Speed_y, g_Character.cl_Crash2);
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap4[i] != NULL)
			g_Trap4[i]->Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.Speed_y, g_Character.Boost_Speed_y, g_Character.cl_Crash2);
	}
	
	g_End.Frame(g_Gauge_F.c_booster, g_Character.c_Speed, g_Character.Speed_y, g_Character.Boost_Speed_y, g_Character.cl_Crash2, g_Character.c_Jump, g_Character.c_Jump_Speed);

	g_Eat.Frame();
	g_Kill.Frame();

	if(g_Limittime.everyEnd == true)
		g_Character.Stop();

	return 0;
}


int CStage1::UpDate()
{
	g_Gauge_F.Key_Act();
	g_Gauge_T.Key_Act();
	g_Gauge_F.Move(g_Character.c_vPos);
	g_Gauge_E.Move(g_Character.c_vPos);
	g_Gauge_T.Move(g_Character.c_vPos);
	for(int i=0 ; i<22 ; i++)
		g_Character.Ground_Crash(g_Road_F[i].rc_vPos, g_Road_F[i].rc_rect, i);
	for(int i=0 ; i<6 ; i++)
		g_Character.Line_Crash(g_Road_S1[i].rc_Line, i);
	for(int i=0 ; i<22 ; i++)
		g_Road_F[i].Move(g_Character.c_vPos);
	for(int i=0 ; i<6 ; i++)
		g_Road_S1[i].Move(g_Character.c_vPos);
	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap3[i] != NULL)
			g_Trap3[i]->Appear(g_Character.c_rect);
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap4[i] != NULL)
			g_Trap4[i]->Operate(g_Character.c_rect);
	}

	for(int i=0 ; i<10 ; i++)
	{
		if(g_Garlic[i] != NULL)
		{
			g_Garlic[i]->Move(g_Character.c_vPos);
			g_Character.Garlic_Crash(g_Garlic[i]->i_vPos, g_Garlic[i]->i_rect, i);
		}
	}

	for(int i=0 ; i<2 ; i++)
	{
		if(g_Beef[i] != NULL)
		{
			g_Beef[i]->Move(g_Character.c_vPos);
			g_Character.Beef_Crash(g_Beef[i]->i_vPos, g_Beef[i]->i_rect, i);
		}
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap1[i] != NULL)
		{
			g_Trap1[i]->Move(g_Character.c_vPos);
			g_Character.Thron1_Crash(g_Trap1[i]->t_vPos, g_Trap1[i]->t_rect, i, g_Gauge_T.c_trigger);
		}
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap2[i] != NULL)
		{
			g_Trap2[i]->Move(g_Character.c_vPos);
			g_Character.Thron2_Crash(g_Trap2[i]->t_vPos, g_Trap2[i]->t_rect, i, 1, g_Gauge_T.c_trigger);
		}
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap3[i] != NULL)
		{
			g_Trap3[i]->Move(g_Character.c_vPos);
			g_Character.Thron2_Crash(g_Trap3[i]->t_vPos, g_Trap3[i]->t_rect, i, 2, g_Gauge_T.c_trigger);
		}
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Trap4[i] != NULL)
		{
			g_Trap4[i]->Move(g_Character.c_vPos);
			g_Character.Snare_Crash(g_Trap4[i]->t_vPos, g_Trap4[i]->t_rect, g_Trap4[i]->ta_rect, i, g_Gauge_T.c_trigger);
		}
	}

	for(int i=0 ; i<3 ; i++)
	{
		if(g_Enemy[i] != NULL)
		{
			g_Enemy[i]->Move(g_Character.c_vPos);
			g_Character.Enemy_Crash(g_Enemy[i]->e_vPos, g_Enemy[i]->e_rect, i, g_Gauge_T.c_trigger);
		}
	}

	g_Character.End(g_End.a_vPos, g_End.a_rect);

	g_Gauge_F.Charge(g_Character.cig_Crash);
	g_Gauge_T.Charge(g_Character.c_trigger);

	for(int i=0 ; i<10 ; i++)
	{
		if(g_Character.ig_Delete[i] == true && g_Garlic[i] != NULL)
		{
			g_Eat.Move(g_Garlic[i]->i_vPos + D3DXVECTOR3(-28,-28,0));
			g_Character.Ig_Check();
			SAFE_DELETE(g_Garlic[i]);
		}
		if(g_Character.i_Effect[i] == true)
		{
			g_EFF[i]->PlayEFF(TRUE);
			g_Character.i_Effect[i] = false;
		}
	}

	for(int i=0 ; i<2 ; i++)
	{
		if(g_Character.ib_Delete[i] == true && g_Beef[i] != NULL)
		{
			g_Eat.Move(g_Beef[i]->i_vPos + D3DXVECTOR3(-28,-28,0));
			g_Character.Ib_Check();
			SAFE_DELETE(g_Beef[i]);
		}
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Character.t1_Delete[i] == true && g_Trap1[i] != NULL)
		{
			g_Kill.Move(g_Trap1[i]->t_vPos + D3DXVECTOR3(-92,-58,0));
			SAFE_DELETE(g_Trap1[i]);
		}
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Character.t2_Delete[i] == true && g_Trap2[i] != NULL)
		{
			g_Kill.Move(g_Trap2[i]->t_vPos + D3DXVECTOR3(-92,-58,0));
			SAFE_DELETE(g_Trap2[i]);
		}
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Character.t3_Delete[i] == true && g_Trap3[i] != NULL)
		{
			g_Kill.Move(g_Trap3[i]->t_vPos + D3DXVECTOR3(-92,-58,0));
			SAFE_DELETE(g_Trap3[i]);
		}
	}

	for(int i=0 ; i<5 ; i++)
	{
		if(g_Character.t4_Delete[i] == true && g_Trap4[i] != NULL)
		{
			g_Kill.Move(g_Trap4[i]->t_vPos + D3DXVECTOR3(-92,-58,0));
			SAFE_DELETE(g_Trap4[i]);
		}
	}

	for(int i=0 ; i<3 ; i++)
	{
		if(g_Character.e_Delete[i] == true && g_Enemy[i] != NULL)
		{
			g_Kill.Move(g_Enemy[i]->e_vPos + D3DXVECTOR3(-92,-58,0));
			SAFE_DELETE(g_Enemy[i]);
		}
	}

	g_Mid_View1.Move(g_Character.c_vPos);
	g_Mid_View2.Move(g_Character.c_vPos);
	g_Mid_View3.Move(g_Character.c_vPos);

	g_End.Move(g_Character.c_vPos);

	if((g_Character.end == true && g_Character.c_Speed == 0) || g_Limittime.everyEnd == true)
	{
		end = g_Clear.Key();
		if(end == true)
			state = 0;
	}

	return 0;
}


HRESULT CStage1::InitD3D()
{
	switch(loading_count)
	{
	case 0:
		/*g_BGM= new CSounds("Sound/sample.wav",100,0);
		g_BGM->PlayBGM(TRUE);*/
		loading_count++;
		break;
	case 1:
		g_Eating.Init("Texture/Item/Eat.png");
		g_Smoke.Init("Texture/smoke.png");
		g_Eat.Init(g_Eating);
		g_Kill.Init(g_Smoke);
		loading_count++;
		break;
	case 2:
		g_Vegetable.Init("Texture/Item/Garlic.png");
		g_Meat.Init("Texture/Item/Meat.png");
		g_Garlic[0]->Init(g_Vegetable,D3DXVECTOR3(600,550,0));
		g_Garlic[1]->Init(g_Vegetable,D3DXVECTOR3(650,550,0));
		g_Garlic[2]->Init(g_Vegetable,D3DXVECTOR3(1500,680,0));
		g_Garlic[3]->Init(g_Vegetable,D3DXVECTOR3(2000,600,0));
		g_Garlic[4]->Init(g_Vegetable,D3DXVECTOR3(2200,600,0));
		loading_count++;
		for(int i = 0; i<10 ; i++)
		g_EFF[i]= new CSounds("Sound/Shot.wav",1000,0);/////////////////////////////////////
		break;
	case 3:
		g_Garlic[5]->Init(g_Vegetable,D3DXVECTOR3(3000,600,0));
		g_Garlic[6]->Init(g_Vegetable,D3DXVECTOR3(3500,500,0));
		g_Garlic[7]->Init(g_Vegetable,D3DXVECTOR3(4000,500,0));
		g_Garlic[8]->Init(g_Vegetable,D3DXVECTOR3(4500,500,0));
		g_Garlic[9]->Init(g_Vegetable,D3DXVECTOR3(5000,1000,0));
		g_Beef[0]->Init(g_Meat,D3DXVECTOR3(500,550,0));
		g_Beef[1]->Init(g_Meat,D3DXVECTOR3(5500,1000,0));
		loading_count++;
		break;
	case 4:
		g_Thorn1.Init("Texture/trap/trap1.png");
		g_Thorn1_Mono.Init("Texture/trap/trap1_mono.png");
		g_Trap1[0]->Init(g_Thorn1,g_Thorn1_Mono,D3DXVECTOR3(600,300,0));
		g_Trap1[1]->Init(g_Thorn1,g_Thorn1_Mono,D3DXVECTOR3(1000,500,0));
		g_Trap1[2]->Init(g_Thorn1,g_Thorn1_Mono,D3DXVECTOR3(1500,650,0));
		g_Trap1[3]->Init(g_Thorn1,g_Thorn1_Mono,D3DXVECTOR3(2100,720,0));
		g_Trap1[4]->Init(g_Thorn1,g_Thorn1_Mono,D3DXVECTOR3(2500,720,0));
		loading_count++;
		break;
	case 5:
		g_Thorn2.Init("Texture/trap/trap2.png");
		g_Thorn2_Mono.Init("Texture/trap/trap2_mono.png");
		g_Trap2[0]->Init(g_Thorn2,g_Thorn2_Mono,D3DXVECTOR3(7000,1050,0));
		g_Trap2[1]->Init(g_Thorn2,g_Thorn2_Mono,D3DXVECTOR3(7800,1050,0));
		g_Trap2[2]->Init(g_Thorn2,g_Thorn2_Mono,D3DXVECTOR3(8200,1050,0));
		g_Trap2[3]->Init(g_Thorn2,g_Thorn2_Mono,D3DXVECTOR3(8700,1050,0));
		g_Trap2[4]->Init(g_Thorn2,g_Thorn2_Mono,D3DXVECTOR3(9500,1050,0));
		loading_count++;
		break;
	case 6:
		g_Thorn3.Init("Texture/trap/trap3.png");
		g_Thorn3_Mono.Init("Texture/trap/trap3_mono.png");
		g_Trap3[0]->Init(g_Thorn3,g_Thorn3_Mono,D3DXVECTOR3(5500,1050,0));
		g_Trap3[1]->Init(g_Thorn3,g_Thorn3_Mono,D3DXVECTOR3(6000,1050,0));
		g_Trap3[2]->Init(g_Thorn3,g_Thorn3_Mono,D3DXVECTOR3(6600,1050,0));
		g_Trap3[3]->Init(g_Thorn3,g_Thorn3_Mono,D3DXVECTOR3(6900,1050,0));
		g_Trap3[4]->Init(g_Thorn3,g_Thorn3_Mono,D3DXVECTOR3(7300,1050,0));
		loading_count++;
		break;
	case 7:
		g_Stone.Init("Texture/trap/trap4.png");
		g_Trap4[0]->Init(g_Stone,g_Stone,D3DXVECTOR3(500,500,0));
		g_Trap4[1]->Init(g_Stone,g_Stone,D3DXVECTOR3(5000,1050,0));
		g_Trap4[2]->Init(g_Stone,g_Stone,D3DXVECTOR3(9500,1050,0));
		g_Trap4[3]->Init(g_Stone,g_Stone,D3DXVECTOR3(10000,1050,0));
		g_Trap4[4]->Init(g_Stone,g_Stone,D3DXVECTOR3(10300,1050,0));
		loading_count++;
		break;
	case 8:
		g_Gauge_e.Init("Texture/gauge_empty.png");
		g_Gauge_E.Init(g_Gauge_e,D3DXVECTOR3(0,0,0));
		g_Gauge_f.Init("Texture/gauge.png");
		g_Gauge_F.Init(g_Gauge_f,D3DXVECTOR3(0,0,0));
		g_Gauge_t.Init("Texture/trigger_gauge.png");
		g_Gauge_T.Init(g_Gauge_t,D3DXVECTOR3(0,0,0));
		loading_count++;
		break;
	case 9:
		g_Tiger.Init("Texture/tiger_running.png");
		g_Tiger_Boost.Init("Texture/tiger_boost.png");
		g_Trigger.Init("Texture/ttigerfever3_16프레임3.png");
		g_Dust.Init("Texture/dust.png");
		g_Character.Init(g_Tiger, g_Tiger_Boost, g_Trigger, g_Dust, D3DXVECTOR3(100,500,0));
		loading_count++;
		break;
	case 10:
		g_Bear_Normal.Init("Texture/bear_normal.png");
		g_Bear_Stand.Init("Texture/bear_stand.png");
		g_Enemy[0]->Init(g_Bear_Stand, D3DXVECTOR3(500,500,0));
		g_Enemy[1]->Init(g_Bear_Stand, D3DXVECTOR3(700,500,0));
		g_Enemy[2]->Init(g_Bear_Stand, D3DXVECTOR3(900,500,0));
		loading_count++;
		break;
	case 11:
		g_Lake.Init("Texture/BackGround/Distant_View.png");
		g_Lake_Mono.Init("Texture/BackGround/Distant_View_Mono.png");
		g_BackGround.Init(g_Lake, g_Lake_Mono, D3DXVECTOR3(0,-200,0));
		loading_count++;
		break;
	case 12:
		g_Mid_Tree1.Init("Texture/BackGround/Mid_View1.png");
		g_Mid_Tree2.Init("Texture/BackGround/Mid_View2.png");
		g_Mid_Tree3.Init("Texture/BackGround/Mid_View3.png");
		g_Mid_Tree1_Mono.Init("Texture/BackGround/Mid_View1_Mono.png");
		g_Mid_Tree2_Mono.Init("Texture/BackGround/Mid_View2_Mono.png");
		g_Mid_Tree3_Mono.Init("Texture/BackGround/Mid_View3_Mono.png");
		loading_count++;
		break;
	case 13:
		g_Mid_View1.Init(g_Mid_Tree1, g_Mid_Tree1_Mono, D3DXVECTOR3(0,-400,0));
		g_Mid_View2.Init(g_Mid_Tree2, g_Mid_Tree2_Mono, D3DXVECTOR3(0,-100,0));
		g_Mid_View3.Init(g_Mid_Tree3, g_Mid_Tree3_Mono, D3DXVECTOR3(0,-100,0));
		loading_count++;
		break;
	case 14:
		g_Flatland.Init("Texture/BackGround/Road/flatland.png");
		g_Slope1.Init("Texture/BackGround/Road/slope1.png");
		g_Flatland_Mono.Init("Texture/BackGround/Road/flatland_mono.png");
		g_Slope1_Mono.Init("Texture/BackGround/Road/slope1_mono.png");
		loading_count++;
		break;
	case 15:
		g_Road_F[0].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(0,200,0), D3DXVECTOR3(0,600,0));
		g_Road_S1[0].Init(g_Slope1, g_Slope1_Mono, D3DXVECTOR3(1024,505,0), D3DXVECTOR3(1024,600,0), D3DXVECTOR3(2048,881,0));
		g_Road_F[1].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(2048,485,0), D3DXVECTOR3(2048,881,0));
		g_Road_S1[1].Init(g_Slope1, g_Slope1_Mono, D3DXVECTOR3(3072,790,0), D3DXVECTOR3(3072,881,0), D3DXVECTOR3(4096,1162,0));
		loading_count++;
		break;
	case 16:
		g_Road_F[2].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(4096,771,0), D3DXVECTOR3(4096,1162,0));
		g_Road_F[3].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(5120,771,0), D3DXVECTOR3(5120,1162,0));
		g_Road_F[4].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(6144,771,0), D3DXVECTOR3(6144,1162,0));
		g_Road_F[5].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(7168,771,0), D3DXVECTOR3(7168,1162,0));
		loading_count++;
		break;
	case 17:
		g_Road_F[6].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(8192,771,0), D3DXVECTOR3(8192,1162,0));
		g_Road_F[7].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(9216,771,0), D3DXVECTOR3(9216,1162,0));
		g_Road_F[8].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(10240,771,0), D3DXVECTOR3(10240,1162,0));
		g_Road_F[9].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(11264,771,0), D3DXVECTOR3(11264,1162,0));
		loading_count++;
		break;
	case 18:
		g_Road_F[10].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(12288,771,0), D3DXVECTOR3(12288,1162,0));
		g_Road_F[11].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(13312,771,0), D3DXVECTOR3(13312,1162,0));
		g_Road_F[12].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(14336,771,0), D3DXVECTOR3(14336,1162,0));
		g_Road_S1[2].Init(g_Slope1, g_Slope1_Mono, D3DXVECTOR3(15360,1076,0), D3DXVECTOR3(15360,1162,0), D3DXVECTOR3(16384,1443,0));
		loading_count++;
		break;
	case 19:
		g_Road_F[13].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(16384,1057,0), D3DXVECTOR3(16384,1443,0));
		g_Road_F[14].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(17408,1057,0), D3DXVECTOR3(17408,1443,0));
		g_Road_S1[3].Init(g_Slope1, g_Slope1_Mono, D3DXVECTOR3(18432,1362,0), D3DXVECTOR3(18432,1443,0), D3DXVECTOR3(19456,1724,0));
		g_Road_F[15].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(19456,1343,0), D3DXVECTOR3(19456,1724,0));
		loading_count++;
		break;
	case 20:
		g_Road_F[16].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(20480,1343,0), D3DXVECTOR3(20480,1724,0));
		g_Road_F[17].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(21504,1343,0), D3DXVECTOR3(21504,1724,0));
		g_Road_F[18].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(22528,1343,0), D3DXVECTOR3(22528,1724,0));
		g_Road_S1[4].Init(g_Slope1, g_Slope1_Mono, D3DXVECTOR3(23552,1648,0), D3DXVECTOR3(23552,1724,0), D3DXVECTOR3(24576,2005,0));
		loading_count++;
		break;
	case 21:
		g_Road_S1[5].Init(g_Slope1, g_Slope1_Mono, D3DXVECTOR3(24576,1934,0), D3DXVECTOR3(24576,2005,0), D3DXVECTOR3(25600,2286,0));
		g_Road_F[19].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(25600,1915,0), D3DXVECTOR3(25600,2286,0));
		g_Road_F[20].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(26624,1915,0), D3DXVECTOR3(26624,2286,0));
		g_Road_F[21].Init(g_Flatland, g_Flatland_Mono, D3DXVECTOR3(27648,1915,0), D3DXVECTOR3(27648,2286,0));
		loading_count++;
		break;
	case 22:
		g_Saint_Tree.Init("Texture/신목.png");
		g_End.Init(g_Saint_Tree, D3DXVECTOR3(27700,1600,0));
		loading_count++;
		break;
	case 23:
		g_LimitTime.Init("Texture/limit.png");
		g_Limittime.tInit(g_LimitTime,D3DXVECTOR3(440,20,0));
		g_Limittime.oInit(g_LimitTime,D3DXVECTOR3(490,20,0));
		loading_count++;
		break;
	case 24:
		g_Success.Init("Texture/clear.png");
		g_Fail.Init("Texture/gameover.png");
		g_Clear.Init(g_Success, D3DXVECTOR3(0,0,0));
		g_GameOver.Init(g_Fail, D3DXVECTOR3(0,0,0));
		loading_count++;
		break;
	case 25:
		g_Character.Shadow();
		loading_count = 0;
		state = 2;
		break;
	}

	SetCursor(false);
	return S_OK;
}


int CStage1::Loading()
{
	InitD3D();

	if( NULL == CDevice::GetDevice() )
		return -1;

	CDevice::GetDevice()->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 255, 255, 255 ), 1.0f, 0 );

	if( SUCCEEDED( CDevice::GetDevice()->BeginScene() ) )
	{
		g_Loading.Render();
	}
	CDevice::GetDevice()->EndScene();
	CDevice::GetDevice()->Present( NULL, NULL, NULL, NULL );

	return 0;
}


HRESULT CStage1::Loading_InitD3D()
{
	g_Footprint.Init("Texture/footprint.png");
	g_Loading_Back.Init("Texture/loading_back.png");
	g_Loading.Init(g_Loading_Back, g_Footprint, D3DXVECTOR3(0,0,0), D3DXVECTOR3(300,400,0));

	SetCursor(false);
	return S_OK;
}


int CStage1::Story()
{
	
	if( NULL == CDevice::GetDevice() )
		return -1;

	CDevice::GetDevice()->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 255, 255, 255 ), 1.0f, 0 );

	if( SUCCEEDED( CDevice::GetDevice()->BeginScene() ) )
	{
		g_Story.Render();
	}
	CDevice::GetDevice()->EndScene();
	CDevice::GetDevice()->Present( NULL, NULL, NULL, NULL );
	
	if(g_Story.storyend == true)
		state= 3;

	return 0;
}


HRESULT CStage1::Story_InitD3D()
{
	g_Storyboard.Init("Texture/Story.png");

	g_Story.Init(g_Storyboard, D3DXVECTOR3(0,0,0));

	SetCursor(false);
	return S_OK;
}