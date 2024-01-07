#pragma once

namespace GrainEngine::Patterns
{
	template<typename T>
	class Singleton
	{
	public:
		Singleton(const Singleton& otherInstance) = delete;
		Singleton(Singleton&& oldInstance) noexcept = delete;
		Singleton& operator= (const Singleton& otherInstance) = delete;
		Singleton&& operator= (Singleton&& oldInstance) noexcept = delete;

		static const T& GetInstance()
		{
			static T instance;
			return instance;
		}
	protected:
		Singleton() = default;
		virtual ~Singleton() noexcept = default;
	};
}