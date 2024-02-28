#pragma once

#include <memory>
#include <string>

#include "ECS/IComponent.h"
#include "Structures/Vertex.h"
#include "Misc/RefPtr.h"
#include "Graphics/Renderer.h"
#include "ECS/ManagedObject.h"
#include "ECS/Entity.h"
#include "ECS/Components/Mesh.h"

namespace GrainEngine::ECS::Components
{
	using namespace GrainEngine::ECS;
	using namespace GrainEngine::Structures;
	using namespace GrainEngine::Misc;
	using namespace GrainEngine::Graphics;

	class MeshRenderer : IComponent
	{
	public:
		MeshRenderer();
		~MeshRenderer() noexcept override = default;

		void Awake(ManagedObject<Entity>& pMEntity) override;
		void PreRender(const Renderer& renderer) override;
		void End(ManagedObject<Entity>& pMEntity) override;

	private:
		bool _registered = false;
		ManagedObject<Entity> _pMParent;
	};
}