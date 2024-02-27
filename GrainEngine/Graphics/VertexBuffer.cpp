#include "VertexBuffer.h"

namespace GrainEngine::Graphics
{
	void VertexBuffer::Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext)
	{
		if (CheckValid() == false)
		{
			THROW_BUFFER_EMPTY_GRAPHICS_ERROR(BUFFER_EMPTY_GRAPHICS_ERROR_MESSAGE);
		}

		pDeviceContext->IASetVertexBuffers(0u, 1u, _pBuffer.GetAddressOf(), &stride, &offset);
	}

	void VertexBuffer::Create(const Vertex* pVertices, unsigned int numberOfVertices)
	{
		D3D11_BUFFER_DESC description = {0};
		D3D11_SUBRESOURCE_DATA initialData = { 0 };

		description.Usage = D3D11_USAGE_DEFAULT;
		description.ByteWidth = stride * numberOfVertices;
		description.StructureByteStride = stride;
		description.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		description.CPUAccessFlags = 0u;
		description.MiscFlags = 0u;

		initialData.pSysMem = pVertices;

		New(description, initialData);
	}

	VertexBuffer::VertexBuffer() :
		Buffer()
	{}
}
