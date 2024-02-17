#include "Entity.h"

namespace GrainEngine::ECS
{
	Entity::Entity() :
		_pComponents()
	{
		_pComponents.push(std::move(std::make_shared<Transform>()));
	}
}