#pragma once
#include "Precompiled.h"
#pragma comment(lib, "d3d9.lib")
#include <d3dx9.h>


enum class BlendingModes
{
	Opaque,
	AlphaBlending
};

struct CUSTOMVERTEX
{
	// rhw -> 동차 좌표계의 W값 이 값이 있으면 변환이 완료된 Vertex
	D3DXVECTOR3 Position;	// Vertex의 변환된 좌표
	Color32 Color;		// Vertex Color
	D3DXVECTOR3 Normal;
};

/// Custom Vertex
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_NORMAL)

