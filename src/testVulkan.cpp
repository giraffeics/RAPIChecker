#include "tests.h"

#ifdef _WIN32
	#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#include <GLFW/glfw3native.h>
#include <vulkan/vulkan.h>

void testVulkan(uint32_t* major, uint32_t* minor)
{
	*major = 0;
	*minor = 0;

	/*** ATTEMPT TO CREATE INSTANCE ***/

	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Graphics API Support Test";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	createInfo.enabledLayerCount = 0;

	VkInstance instance;

	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

	// COULD NOT CREATE VULKAN INSTANCE; VULKAN NOT SUPPORTED
	if (result != VK_SUCCESS)
	{
		return;
	}

	/*** QUERY FOR API SUPPORT FROM DEVICES ***/
	uint32_t numPhysicalDevices = 0;
	vkEnumeratePhysicalDevices(instance, &numPhysicalDevices, nullptr);
	VkPhysicalDevice* devices = new VkPhysicalDevice[numPhysicalDevices];
	vkEnumeratePhysicalDevices(instance, &numPhysicalDevices, devices);

	for (uint32_t i = 0; i < numPhysicalDevices; i++)
	{
		VkPhysicalDeviceProperties properties;
		vkGetPhysicalDeviceProperties(devices[i], &properties);

		*major = VK_VERSION_MAJOR(properties.apiVersion);
		*minor = VK_VERSION_MINOR(properties.apiVersion);
	}
	
	/*** CLEANUP ***/
	vkDestroyInstance(instance, nullptr);
	delete[] devices;
}