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




��Ŀ����
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* n1 = NULL;
        ListNode* n2 = pHead;
        ListNode* n3 = n2->next;
        if(pHead == NULL || pHead->next == NULL)
        {
            return pHead;
        }
        while(n3)
        {
            if(n2->val!= n3->val)
            {
                n1 = n2;
                n2 = n3;
                n3 = n3->next;
            }
            else
            {
                while(n3 && n3->val == n2->val)
                {
                    n3 = n3->next;
                }
                 if(n1)
                n1->next = n3;
            else
                 pHead = n3;
            //ɾ���ظ��Ľڵ�
            if(n2 != n3)
            {
                ListNode* next = n2->next;
                free(n2);
                n2 = next;
            }
            n2=n3;
            //�ͷ�֮���ж�n3�Ƿ�Ϊ��
            if(n3)
            {
                n3=n3->next;
            }
            }
       
           
        }
      
        return pHead;
        

    }
};
