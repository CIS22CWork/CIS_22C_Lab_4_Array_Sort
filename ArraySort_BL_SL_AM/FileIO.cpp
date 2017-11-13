#include "FileIO.h"

bool FileIO::strToFile (std::string str, std::string filePath)
{
	bool flag = false;
	std::ofstream myFile;
	myFile.open (filePath);
	if (myFile)
	{
		myFile << str;
		myFile.close ();
	}
	return flag;
}