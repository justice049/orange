#include<stdio.h>

int Sum(int top)
{
	int i = 1;
	int ret = 0;
	for (; i <= top; i++)
	{
		ret += i;
	}
	return ret;
}

int main()
{
	int top = 100;
	int result = Sum(top);

	printf("result:%d\n", result);
	return 0;
}