#pragma once

#include <string>

#include "PipelineState.h"
#include "Structures/Vertex.h"

namespace GrainEngine::Graphics
{
	using namespace GrainEngine::Structures;

	class GraphicsObject
	{
	public:
		GraphicsObject(unsigned long long id, const Material& material,
			const Vertex* pVerticies, unsigned int verticesCount,
			const unsigned int* pIndices, unsigned int indicesCount);
		~GraphicsObject() noexcept = default;

		PipelineState&& GetState() noexcept
		{
			return std::move(_pipelineState);
		}

	private:
		PipelineState _pipelineState;
	};
}