#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;
ListNode* InitList();
//����
ListNode* ListCreate(x);
// ����
void ListDestory(ListNode** ppHead);
// ��ӡ
void ListPrint(ListNode* pHead);
// β��
void ListPushBack(ListNode* pHead, LTDataType x);
// βɾ
void ListPopBack(ListNode* pHead);
// ͷ��
void ListPushFront(ListNode* pHead, LTDataType x);
// ͷɾ
void ListPopFront(ListNode* pHead);
// ����
ListNode* ListFind(ListNode* pHead, LTDataType x);
// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);