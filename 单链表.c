#include<stdio.h>
#include<stdlib.h>
//定义单链表
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
//初始化
Node* initList()
{
	Node* list = (Node*)malloc(sizeof(Node));
	list->data = 0;
	list->next = NULL;
	return list;
}
//头插
void headInsert(Node* list, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = list->next;
	list->next = node;
	list->data++;
}
//尾插
void tailInsert(Node* list, int data)
{
	Node* head = list;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	list = list->next;
	while (list->next)
	{
		list = list->next;
	}
	list->next = node;
	head->data++;
}
//删除
void delete(Node* list, int data)
{
	Node* pre = list;
	Node* current = list->next;
	while (current)
	{
		if (current->data == data)
		{
			pre->next = current->next;
			free(current);
			current = NULL;
			break;
		}
		pre = current;
		current = current->next;
	}
	list->data--;
}
//遍历
void PrintList(Node* list)
{
	list = list->next;
	while (list)
	{
		printf("%d", list->data);
		list = list->next;
	}
	printf("\n");
}
Node* ReverseList(Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		Node* new = head;
 		Node* pre = head;
		while (new->next != NULL)
		{
			new = new->next;
		}
		Node* new1 = new;
		for (int i = 0; i < head->data - 1; i++)
		{
			while (pre->next != new)
			{
				pre = pre->next;
			}
			new->next = pre;
			new = pre;
			pre = head;
		}
		new->next = NULL;
		head->next = NULL;
		pre->next = NULL;
		pre->data = head->data;
		Node* new2 = malloc(sizeof(Node));
		new2->data = head->data;
		new2->next = new1;
		return new2;
	}
}
int main()
{
	Node* list = initList();
	headInsert(list, 1);
	headInsert(list, 2);
	headInsert(list, 3);
	headInsert(list, 4);
	PrintList(list);
	Node* p=ReverseList(list);
	PrintList(p);
}