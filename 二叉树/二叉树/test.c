#include"Tree.h"
void Test1()
{
	TreeNode* root = CreateTree();
	PrevOrder(root);
}
void Test2()
{
	TreeNode* root = CreateTree();
	InOrder(root);
}
int main()
{
	Test2();
	return;
}