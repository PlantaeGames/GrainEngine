#include "Texture.h"

namespace GrainEngine::Graphics
{
	void Texture::New(D3D11_TEXTURE2D_DESC description)
	{
		if (CheckValid())
		{
			THROW_INVALID_RENDER_TARGET_GRAPHICS_ERROR(INVALID_TEXTURE_GRAPHICS_ERROR_MESSAGE);
		}

		// create Texture here

		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateTexture2D(&description, nullptr, &_pTexture);
		);

		_valid = true;
	}

	void Texture::New(D3D11_TEXTURE2D_DESC description, D3D11_SUBRESOURCE_DATA initialData)
	{
		if (CheckValid())
		{
			THROW_INVALID_RENDER_TARGET_GRAPHICS_ERROR(INVALID_TEXTURE_GRAPHICS_ERROR_MESSAGE);
		}

		// create Texture here
		
		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateTexture2D(&description, &initialData, &_pTexture)
		);

		_valid = true;
	}

	void Texture::Release()
	{
		if (CheckValid() == false)
		{
			THROW_INVALID_RENDER_TARGET_GRAPHICS_ERROR(INVALID_TEXTURE_GRAPHICS_ERROR_MESSAGE);
		}

		_pTexture.Reset();
		_valid = false;
	}

	bool Texture::CheckValid() const noexcept
	{
		return _valid;
	}

	Texture::Texture(D3D11_TEXTURE2D_DESC description, D3D11_SUBRESOURCE_DATA initialData)
	{
		New(description, initialData);
	}

	Texture::Texture(D3D11_TEXTURE2D_DESC description)
	{
		New(description);
	}
}