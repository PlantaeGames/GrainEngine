#pragma once

#include <vector>

#include <Windows.h>

#include "Structures/Point.h"
#include "Key.h"
#include "Input/InputDevice.h"

namespace GrainEngine::Input
{
	using namespace Structures;

	class Mouse : public InputDevice
	{
	public:
		Mouse(unsigned int id);
		Mouse();
		Mouse(const Mouse& otherInstance) = delete;
		Mouse(Mouse&& oldInstance) noexcept = delete;
		Mouse& operator= (const Mouse& otherInstance) = delete;
		Mouse& operator= (Mouse&& oldInstance) noexcept = delete;
		~Mouse() noexcept override = default;

		void Feed(const MSG* const msg) noexcept override;

		bool GetKey(Key key) const noexcept override;
		bool GetKeyDown(Key key) const noexcept override;
		bool GetKeyUp(Key key) const noexcept override;

		void Update() noexcept override;
		Point GetCursorPosition() const noexcept;
	private:
		void UpdateMousePosition(const HWND _handle) noexcept;
	private:
		Point _cursorPosition;
	};
}