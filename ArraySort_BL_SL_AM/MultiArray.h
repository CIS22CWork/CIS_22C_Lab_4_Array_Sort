/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 4

Used Microsoft Visual Studio 2017

MultiArray class
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
	std::string toString ();

	T &operator[] (unsigned int);
	friend std::ostream& operator<< (std::ostream &foo, MultiArray<T> *ObjPtr);
};

template< class T >
MultiArray<T>::MultiArray ()
{
}

template< class T >
MultiArray<T>::MultiArray (unsigned int s)
{
	size = s;
	myarray = new T[size];
}

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

// constructor with user pre-defined size
// calss array member function to set element of myarray 
// with type T values
template< class T >
void MultiArray<T>::setValue (unsigned int elem, T val)
{
	myarray[elem] = val;
}

// for loop to display all elements of an array
template< class T >
std::string MultiArray<T>::toString ()
{
	std::stringstream ss;
	for (unsigned int j = 0; j < size; j++)
	{
		// typeid will retrieve a type for each value
		ss << std::setw (7) << left << j << myarray[j] << std::endl;
	}
	ss << "-----------------------------" << endl;
	return ss.str ();
}

// Implementation of [] operator.  This function must return a
// refernce as array element can be put on left side
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