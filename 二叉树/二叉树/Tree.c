#include"Tree.h"
TreeNode* CreateNode(int x)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	assert(node);
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
TreeNode* CreateTree()
{
	TreeNode* node1 = CreateNode(1);
	TreeNode* node2 = CreateNode(2);
	TreeNode* node3 = CreateNode(3);
	TreeNode* node4 = CreateNode(4);
	TreeNode* node5 = CreateNode(5);
	TreeNode* node6 = CreateNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}
void PrevOrder(TreeNode* root)
{
	if (root == NULL)     //为空打印空   
	{
		printf("N ");
		return;
	}
	printf("%d ", root->data);   //先访问根
	PrevOrder(root->left);      //访问左子树
	PrevOrder(root->right);     //访问右子树
}
void InOrder(TreeNode* root)
{
	if (root == NULL)     //为空打印空   
	{
		printf("N ");
		return;
	}
	InOrder(root->left);       //访问左子树
	printf("%d ", root->data);   //访问根
	InOrder(root->right);     //访问右子树
}
