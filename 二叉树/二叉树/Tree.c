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
	if (root == NULL)     //Ϊ�մ�ӡ��   
	{
		printf("N ");
		return;
	}
	printf("%d ", root->data);   //�ȷ��ʸ�
	PrevOrder(root->left);      //����������
	PrevOrder(root->right);     //����������
}
void InOrder(TreeNode* root)
{
	if (root == NULL)     //Ϊ�մ�ӡ��   
	{
		printf("N ");
		return;
	}
	InOrder(root->left);       //����������
	printf("%d ", root->data);   //���ʸ�
	InOrder(root->right);     //����������
}
