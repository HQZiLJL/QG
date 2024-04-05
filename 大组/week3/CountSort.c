#include <stdio.h>
#include <stdlib.h>
#include "CountSort.h"


int temp[20] = {0};
void countSort(int arr[], int length)
{
	for (int i = 0; i < length;i++)
	{
		temp[arr[i]]++;
	}
	for (int i = 0,j=0; i <20; i++)
	{

		while (temp[i]--)
		{
			arr[j++] = i;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		temp[i] = 0;
	}
}

