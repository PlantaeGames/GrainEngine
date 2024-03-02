#pragma once

#include "Structures/Vector3.h"

namespace GrainEngine::Graphics
{
	using namespace GrainEngine::Structures;

	struct PerspectiveConstantBuffer
	{
		__declspec(align(16))
		Vector3 position;
		__declspec(align(16))
		Vector3 rotation;
		__declspec(align(16))
		Vector3 scale;
	};
}