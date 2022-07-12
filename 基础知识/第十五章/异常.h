
#include <iostream>
#include <exception>
using std::cout;
using std::endl;

#if 0
class bad_hmean
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0)
		:v1(a), v2(b) {}
	void mesg();
};

inline void bad_hmean::mesg()
{
	//错误处理 : 打印一句话
	cout << "hmean(" << v1 << "," << v2 << "):invalid arguments: a = -b!" << endl;
}

class bad_gmean
{
private:
	double v1;
	double v2;
public:
	bad_gmean(double a = 0, double b = 0)
		:v1(a), v2(b) {}
	const char* mesg();
};

inline const char* bad_gmean::mesg()
{
	//错误处理 : 返回一个字符串
	return "gmean() arguments should be >=0 \n";
}
#endif 


/*
栈解退
	程序调用栈解退以回到能够捕获异常的地方 将自动释放栈中的自动存储型变量  如果变量是类，自动调用析构函数
*/

/*
exception：
	logic_error
	runtime_error

*/
#if 1

class Sales
{
public:
	enum { MONTHS = 12 };
	class bad_index :public std::logic_error
	{
	private:
		int bi;
	public:
		//处理错误信息
		explicit bad_index(int ix, const std::string& s =
			"Index error in Sales object\n")
			:std::logic_error(s), bi(ix) {}
		int bi_val()const
		{
			return bi;
		}
		virtual ~bad_index()throw() {}
	};
	//显示构造函数
	explicit Sales(int yy = 0);
	//构造函数
	Sales(int yy, const double* gr, int n);
	virtual ~Sales() {}
	int Year()const
	{
		return year;
	}
	virtual double operator[](int i)const;	//用于显示
	virtual double& operator[](int i);		//用于修改	
private:
	double gross[MONTHS];
	int year;
};

class LabeledSales : public Sales
{
public:
	class nbad_index : public Sales::bad_index
	{
	private:
		std::string lbl;
	public:
		nbad_index(const std::string& lb, int ix, const std::string& s = "Index error in LabeledSales object.\n")
			:Sales::bad_index(ix, s) { lbl = lb; }
		const std::string& label_val()const
		{
			return lbl;
		}
		virtual ~nbad_index()throw() {}
	};
	//显示构造函数
	explicit LabeledSales(const std::string& lb = "none", int yy = 0);
	//构造函数
	LabeledSales(const std::string& lb, int yy, const double* gr, int n);
	virtual ~LabeledSales() {}
	const std::string& Label()const
	{
		return label;
	}
	virtual double operator[](int i)const;
	virtual double& operator[](int i);
private:
	std::string label;
};

#endif 


