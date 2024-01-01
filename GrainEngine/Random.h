#pragma once

#include <random>

class Random
{
private:
	std::mt19937 _randomEngine;
	std::random_device _randomEngineKey;
public:
	Random();
	int NextInt(int min, int max);
	float NextFloat(float min, float max);
};

