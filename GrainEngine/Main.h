#pragma once

#include <Windows.h>

#include "MainWindow.h"
#include "Stopwatch.h"
#include <string>

#define WINDOW_NAME L"GrainEngine"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/// <summary>
/// The Main function of the engine.
/// </summary>
/// <returns>Exit Code.</returns>
size_t Main();