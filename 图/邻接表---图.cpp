#include<iostream>
#include<list>
#include<string>
 
using namespace std;
struct Node
{
	char c;
	int number;
	Node(char c_,int number_):c(c_),number(number_){}
};
class MyGraphy
{
private:
	list<Node> *biao;
	string str;
public:
	MyGraphy()
	{

		cout << "请输入顶点:";
		cin >> str;
		biao = new list<Node>[str.size()];
		for (int i = 0; i < str.size(); i++)
		{
			Node s(str.at(i), i);
			biao[i].push_back(s);
		}

		cout << "请输入图的连接情况：";
		int x,y;
		while (cin >> x>>y)
		{
			Node s(str.at(y-1), y-1);
			biao[x - 1].push_back(s);
		}
	}
	void show()
	{
		for (int i = 0; i < str.size(); i++)
		{
			cout << "顶点" << biao[i].begin()->c << "的连接边有：";
			for (auto a = biao[i].begin(); a != biao[i].end(); a++)
			{
				if(a!= biao[i].begin())
					cout << biao[i].begin()->c << "-----"<<a->c << "   ";
			}
			cout << endl;
		}
	}
	void DFS(int v)
	{
		bool *visit = new bool[str.size()];
		for (int i = 0; i <str.size(); i++)
			visit[i] = false;
		DFSTIL(v, visit);
	}
	void DFSTIL(int v, bool visit[])
	{
		visit[v] = true;
		cout << v << " ";
		for (auto i = biao[v].begin(); i != biao[v].end(); i++)
			if (!visit[i->number])
				DFSTIL(i->number,visit);
	}
};
int main()
{
	MyGraphy A;
	A.show();
	A.DFS(3);
	system("pause");
}