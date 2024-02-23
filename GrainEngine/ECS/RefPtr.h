#pragma once

namespace GrainEngine::ECS
{
	template<typename T>
	class RefPtr
	{
	public:
		explicit RefPtr() :
			_ptr(nullptr)
		{}

		explicit RefPtr(const T* const ptr)
		{
			_ptr = ptr;
		}
		explicit RefPtr(T& object)
		{
			_ptr = &object;
		}
		~RefPtr() noexcept = default;

		RefPtr(const RefPtr<T>& otherInstance) = delete;
		explicit RefPtr(RefPtr<T>&& oldInstance) noexcept
		{
			Swap(oldInstance);
		}

		RefPtr<T>& operator= (const RefPtr<T>& otherInstance) = delete;
		RefPtr<T>& operator= (RefPtr<T>&& oldInstance) noexcept
		{
			Swap(oldInstance);
			return *this;
		}

		T& operator* ()
		{
			return *Get();
		}

		T* operator-> ()
		{
			return Get();
		}

		T* Get()
		{
			return _ptr;
		}

	private:
		void Swap(RefPtr<T>& otherInstance)
		{
			std::swap(_ptr, otherInstance._ptr);
		}

	private:
		T* _ptr = nullptr;
	};
}