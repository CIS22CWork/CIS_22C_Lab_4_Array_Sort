/*
Branden Lee, Stephen Lee, and Alex Morfin
CIS 22C
Fall 2017
Lab 4

Used Microsoft Visual Studio 2017

MultiSort class
contains recursive methods for
-insertion sort
-quicksort
-merge sort
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
	static void insertionPart (MultiArray<T> &arr, int n, int j, T last);
	static void insertionSort (MultiArray<T> &arr, int n, std::string &log);
	static int partition (MultiArray<T> &arr, int low, int high, int i, int j);
	static void quickSort (MultiArray<T> &arr, int low, int high, std::string &log);
	static void mergeAssign (MultiArray<T> &arr, int l, int m, int r, T L[], T R[], int i, int j);
	static void mergeArray (MultiArray<T> &arr, int l, int m, int r, T L[], T R[], int i, int j, int k);
	static void merge (MultiArray<T> &arr, int l, int m, int r);
	static void mergeSort (MultiArray<T> &arr, int l, int r, std::string &log);
};

/* insertion algorithm helper method
@pre j is 0 or more
@post move elements ahead of their current position
@param arr the template array
@param n the size of the array
@param j the index
@param last the last value of the array before move
@return None
*/
template< class T >
void MultiSort<T>::insertionPart (MultiArray<T> &arr, int n, int j, T last)
{
	// Insert last element at its correct position
	// in sorted array.
	if (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		insertionPart (arr, n, --j, last);
	}
	else
	{
		arr[j + 1] = last;
	}
}

/* Recursive Insertion Algorithm
@pre None
@post outputs array contents to log at each recursion depth
@param arr the template array
@param n the size of the array
@param log step log
@return None
*/
template< class T >
void MultiSort<T>::insertionSort (MultiArray<T> &arr, int n, std::string &log)
{
	// Base case
	if (n <= 1)
		return;

	// Sort first n-1 elements
	insertionSort (arr, n - 1, log);

	/* Move elements of arr[0..i-1], that are
	greater than key, to one position ahead
	of their current position */
	insertionPart (arr, n, n - 2, arr[n - 1]);
	// log array state
	log += arr.toString ();
}
/* takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot
@pre None
@post None
@param arr the template array
@param low starting index
@param high ending index
@return the partition
*/
template< class T >
int MultiSort<T>::partition (MultiArray<T> &arr, int low, int high, int i, int j)
{
	int r;
	T tmp;
	if (j <= high - 1)
	{
		if (arr[j] <= arr[high])
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		r = partition (arr, low, high, i, ++j);
	}
	else
	{
		tmp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = tmp;
		r = i + 1;
	}
	return r;
}

/* recursive quick sort algorithm
@pre None
@post outputs array contents to log at each recursion depth
@param arr the template array
@param low starting index
@param high ending index
@param log step log
@return None
*/
template< class T >
void MultiSort<T>::quickSort (MultiArray<T> &arr, int low, int high, std::string &log)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition (arr, low, high, low - 1, low);

		// Separately sort elements before
		// partition and after partition
		quickSort (arr, low, pi - 1, log);
		quickSort (arr, pi + 1, high, log);
	}
	// log array state
	log += arr.toString ();
}

/* Assign two temporary two subarrays of arr[]
@pre First subarray is arr[l..m], Second subarray is arr[m+1..r]
@post template array is merged
@param arr the template array
@param l left
@param m middle
@param r right
@param L left temp array
@param R right temp array
@param i left index
@param j right index
@return None
*/
template< class T >
void MultiSort<T>::mergeAssign (MultiArray<T> &arr, int l, int m, int r, T L[], T R[], int i, int j)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	if (i < n1)
	{
		L[i] = arr[l + i];
	}
	if (j < n2)
	{
		R[j] = arr[m + 1 + j];
	}
	if (i < n1 && j < n2)
		mergeAssign (arr, l, m, r, L, R, i + 1, j + 1);
}

/* Merges two subarrays of arr[]
@pre First subarray is arr[l..m], Second subarray is arr[m+1..r]
@post template array is merged
@param arr the template array
@param l left
@param m middle
@param r right
@param L left temp array
@param R right temp array
@param i left index
@param j right index
@param k array index
@return None
*/
template< class T >
void MultiSort<T>::mergeArray (MultiArray<T> &arr, int l, int m, int r, T L[], T R[], int i, int j, int k)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	if (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			mergeArray (arr, l, m, r, L, R, i + 1, j, k + 1);
		}
		else
		{
			arr[k] = R[j];
			mergeArray (arr, l, m, r, L, R, i, j + 1, k + 1);
		}
	}
	else
	{

		/* Copy the remaining elements of L[], if there
		are any */
		if (i < n1)
		{
			arr[k] = L[i];
			mergeArray (arr, l, m, r, L, R, i + 1, j, k + 1);
		}

		/* Copy the remaining elements of R[], if there
		are any */
		if (j < n2)
		{
			arr[k] = R[j];
			mergeArray (arr, l, m, r, L, R, i, j + 1, k + 1);
		}
	}
}

/* Merges two subarrays of arr[]
@pre First subarray is arr[l..m], Second subarray is arr[m+1..r]
@post template array is merged
@param arr the template array
@param l left
@param m middle
@param r right
@return None
*/
template< class T >
void MultiSort<T>::merge (MultiArray<T> &arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	/* create temp arrays */
	T* L = new T[n1];
	T* R = new T[n2];
	/* Copy data to temp arrays L[] and R[] */
	mergeAssign (arr, l, m, r, L, R, 0, 0);
	/* Merge the temp arrays back into arr[l..r]*/
	mergeArray (arr, l, m, r, L, R, 0, 0, l);
	delete[] L;
	delete[] R;
}

/* recursive merge sort algorithm
@pre None
@post outputs array contents to log at each recursion depth
@param arr the template array
@param l is for left index
@param r is right index
@param log step log
@return None
*/
template< class T >
void MultiSort<T>::mergeSort (MultiArray<T> &arr, int l, int r, std::string &log)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort (arr, l, m, log);
		mergeSort (arr, m + 1, r, log);

		merge (arr, l, m, r);
	}
	// log array state
	log += arr.toString ();
}
#endif