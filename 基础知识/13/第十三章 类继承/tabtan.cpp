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
//	首先创建基类对象
//	派生类构造函数通过成员初始化列表将基类信息传递给基类构造函数
//	派生类构造函数应初始化派生类新增的数据成员
//*/
////在派生类构造函数中必须添加对基类的初始化  即调用对基类的构造函数
//RatedPlay::RatedPlay(unsigned int r, const string& fn, const string& ln, bool ht) :TablenTennusPlay(fn, ln, ht)	  //如果不调用基类构造函数将使用默认的基类构造函数
//{
//	rating = r;
//}
//
////如果参数是基类的类型  那么调用基类的复制构造函数
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
//虚方法  银行
//*/
//namespace BAR
//{
//	typedef std::ios_base::fmtflags format;
//	typedef std::streamsize precis;
//	format setFormat();
//	void restore(format f, precis p);
//
//	//构造函数
//	Brass::Brass(const std::string& s, long an, double bal)
//	{
//		fullname = s;
//		acctNum = an;
//		balance = bal;
//	}
//	void Brass::Deposit(double amt)
//	{
//		//存款 amt到余额里
//		if (amt < 0)
//		{
//			cout << "不允许负存款! \n";
//		}
//		else
//		{
//			balance += amt;		//余额更新
//		}
//	}
//
//	/*
//	virtual 虚方法 基类与派生类的行为会有不同
//	*/
//	void Brass::WithDraw(double wd)
//	{
//		//金额提现
//		format initialSizes = setFormat();
//		precis prec = cout.precision(2);
//
//		if (wd < 0)
//		{
//			cout << "提现金额必须为正; "
//				<< "取消提现; \n";
//		}
//		else if (wd <= balance)
//		{
//			//余额足够 则提现wd
//			balance -= wd;
//		}
//		else
//		{
//			cout << "取款金额: $" << wd
//				<< " 超过了你的剩余余额,取消提现.\n";
//		}
//		restore(initialSizes, prec);
//	}
//
//	void Brass::ViewAcct()const
//	{
//		format initialSize = setFormat();
//		precis prec = cout.precision(2);
//
//		cout << "委托人: " << fullname << endl;
//		cout << "账户账号:" << acctNum << endl;
//		cout << "总余额: $" << balance << endl;
//
//		restore(initialSize, prec);
//	}
//
//	double Brass::Balance()const
//	{
//		//返回余额
//		return balance;
//	}
//	/*
//	虚析构函数
//	*/
//
//	/*
//	派生类
//	*/
//
//	//成员初始化列表初始化基类
//	BrassPlus::BrassPlus(const std::string& s, long an, double bal, double ml, double r) :Brass(s, an, bal)	 //成员初始化列表
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
//		Brass::ViewAcct();				//派生类方法可以调用基类方法
//		cout << "最大借款金额: $ " << maxLoan << endl;
//		cout << "欠款的银行: $ " << owesBank << endl;
//		cout.precision(3);
//		cout << "还款利率: " << 100 * rate << "%\n";
//
//		restore(initialSize, prec);
//	}
//
//	void BrassPlus::WithDraw(double amt)
//	{
//		format initialSize = setFormat();
//		precis prec = cout.precision(2);
//
//		//没有重新定义的成员函数在基类直接调用即可  调用的是基类的
//		double bal = Balance();		//显示余额
//
//		if (amt <= bal)
//		{
//			//调用基类方法
//			Brass::WithDraw(amt);
//		}
//		else if (amt <= bal + maxLoan - owesBank)
//		{
//			//实际借款的金额
//			double advance = amt - bal;
//			owesBank += advance * (1.0 + rate);
//			cout << "银行借款: $ " << advance << endl;
//			cout << "借贷利息: $ " << advance * rate << endl;
//			Deposit(advance);		//借款存进账户 
//			Brass::WithDraw(amt);	//提款
//		}
//		else
//		{
//			cout << "超过最大借款数额，交易取消.\n";
//		}
//
//		restore(initialSize, prec);
//	}
//
//
//	//设置为定点表示法并且返回以前的标记位置
//	format setFormat()
//	{
//		return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
//	}
//
//	//重置格式和精度
//	void restore(format f, precis p)
//	{
//		cout.setf(f, std::ios_base::floatfield);
//		cout.precision(p);
//	}
//}