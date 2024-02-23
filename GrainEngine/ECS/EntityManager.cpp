#include "EntityManager.h"

namespace GrainEngine::ECS
{
	std::vector<ManagedObject<Entity>> EntityManager::GetEntities(const std::string& name)
	{
		std::vector<ManagedObject<Entity>> pMEntities;

		for (auto& pMEntity : _pMEntities)
		{
			if (pMEntity->name != name)
				continue;

			pMEntities.push_back(pMEntity);
		}

		return pMEntities;
	}

	ManagedObject<Entity>& EntityManager::CreateEntity() noexcept
	{
		_pMEntities.push_back(ManagedObject<Entity>().New());
		auto& pMEntity = _pMEntities.back();

		pMEntity->Tick(pMEntity, TickType::Awake);

		return pMEntity;
	}

	ManagedObject<Entity>& EntityManager::GetEntity(const std::string& name)
	{
		for (auto& pMEntity : _pMEntities)
		{
			if (pMEntity->name != name)
				continue;

			return pMEntity;
		}

		THROW_ENTITY_NOT_FOUND_ERROR(ENTITY_NOT_FOUND_ERROR_MESSAGE);
	}

	void EntityManager::RemoveEntity(ManagedObject<Entity>& pMEntity)
	{
		for (auto current = _pMEntities.begin(); current != _pMEntities.end(); ++current)
		{
			if (current->Equals(pMEntity))
				continue;

			_pMEntities.erase(current);

			return;
		}

		THROW_ENTITY_NOT_FOUND_ERROR(ENTITY_NOT_FOUND_ERROR_MESSAGE);
	}

	void EntityManager::Tick(TickType tickType)
	{
		switch (tickType)
		{
			case TickType::None:
				break;

			case TickType::Start:
				StartTick();
				break;
			case TickType::Update:
				UpdateTick();
				break;
			case TickType::End:
				EndTick();
				break;

			default:
				break;
		}
	}

	void EntityManager::StartTick()
	{
		for (auto& pMEntity : _pMEntities)
		{
			pMEntity->Tick(pMEntity, TickType::Start);
		}
	}

	void EntityManager::UpdateTick()
	{
		for (auto& pMEntity : _pMEntities)
		{
			pMEntity->Tick(pMEntity, TickType::Update);
		}
	}

	void EntityManager::EndTick()
	{
		for (auto& pMEntity : _pMEntities)
		{
			pMEntity->Tick(pMEntity, TickType::End);
		}
	}

	EntityManager::EntityManager() :
		_pMEntities()
	{}

	EntityManager::~EntityManager() noexcept
	{
		for (auto& pMEntity : _pMEntities)
		{
			pMEntity.Release();
		}
	}
}