#include "Precompiled.h"
#include "D3DRenderRSI.h"


D3DRenderRSI::~D3DRenderRSI()
{
}

bool D3DRenderRSI::InitD3D(HWND &InNewHandle)
{
	if (!isD3DInitialized) 
	{
		if (InNewHandle == NULL)
		{
			return false;
		}
		if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		{
			return false;
		}

		SetBlendingMode(BlendingMode);

		D3DPRESENT_PARAMETERS d3dpp;
		ZeroMemory(&d3dpp, sizeof(d3dpp));

		d3dpp.Windowed = TRUE;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

		/// 디바이스 생성 및 설정
		if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, /// 기본 Graphic Card로 설정
			D3DDEVTYPE_HAL,/// 하드웨어 가속
			InNewHandle,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING, /// SoftWare로 Vertex Buffer를 처리한다.
			&d3dpp, &g_pd3dDevice)))
		{
			return false;
		}

		g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

		Handle = InNewHandle;
		isD3DInitialized = true;
	}
	return true;
}

void D3DRenderRSI::Shutdown()
{
	if (g_pVB != NULL)
	{
		g_pVB->Release();
	}

	if (g_pd3dDevice != NULL)
	{
		g_pd3dDevice->Release();
	}

	if (g_pD3D != NULL)
	{
		g_pD3D->Release();
	}
}

void D3DRenderRSI::SetBlendingMode(BlendingModes InNewBlendingMode)
{
	BlendingMode = InNewBlendingMode;
}

void D3DRenderRSI::SetLights(D3DXVECTOR3 * InDir, D3DLIGHTTYPE InLightType, float InRange, LinearColor InLightColor)
{
	D3DMATERIAL9 mtrl;
	ZeroMemory(&mtrl, sizeof(D3DMATERIAL9));

	D3DLIGHT9 light;

	light.Type = InLightType;

	light.Diffuse.r = InLightColor.R;
	light.Diffuse.g = InLightColor.G;
	light.Diffuse.b = InLightColor.B;

	D3DXVec3Normalize((D3DXVECTOR3*)&light.Direction, InDir);  

}

void D3DRenderRSI::Clear(const Color32 & InColor)
{
	if (g_pd3dDevice == NULL)
	{
		return;
	}
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(InColor.R, InColor.G, InColor.B), InColor.A, 0);

}

bool D3DRenderRSI::BeginFrame()
{
	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		return true;
	}
	return false;
}

void D3DRenderRSI::EndFrame()
{
	if (!isD3DInitialized)
	{
		return;
	}

	if (SUCCEEDED(g_pd3dDevice->EndScene()))
	{
	}
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void D3DRenderRSI::SetUniformMatrix(D3DMATRIX * InMatirx)
{
	if (isALLInitialized)
	{
		WorldMatrix = InMatirx[0];
		ViewMatrix = InMatirx[1];
		ProjectionMatrix = InMatirx[2];

		g_pd3dDevice->SetTransform(D3DTS_WORLD, &WorldMatrix);
		g_pd3dDevice->SetTransform(D3DTS_VIEW, &ViewMatrix);
		g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &ProjectionMatrix);

		return;
	}
}

void D3DRenderRSI::InitVertexBuffer(CUSTOMVERTEX InVertexData[], int VertexBufferLength ,int InVertexCount)
{
	if (isD3DInitialized)
	{
		if (FAILED(g_pd3dDevice->CreateVertexBuffer(VertexBufferLength * sizeof(CUSTOMVERTEX),
			0, D3DFVF_CUSTOMVERTEX,
			D3DPOOL_DEFAULT,
			&g_pVB, NULL)))
		{
			return;
		}

		CUSTOMVERTEX *pVertices;

		if (FAILED(g_pVB->Lock(0, 0, (void**)&pVertices, 0)))
		{
			return;
		}
		memcpy(pVertices, InVertexData, sizeof(CUSTOMVERTEX) * InVertexCount);
		g_pVB->Unlock();
	  
		isVBInitialized = true;
		isALLInitialized = true;
	}
	return;
}

void D3DRenderRSI::DrawTrianglePrimitive(UINT InVertexIndex, UINT InTriangleCount)
{
	if (isALLInitialized)
	{
		g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
		g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, InVertexIndex, InTriangleCount);
		return;
	}
}
