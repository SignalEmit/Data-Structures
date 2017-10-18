#include<iostream>
#include<stdlib.h>
using namespace std;
class matrix
{
private:
	int H;
	int L;
	int *elem;
public:
	matrix();
	matrix(int a, int b);
	void shuru();
 matrix operator+(const matrix &a)
	{
		matrix s;
		s.H = a.H;
		s.L = a.L;
		for (int i = 0; i < s.L*s.H; i++)
			s.elem[i] = elem[i] + a.elem[i];
		return s;
	}
	void  show();
}; 
matrix::matrix()
{
	H = 0;
	L = 0;
	elem = new int[0];
}
matrix::matrix(int a, int b)
{
	H = a;
	L = b;
	elem = new int[H*L];
}
void matrix::shuru()
{
	for (int i = 0; i < H*L; i++)
		elem[i] = rand() % 9 + 1;
}

void matrix::show()
{
	cout << "¾ØÕóÊä³ö£º" << endl;
	for (int i = 0; i < L; i++)
	{
		for (int o = 0; o < H; o++)
			cout << elem[i*H + o] << " ";
		cout << endl;
	}
}
int main()
{
	matrix s1(2,2),s;
	s1.shuru();
	s1.show();
	matrix s2(2, 2);
	s2.shuru();
	s2.show();
	s1 = s1.operator+(s2);
	s1.show();
	system("pause");



}