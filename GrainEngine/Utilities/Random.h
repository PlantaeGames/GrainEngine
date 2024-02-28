#pragma once

#include <random>

namespace GrainEngine::Utilities
{
	class Random
	{
	private:
		std::random_device _randomEngineKey;
		std::mt19937 _randomEngine;
	public:
		Random();
		~Random() noexcept = default;

		int NextInt(int min, int max) noexcept;
		float NextFloat(float min, float max) noexcept;
	};
}