/*无反值线性表插入*/ 
#include<stdio.h>
#define OK 1
#define NO 0
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{ElemType elem[MAXSIZE];
int last;
}SeqList;
SeqList l;
void charu(SeqList *l,int i,ElemType e);
int main()
{ElemType e;
int o,i,m;
printf("输入n个数:");
scanf("%d",&l.last);
printf("分别是:");
for(o=0;o<l.last;o++)
   scanf("%d",&l.elem[o]);
printf("在几个数字前插入:");
scanf("%d",&i);
printf("插入的数字为:");
scanf("%d",&e);
for(o=0;o<l.last+1;o++)
printf("%d  ",l.elem[o]);
}
void charu(SeqList *l,int i,ElemType e)
{int k;
if((i<1)||(l->last+2)) 
{printf("插入位置i值不合法");

}
if(l->last>=MAXSIZE-1)
{printf("表已满，无法插入");

}
for(k=l->last;k>=i-1;k--)
  l->elem[k+1]=l->elem[k];
l->elem[i-1]=e;
l->last++;

}

