#include"List.h"

void ListInit(List* plist)
{
	assert(plist);
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;

	plist->_head = head;
}
void ListDestory(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;

	while (cur != head)
	{
		ListNode* next = cur->_next;
		free(cur);

		cur = next;
	}
}
ListNode* ByListnode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;

	return node;
}
void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = ByListnode(x);
	tail->_next = newnode;
	newnode->_prev = tail;

	head->_prev = newnode;
	newnode->_next = head;
}
void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* first = head->_next;
	ListNode* newnode = ByListnode(x);

	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = first;
	first->_prev = newnode;
}
void ListPopFront(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* first = head->_next;
	ListNode* next = first->_next;

	free(first);
	head->_next = next;
	next->_prev = head;
}
void ListPopBack(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	assert(head->_next != head);
	ListNode* tail = head->_prev;
	ListNode* prev = tail->_prev;

	free(tail);
	prev->_next = head;
	head->_prev = prev;
}

ListNode* ListFind(List* plist, LTDataType x) 
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}
	return NULL;

}
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = ByListnode(x);
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
// 删除pos位置的节点 
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	free(pos);
	prev->_next = next;
	next->_prev = prev;
}
void ListPrint(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		printf("%d<==>", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void Listtest()
{
	List plt;
	ListInit(&plt);
	ListPushBack(&plt, 1);
	ListPushBack(&plt, 5);
	ListPushBack(&plt, 2);
	ListPushBack(&plt, 6);
	ListPushBack(&plt, 3);
	ListPrint(&plt);
	ListPushFront(&plt, 7);
	ListPrint(&plt);
}