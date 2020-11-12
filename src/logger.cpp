//logger.cpp
//author: Devin Paden
//edited by: Grant Mahoney
//date: 11/11/2020

#include "logger.h"

bool log (std::string msg, std::string programName, std::ofstream& logFile)
{
    //gets the current hostname
    passwd *pws;
    pws = getpwuid(geteuid());

    //gets the process id
    pid_t pid = getpid();

    std::string strTime;

    time_t logTime = time(0);
    strTime = ctime(&logTime);

    int timeSize = strTime.size();

    if(timeSize)
    {
        strTime[timeSize-1] = ' ';
    }

    std::string strProgramName = programName;
    std::string strHostName = pws->pw_name;

    //writes to the logfile
    if(logFile)
    {
        logFile << strTime << strHostName << " " << strProgramName << "[" << pid << "]: " << msg << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}