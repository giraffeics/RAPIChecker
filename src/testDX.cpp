#include "tests.h"
#ifdef CHECK_D3D

#include <d3d12.h>

void testDX(uint32_t* major, uint32_t* minor)
{
	*major = 0;
	*minor = 0;
}

#else
void testDX(uint32_t* major, uint32_t* minor)
{
	*major = 0;
	*minor = 0;
}
#endif