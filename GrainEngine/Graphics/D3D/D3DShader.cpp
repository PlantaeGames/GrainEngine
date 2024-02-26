#include "D3DShader.h"

namespace GrainEngine::Graphics::D3D
{
	void D3DShader::Load()
	{
		CHECK_THROW_D3D_ERROR_INFO(
			D3DReadFileToBlob(_wFileName.c_str(), &_pBinary)
		);
	}

	void D3DShader::Bind() 
	{}

	D3DShader::D3DShader(const std::string& fileName) :
		Shader(fileName),
		_wFileName(),
		_pBinary()
	{
		std::wstringstream wStream;
		wStream << _fileName.c_str();

		_wFileName = wStream.str();

		Load();
	}

	void D3DShader::LoadToPrimaryMemory()
	{}

	void D3DShader::LoadToGPUMemory()
	{}
}