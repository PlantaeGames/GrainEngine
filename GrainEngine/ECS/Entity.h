#pragma once

#include <vector>
#include <string>

#include "ECS/Components/Transform.h"
#include "ManagedObject.h"
#include "IComponent.h"
#include "TickType.h"
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
			for (auto& pMCComponent : _pMComponents)
			{
				if (dynamic_cast<t_T*>(pMCComponent.GetPtr()) == nullptr)
					continue;

				return ManagedObject<t_T>().Hold<IComponent>(pMCComponent);
			}
		}

		template<typename t_T>
		std::vector<ManagedObject<t_T>> GetComponents()
		{
			std::vector<ManagedObject<t_T>> pMComponents = { };

			for (auto& pMCComponent : _pMComponents)
			{
				if (dynamic_cast<t_T*>(pMCComponent.GetPtr()) == nullptr)
					continue;

				pMComponents.push_back(ManagedObject<t_T>().Hold<IComponent>(pMCComponent));
			}

			return pMComponents;
		}

		template<typename t_T>
		ManagedObject<t_T> AddComponent()
		{
			_pMComponents.push_back(ManagedObject<IComponent>().New<t_T>());
			
			ManagedObject<t_T> pMComponent = {};
			pMComponent.Hold<IComponent>(_pMComponents.back());

			return pMComponent;
		}

		void Tick(ManagedObject<Entity>& pMEntity, TickType tickType);

	private:
		void AwakeTick(ManagedObject<Entity>& pMEntity);
		void StartTick(ManagedObject<Entity>& pMEntity);
		void UpdateTick(ManagedObject<Entity>& pMEntity);
		void EndTick(ManagedObject<Entity>& pMEntity);

	public:
		std::string name;
		Tag tag;
		ManagedObject<Transform> pMTransform;

	private:
		std::vector<ManagedObject<IComponent>> _pMComponents;
	};
}