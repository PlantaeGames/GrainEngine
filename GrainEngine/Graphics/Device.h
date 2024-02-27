#pragma once

#include "WinD3D.h"
#include "Patterns/Singleton.h"
#include "Graphics/Errors/D3DGraphicsError.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Patterns;
	using namespace GrainEngine::Graphics::Errors;

	class Device : public Singleton<Device>
	{
		friend Singleton;

	public:
		~Device() noexcept = default;

		ComPtr<ID3D11Device> GetDevice() const noexcept
		{
			return _pDevice;
		}

		ComPtr<ID3D11DeviceContext> GetDeviceContext() const noexcept
		{
			return _pDeviceContext;
		}

	private:
		Device();

		void Create();

	private:
		ComPtr<ID3D11Device> _pDevice;
		ComPtr<ID3D11DeviceContext> _pDeviceContext;
	};
}