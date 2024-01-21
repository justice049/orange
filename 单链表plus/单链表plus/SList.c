#include"SList.h"
void SLprint(SLNode* head)
{
	SLNode* cur = head;
	if (cur == NULL)
	{
		printf("NULL\n");
		return;
	}
	while (cur->next != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("%d->NULL\n", cur->val);
}
SLNode* CreateNode(SLNDataType x)
{
	SLNode* newNode=(SLNode*)malloc(sizeof(SLNDataType));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newNode->val = x;
	newNode->next = NULL;
	return newNode;
}

void SLPushBack(SLNode** pphead, SLNDataType x)
{
	SLNode* newNode = CreateNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;  //改变结构体的指针，用二级指针
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;   
		}
		tail->next = newNode;   //改变结构体，用结构体指针
	}
}
void SLPushFront(SLNode** pphead, SLNDataType x)
{
	SLNode* newNode = CreateNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}
void SLPopBack(SLNode** pphead)
{
	if ((*pphead) == NULL)
	{
		return;
	}
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SLNode* prev = NULL;
	SLNode* tail = *pphead;
	while (tail->next!=NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	tail = NULL;
	prev->next = NULL;
}
void SLPopBackplus(SLNode** pphead)
{
	if ((*pphead) == NULL)
	{
		return;
	}
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SLNode* tail = *pphead;
	while (tail->next->next != NULL)
	{
		tail = tail->next;
	}
	free(tail->next);
	tail->next = NULL;
}
void SLPopFront(SLNode** pphead)
{
	if (*(pphead) == NULL)
	{
		return;
	}
	SLNode* newhead = (*pphead)->next;
	free(*pphead);
	*pphead = newhead;
	return;
}
SLNode* SLFind(SLNode* phead,SLNDataType x)
{

	while (phead != NULL&&phead->val != x)
	{
		phead = phead->next;
	}
	if (phead == NULL)
	{
		printf("查找失败\n");
		return NULL;
	}
	else
	{
		printf("查找成功\n");
		return phead;
	}
}
void SLInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	if (*pphead == pos)
	{
		SLNode* newNode = CreateNode(x);
		newNode->next = *pphead;
		*pphead = newNode;
		return;
	}
	SLNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	SLNode* newNode = CreateNode(x);
	newNode->next = pos;
	prev->next = newNode;
}
void SLErase(SLNode** pphead, SLNode* pos)
{
	if (pos == NULL)
	{
		return;
	}
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
		pos = NULL;
		return;
	}
	SLNode* del = *pphead;
	while (del->next!=pos)
	{
		del = del->next;
	}
	del->next = pos->next;
	free(pos);
	pos = NULL;
	return;
}
void SLDestroy(SLNode** pphead)
{
	SLNode* des=(*pphead)->next;
	while (des&&*pphead)
	{
		free(*pphead);
		*pphead = des;
		des = des->next;
	}
	free(*pphead);
	*pphead = NULL;
	return;
}