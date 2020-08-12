#include "Precompiled.h"
#include "D3DRenderer.h"


bool D3DRenderer::D3DInit()
{

	if (SUCCEEDED(RSI->InitD3D(Handle)))
	{
		IsD3DDeviceInitialized = true;
		return true;
	}
	return false;
}

void D3DRenderer::OnDraw()
{
	if (!IsAllInitialized)
	{
		if (CurrentScreenSize.HasZero())
		{
			return;
		}

		if (!RSI->Initialized())
		{
			return;
		}


		IsRendererInitialized = true;

		IsAllInitialized = IsRendererInitialized && IsD3DDeviceInitialized;

		if (IsAllInitialized)
		{
			BindPipeLineClass();
		}
	}
	else
	{
		PreUpdate();
		Update();
		PostUpdate();
	}

	return;
}

void D3DRenderer::OnResize(const ScreenPoint & InNewScreenSize)
{
	CurrentScreenSize = InNewScreenSize;
	if (IsRendererInitialized)
	{
		//RSI->InitD3D();
	}
}

void D3DRenderer::ShutDown()
{
	RSI->Shutdown();
}

void D3DRenderer::SetHandle(const HWND& InHandle)
{
	if (Handle == NULL)
	{
		Handle = InHandle;
		return;
	}
}

void D3DRenderer::PreUpdate()
{
	RSI->Clear(Color32(0, 0, 0, 255));
	return;
}

void D3DRenderer::Update()
{
	/// 키 입력 움직임

}


void D3DRenderer::PostUpdate()
{

	if (RSI->BeginFrame())
	{
		RenderFrame();
		RSI->EndFrame();
	}

	/// Animation, 렌더링
}

void D3DRenderer::RenderFrame()
{
	/// 
	if (IsRenderPipeLineBinded)
	{
		RenderFrameFunc();
	}
}

void D3DRenderer::BindPipeLineClass()
{
	D3DPipeLine = std::make_unique<D3DRendererPipeLine>(this);
	if (D3DPipeLine != nullptr)
	{
		using namespace std::placeholders;
		RenderFrameFunc = std::bind(&D3DRendererPipeLine::GraphicRenderFrame, D3DPipeLine.get());
		IsRenderPipeLineBinded = true;
	}
}
