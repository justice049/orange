//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//// d1 << cout; -> d1.operator<<(&d1, cout); �����ϳ������
//// ��Ϊ��Ա������һ������һ�������ص�this������d1�������<<�����
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
//	// ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
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
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
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
//	class B // B��������A����Ԫ
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
//	// ������ô�������A aa1();����Ϊ�������޷�ʶ���Ǻ������������Ƕ�����
//	// �������ǿ�����ô����������������������ص��ǲ���ȡ���֣�
//	// ����������������ֻ����һ�У����ǿ��Կ�����һ�����ͻ��Զ�������������
//	A();
//	A aa2(2);
//	// ���������������ĳ����¾ͺܺ���
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
	// ��ֵ����
	A aa1;
	f1(aa1);
	cout << endl;
	// ��ֵ����
	f2();
	cout << endl;
	// ��ʽ���ͣ���������+��������->�Ż�Ϊֱ�ӹ���
	f1(1);
	// һ�����ʽ�У���������+��������->�Ż�Ϊһ������
	f1(A(2));
	cout << endl;
	// һ�����ʽ�У�������������+��������->�Ż�һ����������
	A aa2 = f2();
	cout << endl;
	// һ�����ʽ�У�������������+��ֵ����->�޷��Ż�
	aa1 = f2();
	cout << endl;
	return 0;
}