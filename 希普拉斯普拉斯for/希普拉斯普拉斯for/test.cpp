//class A
//{
//public:
//	explicit A(int x=0)
//		:_x(x)
//	{}
//private:
//	int _x;
//};

//class A
//{
//public:
//	A(int a1,int a2)
//		:_a1(a1)
//		,_a2(a2)
//	{}
//private:
//	int _a1;
//	int _a2;
//};
//
//int main()
//{
//	A aa1 = { 1,2 };
//	const A& aa2 = { 1,2 };
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		,_a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//}

#include<iostream>
using namespace std;

class A
{
public:
	A() 
	{
		n++;
	}
	A(const A& aa)
	{
		n++;
	}

private:
	static int n;
};

A func()
{
	A aa;
	return aa;
}

int main()
{
	A aa1;
	A aa2;
	func();
	cout << n << endl;
	return 0;
}