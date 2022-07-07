//
//
//
//#ifndef TANTEN_H_
//#define TANTEN_H_
//#include <string>
//using std::string;
//
//class TablenTennusPlay
//{
//private:
//	string firstname;
//	string lastname;
//	int hasTable;
//public:
//	TablenTennusPlay(const string& fn = "none", const string& in = "none", bool ht = false);
//	void Name()const;
//	int HasTable()const
//	{
//		return hasTable;
//	}
//	void ResetTable(int v)
//	{
//		hasTable = v;
//	}
//};
//
//
////继承
///*
//派生类对象存储了基类的数据成员
//派生类对象可以使用基类的成员
//*/
///*
//派生类需要将自己的构造函数
//派生类可以添加额外的数据成员和成员函数
//*/
//class RatedPlay : public TablenTennusPlay
//{
//private:
//	unsigned int rating;		//添加一个成员
//public:
//	//派生类构造函数必须使用基类构造函数
//	RatedPlay(unsigned int r = 0, const string& fn = "none",
//		const string& ln = "none", bool ht = false);
//	RatedPlay(unsigned int r, const TablenTennusPlay& tp);
//	unsigned int Rating()const
//	{ 	
//		return rating; 
//	}
//	void ResetRating(unsigned int r) 
//	{
//		rating = r;
//	}/*
//	 隐式复制构造函数和隐式赋值运算符可以将基类对象初始化为派生类对象
//	 或者将派生类对象赋给基类对象
//	 */
//};
//
//
//
///*
//银行
//*/
//
////抽象基类
//class Brass
//{
//private:
//	std::string fullname;		//账户名称
//	long acctNum;				//账户
//	double balance;				//余额
//public:
//	Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
//	void Deposit(double amt);	//存款
//	/*
//	virtual 虚方法 基类与派生类的行为会有不同
//	*/
//	virtual void WithDraw(double amt);	//取款
//	virtual void ViewAcct()const;		//查看账户
//	double Balance()const;
//	/*
//	虚析构函数
//	*/
//	virtual ~Brass(){}
//};
//
////继承
//class BrassPlus :public Brass
//{
//private:
//	//新增的私有成员
//	double maxLoan;		//最大借款数额
//	double rate;		//借款利率
//	double owesBank;	//借款账户
//public:
//	//新增的共有成员函数
//	BrassPlus(const std::string& s = "NullBody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
//	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
//	virtual void WithDraw(double amt);	//取款
//	virtual void ViewAcct()const;		//查看账户
//	void ResetMax(double m)
//	{
//		//重新设置最大借款金额
//		maxLoan = m;
//	}
//	void ResetRste(double r)
//	{
//		//重置利率
//		rate = r;
//	}
//	void ResetOwes()
//	{
//		//重置账户
//		owesBank = 0;
//	}
//};
//
//
//
//
//#endif // TANTEN_H_
