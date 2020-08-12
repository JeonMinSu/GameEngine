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
	// rhw -> ���� ��ǥ���� W�� �� ���� ������ ��ȯ�� �Ϸ�� Vertex
	D3DXVECTOR3 Position;	// Vertex�� ��ȯ�� ��ǥ
	Color32 Color;		// Vertex Color
	D3DXVECTOR3 Normal;
};

/// Custom Vertex
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_NORMAL)

