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

#include <iostream>
#include <iomanip>
#include <typeinfo>

template< class T >
class MultiArray
{
private:
	T* myarray;
	unsigned int size;
public:
	MultiArray ();
	MultiArray (unsigned int s);
	virtual ~MultiArray ();
	void setArray (unsigned int elem, T val);
	void getArray ();

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
MultiArray<T>::~MultiArray ()
{

}

// constructor with user pre-defined size
// calss array member function to set element of myarray 
// with type T values
template< class T >
void MultiArray<T>::setArray (unsigned int elem, T val)
{
	myarray[elem] = val;
}

// for loop to display all elements of an array
template< class T >
void MultiArray<T>::getArray ()
{
	for (unsigned int j = 0; j < size; j++)
	{
		// typeid will retriev a type for each value
		std::cout << std::setw (7) << j << std::setw (13) << myarray[j]
			<< " type: " << typeid(myarray[j]).name () << std::endl;
	}
	std::cout << "-----------------------------" << endl;
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