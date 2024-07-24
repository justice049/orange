#include"Date.h"

bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = Date(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day<=0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

bool Date::operator<(const Date& d)
{
	if (_year > d._year)
	{
		return false;
	}
	if (_month > d._month)
	{
		return false;
	}
	if (GetMonthDay(_year, _month) > GetMonthDay(d._year, d._month))
	{
		return false;
	}
	return true;
}

int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;

	if (*this < d)
	{
		int flag = -1;
		max = d;
		min = *this;
	}
	int n = 0;
	while (min!=max)
	{
		min++;
		n++;
	}
	return n * flag;
}