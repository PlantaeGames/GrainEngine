#pragma once

#include <vector>

#include "ManagedObject.h"
#include "Entity.h"
#include "TickType.h"
#include "ECS/Errors/EntityNotFoundError.h"

namespace GrainEngine::ECS
{
#define ENTITY_NOT_FOUND_ERROR_MESSAGE "Entity Not Found."

	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager() noexcept;

		EntityManager(const EntityManager& otherInstance) = delete;
		EntityManager(EntityManager&& oldInstance) noexcept = delete;

		EntityManager& operator= (const EntityManager& otherInstance) = delete;
		EntityManager& operator= (EntityManager&& oldInstance) noexcept = delete;

		ManagedObject<Entity>& CreateEntity() noexcept;
		ManagedObject<Entity>& GetEntity(const std::string& name);
		void RemoveEntity(ManagedObject<Entity>& pMEntity);

		void Tick(TickType tickType);

	private:
		void StartTick();
		void UpdateTick();
		void EndTick();

	private:
		std::vector<ManagedObject<Entity>> _pMEntities;
	};
}