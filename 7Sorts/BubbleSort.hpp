#pragma once

#include "Swap.h"
void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		int flag = 1;
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				Swap(arr + j, arr + j + 1);
				flag = 0;
			}
		}
		if (flag == 1) {
			break;
		}
	}
}