//#include "tabtan.h"
//#include <iostream>
//using std::cout;
//using std::cin;
//using std::endl;
//
//TablenTennusPlay::TablenTennusPlay(const string& fn, const string& in, bool ht):firstname(fn),lastname(in),hasTable(ht){}
//
//void TablenTennusPlay::Name()const
//{
//	std::cout << lastname << "," << firstname << std::endl;
//}
//
///*
//	���ȴ����������
//	�����๹�캯��ͨ����Ա��ʼ���б�������Ϣ���ݸ����๹�캯��
//	�����๹�캯��Ӧ��ʼ�����������������ݳ�Ա
//*/
////�������๹�캯���б�����ӶԻ���ĳ�ʼ��  �����öԻ���Ĺ��캯��
//RatedPlay::RatedPlay(unsigned int r, const string& fn, const string& ln, bool ht) :TablenTennusPlay(fn, ln, ht)	  //��������û��๹�캯����ʹ��Ĭ�ϵĻ��๹�캯��
//{
//	rating = r;
//}
//
////��������ǻ��������  ��ô���û���ĸ��ƹ��캯��
//RatedPlay::RatedPlay(unsigned int r, const TablenTennusPlay& tp):TablenTennusPlay(tp)
//{
//	rating = r;
//}
//
//
//
//
//
///*
//�鷽��  ����
//*/
//namespace BAR
//{
//	typedef std::ios_base::fmtflags format;
//	typedef std::streamsize precis;
//	format setFormat();
//	void restore(format f, precis p);
//
//	//���캯��
//	Brass::Brass(const std::string& s, long an, double bal)
//	{
//		fullname = s;
//		acctNum = an;
//		balance = bal;
//	}
//	void Brass::Deposit(double amt)
//	{
//		//��� amt�������
//		if (amt < 0)
//		{
//			cout << "���������! \n";
//		}
//		else
//		{
//			balance += amt;		//������
//		}
//	}
//
//	/*
//	virtual �鷽�� ���������������Ϊ���в�ͬ
//	*/
//	void Brass::WithDraw(double wd)
//	{
//		//�������
//		format initialSizes = setFormat();
//		precis prec = cout.precision(2);
//
//		if (wd < 0)
//		{
//			cout << "���ֽ�����Ϊ��; "
//				<< "ȡ������; \n";
//		}
//		else if (wd <= balance)
//		{
//			//����㹻 ������wd
//			balance -= wd;
//		}
//		else
//		{
//			cout << "ȡ����: $" << wd
//				<< " ���������ʣ�����,ȡ������.\n";
//		}
//		restore(initialSizes, prec);
//	}
//
//	void Brass::ViewAcct()const
//	{
//		format initialSize = setFormat();
//		precis prec = cout.precision(2);
//
//		cout << "ί����: " << fullname << endl;
//		cout << "�˻��˺�:" << acctNum << endl;
//		cout << "�����: $" << balance << endl;
//
//		restore(initialSize, prec);
//	}
//
//	double Brass::Balance()const
//	{
//		//�������
//		return balance;
//	}
//	/*
//	����������
//	*/
//
//	/*
//	������
//	*/
//
//	//��Ա��ʼ���б��ʼ������
//	BrassPlus::BrassPlus(const std::string& s, long an, double bal, double ml, double r) :Brass(s, an, bal)	 //��Ա��ʼ���б�
//	{
//		maxLoan = ml;
//		owesBank = 0.0;
//		rate = r;
//	}
//
//	BrassPlus::BrassPlus(const Brass& ba, double ml, double r) :Brass(ba)
//	{
//		maxLoan = ml;
//		owesBank = 0.0;
//		rate = r;
//	}
//
//	void BrassPlus::ViewAcct() const
//	{
//		format initialSize = setFormat();
//		precis prec = cout.precision(2);
//
//		Brass::ViewAcct();				//�����෽�����Ե��û��෽��
//		cout << "�������: $ " << maxLoan << endl;
//		cout << "Ƿ�������: $ " << owesBank << endl;
//		cout.precision(3);
//		cout << "��������: " << 100 * rate << "%\n";
//
//		restore(initialSize, prec);
//	}
//
//	void BrassPlus::WithDraw(double amt)
//	{
//		format initialSize = setFormat();
//		precis prec = cout.precision(2);
//
//		//û�����¶���ĳ�Ա�����ڻ���ֱ�ӵ��ü���  ���õ��ǻ����
//		double bal = Balance();		//��ʾ���
//
//		if (amt <= bal)
//		{
//			//���û��෽��
//			Brass::WithDraw(amt);
//		}
//		else if (amt <= bal + maxLoan - owesBank)
//		{
//			//ʵ�ʽ��Ľ��
//			double advance = amt - bal;
//			owesBank += advance * (1.0 + rate);
//			cout << "���н��: $ " << advance << endl;
//			cout << "�����Ϣ: $ " << advance * rate << endl;
//			Deposit(advance);		//������˻� 
//			Brass::WithDraw(amt);	//���
//		}
//		else
//		{
//			cout << "����������������ȡ��.\n";
//		}
//
//		restore(initialSize, prec);
//	}
//
//
//	//����Ϊ�����ʾ�����ҷ�����ǰ�ı��λ��
//	format setFormat()
//	{
//		return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
//	}
//
//	//���ø�ʽ�;���
//	void restore(format f, precis p)
//	{
//		cout.setf(f, std::ios_base::floatfield);
//		cout.precision(p);
//	}
//}