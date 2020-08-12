#pragma once

#include "LinearColor.h"
#include "RSIDataTypes.h"

interface IRenderingSoftwareInterface
{
public:

	virtual bool InitD3D(HWND  &nHandle) = 0;
	virtual void Shutdown() = 0;
	virtual void SetBlendingMode(BlendingModes InNewBlendingMode) = 0;
	
	virtual void SetLights (D3DXVECTOR3 *InDir, D3DLIGHTTYPE InLightType, float InRange, LinearColor InLightColor = LinearColor::White) = 0;

	virtual void Clear(const Color32 &InColor) = 0;
	virtual bool BeginFrame() = 0;
	virtual void EndFrame() = 0;

	virtual void SetUniformMatrix(D3DMATRIX *InMatirx) =  0;
	virtual void InitVertexBuffer(CUSTOMVERTEX InVertexData[], int VertexBufferLength, int InVertexCount) = 0;
	virtual void DrawTrianglePrimitive(UINT InVertexIndex, UINT InTriangleCount) = 0;

	virtual bool Initialized() const = 0;
	virtual bool VBInitializedVB() const = 0;
	virtual bool ALLInitialized() const = 0;


};