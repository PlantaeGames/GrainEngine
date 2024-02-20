#include "Entity.h"

namespace GrainEngine::ECS
{
	Entity::Entity() :
		_pComponents(),
		name("Entity"),
		transform(),
		tag(Tag::None)
	{
		_pComponents.push_back(ManagedObject<IComponent>().New<Transform>());

		const auto transform = GetComponent<Transform>();
		this->transform = transform;
	}

	Entity::~Entity() noexcept
	{
		for (auto& pComponent : _pComponents)
		{
			pComponent.Release();
		}
	}
}