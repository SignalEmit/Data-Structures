#include<iostream>
using namespace std;
template<class T>
struct MyStruct								//�ڵ� struct Ĭ�Ϸ���public 
{
	T data;
	MyStruct *next;
	MyStruct()								//Ĭ�Ϲ��캯��  ͷ���ʹ�� 
	{
		next = NULL;
	}
	MyStruct(const T &x)				
	{
		data = x;
		next = NULL;
	}
	MyStruct(const T& p, MyStruct<T> *l = NULL)			//������ʹ�� 
	{
		data = p;
		next = l;
	}
};
template<class T>
class linklist											//������ 
{
private:
	MyStruct<T> *head;									//ͷָ�� 
public:
	linklist()											//���캯�� 
	{
		head = new MyStruct<T>();					//��ʼ������ͷ���  ʹ�ýڵ����һ�����캯�� 
	}
	void toucha();									//ͷ�巨 
	void show();									//��� 
	void houxushuchu();
	int jisuanjidiangeshu();
	void shanchu(int i);
	void chazhaoyuansu(T c);
	void charu(T c, int i);
	void lianjie(const linklist<T> &s);
	void gai(linklist<T> &s,const T&a,const T&change);
};
template<class T>
void linklist<T>::gai(linklist<T> &s,const T&a,const T&change)				//�޸� 
{
	MyStruct<T> *zhizhen;					//����һ���ڵ�ָ��ͷ�ڵ� ��֤  ͷ��㲻�ƶ� 
	zhizhen=head->next;
	while(zhizhen!=NULL)					//�����ڵ� 
	{
		if(zhizhen->data==a)				//�ҵ��Ļ����¸�ֵ 
		{		
			zhizhen->data=change;
		}
		zhizhen=zhizhen->next;					//ָ������ 
	}
}
template<class T>
void linklist<T>::lianjie(const linklist<T> &s)		//�ڵ����� 
{
	MyStruct<T> *p;
	p=jiansuo(jisuanjidiangeshu(), head);
	p ->next= s.head->next;

}
template<class T>
void linklist<T>::charu(T c, int i)					//����ڵ� 
{
	MyStruct<T> *p,*q;
	p=jiansuo(i, head);								//�ҵ��ڵ�λ��  �����ؽڵ�λ��			
	q = new MyStruct<T>(c, p->next);				//�ͽڵ����ͬ 
	p->next = q;
}
template<class T>
void linklist<T>::shanchu(int i)					//ɾ�� 
{	
	MyStruct<T> *p,*q;						//�ͽڵ������ͬ�������˲���  ɾ���ڵ� 
	p = jiansuo(i,head);	//�ҵ��ڵ�λ��  �����ؽڵ�λ��	
	q = p->next;			//�����ýڵ� 
	p->next = q->next;		//�ڵ������� 
}
template<class T>
int linklist<T>::jisuanjidiangeshu()				//ѭ�������ڵ����   ���޸���ͬ 
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
MyStruct<T> * jiansuo(int i,MyStruct<T> *head)				//���ڼ����ڵ� 
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
void linklist<T>::houxushuchu()								//������� 
{
	int p;
	MyStruct<T> *q;
	p = jisuanjidiangeshu();
	cout << "������������ǣ�" ;
	for (int i = p; i >= 1; i--)
	{
		q = jiansuo(i,head);
		cout << q->data << " ";
	}
	cout << endl;
}
template<class T>
void linklist<T>::toucha()								//ͷ�巨 
{
	MyStruct<T> *p;
	T x;
	cout << "����������ֵ �����롰����ʱ�˳���";
	cin >> x;
	while (x != '!')
	{
		p = new MyStruct<T>(x, head->next);
		head->next = p;
		cin >> x;
	}
}
template<class T>
void linklist<T>::show()							//������� 
{
	MyStruct<T> *p;
	p = head->next;
	cout << "����������������ǣ�";
	while (p != NULL)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}
template<class T>
void linklist<T>::chazhaoyuansu(T c)					//���� ���޸Ĳ�����ͬ 
{
	MyStruct<T> *p;
	p = head->next;
	int i = 0;
	while (p != NULL)
	{
		if (p->data == c)
		{cout << "�ҵ���" << endl;
		return;
	}
		p = p->next;
		}
	cout << "û�ҵ�" << endl;
}
int main()
{
	linklist<int> l;										//����������� 
	l.toucha();		//ͷ��          ʣ�µĲ��ֶ��ǵ��ú���  ��ɲ�������һ�䶼���Կ���ע�� 
	cout << "������Ľڵ����Ϊ��" << l.jisuanjidiangeshu() << endl;
	l.houxushuchu();
	l.show();
	int a;
	cout << "����Ҫɾ����λ�ã�";
	cin >> a;
	if (a > l.jisuanjidiangeshu())
		cout << "ɾ��λ�ô���" << endl;
	else
	{
		l.shanchu(l.jisuanjidiangeshu() - a);
		l.houxushuchu();
	}
	cout << "������Ҫ���ҵ�Ԫ�أ�";
int c;
	cin >> c;
	l.chazhaoyuansu(c);
	char pppp,qqqq;
	cout<<"������޸ĵ�ֵ��";
	cin>>pppp;
	cout<<"�����޸ĺ��ֵ��";
	cin>>qqqq;
	l.gai(l,pppp,qqqq);
	cout << "������Ҫ�����Ԫ�أ�";
	int s;
	int t;
	cin >> s;
	cout << "����������λ�ã�";
	cin >> t;
	if (t > l.jisuanjidiangeshu() || t <= 0)
		cout << "�����λ�ô���" << endl;
	else
	{
		l.charu(s, l.jisuanjidiangeshu() - t + 1);
		l.houxushuchu();
	}
	linklist<int> b;
	b.toucha();
	b.lianjie(l);
	cout << "���������������";
	b.houxushuchu();
	system("pause");
	return 0;
}

