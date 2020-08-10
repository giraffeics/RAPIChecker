#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

void testVulkan(uint32_t* major, uint32_t* minor);
void testGL(uint32_t* major, uint32_t* minor);
void testDX(uint32_t* major, uint32_t* minor);