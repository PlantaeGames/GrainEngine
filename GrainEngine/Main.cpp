#include "Main.h"

namespace GrainEngine
{
	size_t Main()
	{
		MainWindow mainWindow(WINDOW_NAME, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

		auto& inputManager = InputManager::GetInstance();

		auto stopwatch = Stopwatch();
		float deltaTime = 0.0f;

		MSG msg = { 0 };

		mainWindow.Show();

		while (true)
		{
			while (mainWindow.PeekAndDispatchMessage(&msg))
			{
				// grabbing input
				inputManager.Feed(&msg);
			}
			if	  (msg.message == WM_QUIT) break;

			// engine code
			stopwatch.Reset();
			stopwatch.Start();

			/// other code here.
			if (InputManager::GetInstance().GetKeyDown(Key::Down) &&
				InputManager::GetInstance().GetKeyDown(Key::Up))
			{
				Error::Log("Test");
			}
			/// ...
			///				///

			inputManager.Update();

			deltaTime = stopwatch.Lapse();
			auto fps = (unsigned int)((1.0f / deltaTime));
			//				//
		}

		size_t exitCode = (size_t)msg.wParam;
		return exitCode;
	}
}