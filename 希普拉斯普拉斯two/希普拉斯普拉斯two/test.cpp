//#include<iostream>
//using namespace std;
//
//class ob
//{
//public:
//	void func()
//	{
//		cout << "void func()" << endl;
//	}
//};
//
//typedef void(ob::* pobfunc)();
//
//int main()
//{
//	pobfunc p = &ob::func;
//	ob tmp;
//	(tmp.*p)();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//
//int main()
//{
//	
//}
//


//// 全局的operator==
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 运算符重载成全局的需要成员变量是公有的，没办法保证封装性
//// 可以用友元解决，或者干脆重载成成员函数
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//void Test()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//}


//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//// 赋值运算符重载成全局函数，注意重载成全局函数时没有this指针了，需要给两个参数
//Date& operator=(Date& left, const Date& right)
//{
//	if (&left != &right)
//	{
//		left._year = right._year;
//		left._month = right._month;
//		left._day = right._day;
//	}
//	return left;
//}
//// 编译失败：
//// error C2801: “operator =”必须是非静态成员
//

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 前置++：返回+1之后的结果
	// 注意：this指向的对象函数结束后不会销毁，故以引用方式返回提高效率
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	// 后置++：
	// 前置++和后置++都是一元运算符，为了让前置++与后置++形成能正确重载
	// C++规定：后置++重载时多增加一个int类型的参数，但调用函数时该参数不用传递，编译器自动传递
	// 注意：后置++是先使用后+1，因此需要返回+1之前的旧值，故需在实现时需要先将this保存一份，然后给this + 1
	//而temp是临时对象，因此只能以值的方式返回，不能返回引用
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}
private:
	int _year;
	int _month;
	int _day;
}; 
int main()
{
	Date d;
	Date d1(2022, 1, 13);
	d = d1++;
	d = ++d1; 
	return 0;
}
