//#include<iostream>
//using namespace std;
//
//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1; 
//	}
//	/*Time(const Time& t)
//	{
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//	}*/
//	void Print(Time T)
//	{
//		cout << T._hour << endl;
//		cout << T._minute << endl;
//		cout << T._second << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//int main()
//{
//	Time t1;
//	Time t2(t1);
//	t1.Print(t1);
//	t2.Print(t2);
//
//	return 0;
//}//#include<iostream>//using namespace std;////typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	Stack(const Stack& s)
//	{
//		DataType* tmp = (DataType*)malloc(s._capacity * (sizeof(DataType)));
//		if (tmp == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//
//		memcpy(tmp, s._array, sizeof(DataType) * s._size);
//
//		_array = tmp;
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//	int i = 97;
//	char ch = 'a';
//	if (i == ch)
//	{
//		cout << "相等" << endl;
//	}
//	return 0;
//}


#include<iostream>
using namespace std;

class Time
{
public:
	Time(int hour,int minute,int second)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
	}
	Time(const Time& t)
	{
		_hour = t._hour;
		_minute = t._minute;
		_second = t._second;
	}
	void Print(Time T)
	{
		cout << T._hour << endl;
		cout << T._minute << endl;
		cout << T._second << endl;
	}
	int GetHour()
	{
		return _hour;
	}
	int GetMin()
	{
		return _minute;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

bool operator<(Time x, const Time& y)
{
	if (x.GetMin() < x._hour)
	{
		return true;
	}
	else if (x._hour == x._hour)
	{
		if (x._minute < y._minute)
		{
			return true;
		}
		else if (x._minute == y._minute)
		{
			return x._second < y._second;
		}
		else if (x._minute == y._minute)
		{
			return x._second < y._second;
		}
	}
	return false;
}

int main()
{
	Time t1(0, 4, 9);
	Time t2(5, 2, 0);
	t1.Print(t1);
	t2.Print(t2);
	t1.GetMin();
	cout << (t1 < t2) << endl;   //    <<运算符优先级比较高，需要加括号
	return 0;
}