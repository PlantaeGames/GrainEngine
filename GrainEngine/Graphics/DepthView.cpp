#include "DepthView.h"

namespace GrainEngine::Graphics
{
	void DepthView::Bind()
	{}

	void DepthView::Release()
	{
		if (CheckValid() == false)
		{
			THROW_INVALID_DEPTH_VIEW_GRAPHICS_ERROR(INVALID_DEPTH_VIEW_GRAPHICS_ERROR_MESSAGE);
		}

		_pDepthView.Reset();

		_valid = false;
	}

	bool DepthView::CheckValid() const noexcept
	{
		return _valid;
	}

	void DepthView::New(const ComPtr<ID3D11Texture2D>& pDepthTexture)
	{
		if (CheckValid())
		{
			THROW_INVALID_DEPTH_VIEW_GRAPHICS_ERROR(INVALID_DEPTH_VIEW_GRAPHICS_ERROR_MESSAGE);
		}

		D3D11_DEPTH_STENCIL_VIEW_DESC description = {};

		description.Format = DXGI_FORMAT_D32_FLOAT;
		description.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		description.Texture2D.MipSlice = 0u;

		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateDepthStencilView(pDepthTexture.Get(), &description, &_pDepthView)
		);

		_valid = true;
	}

	void DepthView::Create(const ComPtr<ID3D11Texture2D>& pDepthTexture)
	{
		New(pDepthTexture);
	}

	DepthView::DepthView(const ComPtr<ID3D11Texture2D>& pDepthTexture) :
		PipelineComponent()
	{
		Create(pDepthTexture);
	}
}