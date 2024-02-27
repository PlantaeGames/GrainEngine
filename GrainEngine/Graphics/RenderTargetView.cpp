#include "RenderTargetView.h"

namespace GrainEngine::Graphics
{
	void RenderTargetView::Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext)
	{
		pDeviceContext->OMSetRenderTargets(1u, _pTargetView.GetAddressOf(), nullptr);
	}

	void RenderTargetView::Create(const ComPtr<ID3D11Resource>& pBuffer)
	{
		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateRenderTargetView(pBuffer.Get(), nullptr, &_pTargetView);
		);
	}

	void RenderTargetView::Clear(const ComPtr<ID3D11DeviceContext>& pDeviceContext)
	{
		const float color[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		pDeviceContext->ClearRenderTargetView(_pTargetView.Get(), color);
	}

	RenderTargetView::RenderTargetView(const ComPtr<ID3D11Resource>& pBuffer) :
		PipelineComponent(pDevice)
	{
		Create(pBuffer);
	}
}