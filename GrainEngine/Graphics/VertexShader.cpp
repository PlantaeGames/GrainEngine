#include "VertexShader.h"

namespace GrainEngine::Graphics
{
	void VertexShader::UpdateTransform(TransformConstantBuffer transformConstantBuffer)
	{
		_transformBuffer.Update(reinterpret_cast<char*>(&transformConstantBuffer));
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

		TransformConstantBuffer transform = {};
		transform.position = { 0.0f, 0.0f, 0.0f };
		transform.rotation = { 0.0f, 0.0f, 0.0f };
		transform.scale = { 0.0f, 0.0f, 0.0f };

		_transformBuffer.Create(0u, sizeof(TransformConstantBuffer), 0u,
			reinterpret_cast<char*>(&transform));
	}
}