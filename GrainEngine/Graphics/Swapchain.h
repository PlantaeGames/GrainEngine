#pragma once

#include "WinD3D.h"
#include "DXFactory.h"
#include "Device.h"
#include "RenderTargetView.h"
#include "PipelineComponent.h"
#include "Errors/Error.h"
#include "Window.h"
#include "Graphics/Errors/D3DGraphicsError.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	class Swapchain : public PipelineComponent
	{
	public:
		Swapchain(const Window* pWindow);
		~Swapchain() noexcept = default;

		void Bind() override;
		void ClearScreen();
		void Present();

	private:
		void Create(const Window* pWindow);

	private:
		ComPtr<IDXGISwapChain> _pSwapchain;
		ComPtr<ID3D11Resource> _pBackBuffer;
		RenderTargetView _backView;

		unsigned int _windowWidth = 0u;
		unsigned int _windowHeight = 0u;
	};
}