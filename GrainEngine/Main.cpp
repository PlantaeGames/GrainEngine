#include "Main.h"

namespace GrainEngine
{
	size_t Main()
	{
		MainWindow mainWindow(WINDOW_NAME, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
		mainWindow.Show();

		auto stopwatch = Stopwatch();
		float deltaTime = 0.0f;

		MSG msg = { 0 };
		while (mainWindow.PeekAndDispatchMessage(&msg))
		{
			stopwatch.Reset();
			stopwatch.Start();

			// other code here.

			deltaTime = stopwatch.Lapse();
			auto fps = (unsigned int)((1.0f / deltaTime));
		}

		size_t exitCode = (size_t)msg.wParam;
		return exitCode;
	}
}