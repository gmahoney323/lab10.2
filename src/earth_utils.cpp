//earth_utils.cpp
//author: Devin Paden
//edited by: Grant Mahoney
//date: 11/11/2020

#include "earth_utils.h"
#include <iostream>
#include <sstream>

int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong;
    std::string strLine;
    int recordCount{};

    if(inFile)
    {

        std::ofstream flog;
        flog.open(kmlFileName, std::ios_base::out);

        flog << KMLHEADER1 << std::endl;
        flog << KMLHEADER2 << std::endl;
        flog << KMLDOCSTART << std::endl;

        getline(inFile, strLine);

        while(getline(inFile, strLine))
        {
            std::stringstream s_stream(strLine);
            std::getline(s_stream, strCountry, ',');
            std::getline(s_stream, strCapital, ',');
            std::getline(s_stream, strLat, ',');
            std::getline(s_stream, strLong, ',');

            std::string fullName = strCapital + ", " + strCountry;
            WritePlacemark(flog, fullName, strLat, strLong);
            recordCount++;
        }
        flog << KMLDOCEND << std::endl;
        flog << KMLFOOTER << std::endl;
        flog.close();
    }
    return recordCount;
}

void WritePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude)
{
    kmlFile << "<Placemark>" << std::endl;
    kmlFile << "<name>" << name << "</name>" << std::endl;
    kmlFile << "<Point>" << "<coordinates>" << longitude << "," << latitude << "</coordinates>" << "</Point>" << std::endl;
    kmlFile << "</Placemark>" << std::endl;
}