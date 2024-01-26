#include"List.h"
ListNode* ListCreate(x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
ListNode* InitList()
{
	ListNode* phead = ListCreate(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* tail = pHead->prev;
	ListNode* newNode = ListCreate(x);
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = pHead;
	pHead->prev = newNode;
}
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	printf("ÉÚ±øÎ» ");
	while (cur!=pHead)
	{
		printf("%d <-> ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	return;
}
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListNode* tail = pHead->prev;
	pHead->prev = tail->prev;
	tail->prev->next = pHead;
	free(tail);
	tail = NULL;
	return;
}
void ListDestory(ListNode** pHead)
{
	assert(pHead);
	ListNode* cur = (*pHead)->next;
	while (cur!=*pHead)
	{
		ListNode* del = cur;
		cur = cur->next;
		free(del);	
	}
	free(*pHead);
	*pHead = NULL;
	return;
}
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* head = pHead;
	ListNode* newNode = ListCreate(x);
	newNode->next = pHead->next;
	pHead->next->prev = newNode;
	pHead->next = newNode;
	newNode->prev = pHead;
}
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListNode* cur = pHead->next;
	pHead->next = pHead->next->next;
	cur->next->prev = cur->prev;
	free(cur);
	cur = NULL;
}
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	printf("Ã»ÕÒµ½°¡Å¶\n");
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* pre= pos->prev;
	ListNode* newNode = ListCreate(x);
	newNode->next = pos;
	pos->prev = newNode;
	pre->next = newNode;
	newNode->prev = pre;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* pre = pos->prev;
	ListNode* next = pos->next;
	pre->next = pos->next;
	next->prev = pre;
	free(pos);
	pos = NULL;
}