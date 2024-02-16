#pragma once

#include <list>

namespace GrainEngine::ECS
{
	class ManagedObject
	{
	public:
		explicit ManagedObject(unsigned long ptr);
		virtual ~ManagedObject() noexcept = 0;

		ManagedObject(const ManagedObject& otherInstance);
		ManagedObject(ManagedObject&& oldInstance) noexcept;

		ManagedObject& operator= (const ManagedObject& otherInstance);
		ManagedObject& operator= (ManagedObject&& oldInstance) noexcept;

		unsigned long GetPtr() const noexcept;
		unsigned long GetRefCount() const noexcept;

		void Release();
		void Reset();

	private:
		void ClearReference();
		void AddReference(ManagedObject& otherInstance);

		void Swap(ManagedObject& otherInstance);

	private:
		unsigned long _ptr = 0u;

		std::list<ManagedObject> _refObjects;
	};
}