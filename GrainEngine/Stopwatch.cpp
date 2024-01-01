#include "Stopwatch.h"

Stopwatch::Stopwatch() : _clock()
{
	_start = _clock.now();
}

void Stopwatch::Start()
{
	_start = _clock.now();
}

float Stopwatch::Stop()
{
	_end = _clock.now();

	std::chrono::duration<float> duration = _end - _start;
	return duration.count();
}