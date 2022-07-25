#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
using namespace std;

/*
文件读写
*/
#if 0
inline void eatline()
{
	while (cin.get() != '\n')
		;
}
struct planet
{
	char name[20];
	double population;
	double g;
};

const char* file_name = "planet.dat";

int main()
{
	planet p1;
	cout << fixed << right;

	/*
	从文件读取
	*/
	ifstream fin;
	fin.open(file_name, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "这是你的文件内容: " << endl;
		while (fin.read((char*)&p1, sizeof(p1)))
		{
			cout << setw(20) << p1.name << ": "
				<< setprecision(0) << setw(12) << p1.population << setprecision(2)
				<< setw(6) << p1.g << endl;
		}
		fin.close();
	}

	/*
	写入文件
	*/
	ofstream fout(file_name,
		ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << "文件打开失败" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "输入姓名: ";
	cin.get(p1.name, 20);
	while (p1.name[0] != '\0')
	{
		eatline();
		cout << "输入population: ";
		cin >> p1.population;
		cout << "输入g: ";
		cin >> p1.g;
		eatline();
		fout.write((char*)&p1, sizeof(p1));
		cout << "输入姓名: (回车退出)";
		cin.get(p1.name, 20);
	}
	fout.close();

	/*
	从文件读取
	*/
	fin.clear();		//清空流状态

	fin.open(file_name,
		ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "这是你的文件内容: " << endl;
		while (fin.read((char*)&p1, sizeof(p1)))
		{
			cout << setw(20) << p1.name << ": "
				<< setprecision(0) << setw(12) << p1.population << setprecision(2)
				<< setw(6) << p1.g << endl;
		}
		fin.close();
	}
	cout << "Done!" << endl;
	return 0;
}

#elif 0
/*
随机存取
*/

/*
同时使用 ios_base::in | ios_base::out | ios_base::binary

移动方式: 
	seekg: 移动输入指针
	seekp: 移动输出指针 

	ios_base::beg  ios_base::cur  ios_base::end
	streampos:  文件中的绝对位置  以字节为单位

	检查当前指针的位置: tellg  tellp返回一个表示当前位置的streampos值
*/

const int LIM = 20;
struct planet
{
	char name[LIM];
	double population;
	double g;
};
const char* file_name = "planet.dat";
inline void eatline()
{
	while (cin.get() != '\n')
		;
}
int main()
{
	planet p1;
	cout << fixed;


	fstream finout;
	/*
	可读可写文件
	*/
	finout.open(file_name, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	if (finout.is_open())
	{
		/*
		移动输入指针到文件开头
		*/
		finout.seekg(0);	
		cout << "这是文件的内容: " << endl;
		/*
		finout.read((char*)&p1,sizeof(p1))	从文件里读取信息
		*/
		while (finout.read((char*)&p1, sizeof(p1)))
		{
			//设置宽度与小数点位数
			cout << ct++ << ": " << setw(LIM) << p1.name
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(3) << setw(12) << p1.g << endl;
		}
		if (finout.eof())
		{
			finout.clear();
		}
		else
		{
			cerr << "读取文件失败" << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << "打开文件失败" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "请输入你要修改的信息编号: ";
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "编号输入错误" << endl;
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof(p1);
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "定位文件位置失败" << endl;
		exit(EXIT_FAILURE);
	}

	finout.read((char*)&p1, sizeof(p1));
	cout << "此人的信息: " << endl;
	cout << ct++ << ": " << setw(LIM) << p1.name
		<< setprecision(0) << setw(12) << p1.population
		<< setprecision(3) << setw(12) << p1.g << endl;
	if (finout.eof())
	{
		finout.clear();
	}
	cout << "请输入姓名: ";
	cin.get(p1.name, LIM);
	eatline();
	cout << "请输入population: ";
	cin >> p1.population;
	cout << "请输入 g: ";
	cin >> p1.g;
	eatline();
	/*
	定位输出指针的位置
	*/
	finout.seekp(place);
	/*
	往文件写入信息
	*/
	finout.write((char*)&p1, sizeof(p1)) << flush;
	if (finout.fail())
	{
		cerr << "信息写入文件失败" << endl;
		exit(EXIT_FAILURE);
	}


	ct = 0;
	/*
	重新定位到输入指针的文件头
	*/
	finout.seekg(0);
	cout << "这是文件的内容: " << endl;
	while (finout.read((char*)&p1, sizeof(p1)))
	{
		cout << ct++ << ": " << setw(LIM) << p1.name
			<< setprecision(0) << setw(12) << p1.population
			<< setprecision(3) << setw(12) << p1.g << endl;
	}
	finout.close();

	return 0;
}
#elif 0

/*
临时文件
*/
int main()
{
	cout << TMP_MAX << " " << L_tmpnam << endl;
	char pszName[L_tmpnam]{};
	for (int i = 0; i < 10; i++)
	{
		tmpnam(pszName);
		cout << pszName << endl;
	}
	return 0;
}

#elif 1

int main()
{
	/*
	与string对象相关联的istringstream
	*/
	string is = "wodjaowdadawd adwad ad达娃大 达娃大";
	istringstream instr(is);
	string word;
	while (instr >> word)
	{
		cout << word << endl;
	}

	return 0;
}
#endif