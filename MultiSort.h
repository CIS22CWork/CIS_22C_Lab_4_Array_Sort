/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 4

Used Microsoft Visual Studio 2017

MultiArray class
*/
#ifndef MULTI_SORT_H
#define MULTI_SORT_H

#include <string>

template< class T >
class MultiSort
{
private:
	T* myarray;
	unsigned int size;
public:
	static void insertionSort (MultiArray<T> &arr, unsigned int n);
};

/* Function to sort an array using insertion sort*/
template< class T >
void MultiSort<T>::insertionSort (MultiArray<T> &arr, unsigned int size)
{
	int i, j;
	int n = (int)size;
	T key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

#endif