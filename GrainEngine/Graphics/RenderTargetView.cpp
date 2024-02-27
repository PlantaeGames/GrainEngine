#include "RenderTargetView.h"

namespace GrainEngine::Graphics
{
	void RenderTargetView::Bind()
	{
		_pDeviceContext->OMSetRenderTargets(1u, _pTargetView.GetAddressOf(), nullptr);
	}

	void RenderTargetView::New(const ComPtr<ID3D11Resource>& pBuffer)
	{
		if (CheckValid())
		{
			THROW_INVALID_RENDER_TARGET_GRAPHICS_ERROR(INVALID_RENDER_TARGET_GRAPHICS_ERROR_MESSAGE);
		}

		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateRenderTargetView(pBuffer.Get(), nullptr, &_pTargetView);
		);
	}

	void RenderTargetView::Release()
	{
		if (CheckValid() == false)
		{
			THROW_INVALID_RENDER_TARGET_GRAPHICS_ERROR(INVALID_RENDER_TARGET_GRAPHICS_ERROR_MESSAGE);
		}

		_pTargetView.Reset();
	}

	void RenderTargetView::Clear()
	{
		const float color[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		_pDeviceContext->ClearRenderTargetView(_pTargetView.Get(), color);
	}

	bool RenderTargetView::CheckValid() const noexcept
	{
		return _pTargetView.Get() != nullptr;
	}

	RenderTargetView::RenderTargetView(const ComPtr<ID3D11Resource>& pBuffer) :
		PipelineComponent()
	{
		New(pBuffer);
	}
}