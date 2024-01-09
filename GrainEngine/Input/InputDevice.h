#pragma once

#include <vector>

#include <windows.h>

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

		virtual ~InputDevice() noexcept = default;

		virtual void Feed(const MSG* msg) noexcept = 0;

		virtual bool GetKey(Key key) const noexcept;
		virtual bool GetKeyDown(Key key) const noexcept;
		virtual bool GetKeyUp(Key key) const noexcept;

		virtual void Clear() noexcept;

		virtual void Update() noexcept = 0;

		unsigned int GetId() const noexcept { return _id; }
		void SetId(const unsigned int id) noexcept { _id = id; }
	private:
		bool Includes(const vector<Key>& container, Key key) const noexcept;
		void Remove(vector<Key>& container, Key key) noexcept;

	protected:
		InputDevice();

		void Add(Key key, bool keyUp = false) noexcept;
	private:
		vector<Key> _keys;
		vector<Key> _keysDown;
		vector<Key> _keysUp;

		unsigned int _id = 0;
	};
}