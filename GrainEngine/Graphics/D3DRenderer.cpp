#include "D3DRenderer.h"

namespace GrainEngine::Graphics
{
	void D3DRenderer::Present() const
	{
		THROW_DERROR(_pSwapchain->Present(1u, 0u));
	}

	D3DRenderer::D3DRenderer(HWND hWnd)
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

		// creating device and swapchain
		unsigned int creationFlags = 0;
#ifdef _DEBUG
		creationFlags |= D3D10_CREATE_DEVICE_DEBUG;
#endif
		THROW_DERROR(D3D11CreateDeviceAndSwapChain(
			nullptr,					// adapter, using default
			D3D_DRIVER_TYPE_HARDWARE,	// hardware accelerated
			nullptr,					// idk
			creationFlags,
			nullptr,					// feature levels to obtain
			0,							// get any feature level
			D3D11_SDK_VERSION,			// current installed
			&swapchainDesc, 			// swapchain properties
			&_pSwapchain,				
			&_pDevice,
			nullptr,					// obtained feature level
			&_pDeviceContext));

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

	std::vector<std::string> D3DRenderer::DXGIInfoQueue::GetMessages() const
	{
		std::vector<std::string> messages {};
		unsigned long long currentIndex = _pInfoQueue->GetNumStoredMessages(DXGI_DEBUG_ALL);

		messages.emplace_back("\n[ Info ]\n");

		for (auto i = _lastMessageIndex; i < currentIndex; ++i)
		{
			SIZE_T len = 0;

			THROW_DERROR_NO_INFO(_pInfoQueue->GetMessage(DXGI_DEBUG_ALL, i, nullptr, &len));

			auto messageBytes = std::make_unique<byte[]>(len);
			if (!messageBytes)
			{
				THROW_LAST_ERROR();
			}
			auto* message = reinterpret_cast<DXGI_INFO_QUEUE_MESSAGE*>(messageBytes.get());

			THROW_DERROR_NO_INFO(_pInfoQueue->GetMessage(DXGI_DEBUG_ALL, i, message, &len));

			messages.emplace_back(message->pDescription);
		}

		return messages;
	}

	void D3DRenderer::DXGIInfoQueue::Set() noexcept
	{
		_lastMessageIndex = _pInfoQueue->GetNumStoredMessages(DXGI_DEBUG_ALL);
	}

	D3DRenderer::DXGIInfoQueue::DXGIInfoQueue()
	{
		typedef HRESULT(WINAPI *DXGIGetDebugInterface)(REFIID, void**);

		const auto hModDxgi = LoadLibraryExA("dxgidebug.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
		if (hModDxgi == nullptr)
		{
			THROW_LAST_ERROR();
		}

		const auto DxgiGetDebugInterface = reinterpret_cast<DXGIGetDebugInterface>(
				reinterpret_cast<void*>(GetProcAddress(hModDxgi, "DXGIGetDebugInterface")));

		if (DxgiGetDebugInterface == nullptr)
		{
			THROW_LAST_ERROR();
		}

		THROW_DERROR_NO_INFO(DxgiGetDebugInterface(__uuidof(IDXGIInfoQueue), 
				reinterpret_cast<void**>(&_pInfoQueue)));
	}

	D3DRenderer::DXGIInfoQueue::~DXGIInfoQueue() noexcept
	{
		if (_pInfoQueue != nullptr)
		{
			_pInfoQueue->Release();
		}
	}
}