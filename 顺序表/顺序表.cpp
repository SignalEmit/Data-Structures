#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct
{
	int elem[MAXSIZE];
	int last;
}SeqList;
void shuru(SeqList *L)
{
	int i;
	scanf_s("%d", &L->last);
	printf("输入的数：");
		for (i = 0; i < L->last; i++)
			scanf_s("%d",&L->elem[i]);
}
int a(SeqList L, int e)
{
int	i = 0;
	while((i<=L.last)&&(L.elem[i]!=e))
		i++;
		if (i <= L.last)
			return(i+1);
		else
			return(-1);
	}
void b(SeqList *L, int i, int e)
{
	int k;
	if ((i < 1) || (i > L->last + 2))
		{
			printf("插入位置不合法！");
	return;
	}
	if (L->last >= MAXSIZE)
		{
			printf("表已满");
			return;
	}
		for (k = L->last; k >= i - 1; k--)
		{
			L->elem[k + 1] = L->elem[k];
		}
	L->elem[i - 1] = e;
	L->last++;
	printf("插入成功！");
}
int main()
{
	int i;
	SeqList L;
	shuru(&L);
	b(&L, 2, 8);
	printf("输出的数为：");
	for (i = 0; i < L.last; i++)
	{
		printf("%3d", L.elem[i]);
	}
	system("pause");
	return 0;
}