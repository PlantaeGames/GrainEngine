#include "Transform.h"

namespace GrainEngine::ECS::Components
{
	Transform::Transform() :
		IComponent(),
		position(0.0f, 0.0f, 0.0f),
		rotation(0.0f, 0.0f, 0.0f),
		scale(0.0f, 0.0f, 0.0f)
	{}

	Transform::~Transform() noexcept {}
}