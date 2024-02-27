#include "VertexBuffer.h"

namespace GrainEngine::Graphics
{
	void VertexBuffer::Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext)
	{
		pDeviceContext->IASetVertexBuffers();
	}


	VertexBuffer::VertexBuffer(const ComPtr<ID3D11Device>& pDevice) :
		Buffer(pDevice)
	{
	}
}
