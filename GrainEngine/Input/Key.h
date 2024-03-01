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
		W = 0x57,
		S = 0x53,
		A = 0x41,
		D = 0x44,

		// mouse
		MouseRight = VK_RBUTTON,
		MouseLeft = VK_LBUTTON,
		MouseMiddle = VK_MBUTTON
	};
}