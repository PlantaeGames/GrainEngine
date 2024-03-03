#pragma once

#include "Components/InputManager.h"
#include "Components/MainWindow.h"
#include "Components/Time.h"
#include "Errors/Error.h"
#include "Components/Game.h"
#include "Misc/RefPtr.h"
#include "ECS/GarbageCollector.h"

#include "ECS/ManagedObject.h"
#include "ECS/Components/Mesh.h"
#include "ECS/Components/MeshRenderer.h"
#include "ECS/Scripts/Movement.h"
#include "ECS/Components/Camera.h"
#include "Utilities/Random.h"

namespace GrainEngine::Components
{
#define WINDOW_NAME L"GrainEngine"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::ECS;
	using namespace GrainEngine::ECS::Components;
	using namespace GrainEngine::Misc;
	using namespace GrainEngine::ECS::Scripts;
	using namespace GrainEngine::Utilities;

	class Engine
	{
	private:
		MainWindow _mainWindow;
		Game _game;
		MSG _msg;
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