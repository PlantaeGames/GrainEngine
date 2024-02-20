#pragma once

#include <vector>

#include "ManagedObject.h"

namespace GrainEngine::ECS
{
	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager() noexcept;

		EntityManager(const EntityManager& otherInstance) = delete;
		EntityManager(EntityManager&& oldInstance) noexcept = delete;

		EntityManager& operator= (const EntityManager& otherInstance) = delete;
		EntityManager& operator= (EntityManager&& oldInstance) noexcept = delete;

	private:

	};
}