//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	A _aobj;  // 没有默认构造函数
//	int& _ref;  // 引用
//	const int _n; // const 
//};//class Date
//{
//public:
//	Date(int year, int month, int day, int& x)
//		: _n(1)
//		, _year(year)
//		, _month(month)
//		, _day(day)
//		, _ref(x)
//		, _p((int*)malloc(sizeof(4) * 10))
//	{
//		if (_p == nullptr)
//		{
//			perror("malloc fail");
//		}
//		for (size_t i = 0; i < 10; i++)
//		{
//			_p[i] = 0;
//		}
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	const int _n;
//	int& _ref;
//	int* _p;
//};//#include<iostream>//using namespace std;////class C
//{
//public:
//	C(int x=0)
//		:_x(x)
//	{}
//private:
//	int _x;
//	C cc1 = xx;
//};
//
//int main()
//{
//	C cc1(1);
//	C cc2 = 2;
//	const C& cc3 = 2;
//	return 0;
//}


#include<iostream>
using namespace std;

class C
{
public:
	C(int x = 0)
		:_x(x)
	{}
private:
	int _x;
};

class Stack
{
public:
	void Push(const C& c)
	{

	}
};

int main()
{
	//前
	Stack st;
	C cc3(3);
	st.Push(cc3);
	//后
	Stack st;
	st.Push(4);
	return 0;
}