#pragma once

#include <list>

#include "ManagedObject.h"

namespace GrainEngine::ECS
{
	class SmartObject : ManagedObject
	{
		SmartObject();
		~SmartObject() noexcept override;

		SmartObject(const SmartObject& otherInstance) = delete;
		SmartObject(SmartObject&& oldInstance) noexcept = delete;

		SmartObject& operator= (const SmartObject& otherInstance) = delete;
		SmartObject& operator= (SmartObject&& oldInstance) noexcept = delete;
	};
}