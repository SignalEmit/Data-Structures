#include<iostream>
using namespace std;
template<class T>
class one
{
private:
	int size;
	T *elem;
public:
	one()
	{	
		elem = new T[50];
	}
	one(int e)
	{
		size = e;
		elem = new T[50];
	}
friend one<T> operator+(const one<T>&s, const one<T>&w)
	{
		one<T> p;
		p.size = s.size;
		for (int i = 0; i < 3; i++)
			p.elem[i] = s.elem[i] + w.elem[i];
		return p;
	}
	void shuru()
	{
		for (int i = 0; i < size; i++)
			cin >> elem[i];
	}
	void show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << elem[i] << "  ";
		}
	}
};
int main()
{
	one<int> l(3);
	l.shuru();
	l.show();
	one<int> w(3);
	w.shuru();
	one<int> p;
	p = l + w;
	system("pause");
	p.show();
	system("pause");

}
