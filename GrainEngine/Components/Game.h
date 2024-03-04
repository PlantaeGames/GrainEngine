#pragma once

#include "ECS/WorldManager.h"
#include "Graphics/Renderer.h"

namespace GrainEngine::Components
{
	using namespace GrainEngine::ECS;
	using namespace GrainEngine::Graphics;

	class Game
	{
	public:
		Game(const Window* pWindow);
		~Game() noexcept = default;

		Game(const Game& otherInstance) = delete;
		Game(Game&& oldInstance) noexcept = delete;

		Game& operator= (const Game& otherInstance) = delete;
		Game& operator= (Game&& oldInstance) noexcept = delete;

		void Start();
		void Update();
		void PrepareRender();
		void Render();
		void End();

		WorldManager& GetWorldManager() const noexcept
		{
			return _worldManager;
		}

	private:
		void PreRender();
		void PostRender();

	private:
		mutable WorldManager _worldManager;
		mutable Renderer _renderer;
	};
}