#pragma once

#include <memory>
#include <stack>

#include "IComponent.h"
#include "Components/Transform.h"
#include "ManagedObject.h"

namespace GrainEngine::ECS
{
	using namespace Components;

	class Entity
	{
	public:
		Entity();
		~Entity() noexcept = default;

		Entity(const Entity& otherInstance) = default;
		Entity(Entity&& oldInstance) noexcept = default;

		Entity& operator= (const Entity& otherInstance) = default;
		Entity& operator= (Entity&& oldInstance) noexcept = default;

	private:
		std::stack<std::shared_ptr<IComponent>> _pComponents;


	};
}