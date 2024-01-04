#include "Main.h"

size_t Main()
{
	Window mainWindow(WINDOW_NAME, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	mainWindow.Show();

	MSG msg = { 0 };
	while (mainWindow.PeekAndDispatchMessage(&msg))
	{ 
	}

	size_t exitCode = (size_t) msg.wParam;
	return exitCode;
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	size_t returnCode = 0;
	try
	{
		returnCode = Main();
	}
	catch (const Error& error)
	{
		error.Show();
	}
	catch (const std::exception& exception)
	{
		GENERATE_ERROR(exception.what()).Show();
	}
	return (int) returnCode;
}