#include<iostream>
#include<stdlib.h> 
#define m 100
using namespace std;
typedef struct
{	int shuju[m];
	int top;
}q;

void chushihua(q *s)									//ջ�ĳ�ʼ�� 
{

s->top=-1;
}
int jinzhan(q *s,int x)										//��ջ���� 
{if(s->top==m-1)
	return (0);
		else
			{s->top++;
			s->shuju[s->top]=x;
			return 1;
			}
}
int chuzhan(q *s,int *x)									//��ջ���� 
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
cout<<"��ջ�Ƿ�ɹ�"<<jinzhan(s,x)<<endl;								//��ջ 
cout<<"��ջ�Ƿ�ɹ�"<<chuzhan(s,p)<<endl; 								//��ջ 
return 0; 
}
