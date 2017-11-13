/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 4

Used Microsoft Visual Studio 2017

main
Prompts the user for an array of up to a certain size and a select type
Program will sort the array recursively using:
-Insertion Sort
-Quick Sort
-Merge Sort
Prints each step for each sort algorithm to standard out
Saves steps to a file
*/
#include <iostream>
#include "MultiArray.h"
#include "MultiSort.h"
#include "commandLineUI.h"

using namespace std;

int main ()
{
	CommandLineUI::enterLoop ();
	system ("pause");
	return 0;
}