#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//����һ����������������Ƿ��Ǿ���ԳƵġ�

���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�

    1
   / \
  2   2
 / \ / \
3  4 4  3


����������� [1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:

    1
   / \
  2   2
   \   \
   3    3



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;

bool isSametree(Node* s,Node* t)
{
    if(s == NULL && t == NULL)
    {
        return true;
    }
    if(s == NULL || t == NULL)
    {
        return false;
    }
    if(s->val != t->val)
    {
        return false;
    }
    
    return isSametree(s->left,t->right) && isSametree(s->right,t->left); 

}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL)
    {
        return true;
    }
    
    return isSametree(root->left,root->right) && isSametree(root->right,root->left);
}




