#pragma once

#include <memory>

#include "Entity.h"

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
		IComponent(std::weak_ptr<Entity>&& pEntity)
		{
			_pEntity = pEntity;
		}

		virtual void Awake() {}
		virtual void Start() {}
		virtual void Update() {}
		virtual void End() {}

	protected:
		std::weak_ptr<Entity> _pEntity;
	};
}