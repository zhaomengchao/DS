对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。 
给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。 
测试样例： 
1->2->2->1
返回：true
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
//链表的逆置，取节点头插思想
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    while(cur)
    {
        struct ListNode* next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        //首先遍历链表，算出它的链表长度
        int n = 0;
        struct ListNode* cur = A;
        while(cur)
        {
            cur = cur->next;
            n++;
        }
        cur = A;
        int mid = n/2;
        while(mid--)
        {
            cur = cur ->next;
        }
        ListNode* head = A;
        ListNode*pHead = reverseList(cur);
        mid = n/2;//尤其注意如果缺少此处会产生越界，或者空间占用过大。
        while(mid--)
        {
            if(head->val == pHead->val)
            {
                head = head->next;
                pHead = pHead->next;
            }
            else
            {
               return false;
            }
          
            
        }
         return true;
    }
};
