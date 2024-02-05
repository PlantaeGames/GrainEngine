#include "D3DRenderer.h"

namespace GrainEngine::Graphics
{
	void D3DRenderer::Present() const noexcept
	{
		_pSwapchain->Present(1u, 0u);
	}

	D3DRenderer::D3DRenderer(HWND hWnd)
	{
		HRESULT result = 0;

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

		// creating device and swapchain
		result = D3D11CreateDeviceAndSwapChain(
			nullptr,					// adapter, using default
			D3D_DRIVER_TYPE_HARDWARE,	// hardware accelerated
			nullptr,					// idk
			0,
			nullptr,					// feature levels to obtain
			0,							// get any feature level
			D3D11_SDK_VERSION,			// current installed
			&swapchainDesc, 			// swapchain properties
			&_pSwapchain,				
			&_pDevice,
			nullptr,					// obtained feature level
			&_pDeviceContext);

		Error::Log("D3D 11 Device and Swapchain Created.\n");
	}

	D3DRenderer::~D3DRenderer() noexcept
	{
		if (_pSwapchain != nullptr)
		{
			_pSwapchain->Release();
		}
		if (_pDeviceContext != nullptr)
		{
			_pDeviceContext->Release();
		}
		if (_pDevice != nullptr)
		{
			_pDevice->Release();
		}
	}
}