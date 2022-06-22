#include <iostream>
#include <math.h>
#include "namesp.cpp"

void other(void);
void anthor(void);


int main()
{
	using debts::Debts;
	using debts::showDebts;	//如果有函数重载，则将导入所有的函数版本

	Debts golf = { {"Benny","Gotansiff"},120.99 };
	//显示
	showDebts(golf);
	//另外三个
	other();
	anthor();

	return 0;
}

void other(void)
{
	using std::cout;
	using std::cin;
	using namespace debts;	//导入整个名称空间
	Person dg = { "Doodles","Glster" };
	cout << endl;
	Debts zippy[3];
	for (int i = 0; i < 3; i++)
	{
		//输入
		getDebts(zippy[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		//显示
		showDebts(zippy[i]);
	}
	cout << "Total debts :" << sumDebts(zippy, 3) << endl;
}

void anthor(void)
{
	using pers::Person;
	Person collector = { "Milo","Rightshift" };
	pers::showPerson(collector);
	std::cout << std::endl;
}