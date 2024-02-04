#pragma once

#include "Graphics/Window.h"

namespace GrainEngine::Components
{
	using namespace Graphics;

	class MainWindow : public Window
	{
	public:
		MainWindow(const wchar_t* name,
			unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		MainWindow(const MainWindow& otherInstance) = default;
		MainWindow(MainWindow&& oldInstance) = default;
		MainWindow& operator= (const MainWindow& newInstance) = delete;
		MainWindow& operator= (MainWindow&& oldInstance) noexcept = delete;
		~MainWindow() noexcept override = default;

		bool PeekAndDispatchMessage(MSG* pMsg) const noexcept override;
	private:
		MainWindow() = delete;
		LRESULT WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept override;
	};
}