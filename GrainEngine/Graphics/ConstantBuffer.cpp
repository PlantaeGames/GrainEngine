#include "ConstantBuffer.h"
#include "VertexBuffer.h"

namespace GrainEngine::Graphics
{
	void ConstantBuffer::Update(const float** ppTransform)
	{
		
		//_pDeviceContext->UpdateSubresource()
	}

	void ConstantBuffer::Bind()
	{
		if (CheckValid() == false)
		{
			THROW_BUFFER_EMPTY_GRAPHICS_ERROR(BUFFER_EMPTY_GRAPHICS_ERROR_MESSAGE);
		}

		switch (_bindPos)
		{
		case ConstantBufferBindPosition::None:
			break;
		case ConstantBufferBindPosition::VertexShader:
			_pDeviceContext->VSSetConstantBuffers(0u, _slot, _pBuffer.GetAddressOf());
			break;
		case ConstantBufferBindPosition::PixelShader:
			_pDeviceContext->PSSetConstantBuffers(0u, _slot, _pBuffer.GetAddressOf());
			break;

		default:
			break;
		}
	}

	void ConstantBuffer::Create(unsigned int slot, const char* pInitialData)
	{
		D3D11_BUFFER_DESC description = { 0 };
		D3D11_SUBRESOURCE_DATA initialData = { 0 };

		description.Usage = D3D11_USAGE_DEFAULT;
		description.ByteWidth = _stride * _rows * _columns;
		description.StructureByteStride = _stride;
		description.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		description.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		description.MiscFlags = 0u;

		initialData.pSysMem = pInitialData;

		New(description, initialData);

		_slot = (UINT) slot;
	}

	ConstantBuffer::ConstantBuffer(ConstantBufferBindPosition bindPos) :
		Buffer(),
		_bindPos(bindPos)
	{}
}
