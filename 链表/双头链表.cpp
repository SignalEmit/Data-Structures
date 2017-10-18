#include <iostream>
using namespace std;
template<class T>
struct A
{
	T data;
	A<T> *right;
	A<T> *left;
	A()
	{
		right=NULL;
		left=NULL;
	}
	A(T item,A<T> *l=NULL,A<T> *o=NULL)
	{
		data=item;
		right=l;
		left=o;
	}
	
 } ;
 template<class T>
 class linklist
 {
 	private:
 		A<T> *head;
 		int lef;
 		int rih;
 	public:
 		linklist()
 		{
 			head=new A<T>();
 			lef=0;
 			rih=0;
		 }
	int jishuleft();
		int jishuright();
		void charuleft(T item);
		void charuright(T item);
		void show(); 
};
template<class T>
int linklist<T>::jishuleft()
{
	A<T> *p;
	p=head->left;
	while(p!=NULL)
		lef++;
	return lef;
	
}
template<class T>
int linklist<T>::jishuright()
{
	A<T> *p;
	p=head->right;
	while(p!=NULL)
		rih++;
	return rih;
	
}
template<class T>
void linklist<T>::charuright(T item)
{
	A<T> *p,*q;
	q=head;
	p=new A<T>(item,q->right,NULL);
	q->right=p;
}
template<class T>
void linklist<T>::show()
{
	A<T> *p;
	p=head->right;
	while(p!=NULL)
		cout<<p->data<<" ";
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	linklist<int> l;
	for(int i=0;i<6;i++)
	l.charuright(i);
	l.show();
	return 0;
}
