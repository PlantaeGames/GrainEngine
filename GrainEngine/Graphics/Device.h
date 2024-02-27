#pragma once

#include "WinD3D.h"
#include "Patterns/Singleton.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Patterns;

	class Device : public Singleton<Device>
	{
		friend Singleton;

	public:
		~Device() noexcept = default;

		ComPtr<ID3D11Device> GetDevice() const noexcept
		{
			return _pDevice;
		}

	private:
		Device();

		void Create();

	private:
		ComPtr<ID3D11Device> _pDevice;
	};
}