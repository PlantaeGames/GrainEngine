#include "ConstantBuffer.h"
#include "VertexBuffer.h"

namespace GrainEngine::Graphics
{
	void ConstantBuffer::Update(char* pData)
	{
		D3D11_MAPPED_SUBRESOURCE resource = { 0 };
		
		CHECK_THROW_D3D_ERROR_INFO(
			_pDeviceContext->Map(_pBuffer.Get(), 0u, D3D11_MAP_WRITE_DISCARD, 0u, &resource)
		);

		// updating
		std::memcpy(resource.pData, pData, _size);

		_pDeviceContext->Unmap(_pBuffer.Get(), 0u);
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

	void ConstantBuffer::Create(unsigned int slot, const char* pInitialData)
	{
		D3D11_BUFFER_DESC description = { 0 };
		D3D11_SUBRESOURCE_DATA initialData = { 0 };

		UINT alignment = (_size * 2) - ((_size * 2) % 16);

		description.Usage = D3D11_USAGE_DYNAMIC;
		description.ByteWidth = alignment;
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
