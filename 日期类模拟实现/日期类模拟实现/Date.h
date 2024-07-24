#pragma once
#include<iostream>
#include<assert.h>
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
	Date(const Date& tmp)
	{
		_year = tmp._year;
		_month = tmp._month;
		_day = tmp._day;
	}
	//获取某年某月天数
	int GetMonthDay(int year,int month)
	{
		assert(month > 0 && month < 13);
		static int days[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[month];
		if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	Date operator++(int)
	{
		Date tmp = (*this);
		_day += 1;
		return tmp;
	}
	Date& operator--()
	{
		_day -= 1;
		return *this;
	}
	Date operator--(int)
	{
		Date tmp = (*this);
		_day -= 1;
		return tmp;
	}
	
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	bool operator<(const Date& d);
	Date& operator+=(int day);
	Date operator+(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(const Date& d);
	
	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

