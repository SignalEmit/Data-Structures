#include<iostream>
using namespace std;
struct A {
	int HH;
	int LH;
	int Sc;
};
class B {
private:
	int H;
	int feigeshu;
	int L;
	int *elem;
	int maxsize;
public:
	B(int a, int b, int c, int d);
	void show();
	void charu(int a,int b,int c);
	void zhuanzhi();
};
B::B(int a, int b,int c,int d)
{
	H = a;
	L = b; 
	feigeshu = c;
	maxsize = d;
	elem = new int[d];
	for (int i = 0; i < H*L; i++)
		elem[i] = 0;
}
void B::zhuanzhi()
{
	for(int i=0;i<L;i++)
		for (int o = 0; o < H; o++)
		{
			if(L>H)
			{
				int a;
				a = elem[i*H + o];
				elem[i*H + o] = elem[o*H + i];
				elem[o*H+i] = a;
			}
		}
}
void B::charu(int a, int b, int c)
{
	A n;
	n.HH = b;
	n.LH = a;
	n.Sc = c;
	elem[(n.LH - 1)*H + n.HH-1] = n.Sc;
}
void B::show()
{
	for(int i=0;i<L;i++)
	{
		for (int o = 0; o < H; o++)
			cout << elem[i*H + o] << " ";
		cout << endl;
	}
	cout << "\n" << endl;
}
int main()
{
	B l(3, 3, 2, 100);
	l.show();
	int c,a,b;
	cout << "一次输入插入的行列和元素：" << endl;
	cin >> a;
	while(a!=-1)
	{
		cin >> b >> c;
		l.charu(a,b, c);
		cin >> a;
	}
	l.show();
	l.zhuanzhi();
	l.show();
	system("pause");
}
