#pragma once

#include <windows.h>

#include "Patterns\Singleton.h"
#include "Input\Mouse.h"
#include "Input\Keyboard.h"

namespace GrainEngine::Input
{
	using namespace Patterns;

	class Input : public Singleton<Input>
	{
	public:
		Input(const Input& otherInstance) = delete;
		Input(Input&& oldInstance) noexcept = delete;
		Input& operator= (const Input& otherInstance) = delete;
		Input& operator= (Input&& oldInstance) noexcept = delete;

	private:
		Input();
		~Input() noexcept override = default;

	private:
		Keyboard _keyboard;
		Mouse _mouse;
	};
}

