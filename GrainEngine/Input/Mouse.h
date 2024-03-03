#pragma once

#include <vector>

#include <Windows.h>

#include "Structures/Point.h"
#include "Key.h"
#include "Structures/Rect.h"
#include "Input/InputDevice.h"
#include "Errors/Error.h"

namespace GrainEngine::Input
{
	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Structures;

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
		void UpdateMouseDeltaPosition() noexcept;
		Point GetCursorDirection() const noexcept;
	private:
		void UpdateMousePosition(const HWND handle) noexcept;
	private:
		Point _cursorPosition;
		Point _cursorLastPositionUnRel;
		Point _cursorDir;
	};
}