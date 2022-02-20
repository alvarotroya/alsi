#ifndef VULKFRAME_H
#define VULKFRAME_H
#include "MainFrame.h"
#include "Defines.h"
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <string>


class VulkFrame : public virtual MainFrame 
{

/*------------------------------------------------
-
- VulkFrame is used to represent a Window based on
- Vulkan api.
- This class inherits from MainFrame 
- 
------------------------------------------------*/

public:
	VulkFrame();
	VulkFrame(unsigned int, unsigned int ,std::string );
	~VulkFrame();

	void cleanup();
	void initWindow();
	void mainLoop();
private:
	GLFWwindow* window;
};

#endif