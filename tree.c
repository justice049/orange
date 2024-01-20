#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;
void createTree(TreeNode** T)
{
	char data;
	scanf("%c\n", &data);
	if (data == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data = data;
		createTree(&((*T)->lchild));
		createTree(&((*T)->rchild));
	}
}
void preOrder(TreeNode* T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
void inOrder(TreeNode* T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		inOrder(T->lchild);
		printf("%c", T->data);
		inOrder(T->rchild);
	}
}
void postOrder(TreeNode* T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c", T->data);
	}
}
int main()
{
	TreeNode* T;
	createTree(&T);
	preOrder(T);
	printf("\n");
	inOrder(T);
	printf("\n");
	postOrder(T);
	return 0;
}