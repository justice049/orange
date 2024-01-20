#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
Node* initList()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = L;
	return L;
}
void headInsert(Node* L, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = L->next;
	L->next = node;
	L->data++;
}
void printList(Node* L)
{
	Node* node = L->next;
	while (node!=L)
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}
void tailInit(Node* L, int data)
{
	Node* n = L;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data=data;
	while (n->next != L)
	{
		n = n->next;
	}
	node->next = L;
	n->next = node;
}
int delete(Node* L, int data)
{
	Node* preNode = L;
	Node* node = L->next;
	while (node != L)
	{
		if (node->data == data)
		{
			//delete
			preNode->next = node->next;
			free(node);
			node = NULL;
			return TRUE;
		}
		preNode = node;
		node = node->next;
	}
	return FALSE;
}
int main()
{
	Node* list = initList();
	headInsert(list, 1);
	headInsert(list, 2);
	headInsert(list, 3);
	tailInit(list, 4);
	tailInit(list, 5);
	tailInit(list, 6);
	delete(list, 4);
	printList(list);

	return 0;
}