#include "Transform.h"

namespace GrainEngine::ECS::Components
{
	Transform::Transform() :
		IComponent(),
		position(),
		rotation(),
		scale(1.0f, 1.0f, 1.0f)
	{}

	Transform::~Transform() noexcept {}
}