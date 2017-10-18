#include<iostream>
using namespace std;
template<class T>
class Tree
{
private:
	Tree<T> *left;
	Tree<T> *right;
public:
	T data;
	Tree() :left(NULL), right(NULL)
	{}
	Tree(T item, Tree<T> *l = NULL, Tree<T> *r = NULL) :data(item), left(l), right(r)
	{}
	Tree<T> *&lf(void)
	{
		return left;
	}
	Tree<T> *&ri(void)
	{
		return right;
	}

};
template<class T>
Tree<T>* GetTree(const T item, Tree<T> *l = 0, Tree<T> *r = 0)
{
	Tree<T> *p;
	p = new Tree<T>(item, l, r);
	return p;
}
void MakeTree(Tree<char> *&root)
{
	Tree<char>  *c, *g, *e, *b, *f, *d, *kong = 0;
	c = GetTree('C');
	g = GetTree('G');
	e = GetTree('E');
	b = GetTree('B', c);
	f = GetTree('F', kong, g);
	d = GetTree('D', e, f);
	root = GetTree('A', b, d);
}
template<class T>
void show(Tree<T> *root, int level)
{
	if (root != NULL)
	{
		show(root->ri(), level + 1);
		if (level != 0)
		{
			for (int i = 0; i < 6 * (level + 1); i++)
				cout << " ";
			cout << "----";
		}
		cout << root->data << endl;
		show(root->lf(), level + 1);
	}
}
template<class T>
void qianxu(Tree<T> *t)
{
	if (t != NULL)
	{
		Vist(t);
		qianxu(t->lf());
		qianxu(t->ri());
	}
}
template<class T>
void zhongxu(Tree<T> *t)
{
	if (t != NULL)
	{
		zhongxu(t->lf());
		Vist(t);
		zhongxu(t->ri());
	}
}
template<class T>
void houxu(Tree<T> *t)
{
	if (t != NULL)
	{
		houxu(t->lf());
		houxu(t->ri());
		Vist(t);
	}
}
template<class T>
void Vist(Tree<T> *s)
{
	cout << s->data << " ";
}
template<class T>
void shifangkongjian(Tree<T> *p)
{
	if ((p->lf() != NULL) && p != NULL)
		shifangkongjian(p->lf());
	if ((p->ri()) && p != NULL)
		shifangkongjian(p->ri());
	delete p;
}
template<class T >
Tree<T> *find(Tree<T> *s,T x)
{
	Tree<T> *p;
	if (s == NULL)
		return NULL;
	if (s->data == x)
		return s;
	if (s->lf() != NULL)
	{
		p = find(s->lf(), x);
		if (p != NULL)
			return p;
	}
	if (s->ri() != NULL)
	{
		p = find(s->ri(), x);
			return p;
	}
	return NULL;
}
int main()
{
	Tree <char> *gen=NULL;
	Tree<char> *o;
	MakeTree(gen);
	show(gen,0);
	cout << endl;
	cout << "前序遍历：" << endl;
	qianxu(gen);
	cout << endl;
	cout << "中序遍历：" << endl;
	zhongxu(gen);
	cout << endl;
	cout << "后序遍历" << endl;
	houxu(gen);
	cout << endl;
	o = find(gen, 'G');
	if (o == NULL)
		cout << "没找到" << endl;
	else
		cout << "找到了" << endl;
	system("pause");
}