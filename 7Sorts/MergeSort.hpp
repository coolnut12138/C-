#pragma once

void Merge(int arr[], int left, int mid, int right, int* extra)
{
	int size = right - left;
	int left_index = left;
	int right_index = mid;
	int extra_index = 0;
	while (left_index < mid && right_index < right) {
		if (arr[left_index] <= arr[right_index]) {
			extra[extra_index] = arr[left_index];
			left_index++;
		}
		else {
			extra[extra_index] = arr[right_index];
			right_index++;
		}
		extra_index++;
	}

	while (left_index < mid) {
		extra[extra_index++] = arr[left_index++];
	}
	while (right_index < right) {
		extra[extra_index++] = arr[right_index++];
	}

	for (int i = 0; i < size; i++) {
		arr[left + i] = extra[i];
	}
}

void _MergeSort(int arr[], int left, int right, int* extra)
{
	if (left + 1 == right) {
		return;
	}
	if (left >= right) {
		return;
	}

	int mid = left + (right - left) / 2;
	_MergeSort(arr, left, mid, extra);
	_MergeSort(arr, mid, right, extra);
	Merge(arr, left, mid, right, extra);
}

void MergeSort(int arr[], int size)
{
	int *extra = new int[size];
	_MergeSort(arr, 0, size, extra);
	delete[] extra;
}