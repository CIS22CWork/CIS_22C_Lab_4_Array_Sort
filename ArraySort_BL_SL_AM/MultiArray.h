/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 4

Used Microsoft Visual Studio 2017

MultiArray class
A template array that may be instantiated as any type
*/
#ifndef MULTI_ARRAY_H
#define MULTI_ARRAY_H

#include <string>
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <sstream>

template< class T >
class MultiArray
{
private:
	T* myarray;
	unsigned int size;
public:
	MultiArray ();
	MultiArray (unsigned int s);
	MultiArray (const MultiArray<T> &target);
	virtual ~MultiArray ();
	void setValue (unsigned int elem, T val);
	void clear();
	std::string toString ();

	T &operator[] (unsigned int);
	friend std::ostream& operator<< (std::ostream &foo, MultiArray<T> *ObjPtr);
};

//******************************************************
// constructors and destructors       
//******************************************************
template< class T >
MultiArray<T>::MultiArray ()
{
	size = 0;
}
template< class T >
MultiArray<T>::MultiArray (unsigned int s)
{
	size = s;
	myarray = new T[size];
}

/* copy constructor */
template< class T >
MultiArray<T>::MultiArray (const MultiArray<T> &target)
{
	size = target.size;
	myarray = new T[size];
	for (unsigned i = 0; i < target.size; i++)
		myarray[i] = target.myarray[i];
}

template< class T >
MultiArray<T>::~MultiArray ()
{

}

/* sets index value
@pre None
@post sets array element
@param elem array index
@param val value to store
@return None
*/
template< class T >
void MultiArray<T>::setValue (unsigned int elem, T val)
{
	myarray[elem] = val;
}

/* clears array data
@pre size is more than 0
@post deletes array pointer
@return None
*/
template< class T >
void MultiArray<T>::clear ()
{
	if (size > 0)
	{
		delete[] myarray;
		size = 0;
	}
}

/* displays all elements of the array
@pre None
@post standard output of array contents
@return None
*/
template< class T >
std::string MultiArray<T>::toString ()
{
	std::stringstream ss;
	for (unsigned int j = 0; j < size; j++)
	{
		ss << std::setw (7) << left << j << myarray[j] << std::endl;
	}
	ss << "-----------------------------" << endl;
	return ss.str ();
}

/*subscript [] operator overload makes the template behave like an array
@pre index is less than the size
@post None
@param index the position in the array
@return return the element at the index
*/
template< class T >
T &MultiArray<T>::operator[](unsigned int index)
{
	if (index >= size)
	{
		cout << "Array index out of bound, exiting";
		exit (0);
	}
	return myarray[index];
}

#endif