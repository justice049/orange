#include<stdio.h>
struct area
{
	int start;
	int end;
};
struct destop
{
	struct area left;
	struct area right;
};
int main()
{
	struct destop d;
	d.left.start = 1;
	d.left.end = 50;
	d.right.start = 50;
	d.right.end = 100;
	//下面是区域的调整：
	d.left.start = 1;
	d.left.end += 20;

	d.right.start -= 20;
	d.right.end = 100;
	return 0;
}