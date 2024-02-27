#include "VertexShader.h"

namespace GrainEngine::Graphics
{
	void VertexShader::Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext)
	{
		pDeviceContext->VSSetShader(_pVertexShader.Get(), nullptr, 0);
	}

	void VertexShader::LoadToGPU()
	{
		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateVertexShader(reinterpret_cast<void*>(_pBinary->GetBufferPointer()),
				_pBinary->GetBufferSize(),
				nullptr, &_pVertexShader)
		);
	}

	VertexShader::VertexShader(const std::string& fileName, const ComPtr<ID3D11Device>& pDevice) :
		Shader(fileName, pDevice),
		_pVertexShader()
	{
		LoadToGPU();
	}
}