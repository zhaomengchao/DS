

//
//输入一个链表，输出该链表中倒数第k个结点。
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



//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/merge-two-sorted-lists
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
	//找头
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
	tail = head;//头尾同节点
	while (l1 != NULL && l2 != NULL)//尾插
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
