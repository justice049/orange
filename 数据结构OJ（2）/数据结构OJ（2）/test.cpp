//��������ָһ������ƽ����β�����ڸ����������Ȼ���������n(����n)���ڵ��������ĸ���
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

//����С�� N ����������
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

//��һ���ַ������ҵ���һ��ֻ����һ�ε��ַ�,
// ����������λ��, ���û���򷵻� -1 ����Ҫ���ִ�Сд��
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


//ʵ��һ���㷨��ȷ��һ���ַ��� s �������ַ��Ƿ�ȫ����ͬ
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


//���������ַ��� s1 �� s2 �����дһ������
// ȷ������һ���ַ������ַ��������к��ܷ�����һ���ַ���
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

//����һ���ַ�������дһ�������ж����Ƿ�Ϊĳ�����Ĵ�������֮һ��
// ���Ĵ���ָ������������һ���ĵ���
//����������ָ��ĸ���������С����Ĵ���һ�����ֵ䵱�еĵ���
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


//���ճ��������У����Ǿ����������ܳ��ĵ��ʣ����� "localization" �� "internationalization" �ȡ�
//Ϊ����д���㣬���ǻὫ̫���ĵ��ʽ�����д������������¶��壺
//���һ�����ʰ������ַ��������� 10 ��������Ϊ����һ�������ʡ����еĳ����ʶ���Ҫ������д����д�ķ�����
//��д��������ʵ���β�ַ���Ȼ��������β�ַ��м�д���������ȥ����β�ַ������������ַ�������
//���� "localization" ��д��õ����� "l10n" �� "internationalization" ��д��õ����� "i18n" ��
//�ָ��� n �����ʣ������еĳ����ʽ�����д������İ�ԭ�������
//����������
//��һ�а���Ҫ������n��1��n��100
//������n��ÿ�а���һ����СдӢ���ַ����ɵ��ַ������ַ������Ȳ�����100��
//�����������˳�����������ÿ������
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


//URL������дһ�ַ��������ַ����еĿո�ȫ���滻Ϊ % 20 ��
//�ٶ����ַ���β�����㹻�Ŀռ��������ַ���
//����֪���ַ����ġ���ʵ������
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



//�ַ���ѹ���������ַ��ظ����ֵĴ�������дһ�ַ�����ʵ�ֻ������ַ���ѹ�����ܡ�
//���磬�ַ��� aabcccccaaa ���Ϊ a2b1c5a3 ������ѹ��������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ���������Լ�����
//������ֻ������СдӢ����ĸ��a��z��
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
//��Խ�������д���򣬽���ĳ������������λ��ż��λ��
//����ʹ�ý��ٵ�ָ�Ҳ����˵��λ0��λ1������λ
//2��λ3�������Դ����ƣ�
int exchangeBits(int num)
{
    int t = 0b01010101010101010101010101010101;
    return ((num & t) << 1) + ((num & (t << 1)) >> 1);
}

//
//�ݹ�˷��� дһ���ݹ麯������ʹ��* �������
//ʵ����������������ˡ�����ʹ�üӺš����š�λ�ƣ���Ҫ����һЩ
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

//���С�ڵ��� n ���� 7 �й����ֵĸ��������� 7 �ı��������а��� 7 ������
//���� 17 ��27 ��37 ... 70 ��71 ��
//72 ��73...���ĸ�����һ���������������ж������ݣ���ע�⴦��
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

//���һ���㷨����� n �׳��ж��ٸ�β����
int trailingZeroes(int n)
{
    return n / 5 + n / 25 + n / 125 + n / 625 + n / 3125 + n / 15625 + n / 78125 + n / 390625
        + n / 1953125 + n / 9765625 + n / 48828125
        + n / 244140625 + n / 1220703125;
}

//д��һ�����򣬽���һ����������ֵ���������ֵ�Ľ�������ֵ�����С�������ֵ���ڵ��� 0.5 ,����ȡ����
//С�� 0.5 ��������ȡ����
//���ݷ�Χ����֤����������� 32 λ��������Χ��
//��������������һ����������ֵ
//����������������ֵ�Ľ�������ֵ
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