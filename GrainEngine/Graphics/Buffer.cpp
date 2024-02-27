#include "Buffer.h"

namespace GrainEngine::Graphics
{
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