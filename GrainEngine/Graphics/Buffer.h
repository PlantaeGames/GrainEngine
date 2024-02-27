#pragma once

#include "WinD3D.h"
#include "PipelineComponent.h"
#include "Errors/Error.h"
#include "Graphics/Errors/D3DGraphicsError.h"
#include "Graphics/Errors/BufferNotEmptyGraphicsError.h"
#include "Graphics/Errors/BufferEmptyGraphicsError.h"

namespace GrainEngine::Graphics
{
#define BUFFER_NOT_EMPTY_GRAPHICS_ERROR_MESSAGE "Buffer is already allocated."
#define BUFFER_EMPTY_GRAPHICS_ERROR_MESSAGE "Buffer is not allocated."

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	class Buffer : PipelineComponent
	{
	public:
		Buffer();
		Buffer(const D3D11_BUFFER_DESC description, const D3D11_SUBRESOURCE_DATA initialData, const ComPtr<ID3D11Device>& pDevice);
		virtual ~Buffer() noexcept override = default;

		virtual void Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext) override = 0;

		void New(const D3D11_BUFFER_DESC description, const D3D11_SUBRESOURCE_DATA initialData);
		void Release();

	protected:
		bool CheckValid() const noexcept;

	protected:
		ComPtr<ID3D11Buffer> _pBuffer;
	};
}