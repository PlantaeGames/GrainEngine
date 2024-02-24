#pragma once

#include "Components/InputManager.h"
#include "Components/MainWindow.h"
#include "Components/Time.h"
#include "Errors/Error.h"
#include "Graphics/D3D/D3DRenderer.h"
#include "Components/Game.h"
#include "Misc/RefPtr.h"
#include "ECS/GarbageCollector.h"

namespace GrainEngine::Components
{
#define WINDOW_NAME L"GrainEngine"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Misc;
	using namespace Graphics;

	class Engine
	{
	private:
		Game _game;
		MainWindow _mainWindow;
		MSG _msg;
		D3DRenderer _renderer;
		mutable RefPtr<Time> _pRTime;
		mutable RefPtr<InputManager> _pRInputManager;

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
		void PrepareTick();
		void Tick();
		void EndTick();

		unsigned int Run();
		void InitializeInput() const noexcept;
		void InitializeWindow() const noexcept;
	};
}