#include "D3DGraphicsError.h"

namespace GrainEngine::Graphics::D3D::Errors
{
#ifdef _DEBUG
	bool D3DGraphicsError::DXGIInfoQueue::CheckMessages() const noexcept
	{
		unsigned long long currentIndex = _pInfoQueue->GetNumStoredMessages(DXGI_DEBUG_ALL);
		return _lastMessageIndex - currentIndex > 0;
	}

	std::vector<std::string> D3DGraphicsError::DXGIInfoQueue::GetMessages() const
	{
		std::vector<std::string> messages{};
		unsigned long long currentIndex = _pInfoQueue->GetNumStoredMessages(DXGI_DEBUG_ALL);

		messages.emplace_back("\n[ Info ]\n");

		for (auto i = _lastMessageIndex; i < currentIndex; ++i)
		{
			SIZE_T len = 0;

			CHECK_THROW_D3D_ERROR_NO_INFO(_pInfoQueue->GetMessage(DXGI_DEBUG_ALL, i, nullptr, &len));

			auto messageBytes = std::make_unique<byte[]>(len);
			if (!messageBytes)
			{
				THROW_LAST_ERROR();
			}
			auto* message = reinterpret_cast<DXGI_INFO_QUEUE_MESSAGE*>(messageBytes.get());

			CHECK_THROW_D3D_ERROR_NO_INFO(_pInfoQueue->GetMessage(DXGI_DEBUG_ALL, i, message, &len));

			messages.emplace_back(std::string(message->pDescription) + "\n");
		}

		return messages;
	}

	void D3DGraphicsError::DXGIInfoQueue::Set() noexcept
	{
		_lastMessageIndex = _pInfoQueue->GetNumStoredMessages(DXGI_DEBUG_ALL);
	}

	D3DGraphicsError::DXGIInfoQueue::DXGIInfoQueue()
	{
		typedef HRESULT(WINAPI* DXGIGetDebugInterface)(REFIID, void**);

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

		CHECK_THROW_D3D_ERROR_NO_INFO(DxgiGetDebugInterface(__uuidof(IDXGIInfoQueue), &_pInfoQueue));
	}
#endif

	D3DGraphicsError::D3DGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		GraphicsError(message, fileName, lineNumber)
	{}
}