#pragma once

template<class T>
class Singleton
{
public:
	 Singleton(const Singleton& otherInstance) = delete;
	 Singleton(Singleton&& oldInstance) noexcept = delete;
	static const T& GetInstance()
	{
		static T instance;
		return instance;
	}
	 Singleton& operator= (const Singleton& otherInstance) = delete;
	 Singleton&& operator= (Singleton&& oldInstance) noexcept = delete;
protected:
	 Singleton() = default;
	virtual ~Singleton() noexcept = default;
};