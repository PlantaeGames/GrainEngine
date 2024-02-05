#pragma once

#include <windows.h>

#include <d3d11.h>
#include <dxgi.h>

#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "dxgi.lib")


#include "Patterns/Singleton.h"
#include "Errors/Error.h"

namespace GrainEngine::Graphics
{
	using namespace Patterns;
	using namespace Errors;

	class D3DRenderer
	{
	public:
		D3DRenderer(HWND hWnd);

		D3DRenderer(const D3DRenderer& otherInstance) = delete;
		D3DRenderer(D3DRenderer&& oldInstance) noexcept = delete;
		D3DRenderer& operator= (const D3DRenderer& otherInstance) = delete;
		D3DRenderer& operator= (D3DRenderer&& oldInstance) noexcept = delete;

		~D3DRenderer() noexcept;

		void Present() const noexcept;

	private:
		ID3D11Device* _pDevice;
		ID3D11DeviceContext* _pDeviceContext;
		IDXGISwapChain* _pSwapchain;
	};
}

