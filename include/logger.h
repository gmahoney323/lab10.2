//logger.h
//author: Devin Paden
//edited by: Grant Mahoney
//date: 11/11/2020

#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>

//creates a discrete syslog message
bool log (std::string msg, std::string programName, std::ofstream& logFile);

#endif