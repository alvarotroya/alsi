#include "Vulkan/VulkFrame.h"

VulkFrame::VulkFrame()
{
    VulkFrame(800,600,"VulkFrame");
}

VulkFrame::VulkFrame(unsigned int width, unsigned int height,std::string windowname)
{
    this->windowname = windowname;
    this->height      = height;
    this->width       = width;
}


VulkFrame::~VulkFrame()
{
	this->cleanup();

}


void VulkFrame::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    this->window = glfwCreateWindow(this->width, this->height, this->windowname.c_str() , nullptr, nullptr);
}


void VulkFrame::mainLoop()
{
    /*
	while(!glfwWindowShouldClose(window)) {
        std::cout<<"MAINLOOP"<<std::endl;
        glfwPollEvents();
    }
    */

}


void VulkFrame::cleanup()
{
	glfwDestroyWindow(this->window);
    glfwTerminate();
}