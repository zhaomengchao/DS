给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]


进阶: 递归算法很简单，你可以通过迭代算法完成

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int treeSize(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    return treeSize(root->left)+treeSize(root->right)+1;
}
void _preorderTraversal(struct TreeNode* root, int* a,int* index)
{
    if(root == NULL)
    {
        return;
    }
    a[*index] = root->val;
    (*index)++;
    _preorderTraversal(root->left,a,index);
    _preorderTraversal(root->right,a,index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = treeSize(root);
    int *array =(int*)malloc((*returnSize)*sizeof(int));
    int index = 0;
    _preorderTraversal(root,array,&index);
    return array;
}


