#pragma once

#include <memory>

#include "ECS/IComponent.h"
#include "Structures/Vertex.h"
#include "Misc/RefPtr.h"
#include "ECS/ManagedObject.h"
#include "Utilities/Random.h"

namespace GrainEngine::ECS::Components
{
	using namespace GrainEngine::ECS;
	using namespace GrainEngine::Structures;
	using namespace GrainEngine::Misc;
	using namespace GrainEngine::Utilities;

	class Mesh : public IComponent
	{
	public:
		Mesh();
		~Mesh() noexcept override;

		RefPtr<Vertex> GetVertices() noexcept
		{
			return RefPtr<Vertex>(_pVertices.get());
		}

		unsigned int GetVerticesCount() const noexcept
		{
			return _verticesCount;
		}

		void Awake(ManagedObject<Entity>& pMEntity) override {};

	private:
		std::unique_ptr<Vertex[]> _pVertices;
		unsigned int _verticesCount = 3u;
	};
}