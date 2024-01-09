#include "MainWindow.h"

namespace GrainEngine::Components
{
	MainWindow::MainWindow(const wchar_t* name,
		unsigned int x, unsigned int y, unsigned int width, unsigned int height) :
		Window(name, x, y, width, height)
	{}

	LRESULT MainWindow::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
	{
		return Window::WindowProc(hWnd, msg, wParam, lParam);
	}

	bool MainWindow::PeekAndDispatchMessage(MSG* pMsg) const noexcept
	{
		bool result = false;
		result = PeekMessageW(pMsg, nullptr, 0, 0, PM_REMOVE);

		if (pMsg->message == WM_QUIT)
		{
			return result;
		}

		TranslateMessage(pMsg);
		DispatchMessageW(pMsg);

		return result;
	}
}