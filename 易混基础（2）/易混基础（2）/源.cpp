（1）
#include <stdio.h>
int main() 
{
	int m[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int(*p)[4] = (int(*)[4])m;
	printf("%d", p[1][2]);
	return 0;
}
输出结果：7



（2）
int main()
{
	char p1[15] = "abcd", * p2 = "ABCD", str[50] = "xyz";
	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	printf("%s", str);
	return 0;
}
输出结果：xycdBCD



（3）
#include<stdio.h>
char* f(char* str, char ch)
{
	char* it1 = str;
	char* it2 = str;
	while (*it2 != '\0')
	{
		while (*it2 == ch)
		{
			it2++;
		} 
		*it1++ = *it2++;
	} 
	return str;
} 
int main() 
{
	char a[10];
	strcpy(a, "abcdcccd");
	printf("%s", f(a, 'c'));
	return 0;
}
输出结果：abddcccd



（4）
int main()
{
	char arr[2][4];
	strcpy(arr[0], "you");
	strcpy(arr[1], "me");
	arr[0][3] = '&';
	printf("%s \n", arr);
	return 0;
}
输出结果： you& me


（5）
struct st
{
	int* p;
	int i;
	char a;
};
int sz = sizeof(struct st);
在64位处理器上运行后 sz 的值是什么？
输出结果：16


（6）
enum weekday
{
	sun,
	mon = 3,
	tue,
	wed
};
enum weekday workday;
workday = wed;
printf("%d\n", workday);
输出结果：5



（7）
#include <stdio.h>
typedef struct List_t
{
	struct List_t* next;
	struct List_t* prev;
	char data[0];
}list_t;
int main()
{
	printf("%d", sizeof(list_t));
	return 0;
}
输出结果：8


（8）
#include<stdio.h>
void fut(int** s, int p[2][3])
{
	**s = p[1][1];
} 
int main()
{
	int a[2][3] = { 1,3,5,7,9,11 }, * p;
	p = (int*)malloc(sizeof(int));
	fut(&p, a);
	printf("%d", *p);
	return 0;
}
输出结果：9


（9）
#include<stdio.h>
void fun(char* fname, char* st)
{
	FTLE* myf;
	int i;
	myf = fopen(fname, "w");
	for (i = 0; i < strlen(st); i++) fputc(st[i], myf);
	fclose(myf);
} 
int main()
{
	fun("test.txt", "new world");
	fun("test.txt", "hello,");
	return 0;
}
程序执行后，文件 test.txt 中的内容是：new worldhello,


（10）
#include<stdio.h>
#define Mul(x,y) ++x*++y
int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	printf(“ % d”, Mul(a + b, b + c));
	return 0;
}
输出结果：不确定，是问题表达式