#include "Entity.h"

namespace GrainEngine::ECS
{
	Entity::Entity() :
		name("Entity"),
		tag(Tag::None),
		_pMComponents()
	{
		pMTransform = AddComponent<Transform>();
	}

	Entity::~Entity() noexcept
	{
		for (auto& pMComponent : _pMComponents)
		{
			pMComponent.Release();
		}
	}
}