#include"Snake.h"
void SetPos(short x, short y)
{
	COORD pos = { x, y };
	HANDLE hOutput = NULL;
	//获取标准输出的句柄(⽤来标识不同设备的数值)
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置标准输出上光标的位置为pos
	SetConsoleCursorPosition(hOutput, pos);
}
void WelComeToGame()
{
	setlocale(LC_ALL, "zh-CN");   //设置地域
	//定位光标
	SetPos(30 ,16);
	wchar_t a[] = L"老中小登来玩贪吃蛇啦，欢迎欢迎！！(o°ω°o)！！";
	wprintf(L"%ls \n", a);
	SetPos(46, 35);               //设置光标
	system("pause");              //暂停命令
	system("cls");                //清屏
	SetPos(30, 14);    
	printf("使用 ↑ ↓ ← → 控制蛇身移动Ｏ(≧▽≦)Ｏ！！！\n");
	SetPos(42, 16);
	printf("F3加速，F4减速\n");
	SetPos(40, 35);
	system("pause");
	system("cls");
}
void CreateMap()
{
	SetPos(0, 0);
	int i = 0;
	for (i = 0; i <= 198; i += 2)
	{
		wprintf(L"%lc", WALL);
	}
	SetPos(0, 48);
	for (i = 0; i <= 198; i += 2)
	{
		wprintf(L"%lc", WALL);
	}
	//左打印
	for (i = 1; i <= 39; i++)
	{
		SetPos(0,i);
		wprintf(L"%lc", WALL);
	}
	for (i = 1; i <= 39; i++)
	{
		SetPos(100,i);
		wprintf(L"%lc", WALL);
	}
}
void InitSnake(pSnake ps)
{
	pNode cur = NULL;
	for (int i = 0; i < 5; i++)
	{
		cur = (pNode)malloc(sizeof(Node));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc()");
			return;
		}
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		cur->next = NULL;

		//头插一波
		if (ps->pSnake == NULL)
		{
			ps->pSnake = cur;
		}
		else
		{
			cur->next = ps->pSnake;
			ps->pSnake = cur;
		}
	}
	//打印蛇身
	cur = ps->pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	ps->Status = OK;
	ps->Socre = 0;
	ps->pFood = NULL;
	ps->SleepTime = 200;
	ps->Dir = RIGHT;
	ps->Add = 10;          //吃一口加十分啦
}
void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;
    again:
	do
	{
		x = rand() % 53 + 2;  //2 -- 54
		y = rand() % 25 + 1;  //1 -- 25
	} while (x % 2 != 0);     //x坐标必须为2的倍数
	
	//坐标不能和蛇身冲突
	pNode cur = ps->pSnake;
	while (cur)
	{
		//比较坐标
		if (cur->x == x && cur->y == y)
		{
			goto again;     //如果和蛇身发生冲突，则重新生成
		}
		cur = cur->next;
	}
	pNode pFood = (pNode)malloc(sizeof(Node));
	if (pFood == NULL)
	{
		perror("CreateFood()::malloc()");
		return;
	}
	pFood->x = x;
	pFood->y = y;
	ps->pFood = pFood;

	//打印食物
	SetPos(x, y);
	wprintf(L"%lc", FOOD);
}
void GameStart(pSnake ps)
{
	//控制台窗口的设置
	system("mode con cols=200 lines=300");
	system("title 贪吃蛇");
	//光标隐藏
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //获取句柄
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(handle, &cursor_info);       //获取控制台光标信息
	cursor_info.bVisible = false;                     //隐藏光标

	SetConsoleCursorInfo(handle, &cursor_info);       //设置光标
	//打印欢迎界面
	WelComeToGame();
	//创建地图
	CreateMap();
	//初始化贪吃蛇
	InitSnake(ps);
	//创建食物
	CreateFood(ps);
}
void GameRun(pSnake ps)
{
	PrintHelpInfo();
	do
	{
		SetPos(64, 10);
		printf("得分：%05d", ps->Socre);
	}while()
}
void PrintHelpInfo()
{
	SetPos(64, 15);
	printf("1.不能创墙，不能自己把自己创死");
	SetPos(64, 16);
	printf("2.使用 ↑ ↓ ← → 分别控制蛇的移动");
	SetPos(64, 17);
	printf("3.F3加速，F4减速");
	SetPos(64, 18);
	printf("4.ESC--退出，空格--暂停游戏");

	SetPos(64, 20);
	printf("大侠switch精心出品");
}