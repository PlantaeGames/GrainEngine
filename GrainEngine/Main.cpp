#include "Main.h"

size_t Main()
{
	Window mainWindow(WINDOW_NAME, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, WindowProc);
	mainWindow.Show();

	Random random = Random();
	Stopwatch stopwatch = Stopwatch();

	stopwatch.Start();
	for (int i = 0; i < 10000000; i++)
	{
		int t = random.NextInt(0, 100);
	}

	float time = stopwatch.Stop();

	MSG msg = { 0 };
	while (mainWindow.PeekAndDispatchMessage(&msg))
	{
	}

	size_t exitCode = (size_t) msg.wParam;
	return exitCode;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_CLOSE)
	{
		PostQuitMessage(UI_EXITCODE);
		return 0;
	}

	return DefWindowProcW(hWnd, msg, wParam, lParam);
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	size_t returnCode = Main();
	return (int) returnCode;
}