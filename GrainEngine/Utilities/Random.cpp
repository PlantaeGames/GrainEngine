#include "Random.h"

namespace GrainEngine::Utilities
{
	std::random_device Random::_randomEngineKey;
	std::mt19937 Random::_randomEngine(Random::_randomEngineKey());

	int Random::NextInt(int min, int max) noexcept
	{
		std::uniform_int_distribution<int> distributor(min, max);
		return distributor(Random::_randomEngine);
	}
	float Random::NextFloat(float min, float max) noexcept
	{
		std::uniform_real_distribution<float> distributor(min, max);
		return distributor(Random::_randomEngine);
	}
}