#pragma once

#include "Structures/Vector3.h"

namespace GrainEngine::Graphics
{
	using namespace GrainEngine::Structures;

	struct TransformConstantBuffer
	{
		Vector3 position;
		Vector3 rotation;
		Vector3 scale;
	};
}