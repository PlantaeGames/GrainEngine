#include "IndexBuffer.h"

namespace GrainEngine::Graphics
{
	void IndexBuffer::Bind()
	{
		if (CheckValid() == false)
		{
			THROW_BUFFER_EMPTY_GRAPHICS_ERROR(BUFFER_EMPTY_GRAPHICS_ERROR_MESSAGE);
		}

		_pDeviceContext->IASetIndexBuffer(_pBuffer.Get(), DXGI_FORMAT_R32_UINT, _offset);
	}

	void IndexBuffer::Create(const unsigned int* pIndices, unsigned int indicesCount)
	{
		D3D11_BUFFER_DESC description = { 0 };
		D3D11_SUBRESOURCE_DATA initialData = { 0 };

		description.Usage = D3D11_USAGE_DEFAULT;
		description.ByteWidth = _stride * indicesCount;
		description.StructureByteStride = _stride;
		description.BindFlags = D3D11_BIND_INDEX_BUFFER;
		description.CPUAccessFlags = 0u;
		description.MiscFlags = 0u;

		initialData.pSysMem = pIndices;

		New(description, initialData);
	}
}