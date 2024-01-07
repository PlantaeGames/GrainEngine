#pragma once

#include <windows.h>

namespace GrainEngine::Input
{
	enum class Key : unsigned short
	{
		Up = VK_UP,
		Down = VK_DOWN,
		Right = VK_RIGHT,
		Left = VK_LEFT
	};
}