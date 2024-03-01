#pragma once

#include "WinD3D.h"
#include "PipelineComponent.h"
#include "Graphics/Errors/D3DGraphicsError.h"
#include "Graphics/Errors/InvalidRenderTargetGraphicsError.h"

namespace GrainEngine::Graphics
{
#define INVALID_TEXTURE_GRAPHICS_ERROR_MESSAGE "Invalid Texture."

	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Graphics::Errors;
	using namespace GrainEngine::Errors;

	class Texture : PipelineComponent
	{
	public:
		Texture() = default;
		Texture(D3D11_TEXTURE2D_DESC description);
		Texture(D3D11_TEXTURE2D_DESC description, D3D11_SUBRESOURCE_DATA initialData);

		virtual ~Texture() noexcept override = default;
	
		virtual void Bind() override = 0;

		virtual void Release();

	protected:
		void New(D3D11_TEXTURE2D_DESC description);
		void New(D3D11_TEXTURE2D_DESC description, D3D11_SUBRESOURCE_DATA initialData);

		bool CheckValid() const noexcept;

	protected:
		ComPtr<ID3D11Texture2D> _pTexture;

	private:
		bool _valid = false;
	};
}