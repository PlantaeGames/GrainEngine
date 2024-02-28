#include "Entity.h"

namespace GrainEngine::ECS
{
	void Entity::RenderTick(const Renderer& renderer, TickType tickType)
	{
		switch (tickType)
		{
		case TickType::PreRender:
			PreRenderTick(renderer);
			break;
		case TickType::PostRender:
			PostRenderTick(renderer);
			break;
		default:
			break;
		}
	}

	void Entity::Tick(TickType tickType)
	{
		switch (tickType)
		{
		case TickType::None:
			break;

		case TickType::Start:
			StartTick();
			break;
		case TickType::Update:
			UpdateTick();
			break;
		case TickType::End:
			EndTick();
			break;

		default:
			break;
		}
	}

	void Entity::Awake(ManagedObject<Entity>& pMEntity)
	{
		_pMSelf = pMEntity;
	}
	void Entity::StartTick()
	{
		for (auto& pMComponent : _pMComponents)
		{
			pMComponent->Start();
		}
	}
	void Entity::UpdateTick()
	{
		for (auto& pMComponent : _pMComponents)
		{
			pMComponent->Update();
		}
	}
	void Entity::PreRenderTick(const Renderer& renderer)
	{
		for (auto& pMComponent : _pMComponents)
		{
			pMComponent->PreRender(renderer);
		}
	}
	void Entity::PostRenderTick(const Renderer& renderer)
	{
		for (auto& pMComponent : _pMComponents)
		{
			pMComponent->PostRender(renderer);
		}
	}
	void Entity::EndTick()
	{
		for (auto& pMComponent : _pMComponents)
		{
			pMComponent->End();
		}
	}

	void Entity::AwakeComponent(ManagedObject<IComponent>& pMComponent)
	{
		pMComponent->Awake(_pMSelf);
	}
	void Entity::EndComponent(ManagedObject<IComponent>& pMComponent)
	{
		pMComponent->End();
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