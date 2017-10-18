#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<cstdlib>
#include<ctime>
const int Hang = 15;
const int Lie = 15;
const int WALL = 4;						//墙
const int She_tou = 9;					//蛇头
const int She_shen = 1;					//蛇身
const int Kongbai = 0;					//空白处
const int Food = 5;						//食物
using namespace std;
struct Jiedian											//节点
{
	int data;											//存放数据
	int  x;												//存放蛇的x坐标
	int y;												//存放蛇的y坐标
	Jiedian *next;										//指针域
	Jiedian(int X, int Y)
	{
		data = 9;
		x = X;
		y = Y;
		next = NULL;
	}
	Jiedian(int a, int X, int Y,Jiedian *l)		//初始化
	{
		data = a;
		x = X;
		y = Y;
		next = l;
	}
	
};
struct lianbiao											//链表
{
	int last_x;
	int last_y;
	Jiedian *Snack_Head;
	lianbiao( int x,int y)
	{
		Snack_Head = new Jiedian(x,y);
	}
	void Push_lianbiao(int a, int X, int Y);
	void Back(int k);
	~lianbiao()
	{
		Jiedian *p;
		p = Snack_Head;
		while (!p)
		{
			p = p->next;
			delete p;
		}
	}
};
class Snack
{
private:
	int i;													//记录蛇除蛇头外的长度
	int Food_x;												//食物的x坐标
	int snack[Hang][Lie];
	int Food_y;												//食物的y坐标
	int snack_head_x;										//蛇头的x坐标
	int snack_head_y;										//蛇头的y坐标
public:
	
	Snack();
	void map();	
	void Suiji_Food();										//随机食物
	bool Cleck_Food();										//检测是否有食物
	bool Eat_Food(lianbiao &s,int x,int y);					//吃掉食物
	bool Bang(int x, int y);								//碰撞检测
	void Move_Up(lianbiao &s, Snack &w);								//向上走
	void Move_Down(lianbiao &s, Snack &w);								//向下走
	void Move_Left(lianbiao &s, Snack &w);								//向左走
	void Move_Right(lianbiao &s, Snack &w);							//向右走
	bool Back_Move_Cleck(lianbiao &s,int a, int b);			//检测是否反向移动
	bool Time(char *c,int nandu);										//按键检测 时间检测
	void Duqu(lianbiao s);									//读取链表中的元素对数组进行重新赋值
	void GOGO(lianbiao &s, int x, int y);					//朝一个方向移动
	~Snack()
	{
	}
};