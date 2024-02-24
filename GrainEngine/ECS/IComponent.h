#pragma once

#include "ManagedObject.h"

namespace GrainEngine::ECS
{
	class Entity;

	class IComponent
	{
	public:
		virtual ~IComponent() noexcept = default;

		IComponent(const IComponent& otherInstance) = default;
		IComponent(IComponent&& oldInstance) noexcept = default;

		IComponent& operator= (const IComponent& otherInstance) = default;
		IComponent& operator= (IComponent&& oldInstance) noexcept = default;

		virtual void Awake(ManagedObject<Entity>& pMEntity) {}
		virtual void Start(ManagedObject<Entity>& pMEntity) {}
		virtual void Update(ManagedObject<Entity>& pMEntity) {}
		virtual void End(ManagedObject<Entity>& pMEntity) {}

	protected:
		IComponent() = default;
	};
}