#include "Game.h"

namespace GrainEngine::Components
{
	void Game::Update()
	{
		_worldManager.GetActiveWorld().Tick(TickType::Update);
	}

	void Game::Start()
	{
		_worldManager.GetActiveWorld().Tick(TickType::Start);
	}

	void Game::End()
	{
		_worldManager.GetActiveWorld().Tick(TickType::End);
	}

	Game::Game() :
		_worldManager()
	{}
}