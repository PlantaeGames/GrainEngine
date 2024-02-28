#include "World.h"

namespace GrainEngine::ECS
{
	World::World(unsigned int id, const std::string& name) :
		_id(id),
		_name(name),
		_entityManager()
	{}

	void World::Tick(TickType tickType)
	{
		_entityManager.Tick(tickType);
	}

	void World::RenderTick(const Renderer& renderer, TickType tickType)
	{
		_entityManager.RenderTick(renderer, tickType);
	}
}