在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
            //删除重复的节点
            if(n2 != n3)
            {
                ListNode* next = n2->next;
                free(n2);
                n2 = next;
            }
            n2=n3;
            //释放之后判断n3是否为空
            if(n3)
            {
                n3=n3->next;
            }
            }
       
           
        }
      
        return pHead;
        

    }
};

