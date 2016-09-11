#include "stdafx.h"


CDirect_Sound* CDirect_Sound::GetInstance()
{
	static CDirect_Sound Instance;
	return &Instance;
}


BOOL CDirect_Sound::CreateDirectSound(HWND hWnd)
{
	 g_lpDS = NULL;
	
	if( DirectSoundCreate8(NULL, &g_lpDS, NULL) != DS_OK )//다이렉트 사운드 개체 생성
		return FALSE;
	
	if( g_lpDS->SetCooperativeLevel( hWnd, DSSCL_NORMAL ) != DS_OK )
		return FALSE;

	return TRUE;
}


void CDirect_Sound::DeleteDirectSound()//다이렉트사운드 개체 제거
{
	g_lpDS->Release();

	g_lpDS = NULL;
}


CSounds::CSounds(LPSTR lpFileName,LONG volume,LONG lPan)
{
	pDSBuffer=NULL;
	LoadWave(lpFileName,&pDSBuffer);		
	g_bPlay=FALSE;
	SetVolume(volume);
	SetPan(lPan);
	g_lpDS=CDirect_Sound::Getg_lpDS();
}


BOOL CSounds::LoadWave(LPSTR lpFileName, LPDIRECTSOUNDBUFFER* lpDSBuffer)//경로에서 파일을 로딩
{	

	
	hmmio = mmioOpen(lpFileName, NULL, MMIO_ALLOCBUF|MMIO_READ);//웨이브 파일을 열어, MMIO 핸들을 얻는다.
	if(hmmio==NULL)  
		return FALSE;
	
	ckInRIFF.fccType = mmioFOURCC('W', 'A', 'V', 'E');//하위 청크 이름 등록
	if( (mmioDescend(hmmio, &ckInRIFF, NULL, MMIO_FINDRIFF)) != 0 )//RIFF청크에서 WAVE 청크를 찾아 내려감
	{
		mmioClose(hmmio, 0);  
		return FALSE;
	}
	
	ckIn.ckid = mmioFOURCC('f', 'm', 't', ' '); //하위 청크 이름 등록(청크는 모두 4개의 문자코드이므로 fmt는 뒤에 공백이 있다.) 
	if( mmioDescend(hmmio, &ckIn, &ckInRIFF, MMIO_FINDCHUNK) != 0)//WAVE청크에서 fmt청크를 찾아 내려감
	{
		mmioClose(hmmio, 0);//실패시 열려있는 웨이브파일을 닫는다.
		return FALSE; 
	}

	
	if( mmioRead(hmmio, (HPSTR) &pcmWaveFormat, sizeof(pcmWaveFormat))!= sizeof(pcmWaveFormat) )//fmt 청크에서 wav파일 포맷을 읽는다.
	{
		mmioClose(hmmio, 0);//실패시 열려있는 웨이브파일을 닫는다.
		return FALSE;
	}
	
	pWaveFormat = new WAVEFORMATEX;//WAVEFORMATEX를 메모리에 할당

	
	memcpy( pWaveFormat, &pcmWaveFormat, sizeof(pcmWaveFormat) );
	pWaveFormat->cbSize = 0;

	
	if( mmioAscend(hmmio, &ckIn, 0) )//fmt청크에서 WAVE 청크로 올라간다.
	{
		mmioClose(hmmio, 0);
		return FALSE;
	}

	

	//찾아 내려간다.
	ckIn.ckid = mmioFOURCC('d', 'a', 't', 'a');//내려갈 하위 청크이름을 등록
	if( mmioDescend(hmmio, &ckIn, &ckInRIFF, MMIO_FINDCHUNK) != 0 )
	{
		mmioClose(hmmio, 0);//실패하면 열려있는 웨이브파일을 닫고 리턴(꼭 해준다.)
		return FALSE;
	}

	BYTE*   pData = NULL;
	
	pData = new BYTE[ckIn.cksize] ;//data chunk 사이즈 만큼 메모리 할당

	
	mmioRead(hmmio, (LPSTR)pData, ckIn.cksize);//data chunk에 있는 순수한 wave data를 읽어 들인다.

	
	mmioClose(hmmio, 0);//여기까지 왔으면 wav파일읽기에 성공한 것이므로, 열려있는 wav파일을 닫는다.

	
	ZeroMemory( &dsbd, sizeof(DSBUFFERDESC) );
	dsbd.dwSize = sizeof(DSBUFFERDESC);
	dsbd.dwFlags = DSBCAPS_CTRLDEFAULT | DSBCAPS_STATIC | DSBCAPS_LOCSOFTWARE ;

	dsbd.dwBufferBytes = ckIn.cksize;

	dsbd.lpwfxFormat = pWaveFormat;

	
	if( CDirect_Sound::Getg_lpDS()->CreateSoundBuffer( &dsbd, lpDSBuffer, NULL ) != DS_OK )//사운드 버퍼의 생성
		return FALSE;

	VOID* pBuff1 = NULL;  //사운드 버퍼의 첫번째 영역주소 
	VOID* pBuff2 = NULL;  //사운드 버퍼의 두번째 영역주소
	DWORD dwLength;      //첫번째 영역크기       
	DWORD dwLength2;     //두번째 영역크기

	
	if( (*lpDSBuffer)->Lock( 0, dsbd.dwBufferBytes, &pBuff1, &dwLength,&pBuff2, &dwLength2, 0L ) != DS_OK )
	{
		(*lpDSBuffer)->Release();
		(*lpDSBuffer) = NULL;

		return FALSE;
	}   

	memcpy( pBuff1, pData, dwLength );                    //버퍼의 첫번째 영역을 복사
	memcpy( pBuff2, (pData+dwLength), dwLength2); //버퍼의 두번째 영역을 복사

	
	(*lpDSBuffer)->Unlock(pBuff1, dwLength, pBuff2, dwLength2 );
	pBuff1 = pBuff2= NULL;

	
	delete[] pData;
	delete pWaveFormat;//할당된 메모리 해제


	return TRUE;   
}


void CSounds:: PlayBGM(BOOL Loop)
{
	if( pDSBuffer==NULL ) 
		return;
	
	if( !pDSBuffer->Play( 0, 0, (Loop) ? 1 :0 ) )
		return;
	g_bPlay = Loop;
}

void CSounds:: PlayEFF(BOOL Loop)
{
	if( pDSBuffer==NULL ) 
		return;
	
	if( !pDSBuffer->Play( 0, 0, (Loop) ? 0 :0 ) )
		return;
	g_ePlay = Loop;
}


void CSounds::Stop()
{
	//버퍼가 비어있으면 종료

	if(pDSBuffer == NULL)  
		return;

	pDSBuffer->Stop();  //멈춤

	g_bPlay = FALSE;
	pDSBuffer->SetCurrentPosition(0L); //처음위치로
}


BOOL CSounds::SetVolume( LONG lVolume)
{
	if( pDSBuffer->SetVolume( DSVOLUME_TO_DB(lVolume)) != DS_OK )
		return FALSE;
	return TRUE;  
}


BOOL CSounds::SetPan( LONG lPan)//범위:-1000~1000
{
	if( pDSBuffer->SetPan(lPan) != DS_OK )
		return FALSE;
	return TRUE;
}