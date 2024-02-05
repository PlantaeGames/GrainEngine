#pragma once

#include "Components/InputManager.h"
#include "Components/MainWindow.h"
#include "Components/Time.h"
#include "Errors/Error.h"
#include "Patterns/Singleton.h"
#include "Graphics/D3DRenderer.h"

namespace GrainEngine::Components
{
#define WINDOW_NAME L"GrainEngine"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

	using namespace Patterns;
	using namespace Errors;
	using namespace Graphics;

	class Engine : public Singleton<Engine>
	{
		friend Singleton;

	private:
		MainWindow _mainWindow;
		D3DRenderer _renderer;

		bool _running = false;
		unsigned int _exitCode = 0;

	public:
		Engine(const Engine& otherInstance) = delete;
		Engine(Engine&& oldInstance) noexcept = delete;
		Engine& operator= (const Engine& otherInstance) = delete;
		Engine& operator= (Engine&& oldInstance) noexcept = delete;

		unsigned int Start() noexcept;
		void Stop(unsigned int exitCode) noexcept;

	private:
		Engine();
		~Engine() noexcept override = default;

		unsigned int Run() noexcept;
		InputManager& InitializeInput() const noexcept;
	};
}