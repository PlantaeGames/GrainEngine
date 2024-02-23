#pragma once

#include <vector>

#include "ECS/Errors/WorldNotFoundError.h"
#include "ECS/Errors//CannotRemoveActiveWorldError.h"
#include "World.h"
#include "RefPtr.h"
#include "TickType.h"

namespace GrainEngine::ECS
{
#define WORLD_NOT_FOUND_ERROR_MESSAGE "World Not Found."
#define CANNOT_REMOVE_ACTIVE_WORLD_ERROR_MESSAGE "Cannot Remove Active World."

	using namespace Errors;

	class WorldManager
	{
	public:
		WorldManager();
		~WorldManager() noexcept = default;

		WorldManager(const WorldManager& otherInstance) = delete;
		WorldManager(WorldManager&& oldInstance) noexcept = delete;

		WorldManager& operator= (const WorldManager& otherInstance) = delete;
		WorldManager& operator= (WorldManager&& oldInstance) noexcept = delete;

		World& GetActiveWorld() const noexcept
		{
			return *_pRActiveWorld;
		}

		World& CreateWorld() noexcept;
		World& GetWorld(unsigned int id);
		World& GetWorld(std::string& name);
		void RemoveWorld(World& world);

		void Tick(TickType tickType);

	private:
		std::vector<World> _worlds;
		mutable RefPtr<World> _pRActiveWorld;
	};
}