#ifndef COMMAND_LINE_UI_H
#define COMMAND_LINE_UI_H

#include <iostream>
#include <sstream>
#include <limits>
#include "MultiArray.h"
#include "MultiSort.h"
#include "FileIO.h"

class CommandLineUI
{
private:
	static const int SORT_MAX_SIZE = 32;
public:
	CommandLineUI ();
	static void enterLoop ();
};

#endif