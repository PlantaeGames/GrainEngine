#include "Entity.h"

namespace GrainEngine::ECS
{
	Entity::Entity() :
		_pComponents()
	{
		_pComponents.push_back(ManagedObject<Transform>());
	}
}