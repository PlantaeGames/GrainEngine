#pragma once

#include "ManagedObject.h"
#include "Graphics/Renderer.h"

namespace GrainEngine::ECS
{
	using namespace GrainEngine::Graphics;

	class Entity;

	class IComponent
	{
	public:
		virtual ~IComponent() noexcept = default;

		IComponent(const IComponent& otherInstance) = default;
		IComponent(IComponent&& oldInstance) noexcept = default;

		IComponent& operator= (const IComponent& otherInstance) = default;
		IComponent& operator= (IComponent&& oldInstance) noexcept = default;

		bool operator== (const IComponent& rhs) const noexcept
		{
			return rhs._id == _id;
		}

		virtual void Awake(ManagedObject<Entity>& pMEntity) {}
		virtual void Start(ManagedObject<Entity>& pMEntity) {}
		virtual void Update(ManagedObject<Entity>& pMEntity) {}
		virtual void PreRender(const Renderer& renderer) {}
		virtual void PostRender(const Renderer& renderer) {}
		virtual void End(ManagedObject<Entity>& pMEntity) {}

	protected:
		IComponent()
		{
			_id = (unsigned long long)this;
		};

	protected:
		unsigned long long _id = 0u;
	};
}