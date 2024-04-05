#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H

void print_array(int arr[], int length);
void initArr(int arr[], int length);/*
void merge_sort(int l, int r);//·¨1
void merg(int l, int r, int mid);*/
void merge(int arr[], int low, int mid, int height, int* temp);
void merge_sort(int arr[], int low, int height, int* temp);
void mergeSort(int arr[], int length);
#endif
