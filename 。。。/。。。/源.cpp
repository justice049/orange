#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//int main()
//{
//	int T;
//	int n;
//	char c;
//	scanf("%d", &T);
//	while (T)
//	{
//		scanf("%d %c", &n, &c);
//		if (n == 1 || n == 2)
//		{
//			if (c == 'W')
//			{
//				printf("east is anti-fan\n");
//			}
//			else if(c=='E')
//			{
//				printf("west is anti-fan\n");
//			}
//		}
//		else
//		{
//			if (n % 2 == 0)
//			{
//				if (c == 'W')
//				{
//					printf("east is anti-fan\n");
//				}
//				else if (c == 'E')
//				{
//					printf("west is anti-fan\n");
//				}
//			}
//			else
//			{
//				if (c == 'W')
//				{
//					printf("west is anti-fan\n");
//				}
//				else if (c == 'E')
//				{
//					printf("east is anti-fan\n");
//				}
//			}
//		}
//		T--;
//	}
//
//	return 0;
//}
//int main()
//{
//	int m;
//	int x;
//	scanf("%d", &m);
//	while (m)
//	{
//		scanf("%d", &x);
//		if (x == 1)
//		{
//			printf("YES\n");
//		}
//		else
//		{
//			printf("NO\n");
//		}
//		m--;
//	}
//	return 0;
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//
//}
//#include<math.h>
//int main()
//{
//	int a, b, c, d;
//	int count = 0;
//	scanf("%d", &count);
//	while (count)
//	{
//		scanf("%d %d %d %d", &a, &b, &c, &d);
//		double l = (a - c)*(a-c);
//		double t = (d + b)*(d+b);
//		double s = sqrt(l+t);
//		printf("%.2f\n", s);
//		count--;
//	}
//	return 0;
//}
//int main()
//{
//	int k = 0;
//	int n = 0;
//	scanf("%d", &k);
//	while ((n * n + n) <= 2*k)
//	{
//		n++;
//	}
//	n--;
//	int result =( k - n * (n + 1) / 2) * (n + 1) + (n + 1) * (2 * n + 1) * n / 6;
//	printf("%d\n", result);
//	return 0;
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//		printf("%d\n", a);
//	}
//	else if (a == b)
//	{
//		printf("%d\n", a);
//	}
//	else
//	{
//		printf("%d\n", b);
//	}
//	return 0;
//}
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int x[], y[], z[];
//	int i = 1;
//	int count = 0;
//	while (m)
//	{
//		scanf("%d %d %d", &x[i], &y[i], &z[i]);
//		m--;
//		i++;
//	}
//	if ()
//	{
//
//	}
//	return 0;
//}
//int main()
//{
//	int m, n;
//	int x[] = { 0 };
//	int y[] = { 0 };
//	int i = 0;
//	int j = 0;
//	scanf("%d %d", &m, &n);
//	while (m)
//	{
//		scanf("%d", &x[i]);
//		i++;
//	}
//	while (n)
//	{
//		scanf("%d", &y[j]);
//		j++;
//	}
//
//
//	return 0;
//}
typedef struct homework
{
	char c[30];
	int a;
}HW;
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((HW*)e1)->a-((HW*)e2)->a;   //强转的目的是说明其为结构体指针类型
	//括起来是因为强转有临时性，括起来才为最终结果
}
int main()
{
	int n;
	scanf("%d",&n);
	HW arr[10];
	int sz = sizeof(HW);
	qsort(arr, n, sz, cmp_stu_by_age);
}