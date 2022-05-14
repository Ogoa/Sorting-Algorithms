#include<iostream>
#include<ctime>
#include<Windows.h>
#include"Header.h"
using namespace std;


//Author : P15/2122/2021
/*
Purpose : Create aprogram to implement various sorting algorithms.
*/




//The main() function
int main()
{
	int num = 0;
	int option;
	int back;
	/*Prompting the user to enter the number of elements they want in their array
	So that memory is dynamically allocated to the array*/
tryAgain:
		int* myArray = nullptr;
		cout << "\nEnter the number of elements you want in your array:\t";
		cin >> num;

		myArray = new int[num];

		srand((unsigned)time(0));
		for (int i = 0; i < num; i++)
		{
			myArray[i] = (1 + rand() % 100); //Generating non-negative numbers between 1 and 100
		}

		system("cls");
		cout << "\nMAIN MENU\n";
		cout << "1. Insertion Sort\n2. Bubble Sort\n3. Heap Sort\n4. Quick Sort\n5. Merge Sort\n6. EXIT PROGRAM\n";
		cout << "Choose an option:\t";
		cin >> option;
		//Displaying the generated array, before sorting
		cout << "\nThe array generated is:\n";
		for (int i = 0; i < num; i++) {
			cout << myArray[i] << " ";
		}
		cout << "\n";
		switch (option)
		{
		case 1: {
			Sorting myObject1; //Declaring an object of the class 'Sorting'
			myObject1.insertionSort(myArray, num);
			myObject1.displaySortedArray(myArray, num);
			delete myArray; //Manually freeing memory once the sorting is done
			cout << "\nEnter: 1 to go back to the MAIN MENU, 0 to EXIT\n";
			cin >> back;
			switch (back)
			{
			case 1:
				Sleep(500);
				goto tryAgain;
				break;
			default:
				exit(0);
				break;
			}
			break;
		}
		case 2: {
			Sorting myObject2; //Declaring an object of the class 'Sorting'
			myObject2.bubbleSort(myArray, num);
			myObject2.displaySortedArray(myArray, num);
			delete myArray; //Manually freeing memory once the sorting is done
			cout << "\nEnter: 1 to go back to the MAIN MENU, 0 to EXIT\n";
			cin >> back;
			switch (back)
			{
			case 1:
				Sleep(500);
				goto tryAgain;
				break;
			default:
				exit(0);
				break;
			}
			break;
		}
		case 3: {
			Sorting myObject3; //Declaring an object of the class 'Sorting'
			myObject3.heapSort(myArray, num);
			myObject3.displaySortedArray(myArray, num);
			delete myArray; //Manually freeing memory once the sorting is done
			cout << "\nEnter: 1 to go back to the MAIN MENU, 0 to EXIT\n";
			cin >> back;
			switch (back)
			{
			case 1:
				Sleep(500);
				goto tryAgain;
				break;
			default:
				exit(0);
				break;
			}
			break;
		}
		case 4: {
			Sorting myObject4; //Declaring an object of the class 'Sorting'
			myObject4.quickSort(myArray, 0, (num - 1));
			myObject4.displaySortedArray(myArray, num);
			delete myArray; //Manually freeing memory once the sorting is done
			cout << "\nEnter: 1 to go back to the MAIN MENU, 0 to EXIT\n";
			cin >> back;
			switch (back)
			{
			case 1:
				Sleep(500);
				goto tryAgain;
				break;
			default:
				exit(0);
				break;
			}
			break;
		}
		case 5: {
			Sorting myObject5; //Declaring an object of the class 'Sorting'
			myObject5.mergeSort(myArray, 0, (num - 1));
			myObject5.displaySortedArray(myArray, num);
			delete myArray; //Manually freeing memory once the sorting is done
			cout << "\nEnter: 1 to go back to the MAIN MENU, 0 to EXIT\n";
			cin >> back;
			switch (back)
			{
			case 1:
				Sleep(500);
				goto tryAgain;
				break;
			default:
				exit(0);
				break;
			}
			break;
		}
		case 6:
			cout << "\nExiting program";
			for (int i = 0; i < 4; i++)
			{
				Sleep(400);
				cout << ".";
			}
			cout << "\n";
			exit(0);
			break;
		default:
			cout << "\nInvalid option. Try again...";
			system("pause");
			goto tryAgain;
		}
}