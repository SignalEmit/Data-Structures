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
int charu(SeqList *l,int i,ElemType e);
int main()
{ElemType e;
int o,i,m;
printf("����n����:");
scanf("%d",&l.last);
printf("�ֱ���:");
for(o=0;o<l.last;o++)
   scanf("%d",&l.elem[o]);
printf("�ڼ�������ǰ����:");
scanf("%d",&i);
printf("���������Ϊ:");
scanf("%d",e);
m=charu(&l,i,e);
if(m==OK)
printf("�Ѳ���");
else
printf("û�в���");
return 0; 
}
int charu(SeqList *l,int i,ElemType e)
{int k;
if((i<1)||(l->last+2)) 
{printf("����λ��iֵ���Ϸ�");
return (NO);
}
if(l->last>=MAXSIZE-1)
{printf("���������޷�����");
return (NO);
}
for(k=l->last;k>=i-1;k--)
  l->elem[k+1]=l->elem[k];
l->elem[i-1]=e;
l->last++;
return (OK);
}

