编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* cur = pHead;
        ListNode* lessHead,*lessTail;
        ListNode* bigHead,* bigTail;
        
        if(pHead == NULL)
        {
            return NULL;
        }
        lessHead = lessTail = (ListNode*)malloc(sizeof(ListNode));
        bigHead = bigTail = (ListNode*)malloc(sizeof(ListNode));
        while(cur)
        {
            if(cur->val < x)
            {
                lessTail->next = cur;
                lessTail = lessTail -> next;
            }
            else
            {
                bigTail->next = cur;
                bigTail = bigTail -> next;
            }
            cur = cur -> next;
        }
        lessTail->next = bigHead->next;
        bigTail->next = NULL;
        
        pHead = lessHead->next;
        
        free(lessHead);
        free(bigHead);
        
        return pHead;
    }
};
