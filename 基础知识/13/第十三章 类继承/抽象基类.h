


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
	��������  ʵ�ֶ�fullname��acctNum��ֻ������
	*/
	const std::string& Fullname()const
	{
		return fullname;
	}
	long AcctNum()const
	{
		return acctNum;
	}
	Formatting setFormat()const;		//���ø�ʽ
	void Resetore(Formatting& f)const;	//�ָ���ʽ

public:
	AcctABC(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	double Balance()const
	{
		return balance;
	}
	//���麯��
	virtual void Withdraw(double amt) = 0;
	//���麯��
	virtual void ViewAcct()const = 0;
	virtual ~AcctABC() {}
};

/*
������ 1
*/
class Brass :public AcctABC
{
public:
	Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0) :AcctABC(s, an, bal){}
	virtual void Withdraw(double amt);	//ȡ��
	virtual void ViewAcct()const;		//�鿴�˻�
	virtual ~Brass() {}
};

/*
������ 2
*/
class BrassPlus :public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	//�����Ĺ��г�Ա����
	BrassPlus(const std::string& s = "NullBody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.10);
	virtual void Withdraw(double amt);	//ȡ��
	virtual void ViewAcct()const;		//�鿴�˻�
	void ResetMax(double m)
	{
		//���������������
		maxLoan = m;
	}
	void ResetRste(double r)
	{
		//��������
		rate = r;
	}
	void ResetOwes()
	{
		//�����˻�
		owesBank = 0;
	}
};

#endif