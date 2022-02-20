#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include "Log.h"
#include <iostream>
#include "Vulkan/VulkFrame.h"


int main() {

    VulkFrame V = VulkFrame();
    //V.initWindow();
    //V.mainLoop();
    set_loglevel(INFO);
    INFO_LOG("HALLO")
    WARNING_LOG("HALLO")
    ERROR_LOG("HALLO")
    return 0;
}