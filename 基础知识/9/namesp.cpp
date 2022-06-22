#include <iostream>
#include "namesp.h"

namespace pers
{
	using std::cout;
	using std::cin;
	using std::endl;
	void getPerson(Person& p)
	{
		cout << "ÇëÊäÈëÐÕ:";
		cin >> p.fname;
		cout << "ÇëÊäÈëÃû:";
		cin >> p.lname;
	}
	void showPerson(const Person& p)
	{
		cout << p.fname << "," << p.lname << endl;
	}
}

namespace debts
{
	using std::cout;
	using std::cin;
	using std::endl;
	void getDebts(Debts& d)
	{
		getPerson(d.name);
		cout << "Enter the debts:";
		cin >> d.amout;
	}
	void showDebts(const Debts& d)
	{
		showPerson(d.name);
		cout << ": $" << d.amout << endl;
	}
	double sumDebts(const Debts ar[], int n)
	{
		double total = 0;
		for (int i = 0; i < n; i++)
		{
			total += ar[i].amout;
		}
		return total;
	}
}