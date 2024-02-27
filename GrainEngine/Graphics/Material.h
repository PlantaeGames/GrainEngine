#pragma once

#include <string>

#include "WinD3D.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "PipelineComponent.h"

namespace GrainEngine::Graphics
{
	class Material : public PipelineComponent
	{
	public:
		Material(const std::string& vSFile, const std::string& pSFile);
		~Material() noexcept override = default;

		void Bind() override;

	private:
		VertexShader _vertexShader;
		PixelShader _pixelShader;
	};
}

