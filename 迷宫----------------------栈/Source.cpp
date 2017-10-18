#include<iostream>
using namespace std;
struct Jiedian
{
	int Data;
	int *next;
	Jiedian();
	Jiedian(int x, int *next_null = nullptr);
};
Jiedian::Jiedian()
{
	next = NULL;
}
Jiedian::Jiedian(int x, int *next_null = nullptr)
{
	Data = x;
	next = next_null;
}
class Zhan
{
private:
	Jiedian *head;
public:
	Zhan();
	void Push(const int &c);
	void Back();
};
Zhan::Zhan()
{
	head = new Jiedian();
}
void Zhan::Push(const int &c)
{
	Jiedian *p;
	p = new Jiedian(c, head->next);
	head->next = p;
}
void Zhan::Back()
{
	Jiedian *q;
	q = head->next;
	q = q->next;
	head->next = q;
}