#include"Stack.h"
int main()
{
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	STPush(&s, 4);
	STPush(&s, 5);
	printf("%d\n", STSize(&s));
	while (!STEmpty(&s))
	{
		printf("%d ", STTop(&s));
		STPop(&s);
	}
	//һ����ջ˳���Ӧ���ֳ�ջ˳��
	printf("\n%d\n", STSize(&s));
	STDestroy(&s);
	return 0;
}