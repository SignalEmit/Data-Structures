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
printf("����n����:");
scanf("%d",&l.last);
printf("�ֱ���:");
for(o=0;o<l.last;o++)
   scanf("%d",&l.elem[o]);
printf("ɾ����n������");
scanf("%d",&i);
printf("ɾ���ĵ�i��������:") ;
scanf("%d",&e);
m=Delete(&l,i,&e);
if(m==OK)
printf("�������ɾ��");
else
printf("�����δɾ��");
printf("���ص�ֵ������");
for(o=0;o<l.last-1;o++) 
printf("%d   ",l.elem[o]);
return 0;
}
int Delete(SeqList *l,int i,ElemType *e)
{int k;
if((i<1)||(i>l->last+1))
{printf("ɾ��λ�ò��Ϸ�!");
return (NO);
}
*e=l->elem[i-1];
for(k=i;i<=l->last;k++) 
l->elem[k-1]=l->elem[k];
l->last--;
return (OK);
}
