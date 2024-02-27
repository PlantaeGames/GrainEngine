#include "DXFactory.h"

namespace GrainEngine::Graphics
{
	DXFactory::DXFactory()
	{
		CHECK_THROW_D3D_ERROR_INFO(
			CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&_pFactory);
		);
	}
}