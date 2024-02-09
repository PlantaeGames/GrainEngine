#include "Engine.h"

namespace GrainEngine::Components
{
	unsigned int Engine::Run()
	{
		_mainWindow.Show();

		auto& inputManager = InitializeInput();

		const auto& mouse = inputManager.GetDevice<Mouse>();
		const auto& keyboard = inputManager.GetDevice<Keyboard>();

		auto& time = Time::GetInstance();

		MSG msg = { 0 };

		while (_running)
		{
			///  -----------------
			///	  | ENGINE CODE |
			///  -----------------
			float deltaTime = time.Tick();
			inputManager.Update();

			while (_mainWindow.PeekAndDispatchMessage(&msg))
			{
				// grabbing input
				inputManager.Feed(&msg);
			}
			if (msg.message == WM_QUIT)
			{
				Stop((unsigned int)msg.wParam);
			}
			
			///  -----------------
			/// | OTHER CODE HERE |
			///  -----------------


			///  -----------------
			///	  | ENGINE CODE |
			///  -----------------
			
			_renderer.DrawTriangle();
			_renderer.Present();

			Error::Log("FPS: " + std::to_string((int) (1 / deltaTime)) + " \n");
		}

		Error::Log("Engine Stoped.\n");

		return _exitCode;
	}

	InputManager& Engine::InitializeInput() const noexcept
	{
		auto& inputManager = InputManager::GetInstance();

		inputManager.RegisterDevice<Mouse>();
		inputManager.RegisterDevice<Keyboard>();

		return inputManager;
	}

	Engine::Engine(): 
		_mainWindow(WINDOW_NAME, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT),
		_renderer(_mainWindow.GetHandle())		
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