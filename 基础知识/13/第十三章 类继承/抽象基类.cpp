//
//
//#include <iostream>
//#include "�������.h"
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
//		cout << "���ֵ����Ϊ��!" << endl;
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
//		cout << "���ֽ�����Ϊ��; "
//			<< "ȡ������; \n";
//	}
//	else if (wd <= Balance())
//	{
//		//����㹻 ������wd
//		AcctABC::Withdraw(wd);
//	}
//	else
//	{
//		cout << "ȡ����: $" << wda
//			<< " ���������ʣ�����,ȡ������.\n";
//	}
//}
//
//void Brass::ViewAcct()const
//{
//	Formatting f = setFormat();
//	cout << "ί����: " << Fullname() << endl;
//	cout << "�˻��˺�:" <<AcctNum() << endl;
//	cout << "�����: $" << Balance() << endl;
//	Resetore(f);
//
//}
//
//
//
//BrassPlus::BrassPlus(const std::string& s, long an, double bal, double ml, double r) :AcctABC(s, an, bal)	 //��Ա��ʼ���б�
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
//	cout << "ί����: " << Fullname() << endl;
//	cout << "�˻��˺�:" << AcctNum() << endl;
//	cout << "�����: $" << Balance() << endl;
//	cout << "�������: $ " << maxLoan << endl;
//	cout << "Ƿ�������: $ " << owesBank << endl;
//	cout.precision(3);
//	cout << "��������: " << 100 * rate << "%\n";
//
//	Resetore(f);
//}
//
//void BrassPlus::Withdraw(double amt)
//{
//	Formatting f = setFormat();
//
//	//û�����¶���ĳ�Ա�����ڻ���ֱ�ӵ��ü���  ���õ��ǻ����
//	double bal = Balance();		//��ʾ���
//
//	if (amt <= bal)
//	{
//		AcctABC::Withdraw(amt);
//	}
//	else if (amt <= bal + maxLoan - owesBank)
//	{
//		//ʵ�ʽ��Ľ��
//		double advance = amt - bal;
//		owesBank += advance * (1.0 + rate);
//		cout << "���н��: $ " << advance << endl;
//		cout << "�����Ϣ: $ " << advance * rate << endl;
//		Deposit(advance);		//������˻� 
//		AcctABC::Withdraw(amt);	//���
//	}
//	else
//	{
//		cout << "����������������ȡ��.\n";
//	}
//
//	Resetore(f);
//}
