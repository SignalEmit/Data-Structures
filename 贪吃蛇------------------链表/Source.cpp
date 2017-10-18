#include"Head.cpp"
void lianbiao::Push_lianbiao(int a, int X, int Y)				//给链表添加元素
{
	Jiedian *p;													//创建节点p
	p = new Jiedian(a, X, Y, Snack_Head->next);					//给节点p赋值
	Snack_Head->next = p;
}
void lianbiao::Back(int k)										//将链表的最后一个数释放掉
{
	Jiedian *p;
	p = Snack_Head->next;										//出栈
	int i=1;
		if (k == 1)
		{
			last_x = p->x;
			last_y =p->y ;
			Snack_Head->next = NULL;
		}
	else
	{
		while (p != NULL&&i < k - 1)
		{
			p = p->next;
			i++;
		}
		Jiedian *q;
		q = p;
		p = p->next;
		last_x = p->x;
		last_y = p->y;
		q->next = NULL;
	}
	
}
Snack::Snack()															//初始化蛇的所有东西
{
	for (int i = 0; i != Hang; i++)
		for (int o = 0; o != Lie; o++)	
			if (i == 0 || o == 0 || i == Hang - 1 || o == Lie - 1)		
				snack[i][o] = WALL;										//初始化墙	
			else
				snack[i][o] = Kongbai;									//初始化空白处
	snack_head_x = Hang / 2;
	snack_head_y = Lie / 2;
	snack[snack_head_x][snack_head_y] = She_tou;						//初始化蛇头
	i = 0;																//初始化蛇的蛇身
}
void Snack::map()
{
	system("color fc");
	cout << "\t\t\t\t\t******************************贪吃蛇****************************"<<endl;
	cout << "\t\t\t\t\t****************************************************************" << endl;
	cout << "\t\t\t\t\t****************************************************************" << endl;
	cout << "\t\t\t\t\t****************************************************************" << endl;
	cout << "\t\t\t\t\t\t\t\t    向上走按w" << endl;
	cout << "\t\t\t\t\t\t\t\t    向下走按s" << endl;
	cout << "\t\t\t\t\t\t\t\t    向左走按a" << endl;
	cout << "\t\t\t\t\t\t\t\t    向右走按d" << endl;
	for (int i = 0; i != Hang; i++)
	{
		cout << "\t\t\t\t\t\t\t";
		for (int o = 0; o != Lie; o++)
			switch (snack[i][o])
			{
			case WALL:cout << "■"; break;								//墙
			case Kongbai:cout << "  "; break;							//空白
			case She_tou:cout << "☆"; break;							//蛇头
			case Food:cout << "●"; break;								//食物
			case She_shen:cout << "⊙"; break;							//蛇身
			}
		cout << endl;
	}
}
void Snack::Suiji_Food()								//随机出食物
{
	while (1)
	{
	Food_x = rand() % (Hang - 1) + 1;
	Food_y = rand() % (Lie - 1) + 1;
	if (snack[Food_x][Food_y] != She_tou&& snack[Food_x][Food_y] != She_shen&&snack[Food_x][Food_y]!=WALL)
	{
		snack[Food_x][Food_y] = Food;
		break;
	}
}
}
bool Snack::Cleck_Food()								//检测地图上有没有食物有的话返回1，没有的话返回0
{
	for (int i = 0; i != Hang; i++)
		for (int o = 0; o != Lie; o++)
			if (snack[i][o] == Food)
				return 1;
	return 0;
}
bool Snack::Eat_Food(lianbiao &s,int x,int y)			//检测当你吃掉食物的时候蛇身增加 返回1，若没吃到食物返回0
{
	if (snack[x][y] == Food)							//如果是食物的话
	{
		i++;											//蛇身长度加1	
		s.Push_lianbiao(She_shen, snack_head_x, snack_head_y);						//链接
		s.Snack_Head->x = x;							//更新蛇头的x坐标
		s.Snack_Head->y = y;							//更新蛇头的y坐标
		snack_head_x = x;								//更新保存蛇头的坐标
		snack_head_y = y;								//更新保存蛇头的坐标
		return 1;
	}
	else
		return 0;
}
bool Snack::Bang(int x,int y)												//传进蛇头的下一个的坐标如果下一个坐标是墙或者是蛇身那么游戏结束
{
	if (snack[x][y] == WALL || snack[x][y] == She_shen)
	{
		system("cls");
		cout << "*******************************************" << endl;
		cout << "*******************************************" << endl;
		cout << "*******************************************" << endl;
		cout << "*******************************************" << endl;
		cout << "*******************************************" << endl;
		cout << "*******************游戏结束****************" << endl;
		cout << "*******************************************" << endl;
		cout << "*******************************************" << endl;
		cout << "*******************************************" << endl;
		cout << "*******************************************" << endl;
		cout << "*******************************************" << endl;
		cout << "*******************************************" << endl;
		system("pause");
		exit(0);
	}
	else
		return 1;
}
bool Snack::Time(char *c,int nandu)												//计时器+控制键盘输入的东西
{
	clock_t star, end;
	star = clock();
	while (!_kbhit())											//按键检测
	{
		end = clock();
		if ((end - star) >= nandu)
		{
			return 0;
		}
}
	while (1)													//保证和按键检测同时发生
	{
		end = clock();
		if ((end - star) >= nandu)
			break;
	}
	*c = _getch();
	int k;
	while (1)										//清掉_getch()缓冲区的函数  厉害呀
	{
		if (_kbhit())
		{
			k = _getch();
			if (0 == k || 0xE0 == k)
				k = k << 8 | _getch();
		}
		else break;
	}
	return 1;
	}
void Snack::Move_Up(lianbiao &s, Snack &w)											//向上移动拐弯
{
	w.GOGO(s, s.Snack_Head->x - 1, s.Snack_Head->y);							
}
void Snack::Move_Left(lianbiao &s, Snack &w)								//想左移动
{
	w.GOGO(s, s.Snack_Head->x , s.Snack_Head->y-1);
}
void Snack::Move_Down(lianbiao &s, Snack &w)							//向下移动
{
	w.GOGO(s, s.Snack_Head->x + 1, s.Snack_Head->y);
}
void Snack::Move_Right(lianbiao &s,Snack &w)						//向右移动
{
	w.GOGO(s, s.Snack_Head->x , s.Snack_Head->y+1);
}
bool Snack::Back_Move_Cleck(lianbiao &s,int a,int b)					//传进你需要走的下一个坐标的位置如果这个坐标已经出现在链表中则不能走通fan0：如果存在返0，不存在反1
{
	Jiedian *p;
	p = s.Snack_Head->next;
	if (p != NULL)
	{
		if (a == p->x&&b == p->y)
			return 0;
		else
			return 1;
	}
	else
		return 1;
}
void Snack::Duqu(lianbiao s)									//读取链表中的元素对数组的元素重新赋值
{
	snack[s.Snack_Head->x][s.Snack_Head->y] = She_tou;
	Jiedian *p;
	p = s.Snack_Head->next;
	while (p != NULL)
	{
		snack[p->x][p->y] = She_shen;
		p = p->next;
	}
}
void Snack::GOGO(lianbiao &s, int x, int y)			//向着同一个方向移动没有拐弯
{
	s.Snack_Head->x = x;
	s.Snack_Head->y = y;
	s.Push_lianbiao(She_shen, snack_head_x , snack_head_y);
	s.Back(i+1);
	snack_head_x = x;
	snack_head_y = y;
	snack[s.last_x][s.last_y] = Kongbai;
}
