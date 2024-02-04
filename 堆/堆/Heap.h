#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
//规定删除堆顶数据
void HeapPop(HP* php);
HPDataType* HeapTop(HP* php);
bool HeapSize(HP* php);
size_t HeapEmpty(HP* php);

