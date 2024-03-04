#include "Game.h"

namespace GrainEngine::Components
{
	void Game::PrepareRender()
	{
		_renderer.PrepareRender();

		PreRender();
	}

	void Game::Render()
	{
		_renderer.Render();

		PostRender();
	}

	void Game::PreRender()
	{
		_worldManager.GetActiveWorld().RenderTick(_renderer, TickType::PreRender);
	}

	void Game::PostRender()
	{
		_worldManager.GetActiveWorld().RenderTick(_renderer, TickType::PostRender);
	}

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

	Game::Game(const Window* pWindow) :
		_worldManager(),
		_renderer(pWindow)
	{}
}