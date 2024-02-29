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
		friend class Pipeline;

	public:
		PipelineState(unsigned long long id, const Material& material,
			const Vertex* pVerticies, unsigned int verticesCount);
		~PipelineState() noexcept = default;

		bool operator== (const PipelineState& rhs) const noexcept
		{
			return rhs._id == _id;;
		}

		unsigned long long GetId() const noexcept
		{
			return _id;
		}

		Material& GetMaterial() const noexcept
		{
			return _material;
		}

	public:
		unsigned long long _id = 0u;
		mutable Material _material;
		VertexBuffer _vertexBuffer;
		unsigned int _verticesCount;
	};
}