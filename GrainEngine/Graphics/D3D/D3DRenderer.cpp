#include "D3DRenderer.h"

namespace GrainEngine::Graphics
{
	void D3DRenderer::LoadShader(const std::string& name, ID3DBlob** ppShaderBin) const
	{
		assert(name.length() > 0);

		std::wstringstream wideName;
		wideName << name.c_str();

		THROW_DERROR(D3DReadFileToBlob(wideName.str().c_str(), ppShaderBin));
	}

	void D3DRenderer::DrawTriangle()
	{
		const Vertex vertices[] = {
			{ 0.0f, 0.5f },
			{ 0.5f, -0.5f },
			{ -0.5f, -0.5f }
		};

		// creating vertex buffer
		ComPtr<ID3D11Buffer> pVertexBuffer;

		D3D11_BUFFER_DESC bufferDesc = { 0 };
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = sizeof(vertices);
		bufferDesc.StructureByteStride = sizeof(Vertex);
		bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0u;
		bufferDesc.MiscFlags = 0u;

		D3D11_SUBRESOURCE_DATA verticesData = { 0 };
		verticesData.pSysMem = vertices;

		THROW_DERROR(_pDevice->CreateBuffer(&bufferDesc, &verticesData, &pVertexBuffer));

		const UINT strides = sizeof(Vertex);
		const UINT offset = 0u;

		// binding vertex buffer
		_pDeviceContext->IASetVertexBuffers(0u, 1u, pVertexBuffer.GetAddressOf(), &strides, &offset);

		// binding vertex shader
		ComPtr<ID3D11VertexShader> pVertexShader;
		ComPtr<ID3DBlob> pVertexShaderBin;

		LoadShader("Shaders\\Default\\Vertex.cso", &pVertexShaderBin);

		THROW_DERROR(_pDevice->CreateVertexShader(pVertexShaderBin->GetBufferPointer(),
			pVertexShaderBin->GetBufferSize(), nullptr, &pVertexShader));
		
		_pDeviceContext->VSSetShader(pVertexShader.Get(), nullptr, 0u);

		// binding pixel shader
		ComPtr<ID3D11PixelShader> pPixelShader;
		ComPtr<ID3DBlob> pPixelShaderBin;

		LoadShader("Shaders\\Default\\Pixel.cso", &pPixelShaderBin);

		THROW_DERROR(_pDevice->CreatePixelShader(pPixelShaderBin->GetBufferPointer(),
			pPixelShaderBin->GetBufferSize(), nullptr, &pPixelShader));

		_pDeviceContext->PSSetShader(pPixelShader.Get(), nullptr, 0);

		ComPtr<ID3D11InputLayout> pInputLayout;

		const D3D11_INPUT_ELEMENT_DESC inputElementDescs[]
		{
			{ "Position", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA }
		};

		THROW_DERROR(_pDevice->CreateInputLayout(inputElementDescs, 1u, 
			pVertexShaderBin->GetBufferPointer(), pVertexShaderBin->GetBufferSize(),
			&pInputLayout));

		_pDeviceContext->IASetInputLayout(pInputLayout.Get());

		// binding render target / back buffer
		_pDeviceContext->OMSetRenderTargets(1u, _pBackTarget.GetAddressOf(), nullptr);

		// setting input assembler
		_pDeviceContext->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		// binding view port
		D3D11_VIEWPORT viewPort = { 0 };
		viewPort.Height = 600.0f;
		viewPort.Width = 800.0f;
		viewPort.MinDepth = 0.0f;
		viewPort.MaxDepth = 1.0f;
		viewPort.TopLeftX = 0.0f;
		viewPort.TopLeftY = 0.0f;
		_pDeviceContext->RSSetViewports(1u, &viewPort);

		CHECK_DERROR(_pDeviceContext->Draw(3u, 0u));
	}

	void D3DRenderer::Present()
	{
		THROW_DERROR(_pSwapchain->Present(1u, 0u));
	}

	void D3DRenderer::Clear() const noexcept
	{
		const float color[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		ClearBackBuffer(color);
	}

	void D3DRenderer::ClearBackBuffer(const float color[4]) const noexcept
	{
		_pDeviceContext->ClearRenderTargetView(_pBackTarget.Get(), color);
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

		// getting back buffer render target
		ComPtr<ID3D11Resource> pBackBuffer {};
		THROW_DERROR(_pSwapchain->GetBuffer(0, __uuidof(ID3D11Resource), &pBackBuffer));
		THROW_DERROR(_pDevice->CreateRenderTargetView(pBackBuffer.Get(), nullptr, &_pBackTarget));

		Error::Log("Clearing Screen.\n");

		float clearColor[] { 0.0f, 1.0f, 0.0f, 1.0f };
		ClearBackBuffer(clearColor);

	}
#ifdef _DEBUG
	bool D3DRenderer::DXGIInfoQueue::CheckMessages() const noexcept
	{
		unsigned long long currentIndex = _pInfoQueue->GetNumStoredMessages(DXGI_DEBUG_ALL);
		return _lastMessageIndex - currentIndex > 0;
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

			messages.emplace_back(std::string(message->pDescription) + "\n");
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

		THROW_DERROR_NO_INFO(DxgiGetDebugInterface(__uuidof(IDXGIInfoQueue), &_pInfoQueue));
	}
#endif
}