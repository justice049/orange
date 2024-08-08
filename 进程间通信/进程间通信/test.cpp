///////////////add.h/////////////////
//#ifndef __ADD_H__
//#define __ADD_H__ 
//int add(int a, int b);
//#endif // __ADD_H__
///////////////add.c/////////////////
//#include "add.h"
//int add(int a, int b)
//{
//	return a + b;
//}
//
///////////////sub.h/////////////////
//#ifndef __SUB_H__
//#define __SUB_H__ 
//int sub(int a, int b);
//#endif // __SUB_H__
///////////////add.c/////////////////
//#include "add.h"
//int sub(int a, int b)
//{
//	return a - b;
//}
//
/////////////main.c////////////////
//#include <stdio.h>
//#include "add.h"
//#include "sub.h"
//
//int main(void)
//{
//	int a = 10;
//	int b = 20;
//	printf("add(10, 20)=%d\n", a, b, add(a, b));
//	a = 100;
//	b = 20;
//	printf("sub(%d,%d)=%d\n", a, b, sub(a, b));
//}



//#include <math.h>
//#include <stdio.h>
//int main(void)
//{
//	double x = pow(2.0, 3.0);    
//	printf("The cubed is %f\n", x);    
//	return 0;
//}



#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DELAY 100000

int main() {
    int x, y, maxX, maxY; //��ͷ��λ�ú��ն˴��ڵĴ�С
    int direction = KEY_RIGHT; //����
    int snakeLength = 5; //�ߵĳ���
    int snakeX[100], snakeY[100]; //�����λ��
    int foodX, foodY; //ʳ���λ��
    int score = 0; //�÷�
    int gameOver = 0; //��Ϸ������־

    // ��ʼ��ncurses��
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(0);

    // ��ȡ�ն˴��ڵĴ�С
    getmaxyx(stdscr, maxY, maxX);

    // ��ʼ���ߵĳ�ʼλ�úͳ���
    x = maxX / 2;
    y = maxY / 2;
    for (int i = 0; i < snakeLength; i++) {
        snakeX[i] = x - i;
        snakeY[i] = y;
    }

    // ����ʳ��ĳ�ʼλ��
    srand(time(NULL));
    foodX = rand() % maxX;
    foodY = rand() % maxY;

    // ��Ϸѭ��
    while (!gameOver) {
        clear();

        // ������
        for (int i = 0; i < snakeLength; i++) {
            mvprintw(snakeY[i], snakeX[i], "O");
        }

        // ����ʳ��
        mvprintw(foodY, foodX, "*");

        // ��ʾ����
        mvprintw(0, 0, "Score: %d", score);

        // �ƶ��ߵ�λ��
        int nextX = snakeX[0];
        int nextY = snakeY[0];
        switch (direction) {
        case KEY_UP:
            nextY--;
            break;
        case KEY_DOWN:
            nextY++;
            break;
        case KEY_LEFT:
            nextX--;
            break;
        case KEY_RIGHT:
            nextX++;
            break;
        }

        // ����Ƿ�Ե�ʳ��
        if (nextX == foodX && nextY == foodY) {
            score++;
            snakeLength++;
            foodX = rand() % maxX;
            foodY = rand() % maxY;
        }

        // �ƶ��ߵ�����
        for (int i = snakeLength - 1; i > 0; i--) { //��һ���ƶ���ǰһ�ڵ�λ��
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }


        // ������ͷλ��
        snakeX[0] = nextX;
        snakeY[0] = nextY;

        // �����Ϸ��������
        //����Ƿ�Խ��
        if (nextX < 0 || nextX >= maxX || nextY < 0 || nextY >= maxY) {
            gameOver = 1;
        }
        //����Ƿ�ײ���Լ�������
        for (int i = 1; i < snakeLength; i++) {
            if (snakeX[i] == nextX && snakeY[i] == nextY) {
                gameOver = 1;
            }
        }

        // ˢ����Ļ
        refresh();

        // �ӳ�һ��ʱ��
        usleep(DELAY);

        // ��ȡ�û�����
        int key = getch();
        switch (key) {
        case KEY_UP:
        case KEY_DOWN:
        case KEY_LEFT:
        case KEY_RIGHT:
            direction = key;
            break;
        case 'q':
            gameOver = 1;
            break;
        }
    }

    // �����˳�ncurses��
    endwin();

    printf("Game Over! Your score: %d\n", score);

    return 0;
}
