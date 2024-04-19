//¼òÐ´µ¥´Ê
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string str;
//    string s;
//    while (cin >> str)
//    {
//        if (str[0] >= 97 && str[0] <= 122)
//        {
//            str[0] -= 32;
//        }
//        s.push_back(str[0]);
//    }
//    cout << s << endl;
//    return 0;
//}


//dd°®¿ò¿ò
//#include <iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//    int n = 0, x = 0;
//    vector<int>a;
//    vector<int>s;
//    int tmp = 0;
//    int add = 0;
//    cin >> n >> x;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> tmp;
//        a.push_back(tmp);
//        add += tmp;
//        s.push_back(add);
//    }
//    int left = 0;
//    int right = n - 1;
//
//
//    return 0;
//}



//³ý2!
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n = 0, k = 0;
//	cin >> n >> k;
//	vector<int>b;
//	int sum = 0;
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int tmp = 0;
//		cin >> tmp;
//		if (tmp % 2 == 0)
//		{
//			b.push_back(tmp);
//			count++;
//		}
//		else
//		{
//			sum += tmp;
//		}
//	}
//	int count2 = count;
//	std::sort(b.begin(), b.end());
//	while (k > 0)
//	{
//		b[count] = b[count] / 2;
//		k--;
//		if (b[count] < b[count - 1])
//		{
//			count--;
//		}
//	}
//	for (int i = 0; i < count2; i++)
//	{
//		sum += b[i];
//	}
//	cout << sum << endl;
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	long long n = 0, k = 0;
	cin >> n >> k;
	vector<long long>b;
	long long sum = 0;
	long long count = 0;
	for (long long i = 0; i < n; i++)
	{
		long long tmp = 0;
		cin >> tmp;
		if (tmp % 2 == 0)
		{
			b.push_back(tmp);
			count++;
		}
		else
		{
			sum += tmp;
		}
	}
	long long count2 = count;
	std::sort(b.begin(), b.end());
	count--;
	while (k > 0)
	{
		b[count] = b[count] / 2;
		k--;
		if (b[count] < b[count - 1])
		{
			count--;
		}
	}
	for (long long i = 0; i < count2; i++)
	{
		sum += b[i];
	}
	cout << sum << endl;
	return 0;
}