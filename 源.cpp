#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;
typedef struct StackNode
{
	TreeNode* data;
	struct StackNode* next;
}StackNode;