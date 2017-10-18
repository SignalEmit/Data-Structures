#include<iostream>
#include<stdlib.h> 
#define m 100
using namespace std;
typedef struct
{	int shuju[m];
	int top;
}q;

void chushihua(q *s)									//栈的初始化 
{

s->top=-1;
}
int jinzhan(q *s,int x)										//进栈运算 
{if(s->top==m-1)
	return (0);
		else
			{s->top++;
			s->shuju[s->top]=x;
			return 1;
			}
}
int chuzhan(q *s,int *x)									//出栈运算 
{if(s->top==-1)
	return 0;
		else
			{
			*x=s->shuju[s->top];
			s->top--;
			return 1;}
			
}


int main()
{q *s;
int *p;
int x;
cin>>x;
cout<<"进栈是否成功"<<jinzhan(s,x)<<endl;								//进栈 
cout<<"出栈是否成功"<<chuzhan(s,p)<<endl; 								//出栈 
return 0; 
}
