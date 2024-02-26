#pragma once

#undef GetMessage

#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>

#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "dxgi.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "d3dcompiler.lib")

#ifdef _DEBUG
#include <dxgidebug.h>
#endif

#include "wrl/client.h"