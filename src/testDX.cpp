#include "tests.h"
#ifdef CHECK_D3D

#include <dxgi.h>
#include <d3d10_1.h>
#include <d3d11.h>
#include <d3d12.h>

#include <iostream>

void testDX(uint32_t* major, uint32_t* minor)
{
	*major = 0;
	*minor = 0;

	// Check for API support
	D3D_FEATURE_LEVEL featureLevels[] = {
		D3D_FEATURE_LEVEL_12_1,
		D3D_FEATURE_LEVEL_12_0,
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1,
	};

	D3D_FEATURE_LEVEL featureLevel;
	ID3D11Device* device;

	HRESULT result = D3D11CreateDevice(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		featureLevels,
		sizeof(featureLevels)/sizeof(D3D_FEATURE_LEVEL),
		D3D11_SDK_VERSION,
		&device,
		&featureLevel,
		nullptr
	);

	switch (featureLevel)
	{
	case D3D_FEATURE_LEVEL_12_1:
		*major = 12;
		*minor = 1;
		break;
	case D3D_FEATURE_LEVEL_12_0:
		*major = 12;
		*minor = 0;
		break;
	case D3D_FEATURE_LEVEL_11_1:
		*major = 11;
		*minor = 1;
		break;
	case D3D_FEATURE_LEVEL_11_0:
		*major = 11;
		*minor = 0;
		break;
	case D3D_FEATURE_LEVEL_9_3:
		*major = 9;
		*minor = 3;
		break;
	case D3D_FEATURE_LEVEL_9_2:
		*major = 9;
		*minor = 2;
		break;
	case D3D_FEATURE_LEVEL_9_1:
		*major = 9;
		*minor = 1;
		break;
	}

	// Cleanup
	if (device)
		device->Release();
}

#else
void testDX(uint32_t* major, uint32_t* minor)
{
	*major = 0;
	*minor = 0;
}
#endif