#include<stdio.h>
#include<string.h>
#include<iostream>
const int MAXD = 20;
int s[1 << MAXD];
int main()
{
	int D, I;
	while (scanf_s("%d%d", &D, &I) == 2)				//D��� IС�����
	{
		memset(s, 0, sizeof(s));			//���³�ʼ��Ϊ0
		int k, n = (1 << D) - 1;			//�ܴ�С����Ϊ2��n�η�-1
		for (int i = 0; i < I; i++)			//С��һ������
		{
			k = 1;							//��һ���ڵ�
			for (;;)						
			{
				s[k] = !s[k];				//s[k]״̬ȡ��
				k = s[k] ? k * 2 : k * 2 + 1;		//��s[k]��״̬ȡֵ
				if (k > n)
					break;
			}
		}
		printf("%d\n", k / 2);
	}
	system("pause");
}