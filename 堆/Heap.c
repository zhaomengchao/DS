#include"Heap.h"


void HeapInit(Heap* hp, HPDataType* a, int n)
{
	hp->array = malloc(sizeof(HPDataType)*n);
	memcpy(hp->array, a, sizeof(HPDataType)*n);
	hp->capacity = n;
	hp->size = n;

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(hp->array, hp->size, i);
	}
}

void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

void Adjustdown(HPDataType* a, size_t n, size_t parent)
{
	size_t child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapDestory(Heap* hp)
{

		free(hp->array);
	hp->array = NULL;
	hp->capacity = hp->size == 0;
}

void Adjustup(HPDataType* a, size_t n)
{
	size_t child = n;
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
		}
		else
		{
			break;
		}
		child = parent;
		parent = (child - 1);
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->capacity == hp->size)
	{
		size_t newcapacity = hp->capacity == 0 ? 2 : hp->capacity * 2;
		hp->array = (HPDataType*)realloc(hp->array, newcapacity*sizeof(HPDataType));
		hp->capacity = newcapacity;
	}
	hp->array[hp->size] = x;
	hp->size++;

	Adjustup(hp->array, hp->size - 1);
}
void HeapPop(Heap* hp)
{
	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	Adjustdown(hp->array, hp->size, 0);
}
HPDataType HeapTop(Heap* hp)
{
	return hp->array[0];
}
int HeapSize(Heap* hp)
{
	size_t size = 0;
	for (size_t i = 0; i < hp->size; i++)
	{
		size++;
	}
	return size;
}
int HeapEmpty(Heap* hp)
{
	return hp->array[0] == 0;
}
void HeapSort(int *a,int n)//´ó¶Ñ
{
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		Adjustdown(a, end, 0);
		end--;
	}
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		Adjustdown(a, n, i);
	}
}
void Print(Heap* hp)
{
	for (size_t i = 0; i < hp->size; i++)
	{
		printf("-->%d", hp->array[i]);
	}
	printf("\n");
}


void HeapTest()
{
	Heap hp;
	int a[] = { 2, 4, 9, 6, 8, 7, 6, 1, 0 };
	int size = sizeof(a) / sizeof(int);
	HeapInit(&hp, a, size);
	Print(&hp);
	HeapPush(&hp,5);
	Print(&hp);
	HeapPop(&hp);
	Print(&hp);
	int a = HeapTop(&hp);
	printf("%d", a);
}
 
