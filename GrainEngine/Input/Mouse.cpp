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

	void Mouse::Feed(const MSG* const msg) noexcept
	{
		unsigned int message = (unsigned int)msg->message;
		switch (message)
		{
		case WM_LBUTTONDOWN:
			InputDevice::Add((Key)msg->wParam);
			return;
		case WM_LBUTTONUP:
			InputDevice::Add((Key)msg->wParam, true);
			return;
		case WM_RBUTTONDOWN:
			InputDevice::Add((Key)msg->wParam);
			return;
		case WM_RBUTTONUP:
			InputDevice::Add((Key)msg->wParam, true);
			return;
		case WM_MBUTTONDOWN:
			InputDevice::Add((Key)msg->wParam);
			return;
		case WM_MBUTTONUP:
			InputDevice::Add((Key)msg->wParam, true);
			return;

		default:
			return;
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