#pragma once

#include "ECS/IComponent.h"
#include "ECS/ManagedObject.h"
#include "Structures/Vector3.h"

#include "Errors/Error.h"

namespace GrainEngine::ECS::Components
{
	using namespace Structures;

	class Transform : public IComponent
	{
	public:
		Transform();
		~Transform() noexcept override;

		void Awake(ManagedObject<Entity>& pMEntity) override {}

	public:
		Vector3 position;
		Vector3 rotation;
		Vector3 scale;
	};
}
