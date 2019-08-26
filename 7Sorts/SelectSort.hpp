#pragma once
#include "Swap.h"
void SelectSort(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		int max = 0;
		for (int j = 0; j < size - i; j++) {
			if (arr[j] > arr[max]) {
				max = j;
			}
		}
		Swap(arr + max, arr + size - i - 1);
	}
}