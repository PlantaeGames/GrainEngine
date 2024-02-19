#pragma once

#include "GarbageCollector.h"
#include "Structures/Pair.h"
#include "RefPtr.h"
#include "Errors/Error.h"

namespace GrainEngine::ECS
{
#define DEREFERENCE_OF_NULLPTR_ERROR "Dereference of a NULL PTR."

	using namespace Errors;

	template<typename t_Interface>
	class ManagedObject
	{
		friend GarbageCollector;

	public:
		ManagedObject() :
			_ptr(0u)
		{}

		~ManagedObject() noexcept
		{
			TriggerGC();
		}

		ManagedObject(const ManagedObject& otherInstance)
		{
			IncrementGC();
		}

		ManagedObject& operator= (const ManagedObject& otherInstance)
		{
			TriggerGC();
			IncrementGC();

			return *this;
		}

		ManagedObject(ManagedObject&& oldInstance) noexcept = delete;
		ManagedObject& operator= (ManagedObject&& oldInstance) noexcept = delete;

		template<typename t_T>
		void New()
		{
			NewGC<t_T>();
		}

		void Release()
		{
			ReleaseGC();
		}

		t_Interface* GetPtr() const noexcept
		{
			if (CheckValid() == false)
				THROW_ERROR(DEREFERENCE_OF_NULLPTR_ERROR);

			return reinterpret_cast<t_T*>(_ptr);
		}

		template<typename t_T>
		t_T* GetPtr() const noexcept
		{
			return dynamic_cast<t_T*>(GetPtr());
		}

		t_Interface* operator* ()
		{
			return GetPtr();
		}

		bool CheckValid()
		{
			return _ptr != 0u;
		}

	private:
		template<typename t_T>
		void NewGC()
		{
			if (CheckValid())
			{
				TriggerGC();
			}

			_ptr(GarbageCollector::GetInstance.New<t_T>((unsigned long long) this));
		}
		void TriggerGC()
		{
			if (CheckValid() == false) return;

			GarbageCollector::GetInstance().Trigger<t_T>(_ptr, (unsigned long long) this);
		}
		void IncrementGC() const
		{
			if (CheckValid() == false) return;

			_ptr = otherInstance._ptr;
			GarbageCollector::GetInstance().AddReference<t_T>(_ptr, (unsigned long long) this);
		}
		void ReleaseGC()
		{
			if (CheckValid() == false) return;

			GarbageCollector::GetInstance().Release(_ptr);
		}

	private:
		unsigned long long _ptr = 0u;
	};
}