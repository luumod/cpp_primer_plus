#include <iostream>
#include <cstdlib>
#include <cmath>
#include "异常.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
abort()函数
*/
#if 0
double hmean(double a, double b);

int main()
{
	double x, y, z;

	cout << "输入两个数字 计算调和平均数: ";
	while (cin >> x >> y)
	{
		z = hmean(x, y);
		cout << z << endl;
		cout << "输入两个数字 计算调和平均数: ";
	}
	return 0;
}
double hmean(double a, double b)
{
	if (a == -b)
	{
		cout << "错误! " << endl;
		std::abort();
	}
	return 2.0 * a * b / (a + b);
}
#endif 


/*
返回错误码
*/
#if 0
bool hmean(double a, double b,double* ans);

int main()
{
	double x, y, z;

	cout << "输入两个数字 计算调和平均数: ";
	while (cin >> x >> y)
	{
		if (hmean(x, y, &z))
		{
			cout << z << endl;
		}
		else
		{
			cout << "错误输入! " << endl;
		}
		cout << "输入两个数字 计算调和平均数: ";
	}
	return 0;
}
bool hmean(double a, double b,double* ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans= 2.0 * a * b / (a + b);
		return true;
	}
}

#endif


/*
异常机制: 
	1. 引发异常
	2. 使用处理程序捕获异常
	3. 使用try块
*/

#if 0

double hmean(double a, double b);

int main()
{
	double x, y, z;

	cout << "输入两个数字 计算调和平均数: ";
	while (cin >> x >> y)
	{
		try			//开始try
		{
			z = hmean(x, y);
		}
		catch (const char* s)	//异常类型
		{
			//对异常进行处理
			cout << s << endl;
			cout << "输入两个数字 计算调和平均数: ";
			continue;
		}
		cout << z << endl;
		cout << "输入两个数字 计算调和平均数: ";
	}
	return 0;
}
double hmean(double a, double b)
{
	if (a == -b)
	{
		//引发异常字符串
		throw "错误输入 : a = -b 不被允许! ";	//类似于执行return 
	}
	return 2.0 * a * b / (a + b);
}

#endif // 1

/*
类中的异常处理
*/

#if 0
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
	double x, y, z;
	cout << "请输入两个数字: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << z << endl;
			cout << gmean(x, y) << endl;
			cout << "请输入两个数字: ";
		}
		catch (bad_hmean& bg)
		{
			//此输入错误则跳过
			bg.mesg();			//使用公有方法返回字符串
			cout << "Try again: " << endl;
			continue;
		}
		catch (bad_gmean& hg)
		{
			//此输入错误直接break
			cout << hg.mesg();	//打印字符串
			cout << "错误! " << endl;
			break;
		}
	}
	cout << "Bye! " << endl;
	return 0;
}
double hmean(double a, double b)
{
	/*
	计算调和平均数
	*/
	if (a == -b)
	{
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	/*
	计算相乘的平方根
	*/
	if (a < 0 || b < 0)
	{
		throw bad_gmean(a, b);
	}
	return std::sqrt(a*b);
}

#endif // 1


#if 0
int main()
{
	double vals[12] =
	{
		1220,1100,1122,2212,1232,2334,
		2884,2393,3302,2922,3002,3544,
	};

	double vals2[12] =
	{
		12,11,22,31,32,34,
		28,29,33,29,32,35
	};

	Sales sales1(2011, vals, 12);
	LabeledSales sales2("Blogstaer", 2012, vals, 12);

	cout << "first try block: \n";
	try
	{
		int i;
		cout << "Year= " << sales1.Year() << endl;
		for (int i = 0; i < 12; i++)
		{
			cout << sales1[i] << " ";
			if (i & 6 == 5)
			{
				cout << endl;
			}
		}
		cout << "Year= " << sales2.Year() << endl;
		cout << "Label= " << sales2.Label() << endl;
		for (int i = 0; i < 12; i++)
		{
			cout << sales2[i] << " ";
			if (i & 6 == 5)
			{
				cout << endl;
			}
		}
		cout << "End of try block 1.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad_index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}

	cout << "\nNext try block:\n";
	try
	{
		sales2[2] = 999;
		sales1[20] = 6666;	//数组下标越界 
		cout << "End of try block 2.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad_index: " << bad.bi_val() << endl;
	}
	//触发 bad_index的错误处理机制
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "Done! " << endl;

	return 0;
}
#endif 




/*
意外异常
	
未捕获异常
*/
void MyQuit()
{
	cout << "Terminating due to uncatught exceptionn\n";
	exit(5);
}
int main()
{
	set_terminate(MyQuit);

	return 0;
}