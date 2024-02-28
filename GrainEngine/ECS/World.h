#pragma once

#include <string>

#include "EntityManager.h"
#include "Graphics/Renderer.h"

namespace GrainEngine::ECS
{
	using namespace GrainEngine::Graphics;

	class World
	{
	public:
		World(unsigned int  id, const std::string& name);
		~World() noexcept = default;

		World(const World& otherInstance) = default;
		World(World&& oldInstance) noexcept = default;

		World& operator= (const World& otherInstance) = default;
		World& operator= (World&& oldInstance) noexcept = default;

		bool operator== (const World& world) const noexcept
		{
			return world._id == _id;
		}

		void Tick(TickType tickType);
		void RenderTick(const Renderer& renderer, TickType tickType);

		EntityManager& GetEntityManager() const noexcept
		{
			return _entityManager;
		}

		unsigned int GetId() const noexcept
		{
			return _id;
		}

		const std::string& GetName() const noexcept
		{
			return _name;
		}

		void SetName(const std::string& name) noexcept
		{
			_name = name;
		}

	private:
		unsigned int _id = 0u;
		std::string _name;
		mutable EntityManager _entityManager;
	};
}

