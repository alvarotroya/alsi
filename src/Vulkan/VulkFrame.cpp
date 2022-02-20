#include "Vulkan/VulkFrame.h"

VulkFrame::VulkFrame()
{
    this->windowname  = "VulkFrame";
    this->height      = 600;
    this->width       = 800;
}

VulkFrame::VulkFrame(unsigned int width, unsigned int height,std::string windowname)
{
    this->windowname  
    = windowname;
    this->height      = height;
    this->width       = width;

}


VulkFrame::~VulkFrame()
{
	this->cleanup();
    

}


void VulkFrame::initWindow()
{
    if(this->height > MAX_HEIGHT || this->width > MAX_WIDTH)
    {
        std::cerr<<"Resolution Error: MAX_HEIGHT "<<MAX_HEIGHT<<" MAX_WIDTH "<<MAX_WIDTH<<" ("<<this->height<<","<<this->width<<")"<<std::endl;
        exit(-1);
    }
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    this->window = glfwCreateWindow(this->width, this->height, this->windowname.c_str() , nullptr, nullptr);
}


void VulkFrame::mainLoop()
{
    
	while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
    

}


void VulkFrame::cleanup()
{
	glfwDestroyWindow(this->window);
    glfwTerminate();
}