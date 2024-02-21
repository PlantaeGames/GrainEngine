#pragma once

#include "GarbageCollector.h"
#include "Errors/Error.h"

namespace GrainEngine::ECS
{
#define DEREFERENCE_OF_NULLPTR_ERROR "Dereference of a NULL PTR."
#define INVALID_HOLD_ON_MANAGED_OBJECT "Managed Objects are not compatible."

	using namespace Errors;

	template<typename t_Interface>
	class ManagedObject
	{
		friend GarbageCollector;

	private:
		template<typename t_T>
		void NewGC()
		{
			if (_ptr != 0u)
			{
				TriggerGC();
			}

			_ptr = GarbageCollector::GetInstance().New<t_T>((char*) this);
		}

		void TriggerGC()
		{
			if (_ptr != 0u == false)
				return;

			GarbageCollector::GetInstance().Trigger<t_Interface, ManagedObject<t_Interface>>(_ptr, (char*) this);
		}
		void IncrementGC() const
		{
			if (_ptr != 0u == false)
				return;
			
			GarbageCollector::GetInstance().Increment<t_Interface>(_ptr, (char*) this);
		}
		void ReleaseGC()
		{
			if (_ptr != 0u == false)
				return;

			GarbageCollector::GetInstance().Release<t_Interface, ManagedObject<t_Interface>>(_ptr);
		}

	private:
		char* _ptr = 0u;

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
			_ptr = otherInstance._ptr;

			IncrementGC();
		}

		ManagedObject& operator= (const ManagedObject& otherInstance)
		{
			TriggerGC();

			_ptr = otherInstance._ptr;
			IncrementGC();

			return *this;
		}

		ManagedObject(ManagedObject&& otherInstance) noexcept
		{
			_ptr = otherInstance._ptr;

			IncrementGC();
		}
		ManagedObject& operator= (ManagedObject&& otherInstance) noexcept
		{
			TriggerGC();

			_ptr = otherInstance._ptr;
			IncrementGC();

			return *this;
		}

		template<typename t_T>
		ManagedObject& New()
		{
			NewGC<t_T>();
			return *this;
		}

		ManagedObject& New()
		{
			NewGC<t_Interface>();
			return *this;
		}

		template<typename t_T>
		void Hold(ManagedObject<t_T>& other)
		{
			if (dynamic_cast<t_Interface*>(other._ptr) == nullptr)
				THROW_ERROR(INVALID_HOLD_ON_MANAGED_OBJECT);

			TriggerGC();

			_ptr = other._ptr;

			IncrementGC();
		}

		void Release()
		{
			ReleaseGC();
		}

		t_Interface* GetPtr() const
		{
			if ((_ptr != 0u == false))
				THROW_ERROR(DEREFERENCE_OF_NULLPTR_ERROR);

			return reinterpret_cast<t_Interface*>(_ptr);
		}

		template<typename t_T>
		t_T* GetPtr() const noexcept
		{
			return dynamic_cast<t_T*>(GetPtr());
		}

		t_Interface& operator* ()
		{
			return *GetPtr();
		}
	};
}