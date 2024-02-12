#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}TreeNode;
//创建
TreeNode* CreateTree();
//前序遍历
void PrevOrder(TreeNode* root);


