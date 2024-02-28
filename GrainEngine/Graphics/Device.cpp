#include "Device.h"

namespace GrainEngine::Graphics
{
	void Device::Create()
	{
		unsigned int creationFlags = 0u;

#ifdef _DEBUG
		creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
		CHECK_THROW_D3D_ERROR_INFO(
			D3D11CreateDevice(
				nullptr,
				D3D_DRIVER_TYPE_HARDWARE,
				nullptr,
				creationFlags,
				nullptr,
				0,
				D3D11_SDK_VERSION,
				&_pDevice,
				nullptr,
				&_pDeviceContext
			)
		);
	}

	Device::Device()
	{
		Create();
	}
}