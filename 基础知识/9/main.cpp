#include <iostream>
#include <math.h>
#include "namesp.cpp"

void other(void);
void anthor(void);


int main()
{
	using debts::Debts;
	using debts::showDebts;	//����к������أ��򽫵������еĺ����汾

	Debts golf = { {"Benny","Gotansiff"},120.99 };
	//��ʾ
	showDebts(golf);
	//��������
	other();
	anthor();

	return 0;
}

void other(void)
{
	using std::cout;
	using std::cin;
	using namespace debts;	//�����������ƿռ�
	Person dg = { "Doodles","Glster" };
	cout << endl;
	Debts zippy[3];
	for (int i = 0; i < 3; i++)
	{
		//����
		getDebts(zippy[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		//��ʾ
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