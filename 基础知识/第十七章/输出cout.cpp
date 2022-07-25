#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>	//工具

using namespace std;
/* 
* 常见方法 *
ostream ：
	<<  
	put  字符
	write 字符串
*/

#if 0
int main()
{
	const char* s1 = "abcdfsefs";
	const char* s2 = "ondwao";
	const char* s3 = "dwalcacw";

	/*
	write 字符串地址与待显示的字符数量
	*/
	for (int i = 0; i < strlen(s1); i++)
	{
		cout.write(s1, i);
		cout << endl;
	}

	for (int i = strlen(s2); i >= 0; i--)
	{
		cout.write(s2, i) << endl;
	}
	cout << endl;
	long val = 560646561;
	cout.write((char*)&val, sizeof(val));
	return 0;
}
#elif 0
int main()
{
	int a = 110;
	int b = 9595;
	int c = 652;
	cout << hex;		//十六进制
	cout << a<<endl;
	cout << oct;		//八进制
	cout << b<<endl;
	cout << dec;		//十进制
	cout << c<<endl;
	return 0;
}

#elif 0

int main()
{
	/*
	改变填充字符
	   一直有效
	*/
	cout.fill('*');
	long b[2] = { 200,1000 };

	for (int i = 0; i < 2; i++)
	{
		/*
		设置宽度
		只会有效一次
		*/
		cout.width(10);
		cout << b[i]<<endl;
	}
	
	return 0;
}

#elif 0

int main()
{
	float a = 20.5621;
	double x = 95.23614;

	/*
	设置精度位数
	一直有效
	*/
	cout.precision(3);
	cout << a << endl;
	cout << x << endl;

	return 0;
}

#elif 0

int main()
{
	float a = 20.1;
	double x = 95.236;

	/*
	默认显示六位小数 小数位不够则零填充
	*/
	cout.setf(ios_base::showpoint);
	cout << a << endl;
	cout << x << endl;

	/*
	设置小数的位数
	*/
	cout.precision(7);
	cout << a << endl;
	cout << x << endl;
	return 0;
}
#elif 0

int main()
{
	int a = 60;
	/*
	在正数前面加 + 
	仅当是十进制时有效  如果已经设置为hex或oct则无效
	*/
	cout.setf(ios_base::showpos);
	cout << a << endl;

	//对于十六进制输出 使用大写字母
	cout.setf(ios_base::uppercase);
	cout << hex << a << endl;

	//显示bool值
	cout.setf(ios_base::boolalpha);
	cout << true << " " << false << endl;

	//显示 0  0X前缀
	cout.setf(ios_base::showbase);
	cout << oct << a << endl;

	//显示小数点
	cout.setf(ios_base::showpoint);
	return 0;
}

#elif 0

int main()
{
	/*
	第一个参数					第二个参数
	dec oct hex					basefield		
	fixed  scientific			floatfield		
	left right internal			adjustfield		
	*/
	//设置右对齐 
	cout.setf(ios_base::left, ios_base::adjustfield);
	//正数前加 +
	cout.setf(ios_base::showpos);
	//显示小数位 0
	cout.setf(ios_base::showpoint);
	//设置小数位数
	cout.precision(3);

	//标记  保存此设置  科学计数法
	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
	cout << "Left adjustment: \n";
	for (int i = 1; i <= 41; i += 10)
	{
		cout.width(4);
		cout << i << "|";
		cout.width(12);
		cout << sqrt(double(i)) << "|\n";
	}
	
	//设置符号在前 数字在后对齐
	cout.setf(ios_base::internal, ios_base::adjustfield);
	//回到初始位置 即取消科学计数法表示
	cout.setf(old, ios_base::floatfield);

	cout << "internal adjustment:\n";
	for (int i = 1; i <= 41; i += 10)
	{
		cout.width(4);
		cout << i << "|";
		cout.width(12);
		cout << sqrt(double(i)) << "|\n";
	}

	//右对齐
	cout.setf(ios_base::right, ios_base::adjustfield);
	//定点表示法
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "right adjustment:\n";
	for (int i = 1; i <= 41; i += 10)
	{
		cout.width(4);
		cout << i << "|";
		cout.width(12);
		cout << sqrt(double(i)) << "|\n";
	}

	return 0;
}

#elif 0

int main()
{
	//定点表示 右对齐
	cout << fixed << right;

	/*
	setw			设置宽度
	setfill			设置填充字符
	setprecision	设置小数位数
	*/
	cout << setw(6) << "N" << setw(14) << "square root"
		<< setw(15) << "fourth root\n";
	double root;
	for (int n = 10; n <= 100; n += 10)
	{
		root = sqrt(double(n));
		cout << setw(6) << setfill('-') << n << setfill(' ')
			<< setw(12) << setprecision(3) << root
			<< setw(14) << setprecision(4) << sqrt(root) << endl;
	}

	return 0;
}


#endif // 1
