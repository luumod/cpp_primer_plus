#include <iostream>
#include <string>
#include "练习题.h"
using std::cin;
using std::cout;
using std::endl;

#if 0
Wine::Wine() {}

Wine::Wine(const char* l, int y, const int* yr, const int* bot)
{
	label = l;
	year = y;
	year_and_bottles.Set(ArrayInt(yr, y), ArrayInt(bot, y));

}

Wine::Wine(const char* l, int y)
{
	label = l;
	year = y;
	//把数组传入基类成员函数  列数为y
	year_and_bottles.Set(ArrayInt(y), ArrayInt(y));

}

void Wine::GetBottles()
{
	//类似于创建一个数组 
	ArrayInt yr(year);
	ArrayInt bot(year);

	cout << "请输入" << year << "个年份和瓶数:" << endl;
	for (int i = 0; i < year; i++)
	{
		cout << "输入年份: ";
		cin >> yr[i];
		cout << "输入瓶数: ";
		cin >> bot[i];
	}
	cout << "输入完成!\n";
	year_and_bottles.Set(yr, bot);
}

std::string& Wine::Label()
{
	return label;
}

int Wine::sum()
{
	return year_and_bottles.Sum();
}

void Wine::Show() const
{
	cout << "名称: " << label << endl;
	cout << "\t年份\t瓶数:\n";
	year_and_bottles.Show(year);
}
#endif 


/*
私有继承
*/
#if 0
Wine::Wine() {}

Wine::Wine(const char* l, int y, const int* yr, const int* bot)
	:std::string(l)
{
	PairArray::operator=(PairArray(ArrayInt(yr,y), ArrayInt(bot,y)));
	year = y;

}

Wine::Wine(const char* l, int y)
	:std::string(l)
{
	PairArray::operator=(PairArray(ArrayInt(y), ArrayInt(y)));
	year = y;

}

void Wine::GetBottles()
{
	//类似于创建一个数组 
	ArrayInt yr(year);
	ArrayInt bot(year);

	cout << "请输入" << year << "个年份和瓶数:" << endl;
	for (int i = 0; i < year; i++)
	{
		cout << "输入年份: ";
		cin >> yr[i];
		cout << "输入瓶数: ";
		cin >> bot[i];
	}
	cout << "输入完成!\n";
	PairArray::operator=(PairArray(yr, bot));
}

std::string& Wine::Label()
{
	//
	return (std::string&)*this;
}

int Wine::sum()
{
	return PairArray::Sum();
}

void Wine::Show() const
{
	cout << "名称: " << (const std::string&)*this << endl;
	cout << "\t年份\t瓶数:\n";
	PairArray::Show(year);
}


#endif


#if 0
void Worker::Set()
{
	cout << "Enter worker's name: ";
	std::getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
	return;
}

void Worker::Show() const
{
	cout << "出队: " << endl;
	cout << "Worker name: " << fullname << " ";
	cout << "Worker ID: " << id << endl;
	return;
}
#endif

#if  0
Person::~Person()
{}

void Person::Data() const
{
	cout << "姓: " << fname <<endl;
	cout << "名: " << lname << endl;

}

void Person::Get()
{
	cout << "请输入姓: ";
	std::getline(cin, fname);
	cout << "请输入名: ";
	std::getline(cin, lname);
}

/*
枪手类
*/
void GunsLinger::Data() const
{
	cout << "枪的刻痕数: " << num << endl;
}

void GunsLinger::Get()
{
	cout << "请输入枪的刻痕数: ";
	cin >> num;
	while (cin.get() != '\n')
		continue;
}

double GunsLinger::Draw() const
{
	return double(rand() % 5 + 1);	//返回枪手的拔枪时间
}

//显式枪手信息
void GunsLinger::Show() const
{
	cout << "枪手的信息: ";
	Person::Data();
	Data();
}

//设置枪手信息
void GunsLinger::Set()
{
	cout << "请输入枪手的信息: ";
	Person::Get();
	Get();
}

/*
扑克牌类
*/
void PokerPlayer::Data() const
{
	cout << "扑克牌点数: " << Draw() << endl;
}

double PokerPlayer::Draw() const
{
	return double(rand() % 52 + 1);
}

void PokerPlayer::Set()
{
	cout << "输入扑克玩家的信息: ";
	Person::Get();

}

void PokerPlayer::Show()const
{
	cout << "扑克玩家的信息: ";
	Person::Data();
	Data();
}


/*
坏蛋类
*/
void BadDude::Data() const
{
	GunsLinger::Data();
	PokerPlayer::Data();
	cout << "坏蛋拔枪的时间是: " << Gdraw() << endl;
	cout << "下一张扑克牌是: " << Cdraw() << endl;
}

void BadDude::Get()
{
	GunsLinger::Get();
}

double BadDude::Gdraw() const
{
	//返回拔枪的时间
	return GunsLinger::Draw();
}

double BadDude::Cdraw() const
{
	//返回下一张扑克牌 
	return PokerPlayer::Draw();
}

void BadDude::Set()
{
	cout << "输入坏蛋的信息: " << endl;
	Person::Get();
	Get();
}

void BadDude::Show() const
{
	cout << "坏蛋信息: ";
	Person::Data();
	Data();
}

#endif