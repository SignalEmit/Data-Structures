#include<iostream>
using namespace std;
template<class T>
struct MyStruct								//节点 struct 默认访问public 
{
	T data;
	MyStruct *next;
	MyStruct()								//默认构造函数  头结点使用 
	{
		next = NULL;
	}
	MyStruct(const T &x)				
	{
		data = x;
		next = NULL;
	}
	MyStruct(const T& p, MyStruct<T> *l = NULL)			//做插入使用 
	{
		data = p;
		next = l;
	}
};
template<class T>
class linklist											//链表类 
{
private:
	MyStruct<T> *head;									//头指针 
public:
	linklist()											//构造函数 
	{
		head = new MyStruct<T>();					//初始化链表头结点  使用节点类第一个构造函数 
	}
	void toucha();									//头插法 
	void show();									//输出 
	void houxushuchu();
	int jisuanjidiangeshu();
	void shanchu(int i);
	void chazhaoyuansu(T c);
	void charu(T c, int i);
	void lianjie(const linklist<T> &s);
	void gai(linklist<T> &s,const T&a,const T&change);
};
template<class T>
void linklist<T>::gai(linklist<T> &s,const T&a,const T&change)				//修改 
{
	MyStruct<T> *zhizhen;					//申请一个节点指向头节点 保证  头结点不移动 
	zhizhen=head->next;
	while(zhizhen!=NULL)					//遍历节点 
	{
		if(zhizhen->data==a)				//找到的话重新赋值 
		{		
			zhizhen->data=change;
		}
		zhizhen=zhizhen->next;					//指针下移 
	}
}
template<class T>
void linklist<T>::lianjie(const linklist<T> &s)		//节点连接 
{
	MyStruct<T> *p;
	p=jiansuo(jisuanjidiangeshu(), head);
	p ->next= s.head->next;

}
template<class T>
void linklist<T>::charu(T c, int i)					//插入节点 
{
	MyStruct<T> *p,*q;
	p=jiansuo(i, head);								//找到节点位置  并返回节点位置			
	q = new MyStruct<T>(c, p->next);				//和节点插入同 
	p->next = q;
}
template<class T>
void linklist<T>::shanchu(int i)					//删除 
{	
	MyStruct<T> *p,*q;						//和节点插入相同，不过此操作  删除节点 
	p = jiansuo(i,head);	//找到节点位置  并返回节点位置	
	q = p->next;			//跳过该节点 
	p->next = q->next;		//节点链连接 
}
template<class T>
int linklist<T>::jisuanjidiangeshu()				//循环遍历节点个数   和修改相同 
{
	MyStruct<T> *p;
	int i=0;
	p = head->next;
	while (p != NULL)
	{
		i ++;
		p = p->next;
	}
	return i;
}
template<class T>
MyStruct<T> * jiansuo(int i,MyStruct<T> *head)				//用于检索节点 
{
	MyStruct<T> *p;
	int x = 1;
	p = head->next;
	while (p != NULL && x != i)
	{
		if (i == 0)
			return p;
		p = p->next;
		x++;
	}
	return p;
}
template<class T>
void linklist<T>::houxushuchu()								//正向输出 
{
	int p;
	MyStruct<T> *q;
	p = jisuanjidiangeshu();
	cout << "输出的数依次是：" ;
	for (int i = p; i >= 1; i--)
	{
		q = jiansuo(i,head);
		cout << q->data << " ";
	}
	cout << endl;
}
template<class T>
void linklist<T>::toucha()								//头插法 
{
	MyStruct<T> *p;
	T x;
	cout << "输入待插入的值 当输入“！”时退出：";
	cin >> x;
	while (x != '!')
	{
		p = new MyStruct<T>(x, head->next);
		head->next = p;
		cin >> x;
	}
}
template<class T>
void linklist<T>::show()							//后续输出 
{
	MyStruct<T> *p;
	p = head->next;
	cout << "反着输出的数依次是：";
	while (p != NULL)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}
template<class T>
void linklist<T>::chazhaoyuansu(T c)					//查找 和修改操作相同 
{
	MyStruct<T> *p;
	p = head->next;
	int i = 0;
	while (p != NULL)
	{
		if (p->data == c)
		{cout << "找到了" << endl;
		return;
	}
		p = p->next;
		}
	cout << "没找到" << endl;
}
int main()
{
	linklist<int> l;										//申请链表对象 
	l.toucha();		//头插          剩下的部分都是调用函数  完成操作，第一句都可以看作注释 
	cout << "此连表的节点个数为：" << l.jisuanjidiangeshu() << endl;
	l.houxushuchu();
	l.show();
	int a;
	cout << "输入要删除的位置：";
	cin >> a;
	if (a > l.jisuanjidiangeshu())
		cout << "删除位置错误" << endl;
	else
	{
		l.shanchu(l.jisuanjidiangeshu() - a);
		l.houxushuchu();
	}
	cout << "输入需要查找的元素：";
int c;
	cin >> c;
	l.chazhaoyuansu(c);
	char pppp,qqqq;
	cout<<"输入待修改的值：";
	cin>>pppp;
	cout<<"输入修改后的值：";
	cin>>qqqq;
	l.gai(l,pppp,qqqq);
	cout << "输入需要插入的元素：";
	int s;
	int t;
	cin >> s;
	cout << "输入待插入的位置：";
	cin >> t;
	if (t > l.jisuanjidiangeshu() || t <= 0)
		cout << "插入的位置错误" << endl;
	else
	{
		l.charu(s, l.jisuanjidiangeshu() - t + 1);
		l.houxushuchu();
	}
	linklist<int> b;
	b.toucha();
	b.lianjie(l);
	cout << "两链表链接输出：";
	b.houxushuchu();
	system("pause");
	return 0;
}

