����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

�����У�һ�ø߶�ƽ�����������Ϊ��


һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��


ʾ�� 1:

���������� [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7

���� true ��

ʾ�� 2:

���������� [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4


���� false

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int isHightTree(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftHeigh = isHightTree(root->left);
    int rightHeigh = isHightTree(root->right);
    
    return leftHeigh > rightHeigh ? leftHeigh+1 : rightHeigh+1;
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL)
    {
        return true;
    }
    int leftHeigh = isHightTree(root->left);
    int rightHeigh = isHightTree(root->right);
    
   
    return abs(rightHeigh - leftHeigh) < 2 && isBalanced(root->left) && isBalanced(root->right);
}

