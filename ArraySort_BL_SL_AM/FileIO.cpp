#include "FileIO.h"

bool FileIO::strToFile (std::string str, std::string filePath)
{
	bool flag = false;
	std::ofstream myFile;
	myFile.open (filePath);
	myFile << "Branden Lee, Stephen Lee, and Alex Morfin" << std::endl;
	myFile << "CIS 22C" << std::endl;
	myFile << "Fall 2017" << std::endl;
	myFile << "Lab 4" << std::endl;
	if (myFile)
	{
		myFile << str;
		myFile.close ();
	}
	return flag;
}