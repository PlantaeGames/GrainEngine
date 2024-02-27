#pragma once

#include <vector>
#include <string>

#include "ECS/Components/Transform.h"
#include "ManagedObject.h"
#include "IComponent.h"
#include "TickType.h"
#include "Tag.h"
#include "ECS/Errors/ComponentNotFoundError.h"

namespace GrainEngine::ECS
{
#define COMPONENT_NOT_FOUND_ERROR_MESSAGE "Component Not Found."

	using namespace Components;
	using namespace Errors;

	class Entity
	{
	public:
		Entity();
		~Entity() noexcept;

		Entity(const Entity& otherInstance) = default;
		Entity(Entity&& oldInstance) noexcept  = default;

		Entity& operator= (const Entity& otherInstance) = default;
		Entity& operator= (Entity&& oldInstance) noexcept = default;

		bool operator== (const Entity& entity) const noexcept
		{
			return entity._id == _id;
		}

		template<typename t_T>
		ManagedObject<t_T> GetComponent()
		{
			for (auto& pMCComponent : _pMComponents)
			{
				if (dynamic_cast<t_T*>(pMCComponent.GetPtr()) == nullptr)
					continue;

				return ManagedObject<t_T>().Hold<IComponent>(pMCComponent);
			}

			THROW_COMPONENT_NOT_FOUND_ERROR(COMPONENT_NOT_FOUND_ERROR_MESSAGE);
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

		template<typename t_T>
		void RemoveComponent()
		{
			for (auto current = _pMComponents.begin(); current != _pMComponents.end(); ++current)
			{
				if (dynamic_cast<t_T*>(current->GetPtr()) == nullptr)
					continue;

				_pMComponents.erase(current);

				return;
			}

			THROW_COMPONENT_NOT_FOUND_ERROR(COMPONENT_NOT_FOUND_ERROR_MESSAGE);
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
		unsigned long long _id = 0u;
		std::vector<ManagedObject<IComponent>> _pMComponents;
	};
}