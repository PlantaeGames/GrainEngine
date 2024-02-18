#pragma once

#include "GarbageCollector.h"
#include "Structures/Pair.h"
#include "RefPtr.h"
#include "Errors/Error.h"

namespace GrainEngine::ECS
{
#define DEREFERENCE_OF_NULLPTR_ERROR "Dereference of a NULL PTR."

	using namespace Errors;

	template<typename t_T>
	class ManagedObject
	{
		friend GarbageCollector;

	public:
		ManagedObject() :
			_ptr(GarbageCollector::GetInstance.New<t_T>((unsigned long long) this))
		{}

		~ManagedObject() noexcept
		{
			GarbageCollector::GetInstance().Trigger<t_T>(_ptr, (unsigned long long) this);
		}

		ManagedObject(const ManagedObject& otherInstance)
		{
			_ptr = otherInstance._ptr;
			GarbageCollector::GetInstance().AddReference<t_T>(_ptr, (unsigned long long) this);
		}

		ManagedObject& operator= (const ManagedObject& otherInstance)
		{
			_ptr = otherInstance._ptr;
			GarbageCollector::GetInstance().AddReference<t_T>(_ptr, (unsigned long long) this);

			return *this;
		}

		ManagedObject(ManagedObject&& oldInstance) noexcept = delete;
		ManagedObject& operator= (ManagedObject&& oldInstance) noexcept = delete;

		t_T* GetPtr() const noexcept
		{
			if (_ptr == 0u)
				THROW_ERROR(DEREFERENCE_OF_NULLPTR_ERROR);

			return reinterpret_cast<t_T*>(_ptr);
		}

		template<typename t_Interface>
		t_Interface* GetPtr() const noexcept
		{
			if (_ptr == 0u)
				THROW_ERROR(DEREFERENCE_OF_NULLPTR_ERROR);

			return reinterpret_cast<t_Interface*>(_ptr);
		}

	private:
		void Swap(ManagedObject& otherInstance)
		{
			std::swap(_ptr, otherInstance._ptr);
		}

	private:
		unsigned long long _ptr = 0u;
	};
}