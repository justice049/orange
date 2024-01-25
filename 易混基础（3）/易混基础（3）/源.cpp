（1）
#include <stdio.h>
#define a 10
void foo();
int main()
{
	printf("%d..", a);
	foo();
	printf("%d", a);
	return 0;
} 
void foo() 
{
  #undef a
  #define a 50
}
输出结果：error


（2）
void Func(int N) 
{
	int count = 0;
	for (int k = 0; k < 2 * N * N; ++k) 
	{
		++count;
	} 
	int M = 10;
	while (M--) 
	{
		++count;
	}
	printf("%d\n", count);
}
时间复杂度：O（N）


（3）
int func(unsigned int n) 
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * func(n - 1);
}
时间复杂度：O（N）


（4）
void fun(int n) 
{
	int i = l;
	while (i <= n) 
	{
		i = i * 2;
	}
}
时间复杂度：O（logN）
