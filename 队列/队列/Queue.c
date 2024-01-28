#include"Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail=NULL;
	pq->size = 0;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
	}
	newNode->val = x;
	newNode->next = NULL;
	if (pq->ptail == NULL)
	{
		pq->phead= pq->ptail = newNode;
	}
	else
	{
		pq->ptail->next = newNode;
		pq->ptail = newNode;
	}
	pq->size++;
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size > 0);
	QNode* del = pq->phead;
	pq->phead = pq->phead->next;
	free(del);
	del = NULL;
	if (pq->phead == NULL)
	{
		pq->ptail = NULL;   //·ÀÖ¹ptail³ÉÎªÒ°Ö¸Õë
	}
	pq->size--;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->size = 0;
	pq->phead = pq->ptail = NULL;
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}