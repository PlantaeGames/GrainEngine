#include "ManagedObject.h"

namespace GrainEngine::ECS
{

	ManagedObject::ManagedObject(unsigned long ptr):
		_refObjects()
	{
		_ptr = ptr;
	}

	void ManagedObject::Release()
	{

	}

	void ManagedObject::Reset()
	{
		ClearReference();
		_ptr = 0u;
		_refObjects.clear();
	}

	void ManagedObject::ClearReference()
	{

	}

	void ManagedObject::AddReference(ManagedObject& otherInstance)
	{

	}

	ManagedObject::ManagedObject(const ManagedObject& otherInstance)
	{
		_ptr = otherInstance._ptr;

	}

	ManagedObject::ManagedObject(ManagedObject&& oldInstance) noexcept
	{
		Swap(oldInstance);
	}

	ManagedObject& ManagedObject::operator= (const ManagedObject& otherInstance)
	{

	}

	ManagedObject& ManagedObject::operator= (ManagedObject&& oldInstance) noexcept
	{
		return *this = 
	}

	void ManagedObject::Swap(ManagedObject& otherInstance)
	{
		std::swap(_ptr, otherInstance._ptr);
		_refObjects.swap(otherInstance._refObjects);
	}

	unsigned long ManagedObject::GetPtr() const noexcept
	{
		return _ptr;
	}

	unsigned long ManagedObject::GetRefCount() const noexcept
	{
		return _refObjects.size();
	}


	ManagedObject::~ManagedObject() noexcept
	{
		
	}

}