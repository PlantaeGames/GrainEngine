#include "Main.h"

namespace GrainEngine
{
	size_t Main()
	{
		MainWindow mainWindow(WINDOW_NAME, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

		auto& inputManager = InputManager::GetInstance();
		inputManager.RegisterDevice<Mouse>();
		inputManager.RegisterDevice<Keyboard>();
		const auto& mouseDevice = inputManager.GetDevice<Mouse>();
		const auto& keyboadDevice = inputManager.GetDevice<Keyboard>();

		auto stopwatch = Stopwatch();
		float deltaTime = 0.0f;

		MSG msg = { 0 };

		mainWindow.Show();

		while (true)
		{
			// engine code
			while (mainWindow.PeekAndDispatchMessage(&msg))
			{
				// grabbing input
				inputManager.Feed(&msg);
			}
			if (msg.message == WM_QUIT) break;

			stopwatch.Reset();
			stopwatch.Start();

			/// other code here.
			/// ...
			///				///

			inputManager.Update();

			deltaTime = stopwatch.Lapse();
			auto fps = (unsigned int)((1.0f / deltaTime));
			Error::Log("FPS: " + std::to_string(fps));
			Error::ResetLogCursor();
			//				//
		}

		size_t exitCode = (size_t)msg.wParam;
		return exitCode;
	}
}