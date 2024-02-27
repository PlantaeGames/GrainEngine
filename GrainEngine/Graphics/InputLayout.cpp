#include "InputLayout.h"

namespace GrainEngine::Graphics
{
	void InputLayout::Bind()
	{
		_pDeviceContext->IASetInputLayout(_pInputLayout.Get());
	}

	void InputLayout::Create(const ComPtr<ID3DBlob>& pVertexShaderBinary)
	{
		const D3D11_INPUT_ELEMENT_DESC inputElementDescriptions[] =
		{
			{ "Position", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA }
		};

		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateInputLayout(inputElementDescriptions, std::size(inputElementDescriptions),
				pVertexShaderBinary->GetBufferPointer(), pVertexShaderBinary->GetBufferSize(),
				&_pInputLayout)
		);
	}

	InputLayout::InputLayout(const ComPtr<ID3DBlob>& pVertexShaderBinary) :
		PipelineComponent()
	{
		Create(pVertexShaderBinary);
	}
}