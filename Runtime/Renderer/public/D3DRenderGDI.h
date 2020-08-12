#pragma once

#include <windows.h>
#include <functional>
#include "ScreenPoint.h"
#include "LinearColor.h"

class D3DRenderGDI
{
public:
	D3DRenderGDI() = default;
	~D3DRenderGDI()
	{
	}

public:
	bool InitializedGDI(const ScreenPoint & InScreenSize)
	{
		ScreenSize = InScreenSize;
	}

	ScreenPoint ScreenSize;
};