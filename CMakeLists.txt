cmake_minimum_required(VERSION 3.8)

project("RAPISurvey")

# ADD PROJECT SOURCES
add_executable("${PROJECT_NAME}" "src/main.cpp")

file(GLOB_RECURSE SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "src/main.cpp")
target_sources("${PROJECT_NAME}" PRIVATE "${SOURCES}")

set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 17)
set_property(TARGET "${PROJECT_NAME}" PROPERTY C_STANDARD 17)

# SET UP VULKAN LIBRARY
include_directories("$ENV{VULKAN_SDK}/Include")

# SET UP DIRECT3D LIBRARIES
if(WIN32)
	target_link_libraries("${PROJECT_NAME}" d3d12.lib)
	target_link_libraries("${PROJECT_NAME}" d3d11.lib)
	target_link_libraries("${PROJECT_NAME}" dxgi.lib)
	add_compile_definitions("CHECK_D3D")
endif()

# SET UP OPENGL LIBRARY
find_package(OpenGL)
target_link_libraries("${PROJECT_NAME}" opengl32)

# SET UP GLFW LIBRARY
add_subdirectory("glfw")
include_directories("glfw/include")
target_link_libraries("${PROJECT_NAME}" glfw ${GLFW_LIBRARIES})
