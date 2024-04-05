#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "sort.h"

clock_t start_time, end_time;
double Times1, Times5, Times20, Times100;

int main()
{
	FILE* fp = (FILE*)malloc(sizeof(FILE));//�����ļ��ռ�
	fopen_s(&fp, "Sort.txt", "w");
	if (fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}

	printf(" ���� ��  10000\t\t\t50000\t\t\t200000\t\t\t100*100k\t��s��\n");
	fprintf(fp, "���� \t��\t10000\t\t\t50000\t\t\t200000\t\t\t100*100k\t\t\t��s��\n");

	////����
	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int arr[10000];
	initArr(arr, 10000);
	insert_sort(arr, 10000);
	end_time = clock();     //��ȡ����ʱ��
	Times1 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int arr_a[50000];
	initArr(arr_a, 50000);
	insert_sort(arr_a, 50000);
	end_time = clock();     //��ȡ����ʱ��
	Times5 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int arr_b[200000];
	initArr(arr_b, 200000);
	insert_sort(arr_b, 200000);
	end_time = clock();     //��ȡ����ʱ��
	Times20 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		int arr_c[100];
		initArr(arr_c, 100);
		insert_sort(arr_c, 100);
	}
	end_time = clock();     //��ȡ����ʱ��
	Times100 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("��������%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);
	fprintf(fp, "��������%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);

	////// ����10��
	//////start_time = clock();   //��ȡ��ʼִ��ʱ��
	//////srand((unsigned int)time(NULL));
	//////int brr[10];
	//////initArr(brr, 10);
	//////print_array(brr, 10);
	//////mergeSort(brr, 10);
	//////print_array(brr, 10);
	//////end_time = clock();     //��ȡ����ʱ��
	//////Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	//////printf("�鲢������10���������µ���ʱ��%f seconds\n", Times);

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int brr[10000];
	initArr(brr, 10000);
	mergeSort(brr, 10000);
	end_time = clock();     //��ȡ����ʱ��
	Times1 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int brr_a[50000];
	initArr(brr_a, 50000);
	insert_sort(brr_a, 50000);
	end_time = clock();     //��ȡ����ʱ��
	Times5 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int brr_b[200000];
	initArr(brr_b, 200000);
	insert_sort(brr_b, 200000);
	end_time = clock();     //��ȡ����ʱ��
	Times20 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		int brr_c[100];
		initArr(brr_c, 100);
		insert_sort(brr_c, 100);
	}
	end_time = clock();     //��ȡ����ʱ��
	Times100 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("�鲢����%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);
	fprintf(fp, "�鲢����%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);
	
	////���٣��ݹ飩
	//// ����10��
	////start_time = clock();   //��ȡ��ʼִ��ʱ��
	////srand((unsigned int)time(NULL));
	////int crr[10];
	////initArr(crr, 10);
	////print_array(crr, 10);
	////quickSort(crr, 0, 9);
	////print_array(crr, 10);
	////end_time = clock();     //��ȡ����ʱ��
	////Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	////printf("����������10���������µ���ʱ��%f seconds\n", Times);

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int crr[10000];
	initArr(crr, 10000);
	quickSort(crr, 0, 9999);
	end_time = clock();     //��ȡ����ʱ��
	Times1 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int crr_a[50000];
	initArr(crr_a, 50000);
	quickSort(crr_a, 0, 49999);
	end_time = clock();     //��ȡ����ʱ��
	Times5 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int crr_b[200000];
	initArr(crr_b, 200000);
	quickSort(crr_b, 0, 199999);
	end_time = clock();     //��ȡ����ʱ��
	Times20 = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	
	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		int crr_c[100];
		initArr(crr_c, 100);
		insert_sort(crr_c, 0,99);
	}
	end_time = clock();     //��ȡ����ʱ��
	Times100 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("��������%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);
	fprintf(fp, "��������%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);

	//����
	////start_time = clock();   //��ȡ��ʼִ��ʱ��
	////srand((unsigned int)time(NULL));
	////int drr[10];
	////initArr(drr, 10);
	////print_array(drr, 10);
	////countSort(drr,10);
	////print_array(drr, 10);
	////end_time = clock();     //��ȡ����ʱ��
	////Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	////printf("����������10���������µ���ʱ��%f seconds\n", Times);

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int drr[10000];
	initArr(drr, 10000);
	countSort(drr, 10000);
	end_time = clock();     //��ȡ����ʱ��
	Times1 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int drr_a[50000];
	initArr(drr_a, 50000);
	countSort(drr_a, 50000);
	end_time = clock();     //��ȡ����ʱ��
	Times5 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int drr_b[200000];
	initArr(drr_b, 200000);
	countSort(drr_b, 200000);
	end_time = clock();     //��ȡ����ʱ��
	Times20 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		int drr_c[100];
		initArr(drr_c, 100);
		insert_sort(drr_c, 0, 99);
	}
	end_time = clock();     //��ȡ����ʱ��
	Times100 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("��������%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);
	fprintf(fp, "��������%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);

	//����
	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int err[10000];
	initArr(err, 10000);
	radixSort(err, 10000);
	end_time = clock();     //��ȡ����ʱ��
	Times1 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int err_a[50000];
	initArr(err_a, 50000);
	radixSort(err_a, 50000);
	end_time = clock();     //��ȡ����ʱ��
	Times5 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int err_b[200000];
	initArr(err_b, 200000);
	radixSort(err_b, 200000);
	end_time = clock();     //��ȡ����ʱ��
	Times20 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		int crr_c[100];
		initArr(crr_c, 100);
		insert_sort(crr_c, 0, 99);
	}
	end_time = clock();     //��ȡ����ʱ��
	Times100 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("��������%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);
	fprintf(fp, "��������%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);

	//�ر��ļ�
	fclose(fp);

	return 0;
}


int main1()
{
	FILE* fp = (FILE*)malloc(sizeof(FILE));//�����ļ��ռ�
	fopen_s(&fp, "Sort.txt", "w");
	if (fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}

	printf(" ���� ��  10000\t\t\t50000\t\t\t200000\t\t\t100*100k\t��s��\n");
	fprintf(fp, "\t\t\t ���� \t��10000\t\t\t50000\t\t\t200000\t\t\t100*100k\t\t\t��s��\n");

	////����
	start_time = clock();   //��ȡ��ʼִ��ʱ��
	srand((unsigned int)time(NULL));
	int arr[10000];
	initArr(arr, 10000);
	insert_sort(arr, 10000);
	end_time = clock();     //��ȡ����ʱ��
	Times1 = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("��������%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);
	fprintf(fp, "��������%-20f\t%-20f\t%-20f\t%-20f\n", Times1, Times5, Times20, Times100);

	//�ر��ļ�
	fclose(fp);

	return 0;
}