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
//	return ((struct Stu*)e1)->age-((struct Stu*)e2)->age;   //ǿת��Ŀ����˵����Ϊ�ṹ��ָ������
//	//����������Ϊǿת����ʱ�ԣ���������Ϊ���ս��
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
// void qsort(void* base         //������Ԫ�ص���ʼλ��
//            size_t num         //�����������е�Ԫ�ظ���
//            size_t size        //���������ݵ�ÿ��Ԫ�ش�С��-Ϊ��֪���¸�Ԫ�ش��Ŀ�ʼ��
//            int(*compar)(const void*,const void*));
//            ����ָ��--ָ��ĺ����������Ƚ�����������Ԫ�ش�С��
//            qsort�����ǿ⺯�������������򣬿��������������͵�����
//            ���õ�����˼��Ϊ��������







//            ������ð�������˼��ʵ��qsort����
//             compare����ָ��ĺ����Ĳ����ǣ�Ҫ�Ƚϵ�����Ԫ�صĵ�ַ
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
	//�ַ����Ƚ��ÿ⺯��strcmp
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
		*buf1 = *buf2;          //���ڲ�ȷ���Ƚϵ��������ݵ����ͣ�
	    *buf2 = tmp;           //�ʸ�ֵ��������ʱһ���ֽ�һ���ֽڵĿ�������
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
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)  //�ȽϺ����赥��ʵ��
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);  //�൱�ڸ�ֵ
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

//�����кõ��ҵ����������

