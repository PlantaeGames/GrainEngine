#pragma once

#include <Windows.h>

#include "Window.h"

#define WINDOW_NAME L"GrainEngine"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define UI_EXITCODE 1

/// <summary>
/// The Main function of the engine.
/// </summary>
/// <returns>Exit Code.</returns>
size_t Main();

/// <summary>
/// The Message handler of the window.
/// </summary>
/// <param name="hWnd">Handle of the Window.</param>
/// <param name="msg">The Current Message.</param>
/// <param name="wParam">idk.</param>
/// <param name="lParam">Optional Parametre.</param>
/// <returns></returns>
LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);