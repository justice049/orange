#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdbool.h>
#include<locale.h>
#include<time.h>

#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'

#define POS_X 24
#define POS_Y 5
typedef struct SnakeNode
{
	int x;    //横坐标
	int y;    //纵坐标
	struct SnakeNode* next;
}Node,*pNode;
enum DIRECTION //因为只有这几种就用枚举常量啦
{
   UP=1,
   DOWN,
   LEFT,
   RIGHT
};
enum GAME_STATUS
{ 
	OK,            //正常运行
	NORMAL_END,    //正常退出
	KILL_BY_WALL,  //撞墙噶
	KILL_BY_SELF   //衔尾蛇（bushi）
};
//贪吃蛇结构
typedef struct Snake
{
	pNode pSnake;            //指向头结点的指针（维护整条贪吃蛇）
	pNode pFood;             //指向食物结点的指针
	enum DIRECTION Dir;      //描述蛇方向
	enum GAME_STATUS Status; //游戏状态：正常、退出、撞墙、撞到自己
	int Socre;               //当前获得分数
	int Add;                 //默认每个食物10分，每个食物的分数
	int SleepTime;           //每⾛⼀步休眠时间，休息时间短则速度快，休息时间长则速度慢
}Snake,* pSnake;

//游戏开始--初始化
void GameStart(pSnake ps);

//欢迎界面
void WelComeToGame();

//创建地图
void CreateMap();

//初始化蛇
void InitSnake(pSnake ps);

//创建食物
void CreateFood(pSnake ps);

//游戏的正常运行
void GameRun(pSnake ps);

//打印帮助信息
void PrintHelpInfo();