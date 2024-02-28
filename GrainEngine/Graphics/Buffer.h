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

	class Buffer : public PipelineComponent
	{
	public:
		Buffer();
		Buffer(const D3D11_BUFFER_DESC description, const D3D11_SUBRESOURCE_DATA initialData);
		virtual ~Buffer() noexcept override = default;

		virtual void Bind() override = 0;

		void Release();

	protected:
		void New(const D3D11_BUFFER_DESC description, const D3D11_SUBRESOURCE_DATA initialData);
		bool CheckValid() const noexcept;

	protected:
		ComPtr<ID3D11Buffer> _pBuffer;
	};
}