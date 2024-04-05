#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "RadixCountSort.h"


int Temp[10][200001];

void radixSort(int arr[], int length)
{
	int i;
	int j; 
	int pos;
	for (long k = 10; k < 101; k *= 10)
	{
		for (i = 0; i < length; i++)
		{
			j = 0;
			pos = (arr[i] % k) / (k / 10);
			while (Temp[pos][j])j++;
			Temp[pos][j] = arr[i];
		}
		pos = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < length && Temp[i][j] != 0; j++)
			{
					arr[pos++] = Temp[i][j];
					Temp[i][j] = 0;
			}
		}
	}
}


