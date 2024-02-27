#include "Entity.h"

namespace GrainEngine::ECS
{
	void Entity::Tick(ManagedObject<Entity>& pMEntity, TickType tickType)
	{
		switch (tickType)
		{
		case TickType::None:
			break;

		case TickType::Awake:
			AwakeTick(pMEntity);
			break;
		case TickType::Start:
			StartTick(pMEntity);
			break;
		case TickType::Update:
			UpdateTick(pMEntity);
			break;
		case TickType::End:
			EndTick(pMEntity);
			break;

		default:
			break;
		}
	}

	void Entity::AwakeTick(ManagedObject<Entity>& pMEntity)
	{
		for (auto& pMComponent : _pMComponents)
		{
			pMComponent->Awake(pMEntity);
		}
	}
	void Entity::StartTick(ManagedObject<Entity>& pMEntity)
	{
		for (auto& pMComponent : _pMComponents)
		{
			pMComponent->Start(pMEntity);
		}
	}
	void Entity::UpdateTick(ManagedObject<Entity>& pMEntity)
	{
		for (auto& pMComponent : _pMComponents)
		{
			pMComponent->Update(pMEntity);
		}
	}
	void Entity::EndTick(ManagedObject<Entity>& pMEntity)
	{
		for (auto& pMComponent : _pMComponents)
		{
			pMComponent->End(pMEntity);
		}
	}

	Entity::Entity() :
		name("Entity"),
		tag(Tag::None),
		_pMComponents()
	{
		_id = (unsigned long long) this;

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