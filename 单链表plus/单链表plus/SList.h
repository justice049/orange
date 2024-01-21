#pragma once
#include<stdio.h>
#include<stdlib.h>
//single list
typedef int SLNDataType;
typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
}SLNode;
void SLprint(SLNode* head);

void SLPushFront(SLNode** pphead, SLNDataType x);
void SLPushBack(SLNode** pphead, SLNDataType x);

void SLPopBack(SLNode** pphead);
void SLPopBackplus(SLNode** pphead);
void SLPopFront(SLNode** pphead);

SLNode* SLFind(SLNode* phead,SLNDataType x);

//��posǰ����
void SLInsert(SLNode** pphead,SLNode* pos, SLNDataType x);
//ɾ��posλ��
void SLErase(SLNode** pphead,SLNode* pos);

void SLDestroy(SLNode** pphead);