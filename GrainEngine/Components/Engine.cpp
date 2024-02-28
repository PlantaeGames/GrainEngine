#include "Engine.h"

namespace GrainEngine::Components
{
	void Engine::Tick()
	{
		_game.Update();
	}

	void Engine::PrepareTick()
	{
		_game.PrepareRender();
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
		_game.Render();
	}

	unsigned int Engine::Run()
	{
		InitializeWindow();
		InitializeInput();

		const auto& mouse = _pRInputManager->GetDevice<Mouse>();
		const auto& keyboard = _pRInputManager->GetDevice<Keyboard>();

		// adding test enties in game
		
		auto entity = _game.GetWorldManager().GetActiveWorld().GetEntityManager().CreateEntity();
		entity->AddComponent<Mesh>();
		entity->AddComponent<MeshRenderer>();

		_game.Start();

		_game.PrepareRender();

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

			///  -----------------
			///	  | ENGINE CODE |
			///  -----------------
			
			EndTick();

			Error::Log("CURRENT MANAGED OBJECTS UNDER GC ARE: " + std::to_string(GarbageCollector::GetInstance().GetManagedObjectsCount()) + "\n");
			//Error::Log("FPS: " + std::to_string(_pRTime->FPS()) + " \n");
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
		_game(_mainWindow.GetHandle()),
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