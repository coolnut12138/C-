#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//��������
//ʱ�临�Ӷȣ����:O(n)���Ѿ�����
//			 ƽ����O(n^2)
//			 ���O(n^2)(����)
//�ȶ��ԣ��ȶ������ó������������Ƚ�С���ߴ��������������
void InsertSort(int arr[], int size)
{
	//��һ��ѡ������������ߵ�һ�����Ѿ������õڶ���������һ�������Ƚ�
	//�ڶ���������������Ѿ�����ѡ������������������������ֱȽ�
	//�Դ����ơ�����
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
//ð��
//ʱ�临�Ӷȣ�O(n^2)
void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; ++i){	//�Ƚϵ�����
		int isSorted = -1;
		for (int j = 0; j < size - i - 1; ++j){	//ÿһ�˶����һ����ֵ������������ÿһ�μ�������ֵ��һ�αȽ�
			if (arr[j] > arr[j + 1]){
				Swap(arr + j, arr + j + 1);
				isSorted = 0;	//���һ�£��������û�н�����֤���Ѿ��ź����ˣ������ٽ��к������
			}
				
		}
		if (isSorted == -1){
			break;
		}
	}
}

//ϣ�� 
//��������Խ�������Ч��Խ�������
//ʱ�临�Ӷȣ���ã�O(n) ƽ����O(n^1.3) �O(n^2)
//���ȶ���û����֤��ͬ��������һ���ڣ�
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

//ѡ������
//ʱ�临�Ӷȣ�O(n^2)
void SelectSort(int arr[], int size)
{
	for (int i = 0; i < size; i++){
		int max = 0;
		for (int j = 1; j < size - i; j++){
			if (arr[j] > arr[max]){
				max = j;
			}
		}
		Swap(arr + max, arr + size - i - 1);	//���Σ�ÿһ��ѡ�����ֵ�ŵ���ǰԪ�ظ��������
	}
}

//������
//�����򣬽���ѣ�ÿ��ȡ�Ѷ�Ԫ��������һ��Ԫ�ؽ��н�����Ȼ��ӶѶ�Ԫ�����µ���
//ʱ�临�Ӷȣ�O(nlogn)
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

//����
//ʱ�临�Ӷȣ�Partition��ʱ�临�Ӷ��� O(n),
//			 ���ŵ�ʱ�临�Ӷ���O(n*�������߶�)���������߶������logn�������n��
//			 ���Կ��ŵ�ʱ�临�Ӷ������O(n*logn),���O(n^2)
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

//�ڿӷ�
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

//ǰ���±�
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

#include <stack>
//���ŷǵݹ�(ѭ��+ջʵ��)
void QuickSortNor(int arr[], int size)
{
	stack<int> st;
	//���������������ѹ��ջ����ѹ�ұߣ���ѹ��ߣ�����ȡ��ʱ�����ȡ������ߣ�������ľ������
	st.push(size - 1);
	st.push(0);
	while (!st.empty()){
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();
		if (left >= right){
			continue;	//left >= right����������ֻ��һ������û�����ˣ��Ͳ�����������
		}
		else{
			//�������֣�������ӻ�׼ֵλ�û���Ϊ�������䣬�Ȼ�׼ֵ��ĺͱȻ�׼ֵС��
			int div = Partition_1(arr, left, right);
			st.push(right);
			st.push(div + 1);
			st.push(div - 1);
			st.push(left);
		}
	}
}

//�鲢����(֧���ⲿ����)
void Merge(int arr[], int left, int mid, int right, int extra[])
{
	int size = right - left;
	int left_index = left;
	int right_index = mid;
	int extra_index = 0;
	while (left_index < mid && right_index < right){
		if (arr[left_index] < arr[right_index]){
			extra[extra_index] = arr[left_index];
			left_index++;
		}
		else{
			extra[extra_index] = arr[right_index];
			right_index++;
		}
		extra_index++;
	}
	while (left_index < mid){
		extra[extra_index++] = arr[left_index++];
	}
	while (right_index < right){
		extra[extra_index++] = arr[right_index++];
	}

	for (int i = 0; i < size; i++){
		arr[left + i] = extra[i];
	}
}

void _MergeSort(int arr[], int left, int right, int extra[])
{
	if (left + 1 == right){
		return;
	}

	if (left >= right){
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
int main()
{
	int arr[] = { 3, 6, 2, 63, 4, 8, 3, 7, 9, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	//BubbleSort(arr, size);
	//InsertSort(arr, size);
	//shellSort(arr, size);
	//SelectSort(arr, size);
	//HeapSort(arr, size);
	//QuickSort(arr, size);
	//QuickSortNor(arr, size);
	MergeSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}