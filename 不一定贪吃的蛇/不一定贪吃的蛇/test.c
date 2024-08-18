#include"Snake.h"
#define KEY_PRESS(vk) ( (GetAsyncKeyState(vk) & 0x1) ? 1 : 0 )
void password()
{
	while (1)
	{
		if (KEY_PRESS(0x30))
		{
			printf("0\n");
		}
		else if (KEY_PRESS(0x31))
		{
			printf("1\n");
		}
		else if (KEY_PRESS(0x32))
		{
			printf("2\n");
		}
		else if (KEY_PRESS(0x33))
		{
			printf("3\n");
		}
		else if (KEY_PRESS(0x34))
		{
			printf("4\n");
		}
		else if (KEY_PRESS(0x35))
		{
			printf("5\n");
		}
		else if (KEY_PRESS(0x36))
		{
			printf("6\n");
		}
		else if (KEY_PRESS(0x37))
		{
			printf("7\n");
		}
		else if (KEY_PRESS(0x38))
		{
			printf("8\n");
		}
		else
		{
			printf("9\n");
		}
	}
}
void test()
{
	Snake snake = { 0 };
	//游戏开始--初始化
	GameStart(&snake);
	////游戏运行--游戏正常运行
	GameRun(&snake);
	////游戏结束--游戏善后（链表销毁、释放资源）
	//GameEnd(&snake);
}
int main()
{
	

	//COORD pos1 = { 5,20 };
	//SetConsoleCursorPosition(handle, pos1);
	//int ch = getchar();

	//COORD pos2 = { 20,5 };
	//SetConsoleCursorPosition(handle, pos2);
	//putchar(ch);
	srand((unsigned int)time(NULL));
	test();
	setlocale(LC_ALL, "");
	/*wchar_t ch1 = L'●';
	wchar_t ch2 = L'★';
	wprintf(L"%c\n", ch1);
	wprintf(L"%c\n", ch2);*/
	return 0;
	return 0;
}