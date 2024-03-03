#include "RenderTargetView.h"

namespace GrainEngine::Graphics
{
	void RenderTargetView::Bind()
	{
		QUEUE_CHECK_THROW_D3D_ERROR_INFO(
			_pDeviceContext->OMSetRenderTargets(1u, _pTargetView.GetAddressOf(), _depthTexture.GetView().Get())
		);
	}

	void RenderTargetView::Create(const ComPtr<ID3D11Resource>& pBuffer, unsigned int width, unsigned int height)
	{
		New(pBuffer);

		_depthTexture.Create(width, height);

		_depthWidth = width;
		_depthHeight = height;
	}

	void RenderTargetView::New(const ComPtr<ID3D11Resource>& pBuffer)
	{
		if (CheckValid())
		{
			THROW_INVALID_RENDER_TARGET_GRAPHICS_ERROR(INVALID_RENDER_TARGET_GRAPHICS_ERROR_MESSAGE);
		}

		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateRenderTargetView(pBuffer.Get(), nullptr, &_pTargetView)
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
		if (CheckValid() == false)
		{
			THROW_INVALID_RENDER_TARGET_GRAPHICS_ERROR(INVALID_RENDER_TARGET_GRAPHICS_ERROR_MESSAGE);
		}

		const float color[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		_pDeviceContext->ClearRenderTargetView(_pTargetView.Get(), color);

		_pDeviceContext->ClearDepthStencilView(_depthTexture.GetView().Get(), D3D11_CLEAR_DEPTH, 1.0f, 0u);
	}

	bool RenderTargetView::CheckValid() const noexcept
	{
		return _pTargetView.Get() != nullptr;
	}

	RenderTargetView::RenderTargetView(const ComPtr<ID3D11Resource>& pBuffer, unsigned int width, unsigned int height) :
		PipelineComponent(),
		_pTargetView(),
		_depthTexture()
	{
		Create(pBuffer, width, height);
	}
}