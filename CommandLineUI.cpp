/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 4

Used Microsoft Visual Studio 2017

CommandLineUI class
contains the presentational and interactive interface in the command line for the user.
KEEP ALL COUT<< AND CIN>> HERE
*/

#include "commandLineUI.h"

using namespace std;

CommandLineUI::CommandLineUI ()
{
}

//******************************************************
// CommandLineUI::enterLoop  
//      
// the main menu UI loop
//******************************************************
void CommandLineUI::enterLoop ()
{
	cout << "Welcome to the array sorter! " << endl;
	bool loopActive = true;
	unsigned int size;
	unsigned int i;
	string dataType;
	//cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
	while (loopActive)
	{
		cout << "Please enter the size of the array: ";
		cin >> size;
		cout << "What is the data type (int/double/char/string):";
		cin >> dataType;
		if (dataType == "int")
		{
			MultiArray<int> myarray (size);
			for (i = 0; i < size; i++)
			{
				cout << "Please enter int #" << i + 1 << ": ";
				cin >> myarray[i];
			}
			myarray.getArray ();
		} else if (dataType == "double")
		{
			MultiArray<double> myarray (size);
			for (i = 0; i < size; i++)
			{
				cout << "Please enter double #" << i + 1 << ": ";
				cin >> myarray[i];
			}
			myarray.getArray ();
		}
		else if (dataType == "char")
		{
			MultiArray<char> myarray (size);
			for (i = 0; i < size; i++)
			{
				cout << "Please enter char #" << i + 1 << ": ";
				cin >> myarray[i];
			}
			myarray.getArray ();
		}
		else if (dataType == "string")
		{
			MultiArray<string> myarray (size);
			cin.ignore ();
			for (i = 0; i < size; i++)
			{
				cout << "Please enter string #" << i + 1 << ": ";
				getline (cin, myarray[i]);
			}
			myarray.getArray ();
		}
	}
}

//******************************************************
// operator<<        
//******************************************************
template< class T >
std::ostream& operator<< (std::ostream &foo, MultiArray<T> *ObjPtr)
{
	foo << "hey";
	return foo;
}