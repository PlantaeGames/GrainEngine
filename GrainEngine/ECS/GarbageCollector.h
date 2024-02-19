#pragma once

#include <list>

#include "Patterns/Singleton.h"
#include "Structures/Pair.h"

namespace GrainEngine::ECS
{
	using namespace Patterns;

	class GarbageCollector : public Singleton<GarbageCollector>
	{
		friend Singleton;
	public:
		~GarbageCollector() noexcept = default;

		GarbageCollector(const GarbageCollector& otherInstance) = delete;
		GarbageCollector(GarbageCollector&& oldInstance) noexcept = delete;

		GarbageCollector& operator= (const GarbageCollector& otherInstance) = delete;
		GarbageCollector& operator= (GarbageCollector&& oldInstance) noexcept = delete;

		template<typename t_T>
		unsigned long long New(unsigned long long ref)
		{
			const auto* const pObject = new t_T();

			const auto object = Pair<unsigned long long, Pair<unsigned long long, unsigned long long>>(
				(unsigned long long) pObject,
				Pair<unsigned long long, unsigned long long>((unsigned long long) pObject), 1u)
			);

			_objects.push_back(std::move(object));

			auto reference = Pair<unsigned long long, std::list<unsigned long long>>(
				(unsigned long long) pObject,
				std::list<unsigned long long>()
			);
			reference.y.push_back(ref);

			_references.push_back(std::move(reference));

			return (unsigned long long) pObject;
		}

		template<typename t_T>
		unsigned long long AddReference(unsigned long long id, unsigned long long ref)
		{
			for (auto& object : _objects)
			{
				if (object.x != id) continue;

				++object.y.y;

				break;
			}

			for (auto& reference : _references)
			{
				if (reference.x != id) continue;

				reference.y.push_back(ref);

				break;
			}
		}

		template<typename t_T>
		void Release(unsigned long long id)
		{
			for (auto& object : _objects)
			{
				if (object.x != id) continue;

				// remove danglers
				RemoveReferences<t_T>(id);

				// release
				delete reinterpret_cast<t_T*>(id);
				// clearing from list
				_objects.remove(object);
				
				break;
			}
		}

		template<typename t_T>
		void Trigger(unsigned long long id, unsigned long long ref)
		{
			for (auto& object : _objects)
			{
				if (object.x != id) continue;

				if (object.y.y == 0)
				{
					// remove danglers
					RemoveReferences<t_T>(id);

					// release
					delete reinterpret_cast<t_T*>(id);
					// clearing from list
					_objects.remove(object);
				}
				else
				{
					--object.y.y;

					for (auto& reference : _references)
					{
						if (reference != id) continue;

						for (auto referer : reference.y)
						{
							if (referer != ref) continue;

							reference.y.remove(ref);

							break;
						}

						break;
					}
				}

				break;
			}
		}

	private:
		GarbageCollector() = default;

		template<typename t_T>
		void RemoveReferences(unsigned long long id)
		{
			for (auto& reference : _references)
			{
				if (reference.x != id) continue;

				for (auto& referer : reference.y)
				{
					reinterpret_cast<t_T*>(referer)->_ptr = 0u;
				}

				_references.remove(reference);

				break;
			}
		}

	private:
		std::list<Pair<unsigned long long, Pair<unsigned long long, unsigned long long>>> _objects;
		std::list<Pair<unsigned long long, std::list<unsigned long long>>> _references;
	};
}