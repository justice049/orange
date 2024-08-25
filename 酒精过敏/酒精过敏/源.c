#include<stdio.h>
int divide(int a, int b)
{
    int count = 0;
    if (b > 0 && a > 0 || a < 0 && b < 0)
    {
        while (a > b)
        {
            a = a - b;
            count++;
        }
        return count;
    }
    if (b < 0)
    {
        b = -b;
        while (a > b)
        {
            a = a - b;
            count++;
        }
        count = -count;
        return count;
    }
    if (a < 0)
    {
        a = -a;
        while (a > b)
        {
            a = a - b;
            count++;
        }
        count = -count;
        return count;
    }
}
int main()
{
    int a = divide(-7, 3);
    printf("%d", a);
    return 0;
}