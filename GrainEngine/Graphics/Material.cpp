#include "Material.h"

namespace GrainEngine::Graphics
{
	void Material::Bind()
	{
		_vertexShader.Bind();
		_pixelShader.Bind();
	}

	Material::Material(const std::string& vSFile, const std::string& pSFile) :
		PipelineComponent(),
		_vertexShader(vSFile),
		_pixelShader(pSFile)
	{}
}