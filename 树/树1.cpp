#include<stdio.h>
#include<string.h>
#include<iostream>
const int MAXD = 20;
int s[1 << MAXD];
int main()
{
	int D, I;
	while (scanf_s("%d%d", &D, &I) == 2)				//D深度 I小球个数
	{
		memset(s, 0, sizeof(s));			//重新初始化为0
		int k, n = (1 << D) - 1;			//总大小不能为2的n次方-1
		for (int i = 0; i < I; i++)			//小球一次下落
		{
			k = 1;							//第一个节点
			for (;;)						
			{
				s[k] = !s[k];				//s[k]状态取反
				k = s[k] ? k * 2 : k * 2 + 1;		//看s[k]的状态取值
				if (k > n)
					break;
			}
		}
		printf("%d\n", k / 2);
	}
	system("pause");
}