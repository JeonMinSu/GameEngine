#pragma once
#include <Windows.h>

namespace WindowUtil
{
	inline void GetWindowSize(HWND handle, float *width, float *height)
	{
		RECT rect;
		::GetClientRect(handle, &rect);
		*width = static_cast<float>(rect.right - rect.left);
		*height = static_cast<float>(rect.bottom - rect.top);
	}

	inline void Show(HWND handle)
	{
		//if ()
		//{
		//	::MessageBox(nullptr, _T("asdf"), _T("awdf"), MB_ICONEXCLAMATION || MB_OK);
		//	return FALSE;
		//}
		::ShowWindow(handle, SW_SHOW);
		::UpdateWindow(handle);
		::SetForegroundWindow(handle);
		::SetFocus(handle);
	}

	inline void CenterWindow(HWND handle)
	{
		RECT rc, rcOwner, rcWindow;

		HWND ownerHandle = GetDesktopWindow();
		GetWindowRect(ownerHandle, &rcOwner);
		GetWindowRect(handle, &rcWindow);
		CopyRect(&rc, &rcOwner);

		OffsetRect(&rcWindow, -rcWindow.left, -rcWindow.top);
		OffsetRect(&rc, -rc.left, -rc.top);
		OffsetRect(&rc, -rcWindow.right, -rcWindow.bottom);

		::SetWindowPos(handle, HWND_TOP,
			rcOwner.left + (rc.right / 2),
			rcOwner.top + (rc.bottom / 2),
			0, 0,
			SWP_NOSIZE);
	}
};