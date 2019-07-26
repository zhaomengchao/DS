#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* array;
	size_t size;
	size_t capacity;
}Heap;
void Adjustdown(HPDataType* a, size_t n, size_t parent);
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
void HeapSort(int *a, int n);
void HeapTest();