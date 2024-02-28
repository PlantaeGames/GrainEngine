#pragma once

#include <memory>

#include "ECS/IComponent.h"
#include "Structures/Vertex.h"
#include "Misc/RefPtr.h"

namespace GrainEngine::ECS::Components
{
	using namespace GrainEngine::ECS;
	using namespace GrainEngine::Structures;
	using namespace GrainEngine::Misc;

	class Mesh : IComponent
	{
	public:
		Mesh();
		~Mesh() noexcept override = default;

		RefPtr<Vertex> GetVertices() noexcept
		{
			return RefPtr<Vertex>(_pVertices.get());
		}

		unsigned int GetVerticesCount() const noexcept
		{
			return _verticesCount;
		}

	private:
		std::unique_ptr<Vertex[]> _pVertices;
		unsigned int _verticesCount = 0u;
	};
}