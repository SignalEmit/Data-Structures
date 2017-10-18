#include <iostream>
using namespace std;
template <class T>
class linklist
{
	private:
		int maxsize;
		int length;
		T *elem;
	public:
	
		linklist(int max,int o);
		void shuru();
		~linklist()
		{
			delete []elem;
		}
		bool Isempty()const
		{
			return length==0;
		}
		bool Isfull()const
		{
			return length==maxsize;
		}
		
		int search(const T&b);
		int del(int k);
		void Insert(int k,const T&d);
		void shuchu();
};
template <class T>
linklist<T>::linklist(int max,int o)
{
	elem=new T[max];
	maxsize=max;
	length=o;
}
template <class T>
void linklist<T>::shuru()
{
	for(int k=0;k<length;k++)
		cin>>elem[k]; 
}
template <class T>
int linklist<T>::search(const T&b)
{ int k=-1;
	for(int i=0;i<length;i++)
		if(elem[i]==b)
			{
			k=i;
			return i;}
			if(k==-1)
			{
			cout<<"没找到"<<endl;
			
			} 
		}
template<class T>
int linklist<T>::del(int k)
{T c;
if(k<0||maxsize==0)
	cout<<"无法删除"<<endl;
	else
	{
	c=elem[k];
	for(int i=k;i<length;i++)
		elem[k]=elem[k+1];
	
		length=length-1;
		return c;}
		
	}
template<class T>
void linklist<T>::shuchu()
{	cout<<"输出为："; 
	for(int i=0;i<length;i++)
		cout<<elem[i]<<" ";
 } 
template<class T>
void linklist<T>::Insert(int k,const T&d)
{
	if(k<0||length+1>maxsize)
	  {
	  cout<<"无法插入"<<endl;
	  }
	  else
	  {
	  	for(int i=k;i<length;i++)
	  		elem[i+1]=elem[i];
		elem[k]=d; 
		length++; 
	  }
	  
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	linklist<int> s(15,4);
	s.shuru();
	cout<<"找到他的下表是:"<<s.search(2)<<endl;
	cout<<"删除的值是"<<s.del(1)<<endl; 
	s.shuchu();
	s.Insert(1,9);
	s.shuchu();
	
	return 0;
}
