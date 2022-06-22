#include <string>

namespace pers
{
	struct Person
	{
		std::string fname;
		std::string lname;
	};
	void getPerson(Person&);
	void showPerson(const Person&);
}
namespace debts
{
	using namespace pers;	//使用了pers的名称变量
	struct Debts
	{
		Person name;
		double amout;
	};
	void getDebts(Debts&);
	void showDebts(const Debts&);
	double sumDebts(const Debts ar[], int n);
}