#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H
#include <string>

class MainFrame
{

/*------------------------------------------------
-
- MainFrame is used as base class 
- 
------------------------------------------------*/

public:
	MainFrame();
	~MainFrame();

	virtual void cleanup() = 0;
	virtual void initWindow() = 0;
	virtual void mainLoop() = 0;

protected:

	unsigned int width;
	unsigned int height;
	std::string windowname;

private:
};



#endif
