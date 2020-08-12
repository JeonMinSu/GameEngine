#pragma once

#include <memory>
#include <functional>
#include "RenderingSoftwareInterface.h"
#include "D3DRendererPipeLine.h"


class D3DRenderer
{
public:
	D3DRenderer(IRenderingSoftwareInterface *InRSI) : RSI(InRSI) { };

public:
	const ScreenPoint& GetScreenSize() { return CurrentScreenSize; }

public:
	bool D3DInit();
	void OnDraw();
	void OnResize(const ScreenPoint& InNewScreenSize);
	void ShutDown();

	void SetHandle(const HWND& InHandle);

private:
	FORCEINLINE void PreUpdate();
	FORCEINLINE void Update();
	FORCEINLINE void PostUpdate();
	FORCEINLINE void RenderFrame();

private:
	bool IsAllInitialized = false;
	bool IsD3DDeviceInitialized = false;
	bool IsRendererInitialized = false;
	bool IsRenderPipeLineBinded = false;

	// Screen Size
	ScreenPoint CurrentScreenSize;
	// Renderer Interface

	std::unique_ptr<IRenderingSoftwareInterface> RSI;

	friend class D3DRendererPipeLine;
	std::unique_ptr<D3DRendererPipeLine> D3DPipeLine;

	std::function<void()> RenderFrameFunc;


	FORCEINLINE void BindPipeLineClass();

	HWND Handle;


};