#include "Stopwatch.h"

namespace GrainEngine::Diagnostics
{
	Stopwatch::Stopwatch() : _clock()
	{
		_start = _clock.now();
	}

	void Stopwatch::Start()
	{
		_start = _clock.now();
	}

	float Stopwatch::Lapse()
	{
		_end = _clock.now();

		std::chrono::duration<float> duration = _end - _start;
		return duration.count();
	}

	void Stopwatch::Reset()
	{
		_start = _clock.now();
		_end = _start;
	}
}