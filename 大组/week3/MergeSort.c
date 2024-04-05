#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "MergeSort.h"

//求特定数组的归并：

//int temp[10];
//int a[10];
//
//void initArr(int a[], int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		a[i] = rand() % 10;
//	}
//}
//
//
//void print_array(int arr[], int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void merge_sort(int l, int r)//分
//{
//	if (l < r)
//	{
//		int mid=l+(r-l)/2;     //可能会导致溢出：mid = (l + r) / 2;
//		merge_sort(l, mid);
//		merge_sort(mid + 1, r);
//		merg(l, r, mid + 1);
//	}
//}
//
//void merg(int l, int r, int mid)//治
//{
//	int i, j, p;
//	i = l;
//	j = mid;
//	p = l;
//	while (i < mid && j <=r)
//	{
//		if (a[i] < a[j])
//		{
//			temp[p++] = a[i++];
//		}
//		else
//		{
//			temp[p++] = a[j++];
//		}
//	}
//	while (i < mid)
//	{
//		temp[p++] = a[i++];
//	}
//	while (j <= r)
//	{
//		temp[p++] = a[j++];
//	}
//	p = l;
//	i = l;
//	while (p <= r)
//	{
//		a[i++] = temp[p++];
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	initArr(a, 10);
//	merge_sort(0, 9);
//	print_array(a, 10);
//	printf("\n");
//}

void merge(int arr[], int low, int mid, int height, int* temp)
{
	int i = low;
	int j = mid + 1;
	int k = low;
	while (i <= mid && j <= height)
		temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= height)
		temp[k++] = arr[j++];
	for (i = low; i <= height; i++)
	{
		arr[i] = temp[i];
	}
}

void merge_sort(int arr[], int low, int height,int* temp)
{
	if (low >= height)
		return;
	int mid = low + (height - low) / 2;
	merge_sort(arr, low, mid,temp);
	merge_sort(arr, mid+1, height,temp);
	merge(arr, low, mid, height, temp);
}

void mergeSort(int arr[], int length)
{
	int* temp = (int*)malloc(sizeof(int) * length);
	assert(temp);
	merge_sort(arr, 0, length - 1, temp);
	free(temp);
}

