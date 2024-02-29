#pragma once

#include "ECS/IComponent.h"
#include "ECS/Entity.h"
#include "Misc/RefPtr.h"
#include "Graphics/PerspectivePoint.h"

namespace GrainEngine::ECS::Components
{
	using namespace GrainEngine::ECS;
	using namespace GrainEngine::Misc;
	using namespace GrainEngine::Graphics;

	class Camera : public IComponent
	{
	public:
		Camera() = default;
		~Camera() noexcept override = default;

		void Awake(ManagedObject<Entity>& pMEntity) override;
		void PreRender(const Renderer& renderer) override;

	private:
		bool _init = false;
		ManagedObject<Entity> _pMParent;
		RefPtr<PerspectivePoint> _pRPerspectivePoint;
	};
}