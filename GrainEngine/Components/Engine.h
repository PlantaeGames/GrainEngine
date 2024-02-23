#pragma once

#include "Components/InputManager.h"
#include "Components/MainWindow.h"
#include "Components/Time.h"
#include "Errors/Error.h"
#include "Graphics/D3D/D3DRenderer.h"
#include "Components/Game.h"

namespace GrainEngine::Components
{
#define WINDOW_NAME L"GrainEngine"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

	using namespace GrainEngine::Errors;
	using namespace Graphics;

	class Engine
	{
	private:
		Game _game;
		MainWindow _mainWindow;
		D3DRenderer _renderer;

		bool _running = false;
		unsigned int _exitCode = 0;

	public:
		Engine();
		~Engine() noexcept = default;

		Engine(const Engine& otherInstance) = delete;
		Engine(Engine&& oldInstance) noexcept = delete;
		Engine& operator= (const Engine& otherInstance) = delete;
		Engine& operator= (Engine&& oldInstance) noexcept = delete;

		unsigned int Start();
		void Stop(unsigned int exitCode) noexcept;

	private:
		unsigned int Run();
		InputManager& InitializeInput() const noexcept;
	};
}