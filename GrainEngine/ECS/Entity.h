#pragma once

#include <memory>
#include <list>
#include <string>

#include "ECS/Components/Transform.h"
#include "ManagedObject.h"
#include "IComponent.h"
#include "Tag.h"

namespace GrainEngine::ECS
{
	using namespace ECS::Components;

	class Entity
	{
	public:
		Entity();
		~Entity() noexcept;

		Entity(const Entity& otherInstance) = default;
		Entity(Entity&& oldInstance) noexcept  = default;

		Entity& operator= (const Entity& otherInstance) = default;
		Entity& operator= (Entity&& oldInstance) noexcept = default;

		template<typename t_T>
		ManagedObject<t_T> GetComponent()
		{
			for (const auto& pCComponent : _pComponents)
			{
				if (dynamic_cast<t_T*>(pCComponent.GetPtr()) == nullptr)
					continue;

				ManagedObject<t_T> pComponent = {};
				pComponent.Hold<IComponent>(pCComponent);

				return pComponent;
			}
		}

		template<typename t_T>
		ManagedObject<t_T> AddComponent()
		{
			_pComponents.push_back(ManagedObject<IComponent>().New<t_T>());
			
			ManagedObject<t_T> pComponent = {};
			pComponent.Hold<IComponent>(_pComponents.back());

			return pComponent;
		}

	private:
		std::list<ManagedObject<IComponent>> _pComponents;

	public:
		std::string name;
		ManagedObject<Transform> transform;
		Tag tag;
	};
}