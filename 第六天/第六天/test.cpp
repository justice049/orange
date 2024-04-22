//求最小公倍数吖
#include<iostream>
using namespace std;
int main()
{
    long long a = 0;
    long long b = 0;
    cin >> a >> b;
    long long m = 0;
    long long n = a * b;
    while ((m = a % b) != 0)
    {
        a = b;
        b = m;
    }
    cout << n / b << endl;
    return 0;
}


//