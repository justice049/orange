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
//����
TreeNode* CreateTree();
//ǰ�����
void PrevOrder(TreeNode* root);


