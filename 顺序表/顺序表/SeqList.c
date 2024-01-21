#include"SeqList.h"
void Init(SL* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->capacity = 0;
	psl->size = 0;
}
void SLDestroy(SL* psl)
{
	assert(psl);
	if (psl->a != NULL)
	{
		free(psl->a);
		psl->a = NULL;
		psl->size = 0;
		psl->capacity = 0;
	}
}
void checkcapacity(SL* psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		int newcapcity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * newcapcity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity = newcapcity;
	}
}
void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);
	checkcapacity(psl);
	psl->a[psl->size] = x;
	psl->size++;
}
void SLPushFront(SL* psl, SLDataType x)
{
	assert(psl);
	checkcapacity(psl);
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->a[end+1] = psl->a[end];
		end--;
	}
	psl->a[0] = x;
	psl->size++;
}
void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}
void SLPopBack(SL* psl)
{
	assert(psl);
    assert(psl->size>0);
	psl->size--;  //不能free
}
void SLPopFront(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	int begin = 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		begin++;
	}
	psl->size--;
}
void SLInsert(SL* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);
	checkcapacity(psl);
	int end = psl->size - 1;
	while (end >= pos)
	{
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[pos] = x;
	psl->size++;
}
void SLErase(SL* psl, int pos)
{
	assert(psl);
	assert(pos >= 0 && pos < psl->size);
	int begin = pos + 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		begin++;
	}
	psl->size--;
}
int SLFind(SL* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
//free或者realloc报错通常都是越界
//越界一定会报错吗？？
//越界读通常不会报错
//越界写可能会报错（不同编译器对越界的检查也不同）
//越界检查是抽查
