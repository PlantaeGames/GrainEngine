#pragma once

#include <windows.h>

namespace GrainEngine::Input
{
	enum class Key : unsigned short
	{
		// keyboard
		Up = VK_UP,
		Down = VK_DOWN,
		Right = VK_RIGHT,
		Left = VK_LEFT,

		// mouse
		MouseRight = VK_RBUTTON,
		MouseLeft = VK_LBUTTON,
		MouseMiddle = VK_MBUTTON
	};
}