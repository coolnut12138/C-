#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//插入排序
//时间复杂度：最好:O(n)（已经有序）
//			 平均：O(n^2)
//			 最坏：O(n^2)(逆序)
//稳定性：稳定，适用场景：数据量比较小或者大概率有序的情况。
void InsertSort(int arr[], int size)
{
	//第一次选两个数，最左边的一个数已经有序，用第二个数跟第一个数作比较
	//第二次是左边两个数已经有序，选第三个数与这两个有序的数字比较
	//以此类推。。。
	for (int i = 1; i < size; i++){
		int key = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > key; j--){
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//冒泡
//时间复杂度：O(n^2)
void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; ++i){	//比较的趟数
		int isSorted = -1;
		for (int j = 0; j < size - i - 1; ++j){	//每一趟都会把一个最值换出来，所以每一次减少与最值的一次比较
			if (arr[j] > arr[j + 1]){
				Swap(arr + j, arr + j + 1);
				isSorted = 0;	//标记一下，如果这趟没有交换，证明已经排好序了，不用再进行后面的了
			}
				
		}
		if (isSorted == -1){
			break;
		}
	}
}

//希尔 
//利用数据越有序插排效率越大的特性
//时间复杂度：最好：O(n) 平均：O(n^1.3) 最坏O(n^2)
//不稳定（没法保证相同的数分在一组内）
void InsertWithGap(int arr[], int size, int gap)
{
	for (int i = gap; i < size; i++)
	{
		int key = arr[i];
		int j;
		for (j = i - gap; j >= 0 && arr[j] > key; j -= gap)
		{
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = key;
	}
}

void shellSort(int arr[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;
		InsertWithGap(arr, size, gap);
		if (gap == 1){
			break;
		}
	}
}

//选择排序：
//时间复杂度：O(n^2)
void SelectSort(int arr[], int size)
{
	for (int i = 0; i < size; i++){
		int max = 0;
		for (int j = 1; j < size - i; j++){
			if (arr[j] > arr[max]){
				max = j;
			}
		}
		Swap(arr + max, arr + size - i - 1);	//减治，每一次选出最大值放到当前元素个数的最后
	}
}

//堆排序：
//排升序，建大堆，每次取堆顶元素与堆最后一个元素进行交换，然后从堆顶元素向下调整
//时间复杂度：O(nlogn)
void AdjustDown(int arr[], int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	while (left < size){
		int max = left;
		if (right < size && arr[right] > arr[left]){
			max = right;
		}

		if (arr[root] >= arr[max]){
			break;
		}

		Swap(arr + root, arr + max);
		root = max;
		left = root * 2 + 1;
		right = root * 2 + 2;
	}
}

void CreateHeap(int arr[], int size){
	for (int i = (size - 2) / 2; i >= 0; i--){
		AdjustDown(arr, size, i);
	}
}

void HeapSort(int arr[], int size)
{
	CreateHeap(arr, size);
	for (int i = 0; i < size; i++){
		Swap(arr, arr + size - i - 1);
		AdjustDown(arr, size - i - 1, 0);
	}
}

//快排
//hover
int Partition_1(int arr[], int left, int right)
{
	int begin = left;
	int end = right;
	while (begin < end){
		while (begin < end && arr[begin] <= arr[right]){
			begin++;
		}
		while (begin < end && arr[end] >= arr[right]){
			end--;
		}
		Swap(arr + begin, arr + end);
	}
	Swap(arr + begin, arr + right);
	return begin;
}

//挖坑法
int Partition_2(int arr[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = arr[right];
	while (begin < end){
		while (begin < end && arr[begin] <= pivot){
			begin++;
		}
		arr[end] = arr[begin];
		while (begin < end && arr[end] >= pivot){
			end--;
		}
		arr[begin] = arr[end];
	}
	arr[begin] = pivot;
	return begin;
}

//前后下标
int Partition_3(int arr[], int left, int right)
{
	int div = left;
	for (int i = left; i < right; i++)
	{
		if (arr[i] < arr[right]){
			Swap(arr + i, arr + div);
			div++;
		}
	}
	Swap(arr + div, arr + right);
	return div;
}

void _QuickSort(int arr[], int left, int right)
{
	if (left >= right){
		return;
	}
	//int div = Partition_1(arr, left, right);
	//int div = Partition_2(arr, left, right);
	int div = Partition_3(arr, left, right);

	_QuickSort(arr, left, div - 1);
	_QuickSort(arr, div + 1, right);
}

void QuickSort(int arr[], int size)
{
	_QuickSort(arr, 0, size - 1);
}

int main()
{
	int arr[] = { 3, 6, 2, 63, 4, 8, 3, 7, 9, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	//BubbleSort(arr, size);
	//InsertSort(arr, size);
	//shellSort(arr, size);
	//SelectSort(arr, size);
	//HeapSort(arr, size);
	QuickSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}