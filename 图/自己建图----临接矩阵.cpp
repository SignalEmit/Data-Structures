#include<iostream>
#include<string>
using namespace std;
enum GraphEnum
{
	youxiang,wuxiang
};
class MyGraph
{
private:
	string str;
	int a[10][10];
public:
	MyGraph()
	{
		cout << "请输入树的定点:";
		cin >> str;
		
		for (int i = 1; i <= str.size(); i++)
			for (int o = 1; o <= str.size(); o++)
			{
				a[i][o] = 0;
			}
		cout << "请输入哪儿边和哪个边联通：";
		int x, y;
		while (cin >> x >> y)
		{
			a[x][y] = 1;
		}
		
	}
	void show()
	{
		for (int i = 1; i <= str.size(); i++)
			for (int o = 1; o <= str.size(); o++)
			{
				if (a[i][o] == 1)
				{
					cout << "边" << str[i - 1] << "和边" << str[o - 1] << "联通"<<endl;
				}
			}
	}
	void starDFS(int n)
	{
		bool *judge = new bool[str.size()];
		for (int i = 1; i <=str.size(); i++)
		{
			judge[i] = false;
		}
		DFS(n,judge);
	}
	void DFS(int n,bool judge[])
	{
		

		judge[n] = true;
		cout << str.at(n-1) << " ";
		for (int i = 1; i <= str.size(); i++)
		{
			if (a[i][n] == 1)
				if(!judge[i])
				{
					DFS(i, judge);
				}

		}
	}
};
int main()
{
	MyGraph A;
	A.starDFS(3);
	system("pause");
}