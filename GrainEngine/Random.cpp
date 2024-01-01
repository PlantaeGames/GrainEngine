#include "Random.h"

Random::Random() : _randomEngine(_randomEngineKey())
{
}

int Random::NextInt(int min, int max)
{
	std::uniform_int_distribution<int> distributor(min, max);
	return distributor(_randomEngine);
}
float Random::NextFloat(float min, float max)
{
	std::uniform_real_distribution<float> distributor(min, max);
	return distributor(_randomEngine);
}