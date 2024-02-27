#include "Shader.h"

namespace GrainEngine::Graphics
{
	void Shader::LoadToCPU()
	{
		CHECK_THROW_D3D_ERROR_INFO(
			D3DReadFileToBlob(_wFileName.c_str(), &_pBinary)
		);
	}

	Shader::Shader(const std::string& fileName) :
		PipelineComponent(pDevice)
	{
		assert(fileName.length() > 0);

		std::wstringstream wideStringStream = {};
		wideStringStream << fileName.c_str();

		_wFileName = wideStringStream.str();

		LoadToCPU();
	}
}