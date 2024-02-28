#include "Random.h"

namespace GrainEngine::Utilities
{
	int Random::NextInt(int min, int max) noexcept
	{
		std::uniform_int_distribution<int> distributor(min, max);
		return distributor(_randomEngine);
	}
	float Random::NextFloat(float min, float max) noexcept
	{
		std::uniform_real_distribution<float> distributor(min, max);
		return distributor(_randomEngine);
	}

	Random::Random() :
		_randomEngineKey(),
		_randomEngine(_randomEngineKey())
	{}
}