#include "Mouse.h"

namespace GrainEngine::Input
{
	Mouse::Mouse() :
		InputDevice(),
		_mousePosition()
	{}

	void Mouse::UpdateMousePosition() noexcept
	{
		POINT point = { 0 };
		if (GetCursorPos(&point))
		{
			_mousePosition.x = point.x;
			_mousePosition.y = point.y;
		}
	}

	void Mouse::Update() noexcept
	{
		UpdateMousePosition();
		InputDevice::Clear();
	}

	Point<int> Mouse::GetMousePosition() const noexcept
	{
		return _mousePosition;
	}

	void Mouse::Add(Key key, bool keyUp) noexcept
	{
		InputDevice::Add(key, keyUp);
	}

	bool Mouse::GetKey(Key key) const noexcept
	{
		return InputDevice::GetKey(key);
	}

	bool Mouse::GetKeyDown(Key key) const noexcept
	{
		return InputDevice::GetKeyDown(key);
	}

	bool Mouse::GetKeyUp(Key key) const noexcept
	{
		return InputDevice::GetKeyUp(key);
	}
}