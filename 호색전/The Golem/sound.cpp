#include "stdafx.h"


CDirect_Sound* CDirect_Sound::GetInstance()
{
	static CDirect_Sound Instance;
	return &Instance;
}


BOOL CDirect_Sound::CreateDirectSound(HWND hWnd)
{
	 g_lpDS = NULL;
	
	if( DirectSoundCreate8(NULL, &g_lpDS, NULL) != DS_OK )//���̷�Ʈ ���� ��ü ����
		return FALSE;
	
	if( g_lpDS->SetCooperativeLevel( hWnd, DSSCL_NORMAL ) != DS_OK )
		return FALSE;

	return TRUE;
}


void CDirect_Sound::DeleteDirectSound()//���̷�Ʈ���� ��ü ����
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


BOOL CSounds::LoadWave(LPSTR lpFileName, LPDIRECTSOUNDBUFFER* lpDSBuffer)//��ο��� ������ �ε�
{	

	
	hmmio = mmioOpen(lpFileName, NULL, MMIO_ALLOCBUF|MMIO_READ);//���̺� ������ ����, MMIO �ڵ��� ��´�.
	if(hmmio==NULL)  
		return FALSE;
	
	ckInRIFF.fccType = mmioFOURCC('W', 'A', 'V', 'E');//���� ûũ �̸� ���
	if( (mmioDescend(hmmio, &ckInRIFF, NULL, MMIO_FINDRIFF)) != 0 )//RIFFûũ���� WAVE ûũ�� ã�� ������
	{
		mmioClose(hmmio, 0);  
		return FALSE;
	}
	
	ckIn.ckid = mmioFOURCC('f', 'm', 't', ' '); //���� ûũ �̸� ���(ûũ�� ��� 4���� �����ڵ��̹Ƿ� fmt�� �ڿ� ������ �ִ�.) 
	if( mmioDescend(hmmio, &ckIn, &ckInRIFF, MMIO_FINDCHUNK) != 0)//WAVEûũ���� fmtûũ�� ã�� ������
	{
		mmioClose(hmmio, 0);//���н� �����ִ� ���̺������� �ݴ´�.
		return FALSE; 
	}

	
	if( mmioRead(hmmio, (HPSTR) &pcmWaveFormat, sizeof(pcmWaveFormat))!= sizeof(pcmWaveFormat) )//fmt ûũ���� wav���� ������ �д´�.
	{
		mmioClose(hmmio, 0);//���н� �����ִ� ���̺������� �ݴ´�.
		return FALSE;
	}
	
	pWaveFormat = new WAVEFORMATEX;//WAVEFORMATEX�� �޸𸮿� �Ҵ�

	
	memcpy( pWaveFormat, &pcmWaveFormat, sizeof(pcmWaveFormat) );
	pWaveFormat->cbSize = 0;

	
	if( mmioAscend(hmmio, &ckIn, 0) )//fmtûũ���� WAVE ûũ�� �ö󰣴�.
	{
		mmioClose(hmmio, 0);
		return FALSE;
	}

	

	//ã�� ��������.
	ckIn.ckid = mmioFOURCC('d', 'a', 't', 'a');//������ ���� ûũ�̸��� ���
	if( mmioDescend(hmmio, &ckIn, &ckInRIFF, MMIO_FINDCHUNK) != 0 )
	{
		mmioClose(hmmio, 0);//�����ϸ� �����ִ� ���̺������� �ݰ� ����(�� ���ش�.)
		return FALSE;
	}

	BYTE*   pData = NULL;
	
	pData = new BYTE[ckIn.cksize] ;//data chunk ������ ��ŭ �޸� �Ҵ�

	
	mmioRead(hmmio, (LPSTR)pData, ckIn.cksize);//data chunk�� �ִ� ������ wave data�� �о� ���δ�.

	
	mmioClose(hmmio, 0);//������� ������ wav�����б⿡ ������ ���̹Ƿ�, �����ִ� wav������ �ݴ´�.

	
	ZeroMemory( &dsbd, sizeof(DSBUFFERDESC) );
	dsbd.dwSize = sizeof(DSBUFFERDESC);
	dsbd.dwFlags = DSBCAPS_CTRLDEFAULT | DSBCAPS_STATIC | DSBCAPS_LOCSOFTWARE ;

	dsbd.dwBufferBytes = ckIn.cksize;

	dsbd.lpwfxFormat = pWaveFormat;

	
	if( CDirect_Sound::Getg_lpDS()->CreateSoundBuffer( &dsbd, lpDSBuffer, NULL ) != DS_OK )//���� ������ ����
		return FALSE;

	VOID* pBuff1 = NULL;  //���� ������ ù��° �����ּ� 
	VOID* pBuff2 = NULL;  //���� ������ �ι�° �����ּ�
	DWORD dwLength;      //ù��° ����ũ��       
	DWORD dwLength2;     //�ι�° ����ũ��

	
	if( (*lpDSBuffer)->Lock( 0, dsbd.dwBufferBytes, &pBuff1, &dwLength,&pBuff2, &dwLength2, 0L ) != DS_OK )
	{
		(*lpDSBuffer)->Release();
		(*lpDSBuffer) = NULL;

		return FALSE;
	}   

	memcpy( pBuff1, pData, dwLength );                    //������ ù��° ������ ����
	memcpy( pBuff2, (pData+dwLength), dwLength2); //������ �ι�° ������ ����

	
	(*lpDSBuffer)->Unlock(pBuff1, dwLength, pBuff2, dwLength2 );
	pBuff1 = pBuff2= NULL;

	
	delete[] pData;
	delete pWaveFormat;//�Ҵ�� �޸� ����


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
	//���۰� ��������� ����

	if(pDSBuffer == NULL)  
		return;

	pDSBuffer->Stop();  //����

	g_bPlay = FALSE;
	pDSBuffer->SetCurrentPosition(0L); //ó����ġ��
}


BOOL CSounds::SetVolume( LONG lVolume)
{
	if( pDSBuffer->SetVolume( DSVOLUME_TO_DB(lVolume)) != DS_OK )
		return FALSE;
	return TRUE;  
}


BOOL CSounds::SetPan( LONG lPan)//����:-1000~1000
{
	if( pDSBuffer->SetPan(lPan) != DS_OK )
		return FALSE;
	return TRUE;
}