//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//// d1 << cout; -> d1.operator<<(&d1, cout); 不符合常规调用
//// 因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day << endl;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}


//class Time
//{
//	friend class Date; 
//	// 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day; 
//	Time _t;
//};


//class A
//{
//private:
//	static int k;
//	int h;
//public:
//	class B // B天生就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	};
//};
//int A::k = 1;
//int main()
//{
//	A::B b;
//	b.foo(A());
//
//	return 0;
//}




//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl; 
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//class Solution 
//{
//public:
//	int Sum_Solution(int n) 
//	{
//		//...
//		return n;
//	}
//};
//int main()
//{
//	A aa1;
//	// 不能这么定义对象A aa1();，因为编译器无法识别是函数声明，还是对象定义
//	// 但是我们可以这么定义匿名对象，匿名对象的特点是不用取名字，
//	// 但是他的生命周期只有这一行，我们可以看到下一行他就会自动调用析构函数
//	A();
//	A aa2(2);
//	// 匿名对象在这样的场景下就很好用
//	Solution().Sum_Solution(10);
//	return 0;
//}



class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	} A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
void f1(A aa)
{}
A f2()
{
	A aa;
	return aa;
}
int main()
{
	// 传值传参
	A aa1;
	f1(aa1);
	cout << endl;
	// 传值返回
	f2();
	cout << endl;
	// 隐式类型，连续构造+拷贝构造->优化为直接构造
	f1(1);
	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
	f1(A(2));
	cout << endl;
	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
	A aa2 = f2();
	cout << endl;
	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
	aa1 = f2();
	cout << endl;
	return 0;
}