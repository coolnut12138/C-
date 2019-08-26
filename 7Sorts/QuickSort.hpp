#pragma once
#include "Swap.h"

int Partition1(int arr[], int left, int right){
	int begin = left;
	int end = right;
	while (begin < end) {
		while (begin < end && arr[begin] <= arr[right]) {
			begin++;
		}
		while (begin < end && arr[end] >= arr[right]) {
			end--;
		}
		Swap(arr + begin, arr + end);
	}
	Swap(arr + begin, arr + right);
	return begin;
}

int Partition2(int arr[], int left, int right) {
	int begin = left;
	int end = right;
	int pivot = arr[right];
	while (begin < end) {
		while (begin < end && arr[begin] <= pivot) {
			begin++;
		}
		arr[end] = arr[begin];
		while (begin < end && arr[end] >= pivot) {
			end--;
		}
		arr[begin] = arr[end];
	}
	arr[begin] = pivot;
	return begin;
}

int Partition3(int arr[], int left, int right) {
	int div = left;
	for (int i = left; i < right; i++) {
		if (arr[i] < arr[right]) {
			Swap(arr + i, arr + div);
			div++;
		}
	}
	Swap(arr + div, arr + right);
	return div;
}

void _QuickSort(int arr[], int left, int right) {
	if (left >= right) {
		return;
	}

	//int div = Partition1(arr, left, right);
	//int div = Partition2(arr, left, right);
	int div = Partition3(arr, left, right);
	_QuickSort(arr, left, div - 1);
	_QuickSort(arr, div + 1, right);
}

void QuickSort(int arr[], int size) {
	_QuickSort(arr, 0, size - 1);
}