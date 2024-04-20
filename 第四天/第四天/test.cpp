//ì³²¨ÄÇÆõ
//#include <iostream>
//using namespace std;
//int main()
//{
//    int Fib[105];
//    Fib[0] = 1;
//    Fib[1] = 1;
//    for (int i = 2; i <= 100; i++)
//    {
//        Fib[i] = Fib[i - 1] + Fib[i - 2];
//    }
//    int n = 0;
//    cin >> n;
//    int i;
//    for (i = 1; i <= 100; i++)
//    {
//        if (n > Fib[i] && n < Fib[i + 1])
//        {
//            break;
//        }
//    }
//    int left = n - Fib[i];
//    int right = Fib[i + 1] - n;
//    cout << min(left, right) << endl;
//    return 0;
//}


//Ñî»ÔÈý½Ç
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n = 0;
//    cin >> n;
//    int yh[10][10] = { 0 };
//    for (int i = 0; i < 10; i++)
//    {
//        yh[i][0] = 1;
//    }
//    for (int i = 0; i <= n; i++)
//    {
//        cout << "1" <<" ";
//        for (int j = 1; j <= i; j++)
//        {
//            yh[i][j] = yh[i - 1][j] + yh[i-1][j-1];
//            cout << yh[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int fib(int n)
//{
//    int Fib[105] = { 0 };
//    Fib[0] = 1;
//    Fib[1] = 1;
//    for (int i = 2; i < 100; i++)
//    {
//        Fib[i] = Fib[i - 1] + Fib[i - 2];
//    }
//    int tmp = Fib[n];
//    return tmp;
//}
//int main()
//{
//    cout << fib(5) << endl;
//    return 0;
//}

#include<iostream>
#include<vector>
using namespace std;
vector<int> getRow(int rowIndex)
{
    vector<int> res(rowIndex + 1);
    res[0] = 1;
    for (int i = 1; i <= rowIndex; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            res[j] = (j - 1 >= 0 ? res[j - 1] : 0) + res[j];
        }
    }
    return res;
}
int main()
{
    vector<int> a = getRow(10);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
