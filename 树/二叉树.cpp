#include<iostream>
using namespace std;
template<class T>
class A
{
private:
	A<T> *left;
	A<T> *right;
public:
	T data;
	A(A<T> *l = NULL, A<T> *r = NULL) :left(l), right(r)
	{}
	A(const T item, A<T> *l = NULL, A<T> *r = NULL) :data(item), left(l), right(r)
	{}
	A<T> *&lf()
	{
		return left;
	}
	A<T> *&ri()
	{
		return right;
	}

};
template<class T>
class Tree
{
private:
	A<T> *root;
public:
	Tree()
	{
		root = NULL;
	}
	void MakeTree(const T item,Tree<T> &l,Tree<T> &ri)
	{
		root = new A<T>(item,l.root ,ri.root);
	}
	void show();
	void qianxu();//ǰ�����
	A<T>* chazhao(T x);//����Ԫ��T
	int jiediaangeshu();//����Ҷ�ڵ����
	int high();//���ĸ߶�
	void bijiao(Tree<T> &a);//�Ƚ������Ƿ����
};
int depth = 0;
template<class T>
//*�������������㷨*//
void zhao(A<T> *root,A<T> *p)  
{
	if (p != NULL&&root!=NULL)
	{
		if (root->lf() != p->lf())
		{
			cout << "���������" << endl;
			
		}
	}
	else
	{
		cout << "���������" << endl;
		
	}
}
template<class T>
void Tree<T>::bijiao( Tree<T> &a)
{
	zhao(root,a.root);
}
//*����ڵ����*//
template<class T>
int jishu(A<T> *root, int k)
{
	if (root != NULL)
	{
		if (k > depth)
			depth = k;
		return jishu(root->lf(), k + 1) >= jishu(root->ri(), k + 1) ? jishu(root->lf(), k + 1) :jishu(root->ri(), k + 1);
	}
	return depth;
}
template<class T>
int  Tree<T>::high()
{
	int k = 1;
	return jishu(root, k);
}
template<class T>
int Tree<T>::jiediaangeshu()
{
	int i;
	i = fangwen(root);
	return i;
}
//*����ڵ����㷨*//
template<class T>
int fangwen(A<T> *root)
{
	if (root==NULL)
		return 0;
	else if (root->lf() == NULL && root->ri() == NULL)
	{
		return 1;
	}
	else
		return ( fangwen(root->ri()) + fangwen(root->lf()));
}
template<class T>
A<T>* Tree<T>::chazhao(T x)
{
	A<T> *p;
	 p=find(root,x);
	 return p;
}
//*����Ԫ���㷨*//
template<class T>
A<T>* find(A<T> *root, T x)
{	
	A<T> *p;
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	if (root->lf()!= NULL)
	{
		p = find(root->lf(), x);
		if (p != NULL)
			return p;
	}
	if (root->ri() != NULL)
	{
		p = find(root->ri(), x);
		if(p!=NULL)
			return p;
	}
	return NULL;
}
template<class T>
void Tree<T>::show()
{
	int x = 0;
	di(root, x);
}
//*����㷨*//
template<class T>
void di(A<T> *root, int x)
{
	if (root != NULL)
	{
		di(root->ri(), x + 1);
			if(x!=0)
			{
				for (int i = 0; i < 6* (x + 1); i++)
					cout << " ";
				cout << "---";
			}
			cout << root->data<<endl;
			di(root->lf(), x + 1);
}
}
template<class T>
void Vist(A<T> *root)
{
	cout << root->data;
}
//*ǰ������㷨*//
template<class T>
void qianxu1(A<T> *root)
{
	if (root != NULL)
	{
		Vist(root);
		qianxu1(root->lf());
		qianxu1(root->ri());
		
	}
}
template<class T>
void Tree<T>::qianxu()
{
	qianxu1(root);
}
int main()
{
	Tree<char> a, b, c, d, e, f,o, g,h,null;
	o.MakeTree('O', null, null);
	c.MakeTree('C', null, null);
	h.MakeTree('H', o, null);
	e.MakeTree('E', h,null);
	f.MakeTree('F', null, null);
	d.MakeTree('D', e, f);
	b.MakeTree('B', c, null);
	a.MakeTree('A', b, d);
	a.show();
	cout << a.jiediaangeshu()<< endl;
	cout << "�����ĸ߶��ǣ�"<<a.high()<<endl;
	Tree<char> P;
	P.MakeTree('P', b, d);
	P.show();
	a.bijiao(P);
	system("pause");
}