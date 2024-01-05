#include "MainWindow.h"

MainWindow::MainWindow(const wchar_t* name,
	unsigned int x, unsigned int y, unsigned int width, unsigned int height) :
	Window(name, x, y, width, height),
	keyboard()
{

}

LRESULT MainWindow::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
	switch (msg)
	{
	case WM_KEYDOWN:
		keyboard.Add((Keyboard::Key) wParam);
		break;
	case WM_KEYUP:
		keyboard.Add((Keyboard::Key) wParam, true);
		break;
	}

	return Window::WindowProc(hWnd, msg, wParam, lParam);
}

Keyboard& MainWindow::GetKeyboard() const noexcept
{
	return keyboard;
}