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
int Delete(SeqList *l,int i,ElemType *e);
int main()
{ElemType e;
int o,i,m;
printf("输入n个数:");
scanf("%d",&l.last);
printf("分别是:");
for(o=0;o<l.last;o++)
   scanf("%d",&l.elem[o]);
printf("删除第n个数字");
scanf("%d",&i);
printf("删除的第i个数字是:") ;
scanf("%d",&e);
m=Delete(&l,i,&e);
if(m==OK)
printf("这个数已删除");
else
printf("这个数未删除");
printf("返回的值依次是");
for(o=0;o<l.last-1;o++) 
printf("%d   ",l.elem[o]);
return 0;
}
int Delete(SeqList *l,int i,ElemType *e)
{int k;
if((i<1)||(i>l->last+1))
{printf("删除位置不合法!");
return (NO);
}
*e=l->elem[i-1];
for(k=i;i<=l->last;k++) 
l->elem[k-1]=l->elem[k];
l->last--;
return (OK);
}
