//
//
//#include <iostream>
//#include "抽象基类.h"
//
//using std::cout;
//using std::ios_base;
//using std::endl;
//using std::string;
//
//AcctABC::AcctABC(const std::string& s, long an, double bal)
//{
//	fullname = s;
//	acctNum = an;
//	balance = bal;
//}
//
//void AcctABC::Deposit(double amt)
//{
//	if (amt < 0)
//	{
//		cout << "存款值不能为负!" << endl;
//	}
//	else
//	{
//		balance += amt;
//	}
//
//}
//
//void AcctABC::Withdraw(double amt)
//{
//	balance -= amt;
//}
//
//AcctABC::Formatting AcctABC::setFormat()const
//{
//	Formatting f;
//	f.flag =
//		cout.setf(ios_base::fixed, ios_base::floatfield);
//	f.pr = cout.precision(2);
//	return f;
//}
//
//void AcctABC::Resetore(Formatting& f) const
//{
//	cout.setf(f.flag, ios_base::floatfield);
//	cout.precision(f.pr);
//}
//
//
////Brass::Brass(const std::string& s, long an, double bal) :AcctABC(s, an, bal)
////{
////}
//
//void Brass::Withdraw(double wd)
//{
//
//	if (wd < 0)
//	{
//		cout << "提现金额必须为正; "
//			<< "取消提现; \n";
//	}
//	else if (wd <= Balance())
//	{
//		//余额足够 则提现wd
//		AcctABC::Withdraw(wd);
//	}
//	else
//	{
//		cout << "取款金额: $" << wda
//			<< " 超过了你的剩余余额,取消提现.\n";
//	}
//}
//
//void Brass::ViewAcct()const
//{
//	Formatting f = setFormat();
//	cout << "委托人: " << Fullname() << endl;
//	cout << "账户账号:" <<AcctNum() << endl;
//	cout << "总余额: $" << Balance() << endl;
//	Resetore(f);
//
//}
//
//
//
//BrassPlus::BrassPlus(const std::string& s, long an, double bal, double ml, double r) :AcctABC(s, an, bal)	 //成员初始化列表
//{
//	maxLoan = ml;
//	owesBank = 0.0;
//	rate = r;
//}
//
//BrassPlus::BrassPlus(const Brass& ba, double ml, double r) :AcctABC(ba)
//{
//	maxLoan = ml;
//	owesBank = 0.0;
//	rate = r;
//}
//
//void BrassPlus::ViewAcct() const
//{
//	Formatting f = setFormat();
//
//	cout << "委托人: " << Fullname() << endl;
//	cout << "账户账号:" << AcctNum() << endl;
//	cout << "总余额: $" << Balance() << endl;
//	cout << "最大借款金额: $ " << maxLoan << endl;
//	cout << "欠款的银行: $ " << owesBank << endl;
//	cout.precision(3);
//	cout << "还款利率: " << 100 * rate << "%\n";
//
//	Resetore(f);
//}
//
//void BrassPlus::Withdraw(double amt)
//{
//	Formatting f = setFormat();
//
//	//没有重新定义的成员函数在基类直接调用即可  调用的是基类的
//	double bal = Balance();		//显示余额
//
//	if (amt <= bal)
//	{
//		AcctABC::Withdraw(amt);
//	}
//	else if (amt <= bal + maxLoan - owesBank)
//	{
//		//实际借款的金额
//		double advance = amt - bal;
//		owesBank += advance * (1.0 + rate);
//		cout << "银行借款: $ " << advance << endl;
//		cout << "借贷利息: $ " << advance * rate << endl;
//		Deposit(advance);		//借款存进账户 
//		AcctABC::Withdraw(amt);	//提款
//	}
//	else
//	{
//		cout << "超过最大借款数额，交易取消.\n";
//	}
//
//	Resetore(f);
//}
