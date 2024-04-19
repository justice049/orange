//#include<iostream>
//using namespace std;
//int main()
//{
//	float a = 0;
//	char b = 0;
//	float c = 0;
//	cin >> a >> b;
//	int d = a;
//	c = d;
//	int money = 0;
//	if (a < 1)
//	{
//		if (b == 'y')
//		{
//			cout << "25" << endl;
//		}
//		else
//		{
//			cout << "20" << endl;
//		}
//	}
//	else
//	{
//		if (b == 'y')
//		{
//			if (c - a > 0)
//			{
//				money = 25 + a;
//				cout << money << endl;
//			}
//			else
//			{
//				money = 24 + a;
//				cout << money << endl;
//			}
//		}
//		else
//		{
//			if (c - a > 0)
//			{
//				money = 20 + a;
//				cout << money << endl;
//			}
//			else
//			{
//				money = 19 + a;
//				cout << money << endl;
//			}
//		}
//	}
//	return 0;
//}
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int i = 0;
    int count = n;
    string str1;
    string str2;
    int flag1 = 0;
    int flag2 = 0;
    cin >> str1 >> str2;
    vector <string>strs;
    while (n--)
    {
        string a;
        cin >> a;
        strs.push_back(a);
    }
    vector<int>s1;
    vector<int>s2;
    i = 0;
    int j = 0;
    while (i <= count)
    {
        if (!(strs[i] < str1) && !(strs[i] > str1))
        {
            s1.push_back(i);
            flag1++;
        }
        i++;
    }
    while (j <= count)
    {
        if (!(strs[j] < str2) && !(strs[j] > str2))
        {
            s2.push_back(j);
            flag2++;
        }
        j++;
    }
    if (flag1 && flag2)
    {
        int a = s2[flag2 - 1] - s1[flag1 - 1];
        if (a < 0)
        {
            a = -a;
        }
        cout << a << endl;
        return 0;
    }
    cout << "-1" << endl;
    return 0;
}