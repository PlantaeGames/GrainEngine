#include "DepthState.h"

namespace GrainEngine::Graphics
{
	void DepthState::Bind()
	{
		_pDeviceContext->OMSetDepthStencilState(_pDepthState.Get(), 1u);
	}

	void DepthState::Create()
	{
		D3D11_DEPTH_STENCIL_DESC description = { 0 };
		ZeroMemory(&description, sizeof(description));

		description.DepthEnable = TRUE;
		description.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		description.DepthFunc = D3D11_COMPARISON_GREATER;

		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateDepthStencilState(&description, &_pDepthState);
		);
	}

	DepthState::DepthState() :
		PipelineComponent()
	{
		Create();
	}
}
