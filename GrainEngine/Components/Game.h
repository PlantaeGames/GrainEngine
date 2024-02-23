#pragma once

#include "ECS/WorldManager.h"

namespace GrainEngine::Components
{
	using namespace GrainEngine::ECS;

	class Game
	{
	public:
		Game();
		~Game() noexcept = default;

		Game(const Game& otherInstance) = delete;
		Game(Game&& oldInstance) noexcept = delete;

		Game& operator= (const Game& otherInstance) = delete;
		Game& operator= (Game&& oldInstance) noexcept = delete;

		WorldManager& GetWorldManager() const noexcept
		{
			return _worldManager;
		}

	private:
		mutable WorldManager _worldManager;
	};
}