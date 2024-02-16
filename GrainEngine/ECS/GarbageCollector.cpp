#include "GarbageCollector.h"

#include "SmartObject.h"

namespace GrainEngine::ECS
{
	GarbageCollector::GarbageCollector() :
		_objects()
	{

	}

	GarbageCollector::~GarbageCollector() noexcept
	{
		// clean all smart objects
	}

	GarbageCollector::Garbage::Garbage()
	{
		
	}

}