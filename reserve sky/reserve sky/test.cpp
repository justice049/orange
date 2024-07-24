#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	bool CheckInvalid()
	{
		if (_year > 0||_month<1||_month>12||_day<1||_day>GetMonthDay(_year,_month))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
private:
	int _year;
	int _month;
	int _day;
};


ostream& operator<<(ostream& out,const Date& d)
{
	out << d._year << "Äê" << d._month << "ÔÂ" << d._day << "ÈÕ" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}


int main()
{
	Date d1(1949, 12, 1);
	cin >> d1;
	operator<<(cout, d1);
	cout << d1 << d1;
	return 0;
}