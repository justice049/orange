//#include <stdio.h>
//#include<stdlib.h>
//void print(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//
//}
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//
//}
//void test()
//{
//	int arr[] = { 3,4,1,2,0,9,8,5,6,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print(arr, sz);
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//struct Stu
//{
//	char name[30];
//	int age;
//};
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//void test1()
//{
//	struct Stu s[] = { {"zhangsan",15},{"lisi",20},{"wangwu",25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//}
//
//int main()
//{
//	test1();
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//struct Stu
//{
//	char name[30];
//	int age;
//};
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age-((struct Stu*)e2)->age;   //强转的目的是说明其为结构体指针类型
//	//括起来是因为强转有临时性，括起来才为最终结果
//}
//void test1()
//{
//	struct Stu s[] = { {"zhangsan",20},{"lisi",15},{"wangwu",25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
//}
//
//int main()
//{
//	test1();
//	return 0;
//}



//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//struct Stu
//{
//	char name[30];
//	int age;
//};
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//void test2()
//{
//	struct Stu s[] = { {"zhangsan",20},{"lisi",10},{"wangwu",25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
//}
//int main()
//{
//	test2();
//	return 0;
//}
//#include <stdio.h>
//struct Stu
//{
//	char name[30];
//	int age;
//};
//int main()
//{
//	struct Stu s[] = {{"zhangsan",15},{"lisi",20},{"wangwu",25}};
//	struct Stu* ps = &s[0];
//	printf("%s%d\n", ps->name, ps->age);
//	printf("%s%d\n", (*ps).name, (*ps).age);
//	return 0;
//}
//
// 
// void qsort(void* base         //待排序元素的起始位置
//            size_t num         //待排序数组中的元素个数
//            size_t size        //待排序数据的每个元素大小—-为了知道下个元素从哪开始找
//            int(*compar)(const void*,const void*));
//            函数指针--指向的函数是用来比较数据中两个元素大小的
//            qsort函数是库函数，功能是排序，可以排序任意类型的数据
//            所用的排序思想为快速排序







//            下面用冒泡排序的思想实现qsort函数
//             compare函数指向的函数的参数是：要比较的两个元素的地址
#include <stdio.h>
#include <string.h>
struct Stu
{
	char name[20];
	int age;
};
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e1)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
	//字符串比较用库函数strcmp
}
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*) e2;
}
void Swap(char* buf1, char* buf2, size_t width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;          //由于不确定比较的两个数据的类型，
	    *buf2 = tmp;           //故赋值（拷贝）时一个字节一个字节的拷贝数据
		buf1++;
		buf2++;
	}
}
void bubble(void* base, size_t sz, size_t width, int (*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)  //比较函数需单独实现
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);  //相当于赋值
			}
		}
	}
}
void print(int arr[],int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}
}
void test1()
{
	int arr[] = { 3,1,5,2,4,8,7,6,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr,sz);
}
void test2()
{
	struct Stu s[] = { {"zhangsan",15},{"lisi",20},{"wangwu",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble(s, sz, sizeof s[0], cmp_stu_by_name);
}
void test3()
{
	struct Stu s[] = { {"zhangsan",20},{"lisi",15},{"wangwu",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble(s, sz, sizeof s[0], cmp_stu_by_age);
}
int main()
{
	test1();
	return 0;
}

//能运行好的我的任务结束了

