#pragma once

#include <list>

#include "Patterns/Singleton.h"

namespace GrainEngine::ECS
{
	using namespace Patterns;

	class GarbageCollector : public Singleton<GarbageCollector>
	{
		template<typename _T>
		class SmartObject;

		friend Singleton;

	private:
		class Garbage
		{
		public:
			Garbage();
			~Garbage() noexcept;

			Garbage(const Garbage& otherInstance) = delete;
			Garbage(Garbage&& oldInstance) noexcept = delete;

			Garbage& operator= (const Garbage& otherInstance) = delete;
			Garbage& operator= (Garbage&& oldInstance) noexcept = delete;

		private:
			unsigned long _id = 0u;
			unsigned long _ptr = 0u;

			unsigned long _refCount = 0u;

			std::list<>
		};

	public:
		~GarbageCollector() noexcept;

		GarbageCollector(const GarbageCollector& otherInstance) = delete;
		GarbageCollector(GarbageCollector&& oldInstance) noexcept = delete;

		GarbageCollector& operator= (const GarbageCollector& otherInstance) = delete;
		GarbageCollector& operator= (GarbageCollector&& oldInstance) noexcept = delete;

	private:
		GarbageCollector();

		template<typename T>
		T& New()
		{
			const auto* const object = new T;

			_smartObj

			return *object;
		}

	private:
		std::list<void*> _objects;
	};
}