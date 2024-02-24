#include "WorldManager.h"

namespace GrainEngine::ECS
{
	void WorldManager::Tick(TickType tickType)
	{
		_pRActiveWorld->GetEntityManager().Tick(tickType);
	}

	World& WorldManager::CreateWorld() noexcept
	{
		_worlds.emplace_back((unsigned int)_worlds.size(), std::string("World"));
		return _worlds.back();
	}

	World& WorldManager::GetWorld(unsigned int id)
	{
		for (auto& world : _worlds)
		{
			if (world.GetId() != id)
				continue;

			return world;
		}

		THROW_WORLD_NOT_FOUND_ERROR(WORLD_NOT_FOUND_ERROR_MESSAGE);
	}

	World& WorldManager::GetWorld(std::string& name)
	{
		for (auto& world : _worlds)
		{
			if (world.GetName() != name)
				continue;

			return world;
		}

		THROW_WORLD_NOT_FOUND_ERROR(WORLD_NOT_FOUND_ERROR_MESSAGE);
	}

	void WorldManager::RemoveWorld(World& world)
	{
		if (world.GetId() == _pRActiveWorld->GetId())
		{
			THROW_CANNOT_REMOVE_ACTIVE_WORLD_ERROR(CANNOT_REMOVE_ACTIVE_WORLD_ERROR_MESSAGE);
		}

		for (auto current = _worlds.begin(); current != _worlds.end(); ++current)
		{
			if (current->GetId() != world.GetId())
				continue;

			_worlds.erase(current);

			break;
		}

		THROW_WORLD_NOT_FOUND_ERROR(WORLD_NOT_FOUND_ERROR_MESSAGE);
	}

	WorldManager::WorldManager() :
		_worlds(),
		_pRActiveWorld(CreateWorld())
	{}
}