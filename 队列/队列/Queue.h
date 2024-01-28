#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int QDataType;
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;
void QueueInit(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
void QueueDestroy(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);