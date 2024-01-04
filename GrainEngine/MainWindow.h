#pragma once

#include "Window.h"

class MainWindow : public Window
{
public:
	MainWindow(const wchar_t* name,
		unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	MainWindow(const MainWindow& otherInstance) = default;
	MainWindow(MainWindow&& oldInstance) = default;
	MainWindow& operator= (const MainWindow& newInstance) = default;
	MainWindow& operator= (MainWindow&& oldInstance) = default;
	~MainWindow() noexcept override = default;
private:
	MainWindow() = default;
	LRESULT WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept override;
};