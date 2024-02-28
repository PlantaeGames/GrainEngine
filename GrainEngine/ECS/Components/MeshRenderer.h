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
#include "ECS/Components/Transform.h"

namespace GrainEngine::ECS::Components
{
	using namespace GrainEngine::ECS;
	using namespace GrainEngine::Structures;
	using namespace GrainEngine::Misc;
	using namespace GrainEngine::Graphics;

	class MeshRenderer : public IComponent
	{
	public:
		MeshRenderer();
		~MeshRenderer() noexcept override = default;

		void Awake(ManagedObject<Entity>& pMEntity) override;
		void PreRender(const Renderer& renderer) override;
		void End() override;

	private:
		bool _registered = false;
		ManagedObject<Entity> _pMParent;
	};
}