#include "Entity.h"

namespace GrainEngine::ECS
{
	Entity::Entity() :
		_pComponents()
	{
		_pComponents.push_back(ManagedObject<IComponent>().New<Transform>());
	}

	Entity::~Entity() noexcept
	{
		for (auto& pComponent : _pComponents)
		{
			pComponent.Release();
		}
	}
}