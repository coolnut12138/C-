#include "BubbleSort.hpp"
#include "InsertSort.hpp"
#include "QuickSort.hpp"
#include "ShellSort.hpp"
#include "SelectSort.hpp"
#include "HeapSort.hpp"
#include "MergeSort.hpp"
#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 8,4,0,54,6,7,3,2,1,5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr, size);
	//InsertSort(arr, size);
	//QuickSort(arr, size);
	//ShellSort(arr, size);
	//SelectSort(arr, size);
	//HeapSort(arr, size);
	MergeSort(arr, size);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}