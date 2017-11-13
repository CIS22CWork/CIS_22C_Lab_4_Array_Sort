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
	static void insertionSort (MultiArray<T> &arr, int n, std::string &log);
	static int partition (MultiArray<T> &arr, int low, int high);
	static void quickSort (MultiArray<T> &arr, int low, int high, std::string &log);
	static void merge (MultiArray<T> &arr, int l, int m, int r);
	static void mergeSort (MultiArray<T> &arr, int l, int r, std::string &log);
};

/* Function to sort an array using insertion sort*/
template< class T >
void MultiSort<T>::insertionSort (MultiArray<T> &arr, int n, std::string &log)
{
	// Base case
	if (n <= 1)
		return;

	// Sort first n-1 elements
	insertionSort (arr, n - 1, log);

	// Insert last element at its correct position
	// in sorted array.
	T last = arr[n - 1];
	int j = n - 2;

	/* Move elements of arr[0..i-1], that are
	greater than key, to one position ahead
	of their current position */
	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;
	log += arr.toString ();
}
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
template< class T >
int MultiSort<T>::partition (MultiArray<T> &arr, int low, int high)
{
	T pivot = arr[high];    // pivot
	T tmp;
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
template< class T >
void MultiSort<T>::quickSort (MultiArray<T> &arr, int low, int high, std::string &log)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition (arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort (arr, low, pi - 1, log);
		quickSort (arr, pi + 1, high, log);
	}
	log += arr.toString ();
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
template< class T >
void MultiSort<T>::merge (MultiArray<T> &arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	T *L = new T[n1];
	T *R = new T[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
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
	log += arr.toString ();
}
#endif