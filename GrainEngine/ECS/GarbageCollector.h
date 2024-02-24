#pragma once

#include <list>
#include <utility>

#include "Patterns/Singleton.h"

namespace GrainEngine::ECS
{
	using namespace Patterns;

	class GarbageCollector : public Singleton<GarbageCollector>
	{
		friend Singleton;

	private:
		std::list<std::pair<char*, std::pair<char*, unsigned long>>> _objects;
		std::list<std::pair<char*, std::list<char*>>> _references;

	private:
		GarbageCollector() = default;

		template<typename t_T>
		void RemoveReferences(char* id)
		{
			for (auto& reference : _references)
			{
				if (reference.first != id) continue;

				for (auto& referer : reference.second)
				{
					reinterpret_cast<t_T*>(referer)->_ptr = 0u;
				}

				_references.remove(reference);

				break;
			}
		}

	public:
		~GarbageCollector() noexcept = default;

		GarbageCollector(const GarbageCollector& otherInstance) = delete;
		GarbageCollector(GarbageCollector&& oldInstance) noexcept = delete;

		GarbageCollector& operator= (const GarbageCollector& otherInstance) = delete;
		GarbageCollector& operator= (GarbageCollector&& oldInstance) noexcept = delete;

		unsigned long long GetManagedObjectsCount() const noexcept
		{
			return (unsigned long long) _objects.size();
		}

		template<typename t_T>
		char* New(char* ref)
		{
			const auto* pObject = new t_T();

			auto object = std::pair<char*, std::pair<char*, unsigned long>>();
			object.first = (char*) (pObject);
			object.second = std::pair<char*, unsigned long>(ref, 1u);

			_objects.push_back(std::move(object));

			auto reference = std::pair<char*, std::list<char*>>(
				(char*) pObject,
				std::list<char*>()
			);
			reference.second.push_back(ref);

			_references.push_back(std::move(reference));

			return (char*) pObject;
		}

		template<typename t_T>
		unsigned long Increment(char* id, char* ref)
		{
			for (auto& object : _objects)
			{
				if (object.first != id) continue;

				++object.second.second;

				break;
			}

			for (auto& reference : _references)
			{
				if (reference.first != id) continue;

				reference.second.push_back(ref);

				return (unsigned long) reference.second.size();

				break;
			}

			return 0u;
		}

		template<typename t_T, typename t_Wrapper>
		void Release(char* id)
		{
			for (auto& object : _objects)
			{
				if (object.first != id) continue;

				// remove danglers
				RemoveReferences<t_Wrapper>(id);

				// release
				delete reinterpret_cast<t_T*>(id);
				// clearing from list
				_objects.remove(object);
				
				break;
			}
		}

		template<typename t_T, typename t_Wrapper>
		void Trigger(char* id, char* ref)
		{
			for (auto& object : _objects)
			{
				if (object.first != id) continue;

				if (object.second.second == 0)
				{
					// remove danglers
					RemoveReferences<t_Wrapper>(id);

					// release
					delete reinterpret_cast<t_T*>(id);
					// clearing from list
					_objects.remove(object);
				}
				else
				{
					--object.second.second;

					for (auto& reference : _references)
					{
						if (reference.first != id) continue;

						for (auto referer : reference.second)
						{
							if (referer != ref) continue;

							reference.second.remove(ref);

							break;
						}

						break;
					}
				}

				break;
			}
		}
	};
}