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
// Pre: None
// Post: None
// Purpose: Command Line to interact with the user
//******************************************************
void CommandLineUI::enterLoop ()
{
	cout << "Welcome to the array sorter! " << endl;
	cout << "The sort steps will be saved to \"output.txt\" and be overwritten every sort." << endl;
	bool loopActive = true;
	unsigned int size;
	unsigned int i;
	std::stringstream console;
	std::string outputFileName = "output.txt";
	string dataType, log0, log1, log2;
	//cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
	while (loopActive)
	{
		console.str ("");
		log0 = "";
		log1 = "";
		log2 = "";
		cout << "Please enter the size of the array: ";
		cin >> size;
		if (cin.fail ())
		{
			cin.clear (); // clears failure state
			cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
			cout << "INPUT NOT ALLOWED!" << endl;
			continue;
		}
		if (size > SORT_MAX_SIZE)
		{
			cin.clear (); // clears failure state
			cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
			cout << "Size may not exceed " << SORT_MAX_SIZE << endl;
			continue;
		}
		if (size < 1)
		{
			cin.clear (); // clears failure state
			cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
			cout << "Size must be larger than zero" << endl;
			continue;
		}
		cout << "What is the data type (int/double/char/string):";
		cin >> dataType;
		if (cin.fail ())
		{
			cin.clear (); // clears failure state
			cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
			cout << "INPUT NOT ALLOWED!" << endl;
			continue;
		}
		if (dataType == "int")
		{
			MultiArray<int> myarray (size);
			for (i = 0; i < size; i++)
			{
				cout << "Please enter int #" << i + 1 << ": ";
				cin >> myarray[i];
				if (cin.fail ())
				{
					cin.clear (); // clears failure state
					cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
					cout << "INPUT NOT ALLOWED!" << endl;
					i--;
					continue;
				}
			}
			MultiArray<int> myarray1 (myarray);
			MultiArray<int> myarray2 (myarray);
			// log initial array
			log0 += myarray.toString ();
			log1 += myarray1.toString ();
			log2 += myarray2.toString ();
			MultiSort<int>::insertionSort (myarray, size, log0);
			MultiSort<int>::quickSort (myarray1, 0, size - 1, log1);
			MultiSort<int>::mergeSort (myarray2, 0, size - 1, log2);
			console << "Insertion Sort" << endl << log0 << endl;
			console << "Quick Sort" << endl << log1 << endl;
			console << "Merge Sort" << endl << log2 << endl;
			cout << console.str ();
			FileIO::strToFile (console.str (), outputFileName);
			// clear arrays for next loop
			myarray.clear ();
			myarray1.clear ();
			myarray2.clear ();
		}
		else if (dataType == "double")
		{
			MultiArray<double> myarray (size);
			for (i = 0; i < size; i++)
			{
				cout << "Please enter double #" << i + 1 << ": ";
				cin >> myarray[i];
				if (cin.fail ())
				{
					cin.clear (); // clears failure state
					cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
					cout << "INPUT NOT ALLOWED!" << endl;
					i--;
					continue;
				}
			}
			MultiArray<double> myarray1 (myarray);
			MultiArray<double> myarray2 (myarray);
			// log initial array
			log0 += myarray.toString ();
			log1 += myarray1.toString ();
			log2 += myarray2.toString ();
			MultiSort<double>::insertionSort (myarray, size, log0);
			MultiSort<double>::quickSort (myarray1, 0, size - 1, log1);
			MultiSort<double>::mergeSort (myarray2, 0, size - 1, log2);
			console << "Insertion Sort" << endl << log0 << endl;
			console << "Quick Sort" << endl << log1 << endl;
			console << "Merge Sort" << endl << log2 << endl;
			cout << console.str ();
			FileIO::strToFile (console.str (), outputFileName);
			// clear arrays for next loop
			myarray.clear ();
			myarray1.clear ();
			myarray2.clear ();
		}
		else if (dataType == "char")
		{
			MultiArray<char> myarray (size);
			for (i = 0; i < size; i++)
			{
				cout << "Please enter char #" << i + 1 << ": ";
				cin >> myarray[i];
				if (cin.fail ())
				{
					cin.clear (); // clears failure state
					cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
					cout << "INPUT NOT ALLOWED!" << endl;
					i--;
					continue;
				}
			}
			MultiArray<char> myarray1 (myarray);
			MultiArray<char> myarray2 (myarray);
			// log initial array
			log0 += myarray.toString ();
			log1 += myarray1.toString ();
			log2 += myarray2.toString ();
			MultiSort<char>::insertionSort (myarray, size, log0);
			MultiSort<char>::quickSort (myarray1, 0, size - 1, log1);
			MultiSort<char>::mergeSort (myarray2, 0, size - 1, log2);
			console << "Insertion Sort" << endl << log0 << endl;
			console << "Quick Sort" << endl << log1 << endl;
			console << "Merge Sort" << endl << log2 << endl;
			cout << console.str ();
			FileIO::strToFile (console.str (), outputFileName);
			// clear arrays for next loop
			myarray.clear ();
			myarray1.clear ();
			myarray2.clear ();
		}
		else if (dataType == "string")
		{
			MultiArray<string> myarray (size);
			cin.ignore ();
			for (i = 0; i < size; i++)
			{
				cout << "Please enter string #" << i + 1 << ": ";
				getline (cin, myarray[i]);
				if (cin.fail ())
				{
					cin.clear (); // clears failure state
					cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
					cout << "INPUT NOT ALLOWED!" << endl;
					i--;
					continue;
				}
			}
			MultiArray<string> myarray1 (myarray);
			MultiArray<string> myarray2 (myarray);
			// log initial array
			log0 += myarray.toString ();
			log1 += myarray1.toString ();
			log2 += myarray2.toString ();
			MultiSort<string>::insertionSort (myarray, size, log0);
			MultiSort<string>::quickSort (myarray1, 0, size - 1, log1);
			MultiSort<string>::mergeSort (myarray2, 0, size - 1, log2);
			console << "Insertion Sort" << endl << log0 << endl;
			console << "Quick Sort" << endl << log1 << endl;
			console << "Merge Sort" << endl << log2 << endl;
			cout << console.str ();
			FileIO::strToFile (console.str (), outputFileName);
			// clear arrays for next loop
			myarray.clear ();
			myarray1.clear ();
			myarray2.clear ();
		}
		else
		{
			cin.clear (); // clears failure state
			cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); // discards "bad" characters
			cout << "Type must be int/double/char/string!" << endl;
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