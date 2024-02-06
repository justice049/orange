#pragma once
#include<stdio.h>
typedef int HPDataType;
void AdjustDown(HPDataType* a, int size, int parent);
void Swap(HPDataType* x, HPDataType* y);
void AdjustUp(HPDataType* a, int child);
void Heapsort(HPDataType* a, int n);
