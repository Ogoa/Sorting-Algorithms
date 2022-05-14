#include<iostream>
#include<ctime>
#include"Header.h"
using namespace std;



//INSERTION SORT
void Sorting::insertionSort(int* arr, int num)
{
	//Class method to implement the insertion sort
	for (int i = 0; i < num; i++)
	{
		int a = arr[i];
		int j = i - 1; /* Initialising the variable to be compared to the
                        current element, as the element to its immediate left */
		while (j >= 0 && arr[j] > a)
		{
			arr[j + 1] = arr[j]; /* Moving the greater elements to the left until
                                    a number less than 'a' is encountered */
			j--;
		}
		arr[j + 1] = a;
	}
}



//BUBBLE SORT
void Sorting::bubbleSort(int* arr, int num)
{
	//Class method to implement the bubble sort algorithm
	int temp = 0; //Varaible to temporarily store varibals while creating 'bubbles'
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[j] < arr[i]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}



//HEAP SORT
void Sorting::heapSortHeapify(int* arr, int num, int i)
{
	//Class method to break the existing array into heaps upto individual elements
	int parent = i;
	int leftChild = (i * 2) + 1;
	int rightChild = (i * 2) + 2;

	if (leftChild < num && arr[leftChild] > arr[parent]) {
		parent = leftChild;
	}
	if (rightChild < num && arr[rightChild] > arr[parent]) {
		parent = rightChild;
	}
	if (parent != i) {
		swap(arr[i], arr[parent]);
		heapSortHeapify(arr, num, parent);
	}
}

void Sorting::heapSort(int* arr, int num)
{
	//Class method to group the heapified individual elements into a final array, to finalise the heap sort
	for (int i = (num / 2 - 1); i >= 0; i--)
	{
		heapSortHeapify(arr, num, i);
	}
	for (int i = (num - 1); i > 0; i--)
	{
		swap(arr[0], arr[i]);
		heapSortHeapify(arr, i, 0);
	}
}



//QUICK SORT
int Sorting::seperate(int* arr, int l, int h)
{
	int pivot = arr[h];
	int i = (l - 1);

	for (int j = l; j < h; j++)
	{
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[h]);
	return (i + 1);
}

void Sorting::quickSort(int* arr, int l, int h)
{
	if (l < h)
	{
		int q = seperate(arr, l, h);
		quickSort(arr, l, q - 1);
		quickSort(arr, q + 1, h);
	}
}



//MERGE SORT
void Sorting::mergeSort(int* arr, int lowerBound, int upperBound)
{
	//Class method to execute the merge sort algorithm
	if (lowerBound  <upperBound)
	{
		int midPoint = (lowerBound + upperBound) / 2;
		mergeSort(arr, lowerBound, midPoint);
		mergeSort(arr, midPoint+1, upperBound);
		merge(arr, lowerBound, midPoint, upperBound);
	}
}

void Sorting::merge(int* arr, int lowerBound, int midPoint, int upperBound)
{
	int i = lowerBound; //Starting index for left subarray
	int j = midPoint + 1; //starting index for right subarray
	int k = lowerBound; //Starting index for temporary array
	int* b = new int[upperBound + 1]; //Temporary array
	while (i <= midPoint && j <= upperBound)
	{
		if (arr[i] < arr[j]) {
			b[k] = arr[i]; //Where arr[i] is smaller than arr[j]
			i++;
		}
		else
		{
			b[k] = arr[j]; //Where arr[j] is smaller than arr[i]
			j++;
		}
		k++;
	}
	while (i <= midPoint)
	{
		b[k] = arr[i]; //Copying all elements from the left subarray to the temporary array
		i++;
		k++;
	}
	while (j <= upperBound)
	{
		b[k] = arr[j]; //Copying all elements from the right subarray to the temporary array
		j++;
		k++;
	}

	for (k = lowerBound; k <= upperBound; k++) {
		arr[k] = b[k];
	}
}



//DISPLAYING THE SORTED ARRAY
void Sorting::displaySortedArray(int* arr, int num)
{
	cout << "\nThe sorted aray is:\n";
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}