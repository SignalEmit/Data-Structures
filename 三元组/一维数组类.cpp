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
	T & operator[](int i)const;
	one <T> & operator=(const one <T> &s);
	one <T> operator+()const;
	friend one<T> operator+(const one <T>&e£¬const one <T> &s);
	one <T> operator-()const;
	one <T> operator-(const one <T> &s)const;
};
template<class T>
friend one<T> one <T>::operator+(const one <T>&e,const one <T> &s)
{
	one<T> w;
	w.size = e.size;
	for (int i = 0; i < size; i++)
		w.elem[i] = e.elem[i] + s.elem[i];
	return w;
}
int main()
{
	one<int> l(4);
	one<int> p;
	l.shuru();
	l.show();
	one<int> w(4);
		w.shuru();
		p = l + w;
	p.show();
	system("pause");
	


}
