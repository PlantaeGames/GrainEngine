#include "ConstantBuffer.h"
#include "VertexBuffer.h"

namespace GrainEngine::Graphics
{
	void ConstantBuffer::Update(char* pData)
	{
		Buffer::Update(pData);
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
			_pDeviceContext->VSSetConstantBuffers(_slot, 1u, _pBuffer.GetAddressOf());
			break;
		case ConstantBufferBindPosition::PixelShader:
			_pDeviceContext->PSSetConstantBuffers(_slot, 1u, _pBuffer.GetAddressOf());
			break;

		default:
			break;
		}
	}

	void ConstantBuffer::Create(unsigned int slot, unsigned int size, unsigned int stride, const char* pInitialData)
	{
		_size = (UINT) size;
		_stride = (UINT) stride;

		D3D11_BUFFER_DESC description = { 0 };
		D3D11_SUBRESOURCE_DATA initialData = { 0 };

		description.Usage = D3D11_USAGE_DYNAMIC;
		description.ByteWidth = size;
		description.StructureByteStride = _stride;
		description.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		description.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		description.MiscFlags = 0u;

		initialData.pSysMem = pInitialData;

		New(description, initialData);
	}

	ConstantBuffer::ConstantBuffer(ConstantBufferBindPosition bindPos) :
		Buffer(),
		_bindPos(bindPos)
	{}
}
