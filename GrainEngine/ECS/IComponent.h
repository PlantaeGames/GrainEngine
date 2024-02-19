#pragma once

#include "ManagedObject.h"

namespace GrainEngine::ECS
{
	class IComponent
	{
		class Entity;
	public:
		virtual ~IComponent() noexcept = default;

		IComponent(const IComponent& otherInstance) = default;
		IComponent(IComponent&& oldInstance) noexcept = default;

		IComponent& operator= (const IComponent& otherInstance) = default;
		IComponent& operator= (IComponent&& oldInstance) noexcept = default;

		virtual void Awake(ManagedObject<Entity>& parent) {}
		virtual void Start(ManagedObject<Entity>& parent) {}
		virtual void Update(ManagedObject<Entity>& parent) {}
		virtual void End(ManagedObject<Entity>& parent) {}

	protected:
		IComponent() = default;
	};
}