#pragma once

#include "ECS/IComponent.h"

namespace GrainEngine::ECS::Components
{
	class Transform : public IComponent
	{
	public:
		Transform();
		~Transform() noexcept override;
	};
}
