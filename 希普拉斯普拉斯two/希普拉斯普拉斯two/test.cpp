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


//// ȫ�ֵ�operator==
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
//// ��������س�ȫ�ֵ���Ҫ��Ա�����ǹ��еģ�û�취��֤��װ��
//// ��������Ԫ��������߸ɴ����سɳ�Ա����
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
//// ��ֵ��������س�ȫ�ֺ�����ע�����س�ȫ�ֺ���ʱû��thisָ���ˣ���Ҫ����������
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
//// ����ʧ�ܣ�
//// error C2801: ��operator =�������ǷǾ�̬��Ա
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
	// ǰ��++������+1֮��Ľ��
	// ע�⣺thisָ��Ķ����������󲻻����٣��������÷�ʽ�������Ч��
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	// ����++��
	// ǰ��++�ͺ���++����һԪ�������Ϊ����ǰ��++�����++�γ�����ȷ����
	// C++�涨������++����ʱ������һ��int���͵Ĳ����������ú���ʱ�ò������ô��ݣ��������Զ�����
	// ע�⣺����++����ʹ�ú�+1�������Ҫ����+1֮ǰ�ľ�ֵ��������ʵ��ʱ��Ҫ�Ƚ�this����һ�ݣ�Ȼ���this + 1
	//��temp����ʱ�������ֻ����ֵ�ķ�ʽ���أ����ܷ�������
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
