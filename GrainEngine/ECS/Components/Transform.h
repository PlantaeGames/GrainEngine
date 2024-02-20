#pragma once

#include "ECS/IComponent.h"
#include "Structures/Vector3.h"

namespace GrainEngine::ECS::Components
{
	using namespace Structures;

	class Transform : public IComponent
	{
	public:
		Transform();
		~Transform() noexcept override;

	public:
		Vector3 position;
		Vector3 rotation;
		Vector3 scale;
	};
}
