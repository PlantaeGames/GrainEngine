#pragma once

namespace GrainEngine::Misc
{
	template<typename t_T>
	class RefPtr
	{
	public:
		RefPtr() :
			_ptr(nullptr)
		{}

		RefPtr(t_T* ptr)
		{
			_ptr = ptr;
		}
		RefPtr(t_T& object)
		{
			_ptr = &object;
		}
		~RefPtr() noexcept = default;

		RefPtr(const RefPtr& otherInstance)
		{
			_ptr = otherInstance._ptr;
		}
		RefPtr(RefPtr&& oldInstance) noexcept
		{
			Swap(oldInstance);
		}

		RefPtr<t_T>& operator= (const RefPtr& otherInstance)
		{
			Swap(RefPtr<t_T>(otherInstance));
			return *this;
		}
		RefPtr<t_T>& operator= (RefPtr&& oldInstance) noexcept
		{
			Swap(oldInstance);
			return *this;
		}

		RefPtr<t_T>& operator= (const t_T* ptr)
		{
			_ptr = ptr;
			return *this;
		}

		t_T& operator* ()
		{
			return *Get();
		}

		t_T* operator-> ()
		{
			return Get();
		}

		t_T* Get()
		{
			return _ptr;
		}

	private:
		void Swap(RefPtr<t_T>& otherInstance)
		{
			std::swap(_ptr, otherInstance._ptr);
		}

	private:
		t_T* _ptr = nullptr;
	};
}