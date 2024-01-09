#pragma once

#include <vector>

#include <windows.h>

#include "Key.h"
#include "InputDevice.h"

namespace GrainEngine::Input
{
	class Keyboard : public InputDevice
	{
	public:
		Keyboard();
		Keyboard(const Keyboard& otherInstance) = delete;
		Keyboard(Keyboard&& oldInstance) noexcept = delete;
		Keyboard& operator= (const Keyboard& otherInstance) = delete;
		Keyboard& operator= (Keyboard&& oldInstance) noexcept = delete;
		~Keyboard() noexcept override = default;

		void Feed(const MSG* const msg) noexcept override;

		bool GetKey(Key key) const noexcept override;
		bool GetKeyDown(Key key) const noexcept override;
		bool GetKeyUp(Key key) const noexcept override;

		void Update() noexcept override;
	};
}

