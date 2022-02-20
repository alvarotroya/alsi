#ifndef LOG_H
#define LOG_H 
#include "Defines.h"
#include <iostream>
#include <fstream>

#define FILEPATH "alsi.log"

void message2file(std::string);
void message2cout(std::string);
/*-------------------------------------
-- Some colors                       --
---------------------------------------*/
#define WHITE_COLOR    "\033[37m"
#define WARNING_COLOR  "\033[35m"
#define INFO_COLOR     "\033[34m"
#define ERROR_COLOR    "\033[31m"
#define RESET_COLOR    "\033[0m"


#define NONE    -1
#define INFO    1
#define WARNING 2
#define ERROR   3

#define INFO_MSG    "[INFO   ] "
#define WARNING_MSG "[WARNING] "
#define ERROR_MSG   "[ERROR  ] "

#define ABORT   FALSE
#define LM_DEFAULT 0
#define LM_FILE    1
#define LM_CONSOLE 2



static uint8_t loglevel = INFO;


/*-------------------------------------
--   LM_DEFAULT = file + console     --
--   LM_FILE    = file               --
--   LM_CONSOLE = console            --
---------------------------------------*/
static uint8_t logmode  = LM_DEFAULT; 


/*-------------------------------------
--   some log macros                 --
---------------------------------------*/
#ifdef DEBUG
#define INFO_LOG(MESSAGE)    LOG(INFO,MESSAGE)
#define WARNING_LOG(MESSAGE) LOG(WARNING,MESSAGE)
#define ERROR_LOG(MESSAGE)   LOG(ERROR,MESSAGE)
#define LOG(LOGLVL,MESSAGE) compilelogmsg(LOGLVL,MESSAGE,__FILE__,__LINE__);
#else
#define INFO_LOG(MESSAGE)    LOG(INFO,MESSAGE)
#define WARNING_LOG(MESSAGE) LOG(WARNING,MESSAGE)
#define ERROR_LOG(MESSAGE)   LOG(ERROR,MESSAGE)
#define LOG(LOGLVL,MESSAGE);
#endif

void compilelogmsg(uint8_t LOGLVL,std::string MESSAGE, std::string file,int line)
{
	if(LOGLVL < loglevel) return;
	std::string outputmsg;
	std::string errortype;
	std::string color;
	switch (LOGLVL)
	{
		case INFO:    
			errortype = INFO_MSG;
			color     = INFO_COLOR;
			break;
		case WARNING: 
			errortype = WARNING_MSG;
			color     = WARNING_COLOR;
			break;
		case ERROR:    
			errortype = ERROR_MSG;
			color     = ERROR_COLOR;
			break;
		default:
			return;
	}

	outputmsg += file;
	outputmsg += ":";
	outputmsg += std::to_string(line);
	outputmsg +=  "  ";
	outputmsg += MESSAGE;
	message2cout(color+errortype+RESET_COLOR+ outputmsg);
	message2file(errortype+outputmsg);

}


void set_loglevel(uint8_t lvl)
{
	loglevel = lvl;
}


void message2file(std::string message)
{
	static std::ofstream logfile;
	logfile.open(FILEPATH,std::ios_base::app);
	logfile<<message<<"\n";
	logfile.close();

} 


void message2cout(std::string message)
{
	std::cout<<message<<std::endl;
}


#endif