#pragma once
#include<iostream>

class Sorting {
public:
	//int b[100];
	void insertionSort(int*, int);

	void bubbleSort(int*, int);

	void heapSortHeapify(int*, int, int);
	void heapSort(int*, int);

	int seperate(int*, int, int);
	void quickSort(int*, int, int);
	
	void mergeSort(int*, int, int);
	void merge(int*, int, int, int);

	void displaySortedArray(int*, int);
};