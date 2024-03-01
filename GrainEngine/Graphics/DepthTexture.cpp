#include "DepthTexture.h"

namespace GrainEngine::Graphics
{
	void DepthTexture::Release()
	{
		Texture::Release();
		_depthView.Release();
	}

	void DepthTexture::Bind()
	{
		if (CheckValid() == false)
		{
			THROW_INVALID_DEPTH_TEXTURE_GRAPHICS_ERROR(INVALID_DEPTH_TEXTURE_GRAPHICS_ERROR_MESSAGE);
		}
	}

	void DepthTexture::Create(unsigned int width, unsigned int height)
	{
		if (CheckValid())
		{
			THROW_INVALID_DEPTH_TEXTURE_GRAPHICS_ERROR(INVALID_DEPTH_TEXTURE_GRAPHICS_ERROR_MESSAGE);
		}

		_width = width;
		_height = height;

		D3D11_TEXTURE2D_DESC description = { 0 };

		description.Width = _width;
		description.Height = _height;
		description.MipLevels = 1u;
		description.ArraySize = 1u;
		description.Format = DXGI_FORMAT_D32_FLOAT;
		description.SampleDesc.Count = 1u;
		description.SampleDesc.Quality = 0u;
		description.Usage = D3D11_USAGE_DEFAULT;
		description.BindFlags = D3D11_BIND_DEPTH_STENCIL;

		New(description);

		_depthView.Create(_pTexture);
	}

	DepthTexture::DepthTexture(unsigned int width, unsigned int height) :
		_width(width),
		_height(height),
		_depthView()
	{
		Create(width, height);
	}
}