#include"SList.h"
void Test1()
{
	SLNode* s1=NULL;
	SLPushBack(&s1,1);
	SLPushBack(&s1,2);
	SLPushBack(&s1,3);
	SLPushBack(&s1,4);
	SLprint(s1);
	return;
}
void Test2()
{
	SLNode* s1 = NULL;
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 2);
	SLPushFront(&s1, 3);
	SLPushFront(&s1, 4);
	SLprint(s1);
	return;
}
void Test3()
{
	SLNode* s1 = NULL;
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 2);
	SLPushFront(&s1, 3);
	SLPushFront(&s1, 4);
	SLprint(s1);
	SLPopBack(&s1);
	SLprint(s1);
	SLPopBack(&s1);
	SLprint(s1);
	SLPopBack(&s1);
	SLprint(s1);
	SLPopBack(&s1);
	SLprint(s1);
	SLPopBack(&s1);
	SLprint(s1);
	return;
}
void Test4()
{
	SLNode* s1 = NULL;
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 2);
	SLPushFront(&s1, 3);
	SLPushFront(&s1, 4);
	SLprint(s1);
	SLPopBackplus(&s1);
	SLprint(s1);
	SLPopBackplus(&s1);
	SLprint(s1);
	SLPopBackplus(&s1);
	SLprint(s1);
	SLPopBackplus(&s1);
	SLprint(s1);
	SLPopBackplus(&s1);
	SLprint(s1);
	return;
}
void Test5()
{
	SLNode* s1 = NULL;
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 2);
	SLPushFront(&s1, 3);
	SLPushFront(&s1, 4);
	SLprint(s1);
	SLPopFront(&s1);
	SLprint(s1);
	SLPopFront(&s1);
	SLprint(s1);
	SLPopFront(&s1);
	SLprint(s1);
	SLPopFront(&s1);
	SLprint(s1);
	SLPopFront(&s1);
	SLprint(s1);
	return;
}
void Test6()
{
	SLNode* s1 = NULL;
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLprint(s1);
	SLFind(s1, 1);
	SLFind(s1, 5);
	SLFind(s1, 9);
	SLFind(s1, 4);
	return;
}
void Test7()
{
	SLNode* s1 = NULL;
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLprint(s1);
	SLNode* a = SLFind(s1, 1);
	SLInsert(&s1, a , 9);
	SLprint(s1);
	SLNode* b=SLFind(s1, 4);
	SLInsert(&s1, b, 8);
	SLprint(s1);
	return;
}
void Test8()
{
	SLNode* s1 = NULL;
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLprint(s1);
	SLNode* a = SLFind(s1,0 );
	SLErase(&s1, a);
	SLprint(s1);
	SLNode* d = SLFind(s1, 2);
	SLErase(&s1, d);
	SLprint(s1);
	SLNode* b = SLFind(s1, 4);
	SLErase(&s1, b);
	SLprint(s1);
	return;
}
void Test9()
{
	SLNode* s1 = NULL;
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLprint(s1);
	SLDestroy(&s1);
	SLprint(s1);
	return;
}
int main()
{
	Test9();
	return 0;
}