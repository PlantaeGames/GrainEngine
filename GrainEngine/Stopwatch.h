#pragma once

#include <chrono>

/// <summary>
/// A stopwatch to record time lapse.
/// </summary>
class Stopwatch
{
private:
	std::chrono::steady_clock _clock;
	std::chrono::steady_clock::time_point _start;
	std::chrono::steady_clock::time_point _end;
public:
	/// <summary>
	/// Default constructor.
	/// </summary>
	Stopwatch();
	/// <summary>
	/// Starts the stop watch.
	/// </summary>
	void Start();
	/// <summary>
	/// Records the time lapse from last start.
	/// </summary>
	/// <returns>The lapsed time.</returns>
	float Lapse();
	void Reset();
};
