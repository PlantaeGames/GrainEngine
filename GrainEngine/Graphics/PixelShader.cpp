#include "PixelShader.h"

namespace GrainEngine::Graphics
{
	void PixelShader::Bind()
	{
		_pDeviceContext->PSSetShader(_pPixelShader.Get(), nullptr, 0);
	}

	void PixelShader::LoadToGPU()
	{
		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreatePixelShader(reinterpret_cast<void*>(_pBinary->GetBufferPointer()),
				_pBinary->GetBufferSize(),
				nullptr, &_pPixelShader)
		);
	}

	PixelShader::PixelShader(const std::string& fileName) :
		Shader(fileName),
		_pPixelShader()
	{
		LoadToGPU();
	}
}