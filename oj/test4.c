������������������дһ�����������������Ƿ���ͬ��

����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

ʾ�� 1:

����:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

���: true

ʾ�� 2:

����:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

���: false


ʾ�� 3:

����:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

���: false 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL)
    {
        return true;
    }
    if(p == NULL || q == NULL)
    {
        return false;
    }
    if(p->val != q->val)
    {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    
}



