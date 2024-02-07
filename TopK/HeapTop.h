#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>​
typedef int HPDataType;
void Swap(HPDataType* x, HPDataType* y);
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int size, int parent);
void CreateDate();
void PrintTopK(const char* file, int k);
