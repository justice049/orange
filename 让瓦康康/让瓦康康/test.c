#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char* decodeString(char* s) 
{
	char* str1 = (char*)malloc(sizeof(char) * 9000);
	char* str2 = (char*)malloc(sizeof(char) * 9000);
	size_t len = strlen(s);
	int Top1 = 0;
	int Top2 = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '[')
		{
			str1[Top1++] = '[';
			str2[Top2++] = '[';
		}
		else if (s[i] == ']')
		{
			int sum = 0;
			int x = 10;
			sum += (str1[Top1 - 2] - '0');
			Top1 = Top1 - 2;
			while (Top1 > 0 && str1[Top1 - 1] != '[')
			{
				sum += (str1[Top1 - 1] - '0') * x;
				Top1--;
				x *= 10;
			}
			char* tmp = (char*)malloc(sizeof(char) * 3000);
			int right = 3000;
			Top2--;
			while (str2[Top2] != '[')
			{
				tmp[--right] = str2[Top2];
			}
			while (sum--)
			{
				for (int m = right; m < 3000; m++)
				{
					str2[Top2++] = tmp[m];
				}
			}

		}
		else if (isalpha(s[i]) == 0)
		{
			str1[Top1++] = s[i];
		}
		else
		{
			str2[Top2++] = s[i];
		}
	}
	str2[Top2] = '\0';
	return str2;
}
int main()
{
	char* p = decodeString("3[a2[c]]");
	printf("%s", p);
	return 0;
}