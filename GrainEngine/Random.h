#pragma once

#include <random>

class Random
{
private:
	static std::mt19937 _randomEngine;
	static std::random_device _randomEngineKey;
public:
	static int NextInt(int min, int max) noexcept;
	static float NextFloat(float min, float max) noexcept;
private:
	Random() = default;
};

