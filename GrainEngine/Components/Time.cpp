#include "Time.h"

namespace GrainEngine::Components
{
	unsigned int Time::FPS() const noexcept
	{
		return (unsigned int) (1 / _deltaTime);
	}

	Time::Time()
		: _stopWatch()
	{}

	float Time::Tick() noexcept
	{
		_deltaTime = _stopWatch.Lapse();

		_stopWatch.Reset();
		_stopWatch.Start();

		return GetDeltaTime();
	}

	float Time::GetDeltaTime() const noexcept
	{
		return _deltaTime;
	}
}