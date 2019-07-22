#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>

typedef int sltdatatype;
typedef struct SListNode//�ṹ��
{
	sltdatatype _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList//ͷ�ڵ�
{
	SListNode* head;
}Slist;


void initSlist(Slist* plt);//����ĳ�ʼ��
void Slistpushback(Slist* plt, sltdatatype x);//���
void Slistfrontback(Slist* plt, sltdatatype x);//ǰ��
void Slistpopback(Slist* plt);//��ɾ
void SlistpopFront(Slist* plt);//ǰɾ
SListNode*SListfind(Slist* plt, sltdatatype x);//���������е�ֵ
void SListinsertAfter(SListNode* pos, sltdatatype x);//��pos�����Ԫ��X
void SListRemove(Slist* plt, sltdatatype x);//�ҵ�����X��λ��ɾ����
