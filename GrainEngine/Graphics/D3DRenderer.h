#pragma once

#include <string>
#include <vector>
#include <memory>
#include <sstream>

#include <windows.h>
#undef GetMessage

#include <d3d11.h>
#include <dxgi.h>

#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "dxgi.lib")
#pragma comment (lib, "dxguid.lib")

#ifdef _DEBUG
#include <dxgidebug.h>
#endif

#include <wrl/client.h>

#include "Patterns/Singleton.h"
#include "Errors/Error.h"

namespace GrainEngine::Graphics
{
#define THROW_DERROR_NO_INFO(hResult) if((hResult == S_OK || hResult == S_FALSE) == false) { THROW_ERROR_INFO(hResult) }

#ifdef _DEBUG
#define THROW_DERROR(function)									\
	{															\
	_infoQueue.Set();											\
		HRESULT hResult = function;								\
		if (hResult != S_OK)									\
		{														\
			TCHAR pMessageBuffer[256] = { 0 }; 					\
			FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM,			\
				nullptr,										\
				hResult,										\
				0,												\
				(LPSTR)pMessageBuffer, 256,						\
				nullptr);										\
																\
			std::vector<std::string> infoMessages = _infoQueue.GetMessages();	\
			std::stringstream message;							\
			message << (char*)pMessageBuffer;					\
			for (const std::string& infoMessage : infoMessages)	\
				message << infoMessage;							\
				THROW_ERROR(message.str());						\
		}														\
	}
#else
#define CHECK_DERROR(function) CHECK_DERROR_NO_DETAIL(function)
#endif

	using Microsoft::WRL::ComPtr;

	using namespace Patterns;
	using namespace Errors;

	class D3DRenderer
	{
	private:
		class DXGIInfoQueue
		{
		private:
			ComPtr<IDXGIInfoQueue> _pInfoQueue = nullptr;

			unsigned long long _lastMessageIndex = 0u;
		public:
			DXGIInfoQueue();
			DXGIInfoQueue(const DXGIInfoQueue& otherInstance) = delete;
			DXGIInfoQueue(DXGIInfoQueue& oldInstance) noexcept = delete;

			DXGIInfoQueue& operator= (const DXGIInfoQueue& otherInstance) = delete;
			DXGIInfoQueue& operator= (DXGIInfoQueue& oldInstance) noexcept = delete;

			~DXGIInfoQueue() noexcept = default;

			void Set() noexcept;
			std::vector<std::string> GetMessages() const;
		};
	public:
		D3DRenderer(HWND hWnd);

		D3DRenderer(const D3DRenderer& otherInstance) = delete;
		D3DRenderer(D3DRenderer&& oldInstance) noexcept = delete;
		D3DRenderer& operator= (const D3DRenderer& otherInstance) = delete;
		D3DRenderer& operator= (D3DRenderer&& oldInstance) noexcept = delete;

		~D3DRenderer() noexcept = default;

		void Present();

	private:
		void ClearBackBuffer(float color[4])
		{
			_pDeviceContext->ClearRenderTargetView(_pBackTarget.Get(), color);
		}

	private:
		ComPtr<ID3D11Device> _pDevice;
		ComPtr<ID3D11DeviceContext> _pDeviceContext;
		ComPtr<IDXGISwapChain> _pSwapchain;
		ComPtr<ID3D11RenderTargetView> _pBackTarget;

#ifdef _DEBUG
		DXGIInfoQueue _infoQueue;
#endif
	};
}