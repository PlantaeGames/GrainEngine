#include "Swapchain.h"

namespace GrainEngine::Graphics
{
	void Swapchain::Present()
	{
		CHECK_THROW_D3D_ERROR_INFO(
			_pSwapchain->Present(1u, 0u);
		);
	}

	void Swapchain::ClearScreen()
	{
		_backView.Clear();
	}

	void Swapchain::Create(HWND hWnd)
	{
		// swapchain properties
		DXGI_SWAP_CHAIN_DESC swapchainDesc = { 0 };
		swapchainDesc.BufferDesc.Width = 0;			// same as window
		swapchainDesc.BufferDesc.Height = 0;		// same as window
		swapchainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;	// RGBA (255,255,255,255) color format
		swapchainDesc.BufferDesc.RefreshRate.Numerator = 0;
		swapchainDesc.BufferDesc.RefreshRate.Denominator = 0;
		swapchainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swapchainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapchainDesc.BufferCount = 1;		// double buffering
		swapchainDesc.Windowed = true;
		swapchainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapchainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapchainDesc.SampleDesc.Count = 1;
		swapchainDesc.SampleDesc.Quality = 0;		// no anti analysis
		swapchainDesc.Flags = 0;
		swapchainDesc.OutputWindow = hWnd;

		CHECK_THROW_D3D_ERROR_INFO(
			DXFactory::GetInstance().GetFactory()->
				CreateSwapChain(Device::GetInstance().GetDevice().Get(), &swapchainDesc, &_pSwapchain);
		);

		CHECK_THROW_D3D_ERROR_INFO(
			_pSwapchain->GetBuffer(0u, __uuidof(ID3D11Resource), &_pBackBuffer);
		);

		_backView.New(_pBackBuffer);
	}

	Swapchain::Swapchain(HWND hWnd) :
		_backView()
	{
		Create(hWnd);
	}
}