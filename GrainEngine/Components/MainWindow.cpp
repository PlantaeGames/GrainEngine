#include "MainWindow.h"

namespace GrainEngine::Components
{
	MainWindow::MainWindow(const wchar_t* name,
		unsigned int x, unsigned int y, unsigned int width, unsigned int height) :
		Window(name, x, y, width, height)
	{}

	LRESULT MainWindow::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
	{
		switch (msg)
		{
		case WM_KEYDOWN:
			break;
		case WM_KEYUP:
			break;
		}

		return Window::WindowProc(hWnd, msg, wParam, lParam);
	}
}