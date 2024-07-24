#include"Date.h"

int main()
{
	Date d1(1949, 12, 1);
	Date d2(1949, 12, 2);
	cout << d1 - d2 << endl;
	d1.Print();
	d2.Print();
	return 0;
}