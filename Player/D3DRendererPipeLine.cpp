#include "Precompiled.h"
#include "D3DRendererPipeLine.h"
#include "D3DRenderer.h"

D3DRendererPipeLine::D3DRendererPipeLine(D3DRenderer *InOwner)
{
	RSI = InOwner->RSI.get();
	ScreenSize = InOwner->CurrentScreenSize;
	
	LoadResource();
	LoadScene();

	Owner = InOwner;
}

D3DRendererPipeLine::~D3DRendererPipeLine()
{
}

void D3DRendererPipeLine::LoadResource()
{

	const int vertexBuffetLength = 3;

	Object->SetComponent(new MeshFilter());

	CUSTOMVERTEX *vertices = new CUSTOMVERTEX[vertexBuffetLength]
	{
		{ D3DXVECTOR3(-1.0f, -1.0f, 0.5f),	Color32(255,	0,		0) },
		{ D3DXVECTOR3(1.0f, -1.0f, 0.5f),	Color32(0 ,		255,	0) },
		{ D3DXVECTOR3(0.0f, 2.0f, 0.5f),	Color32(0,		0,		255)}
	};

	SharedMesh->SetMesh(vertexBuffetLength, vertices);
	RSI->InitVertexBuffer(SharedMesh->GetVertexBuffer(), vertexBuffetLength, SharedMesh->GetVertexCount());

	delete[] vertices;

}

void D3DRendererPipeLine::LoadScene()
{
	GOMainCamera->SetComponent(mainCamera);
	mainCamera->transform->SetPosition(D3DXVECTOR3(0.0f, 0.0f, -10.0f));

	Object->GetComponent<MeshFilter>()->SetSharedMesh(SharedMesh);
	Object->transform.SetPosition(D3DXVECTOR3(0.f, 0.f, 100.f));
}

void D3DRendererPipeLine::GraphicRenderFrame()
{
	int StartVertex = 0;
	int TriangleCount = 1;

	D3DXMATRIXA16 matWorld;
	D3DXMATRIXA16 matView;
	D3DXMATRIXA16 matProj;

	float fov = mainCamera->GetFOV();
	float nearZ = mainCamera->GetNearZ();
	float farZ = mainCamera->GetFarZ();

	UINT iTime = timeGetTime() % 1000;
	FLOAT angle = iTime * (2.0f * D3DX_PI) / 1000.0f;

	D3DXMatrixRotationX(&matWorld, angle);

	mainCamera->GetLookAtMatrix(Object->transform, &matView);

	//D3DXMatrixLookAtLH(&matView, &mainCamera->transform->GetPosition(), &LookAt, &UpVec);

	D3DXMatrixPerspectiveFovLH(&matProj, Math::Deg2Rad(fov), 1.f, nearZ, farZ);

	D3DXMATRIXA16 m[3] = { matWorld, matView, matProj };

	RSI->SetUniformMatrix(m);
	RSI->DrawTrianglePrimitive(StartVertex, TriangleCount);
}

void D3DRendererPipeLine::DrawGizmo3D(D3DXMATRIXA16 InVMatrix, D3DXMATRIXA16 InPMatrix)
{

}