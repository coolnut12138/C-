#pragma once
void InsertSortWithGap(int arr[], int size, int gap)
{
	for (int i = gap; i < size; i++) {
		int key = arr[i];
		int j;
		for (j = i - gap; j >= 0 && arr[j] > key; j -= gap) {
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = key;
	}
}

void ShellSort(int arr[], int size)
{
	int gap = size;
	while (1) {
		gap = (gap / 3) + 1;
		InsertSortWithGap(arr, size, gap);
		if (gap == 1) {
			break;
		}
	}
}