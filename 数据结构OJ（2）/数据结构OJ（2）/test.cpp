//自守数是指一个数的平方的尾数等于该数自身的自然数。请求出n(包括n)以内的自守数的个数
#include <stdio.h>
#include<math.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        int a = i;
        int h = 0;
        while (a)
        {
            a /= 10;
            h++;
        }
        if (((int)pow(i, 2) % (int)pow(10, h) == i))
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}

//返回小于 N 的质数个数
#include <math.h>
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        int flag = 1;
        for (int j = 2; j <= sqrt(n); j++)
        {
            if (i % j == 0 && i != j)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}

//在一个字符串中找到第一个只出现一次的字符,
// 并返回它的位置, 如果没有则返回 -1 （需要区分大小写）
int FirstNotRepeatingChar(char* str)
{
  char* p1 = str + 1;
  char* p2 = str;
while (*p2 != '\0')
{
    while (*p1 != *p2 && *p1 != '\0')
    {
        p1++;
    }
    if (*p1 == '\0')
    {
        return p2 - str;
    }
    while (*p2 != '\0')
    {
        p2++;
        char* p = str;
        while (*p != *p2 && p != p2)
        {
            p++;
        }
        if (p == p2)
        {
            p1 = p2 + 1;
            break;
        }
    }
}
return -1;
}


//实现一个算法，确定一个字符串 s 的所有字符是否全都不同
bool isUnique(char* astr)
{
    int arr[10000] = { 0 };
    for (int i = 0; i < strlen(astr); i++)
    {
        arr[astr[i]]++;
    }
    for (int i = 0; i < strlen(astr); i++)
    {
        if (arr[astr[i]] > 1)
        {
            return false;
        }
    }
    return true;
}


//给定两个字符串 s1 和 s2 ，请编写一个程序，
// 确定其中一个字符串的字符重新排列后，能否变成另一个字符串
int cmp(const void* e1, const void* e2)
{
    return *(char*)e1 - *(char*)e2;
}
bool CheckPermutation(char* s1, char* s2)
{
    qsort(s1, strlen(s1), sizeof(char), cmp);
    qsort(s2, strlen(s1), sizeof(char), cmp);
    if (strcmp(s1, s2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
// 回文串是指正反两个方向都一样的单词
//或短语。排列是指字母的重新排列。回文串不一定是字典当中的单词
bool canPermutePalindrome(char* s)
{
    int arr[128] = { 0 };
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        arr[s[i]]++;
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if (arr[s[i]] > 2 && (arr[s[i]] % 2 == 1))
        {
            count++;
            arr[s[i]] = 0;
        }
        if (arr[s[i]] % 2 == 1)
        {
            count++;
        }
    }
    if (count == 1 || count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//在日常书面表达中，我们经常会碰到很长的单词，比如 "localization" 、 "internationalization" 等。
//为了书写方便，我们会将太长的单词进行缩写。这里进行如下定义：
//如果一个单词包含的字符个数超过 10 则我们认为它是一个长单词。所有的长单词都需要进行缩写，缩写的方法是
//先写下这个单词的首尾字符，然后再在首尾字符中间写上这个单词去掉首尾字符后所包含的字符个数。
//比如 "localization" 缩写后得到的是 "l10n" ， "internationalization" 缩写后得到的是 "i18n" 。
//现给出 n 个单词，将其中的长单词进行缩写，其余的按原样输出。
//输入描述：
//第一行包含要给整数n。1≤n≤100
//接下来n行每行包含一个由小写英文字符构成的字符串，字符串长度不超过100。
//输出描述：按顺序输出处理后的每个单词
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char n[100] = { 0 };
        scanf("%s", n);
        int len = strlen(n);
        if (len < 10)
        {
            printf("%s\n", n);
        }
        else
        {
            printf("%c%d%c\n", n[0], len - 2, n[len - 1]);
        }
    }
    return 0;
}


//URL化。编写一种方法，将字符串中的空格全部替换为 % 20 。
//假定该字符串尾部有足够的空间存放新增字符，
//并且知道字符串的“真实”长度
char arr[10000000] = { 0 };
char* replaceSpaces(char* S, int length)
{
    int m = 0;
    int n = 0;
    for (int i = 0; i < length; i++)
    {
        if (S[i] == ' ')
            m++;
    }
    for (int j = 0; j < length; j++)
    {
        if (S[j] == ' ')
        {
            arr[n++] = '%';
            arr[n++] = '2';
            arr[n++] = '0';
        }
        else
        {
            arr[n++] = S[j];
        }
    }
    arr[n++] = '\0';
    return arr;
}



//字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
//比如，字符串 aabcccccaaa 会变为 a2b1c5a3 。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字
//符串中只包含大小写英文字母（a至z）
char a[50005] = { 0 };
char* compressString(char* S)
{
    int n = 0;
    int len = strlen(S);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        char count = '1';
        while (S[i] == S[i + 1])
        {
            count++;
            i++;
        }
        if (count >= '1')
        {
            a[n++] = S[i];
            a[n++] = count;
        }
        else
        {
            a[n++] = S[i];
        }
    }
    if (strlen(a) <= strlen(S))
    {
        return a;
    }
    else
    {
        return S;
    }
}

//
//配对交换。编写程序，交换某个整数的奇数位和偶数位，
//尽量使用较少的指令（也就是说，位0与位1交换，位
//2与位3交换，以此类推）
int exchangeBits(int num)
{
    int t = 0b01010101010101010101010101010101;
    return ((num & t) << 1) + ((num & (t << 1)) >> 1);
}

//
//递归乘法。 写一个递归函数，不使用* 运算符，
//实现两个正整数的相乘。可以使用加号、减号、位移，但要吝啬一些
int multiply(int A, int B)
{
    int c = 0;
    for (int i = 0; i < B; i++)
    {
        c += A;
    }
    return c;
}

int multiply(int A, int B)
{
    if (B == 1)
    {
        return A;
    }
    else if (B % 2 == 0)
    {
        return multiply(A, B / 2) * 2;
    }
    else
    {
        return A + multiply(A, B / 2) * 2;
    }
}

//输出小于等于 n 的与 7 有关数字的个数，包括 7 的倍数，还有包含 7 的数字
//（如 17 ，27 ，37 ... 70 ，71 ，
//72 ，73...）的个数（一组测试用例里可能有多组数据，请注意处理）
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = 0;
    for (int i = 6; i <= n; i++)
    {
        if (n < 7)
        {
            printf("0");
            break;
        }
        if (i % 7 == 0)
        {
            count++;
            continue;
        }
        int m = i;
        while (m > 0)
        {
            int l = m % 10;
            if (l == 7)
            {
                count++;
                break;
            }
            m /= 10;
        }
    }
    printf("%d", count);
    return 0;
}

//设计一个算法，算出 n 阶乘有多少个尾随零
int trailingZeroes(int n)
{
    return n / 5 + n / 25 + n / 125 + n / 625 + n / 3125 + n / 15625 + n / 78125 + n / 390625
        + n / 1953125 + n / 9765625 + n / 48828125
        + n / 244140625 + n / 1220703125;
}

//写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于 0.5 ,向上取整；
//小于 0.5 ，则向下取整。
//数据范围：保证输入的数字在 32 位浮点数范围内
//输入描述：输入一个正浮点数值
//输出描述：输出该数值的近似整数值
#include <stdio.h>
int main()
{
    float a = 0;
    scanf("%f", &a);
    float min = (int)a;
    float max = (int)a + 1;
    if (a < (min + max) / 2)
    {
        printf("%.0f", min);
    }
    else
    {
        printf("%.0f", max);
    }
    return 0;
}