#include "Mouse.h"

namespace GrainEngine::Input
{
	Mouse::Mouse() :
		InputDevice(),
		_mousePosition()
	{}

	void Mouse::UpdateMousePosition(const HWND _handle) noexcept
	{
		POINT point = { 0 };
		if (GetCursorPos(&point) == false)
			return;

		if (ScreenToClient(_handle, &point))
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
		case WM_MOUSEMOVE:
			UpdateMousePosition(msg->hwnd);
			break;
		case WM_LBUTTONDOWN:
			InputDevice::Add(Key::MouseLeft);
			break;
		case WM_LBUTTONUP:
			InputDevice::Add(Key::MouseLeft, true);
			break;
		case WM_RBUTTONDOWN:
			InputDevice::Add(Key::MouseRight);
			break;
		case WM_RBUTTONUP:
			InputDevice::Add(Key::MouseRight, true);
			break;
		case WM_MBUTTONDOWN:
			InputDevice::Add(Key::MouseMiddle);
			break;
		case WM_MBUTTONUP:
			InputDevice::Add((Key)msg->wParam, true);
			break;

		default:
			break;
		}
	}

	void Mouse::Update() noexcept
	{
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