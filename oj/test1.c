#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3


但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

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




