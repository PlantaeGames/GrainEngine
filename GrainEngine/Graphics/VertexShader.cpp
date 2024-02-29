#include "VertexShader.h"

namespace GrainEngine::Graphics
{
	void VertexShader::UpdateTransform(float transform[3][3])
	{
		_transformBuffer.Update(reinterpret_cast<char*>(transform));
	}

	void VertexShader::Bind()
	{
		_pDeviceContext->VSSetShader(_pVertexShader.Get(), nullptr, 0);
		_transformBuffer.Bind();
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
		_transformBuffer(ConstantBufferBindPosition::VertexShader)
	{
		LoadToGPU();

		float transform[3][3] =
		{
			{0.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 0.0f},
			{1.0f, 1.0f, 1.0f}
		};

		_transformBuffer.Create(0u, reinterpret_cast<char*>(transform));
	}
}