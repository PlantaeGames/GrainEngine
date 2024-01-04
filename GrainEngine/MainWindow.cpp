#include "MainWindow.h"

MainWindow::MainWindow(const wchar_t* name,
	unsigned int x, unsigned int y, unsigned int width, unsigned int height) :
	Window(name, x, y, width, height)
{

}

LRESULT MainWindow::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
	return Window::WindowProc(hWnd, msg, wParam, lParam);
}