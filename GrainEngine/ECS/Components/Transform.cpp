#include "Transform.h"

namespace GrainEngine::ECS::Components
{
	Transform::Transform() :
		IComponent(),
		position(),
		rotation(),
		scale(1.0f, 1.0f, 1.0f)
	{

	}

	void Transform::Start(ManagedObject<Entity>& pMEntity)
	{
		
	}

	void Transform::Update(ManagedObject<Entity>& pMEntity)
	{}

	Transform::~Transform() noexcept {}
}