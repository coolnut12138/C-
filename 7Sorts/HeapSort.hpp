#pragma once
#include "Swap.h"

//排升序 建大堆
void AdjustDown(int arr[], int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size) {
		return;
	}

	int max;
	if (right < size && arr[right] > arr[left]) {
		max = right;
	}
	else {
		max = left;
	}

	if (arr[root] >= arr[max]) {
		return;
	}
	Swap(arr + root, arr + max);
	AdjustDown(arr, size, max);
}

void CreateHeap(int arr[], int size)
{
	//从最后一个非叶子节点向上进行向下调整
	for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(arr, size, i);
	}
}

void HeapSort(int arr[], int size)
{
	CreateHeap(arr, size);
	for (int i = 0; i < size; i++) {
		Swap(arr, arr + size - i - 1);
		AdjustDown(arr, size - i - 1, 0);
	}
}