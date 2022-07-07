


#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

class AcctABC
{
private:
	std::string fullname;
	long acctNum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	/*
	保护方法  实现对fullname和acctNum的只读访问
	*/
	const std::string& Fullname()const
	{
		return fullname;
	}
	long AcctNum()const
	{
		return acctNum;
	}
	Formatting setFormat()const;		//设置格式
	void Resetore(Formatting& f)const;	//恢复格式

public:
	AcctABC(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	double Balance()const
	{
		return balance;
	}
	//纯虚函数
	virtual void Withdraw(double amt) = 0;
	//纯虚函数
	virtual void ViewAcct()const = 0;
	virtual ~AcctABC() {}
};

/*
派生类 1
*/
class Brass :public AcctABC
{
public:
	Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0) :AcctABC(s, an, bal){}
	virtual void Withdraw(double amt);	//取款
	virtual void ViewAcct()const;		//查看账户
	virtual ~Brass() {}
};

/*
派生类 2
*/
class BrassPlus :public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	//新增的共有成员函数
	BrassPlus(const std::string& s = "NullBody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.10);
	virtual void Withdraw(double amt);	//取款
	virtual void ViewAcct()const;		//查看账户
	void ResetMax(double m)
	{
		//重新设置最大借款金额
		maxLoan = m;
	}
	void ResetRste(double r)
	{
		//重置利率
		rate = r;
	}
	void ResetOwes()
	{
		//重置账户
		owesBank = 0;
	}
};

#endif