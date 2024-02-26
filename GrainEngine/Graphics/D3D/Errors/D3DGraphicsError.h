#pragma once

#include <string>

#include "Graphics/D3D/WinD3D.h"
#include "Graphics/Errors/GraphicsError.h"
#include "Patterns/Singleton.h"

namespace GrainEngine::Graphics::D3D::Errors
{
#define GENERATE_D3D_GRAPHICS_ERROR(message) D3DGraphicsError(message, __FILE__, __LINE__)
#define THROW_D3D_GRAPHICS_ERROR(message) THROW(GENERATE_D3D_GRAPHICS_ERROR(message))

#define CHECK_THROW_D3D_ERROR_NO_INFO(hResult) if((hResult == S_OK || hResult == S_FALSE) == false) { THROW_ERROR_INFO(hResult) }

#ifdef _DEBUG

#define THROW_D3D_ERROR_INFO()									\
	{														\
		TCHAR pMessageBuffer[256] = { 0 }; 					\
		FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM,			\
			nullptr,										\
			hResult,										\
			0,												\
			(LPSTR)pMessageBuffer, 256,						\
			nullptr);										\
															\
		std::vector<std::string> infoMessages = D3DGraphicsError::DXGIInfoQueue::GetInstance().GetMessages();	\
		std::stringstream message;							\
		message << (char*)pMessageBuffer;					\
		for (const std::string& infoMessage : infoMessages)	\
			message << infoMessage;							\
		THROW_ERROR(message.str());							\
	}														\

#define CHECK_THROW_D3D_ERROR_INFO(function)									\
	{															\
		D3DGraphicsError::DXGIInfoQueue::GetInstance().Set();										\
		HRESULT hResult = function;								\
		if ((hResult == S_OK || hResult == S_FALSE) == false)	\
		{														\
			THROW_D3D_ERROR_INFO();								\
		}														\
	}

#define QUEUE_CHECK_THROW_D3D_ERROR_INFO(function)									\
	{															\
		D3DGraphicsError::DXGIInfoQueue::GetInstance().Set();										\
		function;												\
		HRESULT hResult = S_FALSE;								\
		if (D3DGraphicsError::DXGIInfoQueue::GetInstance().CheckMessages())							\
		{														\
			THROW_D3D_ERROR_INFO();								\
		}														\
	}

#else

#define CHECK_THROW_D3D_ERROR_INFO(function) CHECK_THROW_D3D_ERROR_NO_INFO(function)

#define CHECK_D3D_ERROR_NO_DEBUG(function) function
#define QUEUE_CHECK_THROW_D3D_ERROR_INFO(function) CHECK_D3D_ERROR_NO_DEBUG(function)

#endif

	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Patterns;

	class D3DGraphicsError : public GrainEngine::Graphics::Errors::GraphicsError
	{
#ifdef _DEBUG
	public:
		class DXGIInfoQueue : public Singleton<DXGIInfoQueue>
		{
			friend Singleton;

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
			bool CheckMessages() const noexcept;
		};
#endif

	public:
		D3DGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~D3DGraphicsError() noexcept override = default;
	};
}