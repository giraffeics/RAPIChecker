#include <iostream>
#include "tests.h"

int main()
{
    uint32_t major, minor;

    /*** TEST FOR VULKAN SUPPORT ***/
    testVulkan(&major, &minor);
    std::cout << "Vulkan version: ";
    if(major != 0)
        std::cout << major << "." << minor << std::endl;
    else
        std::cout << "(not supported)" << std::endl;

    /*** TEST FOR OPENGL SUPPORT ***/
    testGL(&major, &minor);
    std::cout << "OpenGL version: ";
    if (major != 0)
        std::cout << major << "." << minor << std::endl;
    else
        std::cout << "(not supported)" << std::endl;

    /*** TEST FOR DIRECT32 SUPPORT ***/
    testDX(&major, &minor);
    std::cout << "Direct3D version: ";
    if (major != 0)
        std::cout << major << "." << minor << std::endl;
    else
        std::cout << "(not supported)" << std::endl;

    /*** TELL USER TO SUBMIT THESE RESULTS ***/
    char input;
    std::cout << "Enter these results into the survey and then close this window." << std::endl;
    std::cin >> input;  // don't close until something has been entered

    return 0;
}
