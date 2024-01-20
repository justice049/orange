#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
Node* initStack()
{
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = 0;
	s->next = NULL;
	return s;
}
int isempty(Node* s)
{
	if (s->data == 0 || s->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int getpop(Node* s)
{
	if (isempty(s))
	{
		return -1;
	}
	else
	{
		return s->next->data;
	}
}
int pop(Node* s)
{
	if (isempty(s))
	{
		return -1;
	}
	else
	{
		Node* node = s->next;
		int data = node->data;
		s->next = node->next;
		free(node);
		node = NULL;
		return data;

	}
}
void push(Node* s, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = s->next;
	s->next = node;
	s->data++;
}
void printstack(Node* s)
{
	Node* node = s->next;
	while (node)
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* s = initStack();
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	printstack(s);
	pop(s);
	printstack(s);
	return 0;
}