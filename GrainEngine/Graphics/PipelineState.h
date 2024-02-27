#pragma once

#include <string>

#include "WinD3D.h"
#include "Material.h"
#include "VertexBuffer.h"
#include "Structures/Vertex.h"

namespace GrainEngine::Graphics
{
	using namespace GrainEngine::Structures;

	class PipelineState
	{
	public:
		PipelineState(unsigned long long id,
			const std::string& vSFile, const std::string& pSFile,
			const Vertex* pVertices, unsigned int verticesCount);
		~PipelineState() noexcept = default;

		bool operator== (const PipelineState& rhs) const noexcept
		{
			return rhs._id == _id;;
		}

		unsigned long long GetId() const noexcept
		{
			return _id;
		}

	private:
		unsigned long long _id = 0u;
		Material _material;
		VertexBuffer _vertexBuffer;
	};
}