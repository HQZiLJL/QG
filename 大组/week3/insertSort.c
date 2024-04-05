#include <stdio.h>
#include <stdlib.h>

void initArr(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 10;
	}
}
 
//·¨1
void insert_sort(int arr[], int length)
{
	int i, j, k;
	for (i = 1; i < length; i++)
	{
		k = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > k)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1]=k;
	}
}

//·¨2
//void insert_sort(int arr[], int length)
//{
//	for (int i = 1; i < length; i++)
//	{
//		for (int j = i; j >= 1 && arr[j] < arr[j - 1]; j--)
//		{
//			int temp = arr[j];
//			arr[j] = arr[j - 1];
//			arr[j - 1] = temp;
//		}
//	}
//}

void print_array(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

