��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱�
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
