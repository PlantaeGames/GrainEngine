#include "Buffer.h"

namespace GrainEngine::Graphics
{
	void Buffer::Update(char* pData)
	{
		D3D11_MAPPED_SUBRESOURCE resource = { 0 };

		CHECK_THROW_D3D_ERROR_INFO(
			_pDeviceContext->Map(_pBuffer.Get(), 0u, D3D11_MAP_WRITE_DISCARD, 0u, &resource)
		);

		std::memcpy(resource.pData, pData, _size);

		_pDeviceContext->Unmap(_pBuffer.Get(), 0u);
	}

	void Buffer::New(const D3D11_BUFFER_DESC description, const D3D11_SUBRESOURCE_DATA initialData)
	{
		if (CheckValid() == true)
		{
			// buffer is already allocated.

			THROW_BUFFER_NOT_EMPTY_GRAPHICS_ERROR(BUFFER_NOT_EMPTY_GRAPHICS_ERROR_MESSAGE);
		}

		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateBuffer(&description, &initialData, _pBuffer.GetAddressOf())
		);

		_size = description.ByteWidth;
	}

	void Buffer::Release()
	{
		if (CheckValid() == false)
		{
			// buffer is not allocated.

			THROW_BUFFER_EMPTY_GRAPHICS_ERROR(BUFFER_EMPTY_GRAPHICS_ERROR_MESSAGE);
		}

		_pBuffer.Reset();
	}

	bool Buffer::CheckValid() const noexcept
	{
		return (_pBuffer.Get() == nullptr) == false;
	}

	Buffer::Buffer(const D3D11_BUFFER_DESC description, const D3D11_SUBRESOURCE_DATA initialData) :
		PipelineComponent()
	{
		New(description, initialData);
	}

	Buffer::Buffer() :
		PipelineComponent()
	{}
}