#pragma once
#include "RenderingSoftwareInterface.h"

class D3DRendererPipeLine
{
public:
	D3DRendererPipeLine() = default;
	D3DRendererPipeLine(class D3DRenderer* InOwner);
	~D3DRendererPipeLine();

public:
	void LoadResource();
	void LoadScene();
	void GraphicRenderFrame();

private:
	FORCEINLINE void DrawGizmo3D(D3DXMATRIXA16 InVMatrix, D3DXMATRIXA16 InPMatrix);

private:

	class D3DRenderer *Owner = nullptr;
	IRenderingSoftwareInterface *RSI = nullptr;

	// Resource

	Mesh *SharedMesh = new Mesh();

	GameObject *Object = new GameObject();


	GameObject *GOMainCamera = new GameObject();;
	Camera *mainCamera = new Camera();

	ScreenPoint ScreenSize;


};