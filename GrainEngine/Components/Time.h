#pragma once

#include "Patterns/Singleton.h"
#include "Diagnostics/Stopwatch.h"

namespace GrainEngine::Components
{
	using namespace Patterns;
	using namespace Diagnostics;

	class Time : public Singleton<Time>
	{
		friend Singleton;

	private:
		Stopwatch _stopWatch;
		float _deltaTime = 0.0f;
	public:
		Time(const Time& otherInstance) = delete;
		Time(Time&& oldInstance) noexcept = delete;
		Time& operator= (const Time& otherInstance) = delete;
		Time& operator= (Time&& oldInstance) noexcept = delete;

		float Tick() noexcept;
		float GetDeltaTime() const noexcept;

	private:
		Time();
		~Time() noexcept override = default;
	};
}