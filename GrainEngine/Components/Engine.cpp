#include "Engine.h"

namespace GrainEngine::Components
{
	void Engine::Tick()
	{
		_game.Update();
	}

	void Engine::PrepareTick()
	{
		_pRTime->Tick();
		_pRInputManager->Update();

		while (_mainWindow.PeekAndDispatchMessage(&_msg))
		{
			// grabbing input
			_pRInputManager->Feed(&_msg);
		}
		if (_msg.message == WM_QUIT)
		{
			Stop((unsigned int)_msg.wParam);
		}
	}

	void Engine::EndTick()
	{
		_game.PrepareRender();
		_game.Render();
	}

	unsigned int Engine::Run()
	{
		InitializeWindow();
		InitializeInput();

		const auto& mouse = _pRInputManager->GetDevice<Mouse>();
		const auto& keyboard = _pRInputManager->GetDevice<Keyboard>();

		// adding test entities in game
		
		auto triangle = _game.GetWorldManager().GetActiveWorld().GetEntityManager().CreateEntity();
		triangle->AddComponent<Mesh>();
		triangle->AddComponent<MeshRenderer>();


		auto camera = _game.GetWorldManager().GetActiveWorld().GetEntityManager().CreateEntity();
		camera->AddComponent<Camera>();
		triangle->AddComponent<Movement>();

		auto random = Random();

		_game.Start();

		Error::ClearLog();

		while (_running)
		{
			///  -----------------
			///	  | ENGINE CODE |
			///  -----------------
		
			PrepareTick();

			///  -----------------
			/// | OTHER CODE HERE |
			///  -----------------
			
			Tick();

			if (keyboard.GetKey(Key::Up))
			{
				auto entity = _game.GetWorldManager().GetActiveWorld().GetEntityManager().CreateEntity();
				entity->AddComponent<Mesh>();
				entity->AddComponent<MeshRenderer>();

				entity->pMTransform->position = {random.NextFloat(-100, 100), random.NextFloat(-100, 100), random.NextFloat(2, 100)};
				entity->pMTransform->scale = { 2,2,2 };

				entity->AddComponent<Movement>();
			}

			///  -----------------
			///	  | ENGINE CODE |
			///  -----------------
			
			EndTick();

			Error::ResetLogCursor();
			//Error::ClearLog();

			Error::Log("CURRENT MANAGED OBJECTS UNDER GC ARE: " + std::to_string(GarbageCollector::GetInstance().GetManagedObjectsCount()) + "\n");
			Error::Log("FPS: " + std::to_string(_pRTime->FPS()) + " \n");
		}

		_game.End();

		Error::Log("Engine Stoped.\n");

		return _exitCode;
	}


	void Engine::InitializeWindow() const noexcept
	{
		_mainWindow.Show();
	}

	void Engine::InitializeInput() const noexcept
	{
		_pRInputManager->RegisterDevice<Mouse>();
		_pRInputManager->RegisterDevice<Keyboard>();
	}

	Engine::Engine(): 
		_mainWindow(WINDOW_NAME, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT),
		_game(dynamic_cast<Window*>(&_mainWindow)),
		_msg(),
		_pRTime(Time::GetInstance()),
		_pRInputManager(InputManager::GetInstance())
	{}

	unsigned int Engine::Start()
	{
		assert(_running == false);

		_running = true;
		Error::Log("Engine Started.\n");

		unsigned int exitCode = Run();

		return exitCode;
	}

	void Engine::Stop(unsigned int exitCode) noexcept
	{
		assert(_running == true);

		_running = false;
		_exitCode = exitCode;

		Error::Log("Stoping Engine.\n");
	}
}