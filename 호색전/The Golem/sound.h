#pragma once
#include "stdafx.h"

#ifndef DSBCAPS_CTRLDEFAULT  //6.0���� ���� ���������Ƿ� define����
#define DSBCAPS_CTRLDEFAULT  (DSBCAPS_CTRLFREQUENCY | DSBCAPS_CTRLPAN | DSBCAPS_CTRLVOLUME)
#endif

//�Է°��� dB(decibel)�� �ٲ��ִ� ��ũ�� �Լ�
#define DSVOLUME_TO_DB(volume)   ((DWORD)(-30*(100-volume))) 

 class CDirect_Sound
 {
 private:
	 LPDIRECTSOUND8  g_lpDS;  //���̷�Ʈ ���尳ü
	 friend class CDirect_Sound;
 public:
	 static CDirect_Sound* GetInstance();
	 BOOL CreateDirectSound(HWND hWnd);//DirectSound ��ü�� �����ϰ� ���·����� �����Ѵ�.
	 void DeleteDirectSound();
	 static LPDIRECTSOUND8 Getg_lpDS(){return GetInstance()->g_lpDS;};
 };


 // ������ Ŭ������ ���� Ŭ���� ���� ������ Ŭ���� �߸�
 class CSounds
 {
 private:
	 BOOL g_ePlay;
	 BOOL g_bPlay;				//������� �´��� Ȯ��
	 HMMIO  hmmio;              //wave������ �ڵ�

	 MMCKINFO    ckInRIFF;//�θ� ûũ
	 MMCKINFO	 ckIn;  // �ڽ� ûũ
	 PCMWAVEFORMAT  pcmWaveFormat;
	 WAVEFORMATEX*     pWaveFormat;
	 DSBUFFERDESC dsbd;// DSBUFFERDESC ����ü 
	 LPDIRECTSOUNDBUFFER pDSBuffer;//���� ����
	 LPDIRECTSOUND8 g_lpDS;//�ε�� �ʿ��� ���̷�Ʈ ���尳ü
	 BOOL LoadWave(LPSTR lpFileName, LPDIRECTSOUNDBUFFER* lpDSBuffer);
 public:
	 CSounds(LPSTR lpFileName,LONG volume,LONG lPan);

	 BOOL SetVolume(LONG lVolume);	//����ũ�� ����
	 BOOL SetPan(LONG lPan);		// �д�ũ�� ����
	 void PlayBGM( BOOL Loop);		// ��� �Լ�(������� �´��� Ȯ���ϴ� �Ű�����)
	 void PlayEFF( BOOL Loop);
	 void Stop();

 };
