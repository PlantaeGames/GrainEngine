#include "Keyboard.h"

namespace GrainEngine::Input
{
	Keyboard::Keyboard() :
		InputDevice()
	{}

	void Keyboard::Feed(const MSG* const msg) noexcept
	{
		unsigned int message = (unsigned int)msg->message;
		switch (message)
		{
		case WM_KEYDOWN:
			InputDevice::Add((Key) msg->wParam);
			return;
		case WM_KEYUP:
			InputDevice::Add((Key)msg->wParam, true);
			return;
		default:
			return;
		}
	}

	bool Keyboard::GetKey(Key key) const noexcept
	{
		return InputDevice::GetKey(key);
	}

	bool Keyboard::GetKeyDown(Key key) const noexcept
	{
		return InputDevice::GetKeyDown(key);
	}

	bool Keyboard::GetKeyUp(Key key) const noexcept
	{
		return InputDevice::GetKeyUp(key);
	}

	void Keyboard::Update() noexcept
	{
		InputDevice::Clear();
	}
}