#include <iostream>
#include <fstream>	//文件输出
using namespace std;

//int main()
//{
//	char ch;
//	cout << "请输入字符串:";
//	cin.get(ch);
//	while (ch != '.')
//	{
//		if (ch == '\n')
//		{
//			cout << ch;
//		}
//		else
//			cout << ++ch<<" ";
//		cin.get(ch);
//	}
//
//	return 0;
//}

//
//const int MAX = 5;
//int main()
//{
//	int golf[MAX];
//	cout << "请输入" << MAX << "个得分:";
//	for (int i = 0; i < MAX; i++)
//	{
//		cout << "得分" << i + 1 << ":";
//		while (!(cin >> golf[i]))
//		{
//			//清空输入
//			cin.clear();
//			while (cin.get() != '\n')
//			{
//				continue;
//			}
//			cout << "请输入下一个:";
//		}
//	}
//	return 0;
//}


//int main()
//{
//	char ch;
//	int a;
//	double b;
//
//	char num[20];
//	cin.getline(num, 20);
//	cout << num << endl;
//	return 0;
//}


//关于文件的操作
//int main()
//{
//
//	/*
//	使用文件输出的步骤:
//	1. 包含头文件 fstream
//	2. 创建一个	  ofstream对象
//	3. 将该fstream对象同一个文件联系起来
//	4. 像使用cout那样使用ofstream对象
//	*/
//	//定义用于处理输出的类
//	ofstream outFile;
//	ofstream fout;
//	//创建一个文件
//	outFile.open("fish.txt");
//	char filename[50];
//	cin >> filename;
//	fout.open(filename);
//	
//	double wt = 125.8;
//	outFile << wt;	//写一个数字到fish.txt文件中
//	char line[80] = "Object hhh 666";
//	fout << line << endl;	//写一行文本到fout指定的文件中
//
//
//	return 0;
//}


//写入文本文件
//int main()
//{
//	char automobine[50];
//	int year;
//	double a_price;
//	double b_price;
//
//	//定义ofstream类对象
//	ofstream outFile;
//	//创建一个文本文件
//	outFile.open("carinfo.txt");
//
//	cout << "Enter the make and model of automobine:";
//	cin.getline(automobine, 50);
//	cout << "Enter the model year:";
//	cin >> year;
//	cout << "Enter the original asking price:";
//	cin >> a_price;
//	b_price = a_price * 0.913;
//
//	//在屏幕上显示信息
//	cout << fixed;	
//	cout.precision(2);
//	cout.setf(ios_base::showpoint);
//	cout << "Make and model: " << automobine << endl;
//	cout << "Year: " << year << endl;
//	cout << "Was asking $" << a_price << endl;
//	cout << "Now asking $" << b_price << endl;
//
//	//添加内容到文件中
//	outFile << fixed;
//	outFile.precision(2);
//	outFile.setf(ios_base::showpoint);
//	outFile << "Make and model: " << automobine << endl;
//	outFile << "Year: " << year << endl;
//	outFile << "Was asking $" << a_price << endl;
//	outFile << "Now asking $" << b_price << endl;
//	outFile.close();	//关闭文件
//
//
//	return 0;
//}



//int main()
//{
//	ifstream inFile;
//	ifstream fin;
//
//	inFile.open("bowling.txt");
//	if (!inFile.is_open())
//	{
//		//打开失败
//		exit(EXIT_FAILURE);
//	}
//
//	char filename[50];
//	cin >> filename;
//	fin.open(filename);
//	double wt;
//	inFile >> wt;
//	char line[80];
//	fin.getline(line, 81);
//
//	return 0;
//}



//读取文本文件信息
//int main()
//{
//	ifstream inFile;
//	inFile.open("fish.txt");
//	if (!inFile.is_open())
//	{
//		exit(0);
//	}
//	double num;
//	//判断是否达到文件末尾
//	if (inFile.eof())
//	{
//		cout << "到达末尾" << endl;
//	}
//	//检查类型匹配与否
//	if (inFile.fail())
//	{
//		cout << "类型不匹配" << endl;
//	}
//	inFile >> num;
//	cout << num << endl;
//
//	inFile.close();
//	return 0;
//}




/*
1）fstream是头文件；

2）ifstream和ofstream分别是用来打开和输出文件；

3）.open()函数是用来打开文件，比如：ifs.open("m.txt", ios::in)；就会打开名为“m.txt”的文件了；

4）is_open()函数是用来判断文件是否打开成功，返回值是布尔值；例如：ifs.is_open()；

5）good()函数是指文件读取成功；

6）.eof()函数是用来判断是否读到了文件尾；

7）.close()函数是用来关闭之前打开的文件；

8）.fail()函数用来判断一个流是否“坏”掉了，当输入流读取失败时，会将字符放在原处，等待下一次读取；
*/



//
int main()
{
	ofstream wrFile;
	wrFile.open("完数.txt");
	int sum;
	//计算从2到1000的完数
	for (int i = 2; i <= 1000; i++)
	{
		cout << endl;
		sum = 1;
		for (int j = 2; j <= i / 2; j++)
		{
			//求出其所有因子之和
			if (i % j == 0)
				sum += j;
		}
		//所有因子之和等于本身，其为完数
		if (sum == i)
		{
			wrFile << sum << "=";
			cout << sum << "=";
			//列式子
			for (int k = 2; k <= i / 2; k++)
			{
				if (i % k == 0)
				{
					wrFile << k << "+";
					cout << k << "+";
				}
			}
			wrFile << endl;
			cout << endl;
		}
		//不是完数，跳过
	}

	wrFile.close();
	return 0;
}


