#include<iostream>
#include<list>
#include<string>
using namespace std;
class Data
{
private:
	string name;
	string street;
	string city;
	string EIP;
	string country;
	string phone_number;
public:
	void name_();
	void street_();
	void city_();
	void EIP_();
	void country_();
	void phone_number_();
	string name_1();
	string street_1();
	string city_1();
	string EIP_1();
	string country_1();
	string phone_number_1();
	void Change_name();
	void Change_street();
	void Change_city();
	void Change_EIP();
	void Change_country();
	void Change_phone_number();
};
void Data::Change_name()
{
	cout << "\t\t请重新输入姓名";
	string s;
	cin >> s;
	name = s;
}
void Data::Change_street()
{
	cout << "\t\t请重新输入街道";
	string s;
	cin >> s;
	street = s;
}
void Data::Change_city()
{
	cout << "\t\t请重新输入城市";
	string s;
	cin >> s;
	city = s;
}
void Data::Change_EIP()
{
	cout << "\t\t请重新输入邮编";
	string s;
	cin >> s;
	EIP = s;
}
void Data::Change_country()
{
	cout << "\t\t请重新输入国家";
	string s;
	cin >> s;
	country = s;
}
void Data::Change_phone_number()
{
	cout << "\t\t请重新输入电话号码";
	string s;
	cin >> s;
	phone_number = s;
}
void Data::phone_number_()
{
	cout << "\t\t\t输入电话：";
	cin >> phone_number;
}
string Data::phone_number_1()
{
	return phone_number;
}
string Data::country_1()
{
	return country;
}
string Data::name_1()
{
	return name;
}
string Data::street_1()
{
	return street;
}
string Data::city_1()
{
	return city;
}
string Data::EIP_1()
{
	return EIP;
}
void Data::city_()
{
	cout << "\t\t\t输入城市：";
	cin >> city;
}
void Data::street_()
{
	cout << "\t\t\t输入街道：";
	cin >> street;
}
void Data::name_()
{
	cout << "\t\t\t输入姓名：";
	cin >> name;
}
void Data::EIP_()
{
	cout << "\t\t\t邮    编：";
	cin >> EIP;
}
void Data::country_()
{
	cout << "\t\t\t输入国家：";
	cin >> country;
}
class Tongxunlu
{
private:
	int i;
	list<Data> a;
public:
	void enter();			//输入
	void display(string s);	//查找并显示信息
	void search(string s);	//按姓名查找是否有此人
	void delete_(string s,string w);	//按姓名删除一个人
	void xiugaixinxi();
};
void genggaigongneng()
{
	cout << "\t\t\t输入1时更改姓名" << endl;
	cout << "\t\t\t输入2时更改电话" << endl;
	cout << "\t\t\t输入3时更改国家" << endl;
	cout << "\t\t\t输入4时更改街道" << endl;
	cout << "\t\t\t输入5时更改城市" << endl;
	cout << "\t\t\t输入6时更改邮编" << endl;
	cout << "\t\t\t输入0退出此界面" << endl;
	cout << "\t\t\t输入其他重新输入" << endl;
	cout << "\t\t\t\t请选择：";
}
void Tongxunlu::xiugaixinxi()
{
	string s_name;		//输入想要查找的人的姓名
	string s_phone_number; //想要查的人的电话号码
	cout << "\t\t输入想要更改信息人的名字：";
		cin >> s_name;
		cout << "\t\t输入想要更改信息人的电话：";
		cin >> s_phone_number;
	auto p = a.begin();
	while (p != a.end())
	{
		if (p->name_1() == s_name&&p->phone_number_1() == s_phone_number)
			break;
	}
	if (p == a.end())
	{
		cout << "\t\t未找到这个人";
		return;
	}
	while (1)
	{
		genggaigongneng();
		int i;
		cin >> i;
		cout << endl;
		switch (i)
		{
		case 1:p->Change_name(); break;
		case 2:p->Change_phone_number(); break;
		case 3:p->Change_country(); break;
		case 4:p->Change_street(); break;
		case 5:p->Change_city(); break;
		case 6:p->Change_EIP(); break;
		case 0:return;
		default:
			break;
		}
		system("cls");
	}
}
void Tongxunlu::delete_(string s,string w)
{
	auto c = a.begin();
	while (c != a.end())
	{
		if (c->name_1() == s&&c->phone_number_1()==w)
		{
			cout << "\t\t\t找到了" << endl;
			c = a.erase(c);
			return;
		}
		else
			c++;
	}
	cout << "\t\t\t没找到" << endl;
}
void Tongxunlu::display(string s)
{
	auto p = a.begin();
	while (p != a.end())
	{
		if (p->name_1() == s)
		{
			cout << "这个人的姓名为：";
			for (auto c : p->name_1())
				cout << c;
			cout << ends;
			cout << "这个人的电话号码为：";
			for (auto c : p->phone_number_1())
				cout << c;
			cout << ends;
			cout << "这个人的国家为：";
			for (auto c : p->country_1())
				cout << c;
			cout << ends;
			cout << "这个人的邮编为：";
			for (auto c : p->EIP_1())
				cout << c;
			cout << ends;
			cout << "这个人所住的街道：";
			for (auto c : p->street_1())
				cout << c;
			cout << ends;
			cout << "这个所住的城市为：";
			for (auto c : p->city_1())
				cout << c;
			cout << endl;
		}
		p++;
	}
	cout << "没找到";
}
void Tongxunlu::search(string w)
{
	auto c = a.begin();
	while (c != a.end())
	{
		if (c->name_1()== w)
		{
			cout << "找到了" << endl;
		}
		c++;
	}
	return;
		cout << "没找到" << endl;
}
void Tongxunlu::enter()
{
	Data people;
	people.name_();
	people.city_();
	people.country_();
	people.EIP_();
	people.street_();
	people.phone_number_();
	a.push_back(people);
		}
void Jiemianxuanzhe()
{
	cout << "\t\t输入1时进入成员输入界面"<<endl;
	cout << "\t\t输入2时进入按姓名查找界面查找是否有此人存在" << endl;
	cout << "\t\t输入3时进入按姓名选择输出个人信息界面" << endl;
	cout << "\t\t输入4时进入按姓名删除某个人信息界面" << endl;
	cout << "\t\t输入5时进入信息更改界面(更改时必须姓名和电话一起)" << endl;
	cout << "\t\t按0退出程序" << endl;
	cout << "\t\t按其他键重新输入" << endl;
	cout << "\t\t\t请选择：";
}
int main()
{
	system("color f4");
	Tongxunlu w;
	while (1)
	{
		Jiemianxuanzhe();
		int a;
		cin >> a;
		cout << endl << endl;
		switch (a)
		{
		case 1: {w.enter(); }; break;
		case 3: {string k;
			cout << "\t\t请输入需查找人的姓名：";
			cin >> k;
			w.display(k);
			system("pause"); }; break;
		case 2: {string k;
			cout << "\t\t请输入需查找人的姓名：";
			cin >> k;
			w.search(k);
			system("pause"); }; break;
		case 4: {string k;
			cout << "\t\t请输入需删除人的姓名：";
			cin >> k;
			cout << endl;
			cout << "\t\t请输入需删除人的电话：";
			string s;
			cin >> s;
			w.delete_(k,s); }; break;
		case 5:w.xiugaixinxi(); break;
		case 0:exit(0); break;
		default:
			break;
		}
		system("cls");
	}
}