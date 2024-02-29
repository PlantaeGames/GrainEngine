#include "VertexShader.h"

namespace GrainEngine::Graphics
{
	void VertexShader::UpdateTransform(const float** ppTransform)
	{

	}

	void VertexShader::Bind()
	{
		_pDeviceContext->VSSetShader(_pVertexShader.Get(), nullptr, 0);
	}

	void VertexShader::LoadToGPU()
	{
		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateVertexShader(reinterpret_cast<void*>(_pBinary->GetBufferPointer()),
				_pBinary->GetBufferSize(),
				nullptr, &_pVertexShader)
		);
	}

	VertexShader::VertexShader(const std::string& fileName) :
		Shader(fileName),
		_pVertexShader(),
		_constantBuffer()
	{
		LoadToGPU();

		_constantBuffer.Create(_pVertexShader);
	}
}