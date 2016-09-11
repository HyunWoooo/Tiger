#pragma once
#include "stdafx.h"

#ifndef DSBCAPS_CTRLDEFAULT  //6.0이후 부터 없어졌으므로 define해줌
#define DSBCAPS_CTRLDEFAULT  (DSBCAPS_CTRLFREQUENCY | DSBCAPS_CTRLPAN | DSBCAPS_CTRLVOLUME)
#endif

//입력값을 dB(decibel)로 바꿔주는 매크로 함수
#define DSVOLUME_TO_DB(volume)   ((DWORD)(-30*(100-volume))) 

 class CDirect_Sound
 {
 private:
	 LPDIRECTSOUND8  g_lpDS;  //다이렉트 사운드개체
	 friend class CDirect_Sound;
 public:
	 static CDirect_Sound* GetInstance();
	 BOOL CreateDirectSound(HWND hWnd);//DirectSound 객체를 생성하고 협력레벨을 설정한다.
	 void DeleteDirectSound();
	 static LPDIRECTSOUND8 Getg_lpDS(){return GetInstance()->g_lpDS;};
 };


 // 프렌드 클래스로 사운드 클래스 생성 프렌드 클래스 잘모름
 class CSounds
 {
 private:
	 BOOL g_ePlay;
	 BOOL g_bPlay;				//음악재생 맞는지 확인
	 HMMIO  hmmio;              //wave파일의 핸들

	 MMCKINFO    ckInRIFF;//부모 청크
	 MMCKINFO	 ckIn;  // 자식 청크
	 PCMWAVEFORMAT  pcmWaveFormat;
	 WAVEFORMATEX*     pWaveFormat;
	 DSBUFFERDESC dsbd;// DSBUFFERDESC 구조체 
	 LPDIRECTSOUNDBUFFER pDSBuffer;//보조 버퍼
	 LPDIRECTSOUND8 g_lpDS;//로드시 필요한 다이렉트 사운드개체
	 BOOL LoadWave(LPSTR lpFileName, LPDIRECTSOUNDBUFFER* lpDSBuffer);
 public:
	 CSounds(LPSTR lpFileName,LONG volume,LONG lPan);

	 BOOL SetVolume(LONG lVolume);	//볼륨크기 조절
	 BOOL SetPan(LONG lPan);		// 패닝크기 조절
	 void PlayBGM( BOOL Loop);		// 브금 함수(음악재생 맞는지 확인하는 매개변수)
	 void PlayEFF( BOOL Loop);
	 void Stop();

 };
