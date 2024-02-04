#pragma once

#include "Patterns/Singleton.h"

namespace GrainEngine::Graphics
{
	using namespace Patterns;

	class D3DRenderer : Singleton<D3DRenderer>
	{
		friend Singleton;

	public:
		D3DRenderer(const D3DRenderer& otherInstance) = delete;
		D3DRenderer(D3DRenderer&& oldInstance) noexcept = delete;
		D3DRenderer& operator= (const D3DRenderer& otherInstance) = delete;
		D3DRenderer& operator= (D3DRenderer&& oldInstance) noexcept = delete;

	private:
		D3DRenderer();
		~D3DRenderer() noexcept = default;
	};
}

