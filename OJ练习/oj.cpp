

//
//����һ����������������е�����k����㡣
///*
//struct ListNode {
//int val;
//struct ListNode *next;
//ListNode(int x) :
//val(x), next(NULL) {
//}
//};*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* slow = pListHead;
		ListNode* fast = pListHead;
		if (pListHead == NULL)
		{
			return NULL;
		}
		while (k--)
		{
			if (fast)
				fast = fast->next;
			else
				return NULL;
		}
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;

	}
};



//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//
//ʾ����
//
//���룺1->2->4, 1->3->4
//�����1->1->2->3->4->4
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/merge-two-sorted-lists
///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     struct ListNode *next;
//* };
//*/


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;

	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	//��ͷ
	if (l1->val < l2->val)
	{
		head = l1;
		l1 = l1->next;

	}
	else
	{
		head = l2;
		l2 = l2->next;
	}
	tail = head;//ͷβͬ�ڵ�
	while (l1 != NULL && l2 != NULL)//β��
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1 != NULL)
	{
		tail->next = l1;
	}
	if (l2 != NULL)
	{
		tail->next = l2;
	}
	return head;
}
