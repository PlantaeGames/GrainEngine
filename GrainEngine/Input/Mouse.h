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
		Point<int> GetMousePosition() const noexcept;
	private:
		void UpdateMousePosition() noexcept;
	private:
		Point<int> _mousePosition;
	};
}