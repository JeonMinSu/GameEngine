
#include "Precompiled.h"
#include "D3DRenderRSI.h"
#include "WindowsPlayer.h"
#include "D3DRenderer.h"

///  1. 윈도우 생성
///  2. DirectX 객체 초기화
///  3. Vertex Buffer 초기화
///  4. 메세지 루프 ->
///  5. 렌더링		
///		1) 후면 퍼버 지우기
///		2) 행렬 설정(월드 행렬 -> 뷰 행렬 -> 프로젝션 행렬)
///		3) Vertex Buffer 그리기 
///  6. DirectX 객체 소거

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR pCmdLine, int nCmdShow)
{

	ScreenPoint defScreenSize(1280, 800);
	D3DRenderer renderer(new D3DRenderRSI());

	WindowsPlayer::gOnResizeFunc = [&renderer](const ScreenPoint& InNewScreenSize )
	{
		if (!InNewScreenSize.HasZero())
		{
			renderer.OnResize(InNewScreenSize);
		}
	};

	WindowsPlayer::gSetHandleFunc = [&renderer](const HWND &InHandle)
	{
		if (InHandle)
		{
			renderer.SetHandle(InHandle);
		}
	};

 	if (!WindowsPlayer::Create(hInstance, defScreenSize))
	{
		return -1;
	}


	if (renderer.D3DInit())
	{
		WindowUtil::Show(WindowsPlayer::gHwnd);
		WindowUtil::CenterWindow(WindowsPlayer::gHwnd);


		while (WindowsPlayer::Tick())
		{
			renderer.OnDraw();
		}

		renderer.ShutDown();
		WindowsPlayer::Destroy();
	}
	else
	{
		::MessageBox(nullptr, _T("D3D Not Initialize!"), _T("Error!"), MB_ICONEXCLAMATION | MB_OK);
		return -1;
	}

	return 0;
}



//static float previousTimer = 0.f;
//static float updatePeriod = 500.f;
	/// Rendering 처리
	//D3DDevicePlayer::Render();

/*	float currentTime = 0.f;
	if (currentTime - previousTimer > updatePeriod)
	{
		float frameFPS = 60.0f;
		WindowsPlayer::SetWindowsStatTitle(60, 0);
		previousTimer = currentTime;
	}
*/
//}
//}

/*else if (!SUCCEEDED(D3DDevicePlayer::Init3D(WindowsPlayer::gHwnd)))
{
	return FALSE;
}*/
/*
if (SUCCEEDED(D3DDevicePlayer::InitVB()))
{*/