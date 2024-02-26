#include "D3DVertexShader.h"

namespace GrainEngine::Graphics::D3D
{
	void D3DVertexShader::Bind()
	{

	}

	void D3DVertexShader::Load()
	{
		CHECK_THROW_D3D_ERROR_INFO(
			_pDevice->CreateVertexShader(reinterpret_cast<void*>(_pBinary->GetBufferPointer()),
				_pBinary->GetBufferSize(),
				nullptr, &_pVertexShader)
		);
	}

	D3DVertexShader::D3DVertexShader(const std::string& fileName, const ComPtr<ID3D11Device>& pDevice) :
		D3DShader(fileName),
		_pVertexShader(),
		_pDevice(pDevice)
	{
		Load();
	}
}