#pragma once

#include "WinD3D.h"
#include "DXFactory.h"
#include "Device.h"
#include "Graphics/Errors/D3DGraphicsError.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	class Swapchain
	{
	public:
		Swapchain(HWND hWnd);
		~Swapchain() noexcept = default;

	private:
		void Create(HWND hWnd);

	private:
		ComPtr<IDXGISwapChain> _pSwapchain;
		ComPtr<ID3D11Resource> _backBuffer;
	};
}