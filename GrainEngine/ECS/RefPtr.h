#pragma once

template<typename T> 
class RefPtr
{
public:
	explicit RefPtr(const T* const ptr)
	{
		_ptr = ptr;
	}
	~RefPtr() {}

	RefPtr(const RefPtr<T>& otherInstance) = delete;
	explicit RefPtr(RefPtr<T>&& oldInstance) noexcept
	{
		Swap(oldInstance);
	}

	RefPtr<T>& operator= (const RefPtr<T>& otherInstance) = delete;
	RefPtr<T>& operator= (RefPtr<T>&& oldInstance) noexcept
	{
		_ptr = nullptr;

		Swap(oldInstance);
	}

	T& operator* () 
	{
		return *_ptr;
	}

	T& operator-> ()
	{
		return *_ptr;
	}

	T* Get()
	{
		return _ptr;
	}

private:
	void Swap(RefPtr<T>& otherInstance)
	{
		auto temp = _ptr;
		_ptr = otherInstance._ptr;

		otherInstance->_ptr = temp;
	}

private:
	T* _ptr = nullptr;
};