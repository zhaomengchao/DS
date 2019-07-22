#define _CRT_SECURE_NO_WARNINGS 1
#include"Lish.h"

void initSlist(Slist* plt)//初始化链表
{
	assert(plt);
	plt->head = NULL;
}


void Slistpushback(Slist* plt, sltdatatype x)//尾插法插入数据到链表
{
	assert(plt);
	SListNode *newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	if (plt->head == NULL)
	{
		plt->head = newnode;
	}
	else
	{
		SListNode *cur = plt->head;
		
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}
void Slistfrontback(Slist* plt, sltdatatype x)//头插法插入数据元素
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	newnode->_next = plt->head;
	plt->head = newnode;
}
void Slistpopback(Slist* plt)//尾删
{
	assert(plt);
	SListNode *cur = plt->head;
	if (cur == NULL)
	{
		return;
	}
	else if (cur->_next == NULL)
	{
		free(cur);
		plt->head = NULL;
	}
	else
	{
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}
}
void SlistpopFront(Slist* plt)
{
	assert(plt);
	SListNode *cur = plt->head;
	if (plt->head == NULL)
	{
		return;
	}
	else
	{
		plt->head = cur->_next;
		free(cur);
		cur = NULL;
	}
}
SListNode* SListfind(Slist* plt, sltdatatype x)
{
	assert(plt);
	SListNode* cur = plt->head;
	while (cur != NULL)
	{
		if (cur->_data == x)
			{
				return cur;
			}
			cur = cur->_next;
	}
	return NULL;
}
void SListinsertAfter(SListNode* pos, sltdatatype x)
{
	assert(pos); 
	SListNode*  newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_next = pos->_next;
	pos->_next = newnode;
}
void SListRemove(Slist* plt, sltdatatype x)//找到并删除
{
	assert(plt);
	SListNode* prev = NULL;
	SListNode* cur = plt->head;
	while (cur!= NULL)
	{
		if (cur->_data == x)
		{
			if (prev == NULL)
			{
				plt->head = cur->_next;
			}
			else
			{
				prev->_next = cur->_next;
			}
			free(cur);
			cur = NULL;
			return;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}

}

void PrintSList(Slist* plt)
{
	assert(plt);
	SListNode* cur = plt->head;
	while (cur != NULL)
	{
		printf("--%d", cur->_data);
		cur = cur->_next;
	}
	printf("--NULL\n");
}

void testSlist()
{
	Slist lt;
	initSlist(&lt);
	Slistpushback(&lt, 1);
	Slistpushback(&lt, 2);
	Slistpushback(&lt, 3);
	Slistpushback(&lt, 5);
	Slistpushback(&lt, 6);
	Slistfrontback(&lt, 0);
	PrintSList(&lt);
	Slistpopback(&lt);
	SlistpopFront(&lt);
	PrintSList(&lt);
	SListRemove(&lt, 3);
	PrintSList(&lt);
}

