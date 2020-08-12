#pragma once

#include <memory>
#include "RenderingSoftwareInterface.h"



class D3DRenderRSI : public IRenderingSoftwareInterface
{
public:
	D3DRenderRSI() = default;
	~D3DRenderRSI();

public:
	virtual bool InitD3D(HWND &InHandle) override;
	virtual void Shutdown() override;
	virtual void SetBlendingMode(BlendingModes InNewBlendingMode) override;

	virtual void SetLights(D3DXVECTOR3 *InDir, D3DLIGHTTYPE InLightType, float InRange, LinearColor InLightColor = LinearColor::White) override;

	virtual void Clear(const Color32 &InColor) override;
	virtual bool BeginFrame() override;
	virtual void EndFrame() override;

	virtual void SetUniformMatrix(D3DMATRIX *InMatirx) override;
	virtual void InitVertexBuffer(CUSTOMVERTEX InVertexData[], int VertexBufferLength, int InVertexCount) override;
	virtual void DrawTrianglePrimitive(UINT InVertexIndex, UINT InTriangleCount) override;

	virtual bool Initialized() const override { return  isD3DInitialized; };
	virtual bool VBInitializedVB() const override { return isVBInitialized; }
	virtual bool ALLInitialized() const override { return isALLInitialized; }

private:
	LPDIRECT3D9 g_pD3D = NULL;
	LPDIRECT3DDEVICE9 g_pd3dDevice = NULL;
	LPDIRECT3DVERTEXBUFFER9 g_pVB = NULL;
	HWND Handle = NULL;

	bool isD3DInitialized = false;
	bool isVBInitialized = false;
	bool isALLInitialized = false;

	BlendingModes BlendingMode = BlendingModes::Opaque;
	D3DXMATRIXA16 WorldMatrix;
	D3DXMATRIXA16 ViewMatrix;
	D3DXMATRIXA16 ProjectionMatrix;

};
