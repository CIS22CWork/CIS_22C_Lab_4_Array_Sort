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
	string dataType, log0, log1, log2;
	//cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
	while (loopActive)
	{
		log0, log1, log2 = "";
		cout << "Please enter the size of the array: ";
		cin >> size;
		if (size > SORT_MAX_SIZE)
		{
			cout << "Size may not exceed " << SORT_MAX_SIZE << endl;
			continue;
		}
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
			MultiSort<int>::insertionSort (myarray, size, log0);
			MultiSort<int>::quickSort (myarray1, 0, size - 1, log1);
			MultiSort<int>::mergeSort (myarray2, 0, size - 1, log2);
			cout << "Insertion Sort" << endl << log0 << endl;
			cout << "Quick Sort" << endl << log1 << endl;
			cout << "Merge Sort" << endl << log2 << endl;
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
			MultiSort<double>::insertionSort (myarray, size, log0);
			MultiSort<double>::quickSort (myarray1, 0, size - 1, log1);
			MultiSort<double>::mergeSort (myarray2, 0, size - 1, log2);
			cout << "Insertion Sort" << endl << log0 << endl;
			cout << "Quick Sort" << endl << log1 << endl;
			cout << "Merge Sort" << endl << log2 << endl;
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
			MultiSort<char>::insertionSort (myarray, size, log0);
			MultiSort<char>::quickSort (myarray1, 0, size - 1, log1);
			MultiSort<char>::mergeSort (myarray2, 0, size - 1, log2);
			cout << "Insertion Sort" << endl << log0 << endl;
			cout << "Quick Sort" << endl << log1 << endl;
			cout << "Merge Sort" << endl << log2 << endl;
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
			MultiSort<string>::insertionSort (myarray, size, log0);
			MultiSort<string>::quickSort (myarray1, 0, size - 1, log1);
			MultiSort<string>::mergeSort (myarray2, 0, size - 1, log2);
			cout << "Insertion Sort" << endl << log0 << endl;
			cout << "Quick Sort" << endl << log1 << endl;
			cout << "Merge Sort" << endl << log2 << endl;
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