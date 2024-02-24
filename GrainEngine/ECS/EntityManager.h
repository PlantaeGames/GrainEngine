#pragma once

#include <vector>

#include "ManagedObject.h"
#include "Entity.h"
#include "TickType.h"
#include "ECS/Errors/EntityNotFoundError.h"

namespace GrainEngine::ECS
{
#define ENTITY_NOT_FOUND_ERROR_MESSAGE "Entity Not Found."

	using namespace Errors;

	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager() noexcept;

		EntityManager(const EntityManager& otherInstance) = default;
		EntityManager(EntityManager&& oldInstance) noexcept = default;

		EntityManager& operator= (const EntityManager& otherInstance) = default;
		EntityManager& operator= (EntityManager&& oldInstance) noexcept = default;

		ManagedObject<Entity>& CreateEntity() noexcept;
		ManagedObject<Entity>& GetEntity(const std::string& name);
		std::vector<ManagedObject<Entity>> GetEntities(const std::string& name);
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