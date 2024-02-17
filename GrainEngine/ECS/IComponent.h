#pragma once

#include "Entity.h"
#include "ManagedObject.h"

namespace GrainEngine::ECS
{
	class IComponent
	{
	public:
		virtual ~IComponent() noexcept = 0;

		IComponent(const IComponent& otherInstance) = default;
		IComponent(IComponent&& oldInstance) noexcept = default;

		IComponent& operator= (const IComponent& otherInstance) = default;
		IComponent& operator= (IComponent&& oldInstance) noexcept = default;

	protected:
		IComponent() = default;

		virtual void Awake(ManagedObject<Entity>& parent) {}
		virtual void Start(ManagedObject<Entity>& parent) {}
		virtual void Update(ManagedObject<Entity>& parent) {}
		virtual void End(ManagedObject<Entity>& parent) {}
	};
}