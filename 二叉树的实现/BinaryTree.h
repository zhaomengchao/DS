#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>


typedef char BITDataType;

typedef struct BinaryTree
{
	BITDataType _data;
	struct BinaryTree* left;
	struct BinaryTree* right;
}BTNode;


BTNode* BinaryTreeCreate(char* a, int* pi);
void BinaryTreeDestory(BTNode* root);

int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);

int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BITDataType x);

// 遍历 
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

// 非递归遍历
// 层序遍历 
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
void TreeTest();