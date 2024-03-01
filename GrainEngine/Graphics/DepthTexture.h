#pragma once

#include "WinD3D.h"
#include "Texture.h"
#include "DepthView.h"
#include "Graphics/Errors/InvalidDepthTextureGraphicsError.h"

namespace GrainEngine::Graphics
{
#define INVALID_DEPTH_TEXTURE_GRAPHICS_ERROR_MESSAGE "Invalid Depth Texture."

	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Graphics::Errors;
	using namespace GrainEngine::Errors;

	class DepthTexture : public Texture
	{
	public:
		DepthTexture() = default;

		DepthTexture(unsigned int width, unsigned int height);
		~DepthTexture() noexcept override = default;

		ComPtr<ID3D11DepthStencilView> GetView() const noexcept
		{
			return _depthView.GetView();
		}

		void Bind() override;

		void Release() override;

		void Create(unsigned int width, unsigned int height);

	private:
		unsigned int _width = 0u;
		unsigned int _height = 0u;

		DepthView _depthView;
	};
}