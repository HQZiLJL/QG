#include <stdio.h>
#include <stdlib.h>
#include "QuickSort_Recursion.h"

void quickSort(int arr[], int left, int right)
{
	if (left >= right)return;
	int i = left;
	int j = right;
	int pivot = arr[i];
	while (i < j)
	{
		while (i < j && arr[j] >= pivot)j--;
		arr[i] = arr[j];
		while (i < j && arr[i] <= pivot)i++;
		arr[j] = arr[i];
	}
	arr[i] = pivot;
	quickSort(arr, left, i - 1);
	quickSort(arr, i+1, right);
}

