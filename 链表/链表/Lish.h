#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>

typedef int sltdatatype;
typedef struct SListNode//结构体
{
	sltdatatype _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList//头节点
{
	SListNode* head;
}Slist;


void initSlist(Slist* plt);//链表的初始化
void Slistpushback(Slist* plt, sltdatatype x);//后插
void Slistfrontback(Slist* plt, sltdatatype x);//前插
void Slistpopback(Slist* plt);//后删
void SlistpopFront(Slist* plt);//前删
SListNode*SListfind(Slist* plt, sltdatatype x);//查找链表中的值
void SListinsertAfter(SListNode* pos, sltdatatype x);//在pos后插入元素X
void SListRemove(Slist* plt, sltdatatype x);//找到等于X的位置删除它
