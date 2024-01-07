#pragma once

#include <vector>

#include "Key.h"

namespace GrainEngine::Input
{
	using std::vector;

	class InputDevice
	{
	public:
		InputDevice(const InputDevice& otherInstance) = delete;
		InputDevice(InputDevice& oldInstance) noexcept = delete;
		InputDevice& operator= (const InputDevice& otherInstance) = delete;
		InputDevice& operator= (InputDevice&& oldInstance) noexcept = delete;
	private:
		bool Includes(const vector<Key>& container, Key key) const noexcept;
		void Remove(vector<Key>& container, Key key) noexcept;
	protected:
		InputDevice();
		virtual ~InputDevice() noexcept = default;

		virtual void Add(Key key, bool keyUp = false) noexcept;

		virtual bool GetKey(Key key) const noexcept;
		virtual bool GetKeyDown(Key key) const noexcept;
		virtual bool GetKeyUp(Key key) const noexcept;

		virtual void Clear() noexcept;

		virtual void Update() noexcept = 0;
	private:
		vector<Key> _keys;
		vector<Key> _keysDown;
		vector<Key> _keysUp;
	};
}