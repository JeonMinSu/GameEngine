#pragma once

#include <Windows.h>
#include <functional>
#include "Res/Resource.h"


namespace WindowsPlayer
{
	static HINSTANCE gInstance;
	static HWND gHwnd;
	static std::function<void(ScreenPoint& InNewScreenSize)> gOnResizeFunc;
	static std::function<void(HWND &Handle)> gSetHandleFunc;

	static const TCHAR *gClassName = _T("D3D_TUTORIAL");
	static TCHAR gTitle[64];
	static TCHAR gPlayTitle[128];


	inline LRESULT CALLBACK WndProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_DISPLAYCHANGE:
		case WM_SIZE:
		{
			int newWidth = (lParam & 0xffff);
			int newHeight = ((lParam >> 16) & 0xffff);
			if (gOnResizeFunc)
			{
				ScreenPoint InNewScreenSize(newWidth, newHeight);
				gOnResizeFunc(InNewScreenSize);
			}
			break;
		}
		case WM_CLOSE:
		{
			DestroyWindow(handle);
			return 0;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		case WM_SYSCOMMAND:
		{
			if (wParam == SC_SCREENSAVE || wParam == SC_MONITORPOWER || wParam == SC_KEYMENU)
			{
				return 0;
			}
			break;
		}
		}

		return DefWindowProc(handle, msg, wParam, lParam);
	}

	inline BOOL Create(HINSTANCE InhInstance, const ScreenPoint &InDafaultScreenSize )
	{
		gInstance = InhInstance;

	#define SIZEOF(a) ((int)(sizeof(a) / sizeof((a)[0])))
		::LoadString(gInstance, IDS_APP_TITLE, gTitle, SIZEOF(gTitle));

		/// Window 객체 속성 지정
		WNDCLASSEX wcex;

		memset(&wcex, 0, sizeof(wcex));
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wcex.lpfnWndProc = WndProc;
		wcex.hInstance = gInstance;
		wcex.hIcon = LoadIcon(gInstance, MAKEINTRESOURCE(IDI_GAMEENGINE));
		wcex.hIconSm = LoadIcon(gInstance, MAKEINTRESOURCE(IDI_SMALL));
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = gClassName;


		/// Window 객체 저장
		if (!::RegisterClassEx(&wcex))
		{
			::MessageBox(nullptr, _T("Window registration failed!"), _T("Error!"), MB_ICONEXCLAMATION | MB_OK);
			return FALSE;
		}

		RECT rect;
		rect.left = 0;
		rect.top = 0;
		rect.right = InDafaultScreenSize.X - 1;
		rect.bottom = InDafaultScreenSize.Y - 1;
		::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		int WindowWidth = rect.right - rect.left + 1;
		int WindowHeight = rect.bottom - rect.top - 1;

		//hWnd = 
		//::CreateWindow(InClassName, InClassName, WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX, 
		//0, 0, InWidth, InHeight, GetDesktopWindow(), NULL, InhInstance, NULL);


		/// Windwo 생성
		gHwnd = ::CreateWindow(gClassName, gTitle, WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,
			(GetSystemMetrics(SM_CXFULLSCREEN) - WindowWidth) / 2, (GetSystemMetrics(SM_CYFULLSCREEN) - WindowHeight) / 2,
			WindowWidth, WindowHeight, NULL, NULL, gInstance, NULL);

		if (!gHwnd)
		{
			::MessageBox(nullptr, _T("Window Create Failed!"), _T("Error!"), MB_ICONEXCLAMATION | MB_OK);
			return FALSE;
		}

		if (gSetHandleFunc) gSetHandleFunc(gHwnd);

		return TRUE;
	}

	/// Window Update
	inline bool Tick()
	{
		MSG msg;
		ZeroMemory(&msg, sizeof(msg));

		/// Message 처리(INPUT SOUND ANIMATION 등...)
		/// PeekMessage() -> 메시지가 없으면 즉시 다음 문장으로
		/// GetMessage() -> 새로운 메시지가 발생 할 때까지 무한정 대기

		while (::PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				return false;
		}

		return true;
	}


	inline void Destroy()
	{
		UnregisterClass(gClassName, gInstance);
		DestroyWindow(gHwnd);
	}

	inline void SetWindowsStatTitle(float frameFPS, int cullingCount)
	{
		_stprintf_s(gPlayTitle, _T("%s Current : %.2fFPS, %d object culled.", gTitle, 10, 10));
		::SetWindowText(gHwnd, gPlayTitle);
	}
};