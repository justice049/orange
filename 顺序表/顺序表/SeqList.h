#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	SLDataType size;      //有效数据个数
	SLDataType capacity;  //有效容量
}SL;
void Init(SL* psl);
void SLDestroy(SL* psl);
void SLPushBack(SL* psl, SLDataType x);
void SLPushFront(SL* psl, SLDataType x);
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);
void SLPrint(SL* psl);
void checkcapacity(SL* psl);
void SLInsert(SL* psl, int pos, SLDataType x);
void SLErase(SL* psl, int pos);
int SLFind(SL* psl,SLDataType x);