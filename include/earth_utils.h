//earth_utils.h
//author: Devin Paden
//edited by: Grant Mahoney
//date: 11/11/2020

#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H

#include <string>
#include <fstream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>

const std::string KMLHEADER1 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
const std::string KMLHEADER2 = "<kml xmlns=\"http://www.opengis.net/kml/2.2\">";
const std::string KMLFOOTER = "</kml>";
const std::string KMLDOCSTART = "<Document>";
const std::string KMLDOCEND = "</Document>";

//processes the given CSV file into their respective values
int processCSV(std::ifstream& inFile, std::string kmlFileName);

//writes an kml placemark for each country in the CSV file
void WritePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude);

#endif