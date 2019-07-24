#include"BinaryTree.h"


BTNode* BinaryTreeCreate(char* a, int* pi)
{
	if (a[*pi] =='#')
	{
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));

	root->_data = a[*pi];
	(*pi)++;

	root->left = BinaryTreeCreate(a, pi);
	(*pi)++;

	root->right = BinaryTreeCreate(a, pi);

	return root;

}
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);

	free(root);

	root = NULL;
}

void BinaryTreePrevOrder(BTNode* root)//前序遍历
{
	if (root == NULL)
	{
		return;
	}
	
	printf("%c ", root->_data);

	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
void BinaryTreeInOrder(BTNode* root)//中序遍历
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreeInOrder(root->left);

	printf("%c ", root->_data);

	BinaryTreeInOrder(root->right);
}
void BinaryTreePostOrder(BTNode* root)//后序遍历
{
	if (root == NULL)
	{
		return;
	}
	
	BinaryTreePostOrder(root->left);

	BinaryTreePostOrder(root->right);

	printf("%c ", root->_data);
}


int BinaryTreeSize(BTNode* root)//二叉树的节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	int leftsize = BinaryTreeSize(root->left);
	int rightsize = BinaryTreeSize(root->right);

	return leftsize + rightsize + 1;

}
int BinaryTreeLeafSize(BTNode* root)//二叉树叶子节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	//判断左右子树，当节点的下一个为空时，即为叶子节点，记为1
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	//遍历左右子树
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}


int BinaryTreeLevelKSize(BTNode* root, int k)//第k层节点的个数
{
	if (root == NULL)
	{
		return 0;
	}
	//根节点不为空时，k == 1 时，返回1；第一层最多有一个节点
	//到第k层，k 为0，递归结束。
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BITDataType x)//找值为x的结点
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* lcur = BinaryTreeFind(root->left, x);
	if (lcur != NULL)
	{
		return root;
	}
	BTNode* rcur = BinaryTreeFind(root->right, x);
	if (rcur != NULL)
	{
		return root;
	}
	return NULL;
}
#include"Queue.h"
void BinaryTreeLevelOrder(BTNode* root)// 层序遍历
{
	if (root == NULL)
	{
		return;
	}
	Queue pq;
	InitQueue(&pq);
	QueuePush(&pq, root);
	while(!QueueEmpty(&pq))
	{
		BTNode* r = QueueFront(&pq);
		QueuePop(&pq);
		printf("%c ", r->_data);
		if (r->left != NULL)
		{
			QueuePush(&pq, r->left);
		}
		if (r->right != NULL)
		{
			QueuePush(&pq, r->right);
		}
	}//切记一定要接受队头返回的值，通过返回的节点，再去遍历左右子树	
}
//判断树不是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	if (root->left == NULL && root->right != NULL)
	{
		return 0;
	}
	if (root->left != NULL && root->right == NULL)
	{
		return 1;
	
	}
	return BinaryTreeComplete(root->left) && BinaryTreeComplete(root->right);

	
	

}

void TreeTest()
{
	char arr[] = "ABD##E##C##";
	int index = 0;
	BTNode* root = NULL;
	root = BinaryTreeCreate(arr, &index);
	printf("前序遍历：");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("中序遍历：");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("后序遍历：");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("二叉树的节点个数：");
	int i = BinaryTreeSize(root);
	printf("%d ", i);
	printf("\n");
	printf("二叉树的叶节点个数：");
	int j = BinaryTreeLeafSize(root);
	printf("%d ", j);
	printf("\n");
	printf("第K层节点个数：");
	int k = BinaryTreeLevelKSize(root, 2);
	printf("%d ", k);
	BTNode* node =  BinaryTreeFind(root, 'B');
	printf("\n");

	printf("层序遍历：");
	BinaryTreeLevelOrder(root);
	printf("\n");

	printf("判断是否为完全二叉树：");
	int m = BinaryTreeComplete(root);
	printf("%d", m);
}