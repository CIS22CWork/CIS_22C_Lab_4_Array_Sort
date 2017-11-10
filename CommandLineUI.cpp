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
			MultiArray<int> myarray1 (myarray);
			MultiArray<int> myarray2 (myarray);
			cout << "Insertion Sort" << endl;
			MultiSort<int>::insertionSort (myarray, size);
			myarray.getArray ();
			cout << "Quick Sort" << endl;
			MultiSort<int>::quickSort (myarray1, 0, size - 1);
			myarray1.getArray ();
			cout << "Merge Sort" << endl;
			MultiSort<int>::mergeSort (myarray2, 0, size - 1);
			myarray2.getArray ();
		}
		else if (dataType == "double")
		{
			MultiArray<double> myarray (size);
			for (i = 0; i < size; i++)
			{
				cout << "Please enter double #" << i + 1 << ": ";
				cin >> myarray[i];
			}
			MultiArray<double> myarray1 (myarray);
			MultiArray<double> myarray2 (myarray);
			cout << "Insertion Sort" << endl;
			MultiSort<double>::insertionSort (myarray, size);
			myarray.getArray ();
			cout << "Quick Sort" << endl;
			MultiSort<double>::quickSort (myarray1, 0, size - 1);
			myarray1.getArray ();
			cout << "Merge Sort" << endl;
			MultiSort<double>::mergeSort (myarray2, 0, size - 1);
			myarray2.getArray ();
		}
		else if (dataType == "char")
		{
			MultiArray<char> myarray (size);
			for (i = 0; i < size; i++)
			{
				cout << "Please enter char #" << i + 1 << ": ";
				cin >> myarray[i];
			}
			MultiArray<char> myarray1 (myarray);
			MultiArray<char> myarray2 (myarray);
			cout << "Insertion Sort" << endl;
			MultiSort<char>::insertionSort (myarray, size);
			myarray.getArray ();
			cout << "Quick Sort" << endl;
			MultiSort<char>::quickSort (myarray1, 0, size - 1);
			myarray1.getArray ();
			cout << "Merge Sort" << endl;
			MultiSort<char>::mergeSort (myarray2, 0, size - 1);
			myarray2.getArray ();
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
			MultiArray<string> myarray1 (myarray);
			MultiArray<string> myarray2 (myarray);
			cout << "Insertion Sort" << endl;
			MultiSort<string>::insertionSort (myarray, size);
			myarray.getArray ();
			cout << "Quick Sort" << endl;
			MultiSort<string>::quickSort (myarray1, 0, size - 1);
			myarray1.getArray ();
			cout << "Merge Sort" << endl;
			MultiSort<string>::mergeSort (myarray2, 0, size - 1);
			myarray2.getArray ();
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

template< class T >
std::ostream& operator<< (std::ostream &foo, MultiSort<T> *ObjPtr)
{
	foo << "hey";
	return foo;
}