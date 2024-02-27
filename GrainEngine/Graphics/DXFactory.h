#pragma once

#include "WinD3D.h"
#include "Patterns/Singleton.h"
#include "Graphics/Errors/D3DGraphicsError.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Patterns;
	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	class DXFactory : public Singleton<DXFactory>
	{
		friend DXFactory;

	public:
		DXFactory() noexcept = default;

		ComPtr<IDXGIFactory> GetFactory() const noexcept
		{
			return _pFactory;
		}

	private:
		DXFactory();

	private:
		ComPtr<IDXGIFactory> _pFactory;
	};
}