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

void BinaryTreePrevOrder(BTNode* root)//ǰ�����
{
	if (root == NULL)
	{
		return;
	}
	
	printf("%c ", root->_data);

	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
void BinaryTreeInOrder(BTNode* root)//�������
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreeInOrder(root->left);

	printf("%c ", root->_data);

	BinaryTreeInOrder(root->right);
}
void BinaryTreePostOrder(BTNode* root)//�������
{
	if (root == NULL)
	{
		return;
	}
	
	BinaryTreePostOrder(root->left);

	BinaryTreePostOrder(root->right);

	printf("%c ", root->_data);
}


int BinaryTreeSize(BTNode* root)//�������Ľڵ����
{
	if (root == NULL)
	{
		return 0;
	}
	int leftsize = BinaryTreeSize(root->left);
	int rightsize = BinaryTreeSize(root->right);

	return leftsize + rightsize + 1;

}
int BinaryTreeLeafSize(BTNode* root)//������Ҷ�ӽڵ����
{
	if (root == NULL)
	{
		return 0;
	}
	//�ж��������������ڵ����һ��Ϊ��ʱ����ΪҶ�ӽڵ㣬��Ϊ1
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	//������������
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}


int BinaryTreeLevelKSize(BTNode* root, int k)//��k��ڵ�ĸ���
{
	if (root == NULL)
	{
		return 0;
	}
	//���ڵ㲻Ϊ��ʱ��k == 1 ʱ������1����һ�������һ���ڵ�
	//����k�㣬k Ϊ0���ݹ������
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BITDataType x)//��ֵΪx�Ľ��
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
void BinaryTreeLevelOrder(BTNode* root)// �������
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
	}//�м�һ��Ҫ���ܶ�ͷ���ص�ֵ��ͨ�����صĽڵ㣬��ȥ������������	
}
//�ж���������ȫ������
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
	printf("ǰ�������");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("���������");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("���������");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("�������Ľڵ������");
	int i = BinaryTreeSize(root);
	printf("%d ", i);
	printf("\n");
	printf("��������Ҷ�ڵ������");
	int j = BinaryTreeLeafSize(root);
	printf("%d ", j);
	printf("\n");
	printf("��K��ڵ������");
	int k = BinaryTreeLevelKSize(root, 2);
	printf("%d ", k);
	BTNode* node =  BinaryTreeFind(root, 'B');
	printf("\n");

	printf("���������");
	BinaryTreeLevelOrder(root);
	printf("\n");

	printf("�ж��Ƿ�Ϊ��ȫ��������");
	int m = BinaryTreeComplete(root);
	printf("%d", m);
}