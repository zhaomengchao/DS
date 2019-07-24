#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
typedef int QUDatatype;
typedef struct QueueNOde
{
	struct QueueNOde* _next;
	QUDatatype _data;
}QueueNOde;
typedef struct Queue
{
	QueueNOde* _front;
	QueueNOde* _rear;
}Queue;

void InitQueue(Queue* pq);
void DestoryQueue(Queue* pq);
void QueuePush(Queue* pq, QUDatatype x);
void QueuePop(Queue* pq);
QueueNOde* BuyQueueNode(QUDatatype x);
QUDatatype QueueFront(Queue* pq);
QUDatatype QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void InitQueue(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
}
void DestoryQueue(Queue* pq)
{
	assert(pq);
	QueueNOde* cur = pq->_front;
	if (cur != NULL)
	{
		QueueNOde* next = cur->_next;
		free(pq->_front);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}


QueueNOde* BuyQueueNode(QUDatatype x)//建立新的节点
{
	QueueNOde* node = (QueueNOde*)malloc(sizeof(QueueNOde));
	node->_data = x;
	node->_next = NULL;
	return node;
}
void QueuePush(Queue* pq, QUDatatype x)//尾插
{
	assert(pq);
	QueueNOde* newnode = BuyQueueNode(x);
	if (pq->_rear == NULL)//说明队列为空，
	{
		pq->_front = pq->_rear = newnode;
	}
	else
	{
		pq->_rear->_next = newnode;
		pq->_rear = newnode;
	}
}
void QueuePop(Queue* pq)//头删
{
	assert(pq && pq->_front != NULL);
	QueueNOde* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;

	if (pq->_front == NULL)//队列中只有一个节点，被释放后，就为空
	{
		pq->_rear = NULL;
	}
}
QUDatatype QueueFront(Queue* pq)
{
	assert(pq && pq->_front != NULL);

	return pq->_front->_data;
}
QUDatatype QueueBack(Queue* pq)
{
	assert(pq && pq->_rear != NULL);
	return pq->_rear->_data;
}
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int n = 0;
	QueueNOde* cur = pq->_front;
	while (cur)
	{
		n = n++;
		cur = cur->_next;
	}

	return n;
}
void print(Queue* pq)
{
	QueueNOde* cur = pq->_front;
	while (cur)
	{
		printf("->%d", cur->_data);
		cur = cur->_next;
	}
}

void QueueTest()
{
	Queue pq;
	InitQueue(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePush(&pq, 5);
	print(&pq);
	printf("\n");

	int a = QueueBack(&pq);
	printf("%d\n", a);
	QueuePop(&pq);
	int c = QueueFront(&pq);
	printf("%d\n", c);
	int b = QueueSize(&pq);
	printf("%d\n", b);
	//print(&pq);


}
