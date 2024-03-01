#pragma once

#include <memory>

#include "ECS/IComponent.h"
#include "Structures/Vertex.h"
#include "Misc/RefPtr.h"
#include "ECS/ManagedObject.h"

namespace GrainEngine::ECS::Components
{
	using namespace GrainEngine::ECS;
	using namespace GrainEngine::Structures;
	using namespace GrainEngine::Misc;

	class Mesh : public IComponent
	{
	public:
		Mesh();
		~Mesh() noexcept override = default;

		RefPtr<Vertex> GetVertices() noexcept
		{
			return RefPtr<Vertex>(_pVertices.get());
		}

		RefPtr<unsigned int> GetIndices() noexcept
		{
			return RefPtr<unsigned int>(_pIndices.get());
		}

		unsigned int GetVerticesCount() const noexcept
		{
			return _verticesCount;
		}

		unsigned int GetIndicesCount() const noexcept
		{
			return _indicesCount;
		}

		void Awake(ManagedObject<Entity>& pMEntity) override {};

	private:
		std::unique_ptr<Vertex[]> _pVertices;
		std::unique_ptr<unsigned int[]> _pIndices;
		unsigned int _verticesCount = 24u;
		unsigned int _indicesCount = 36u;
	};
}