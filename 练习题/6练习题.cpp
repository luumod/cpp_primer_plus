#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <array>
#include <vector>
using namespace std;
//
////1.
////int main()
////{
////	char ch;
////	int count = 0;
////	cout << "请输入字符(@停止):";
////	cin >> ch;
////	while (ch != '@')
////	{
////		if (isupper(ch))
////		{
////			ch=tolower(ch);
////		}
////		cout << ch;
////		cin >> ch;
////	}
////	
////	return 0;
////}
//
//
//
////2.
////int main()
////{
////	array<double, 10> num{};
////	int i;
////	char ch;
////	for (i = 0; i < 10; i++)
////	{
////		cin >> ch;
////		if (isdigit(ch))
////		{
////			num[i] = int(ch)-48;
////		}
////		else
////		{
////			break;
////		}
////	}
////	double av_sum = 0;
////	for (int j = 0; j < i; j++)
////	{
////		av_sum += num[j];
////	}
////	cout << endl << "平均值:" << av_sum / i << endl;
////	for (int k = 0; k < i; k++)
////	{
////		if (num[k] > (av_sum/i))
////		{
////			cout << num[k] << " ";
////		}
////	}
////	return 0;
////}
//
//
//
//
////3.
////int main()
////{
////	char choice;
////	cout << "please enter c,p,t,or g: ";
////	cin >> choice;
////	while (1)
////	{
////		switch (choice)
////		{
////		case 'c':cout << "carnivore" << endl;
////			goto end;
////		case 'p':cout << "pianist" << endl;
////			goto end;
////		case 't':cout << "tree" << endl;
////			goto end;
////		case 'g':cout << "game" << endl;
////			goto end;
////		default:
////			cout << "please enter c,p,t,or g: ";
////			cin >> choice;
////		}
////	}
////end:;
////	return 0;
////}
//
//
//
////4.
////const int strsize = 256;
////struct bop
////{
////	char fullname[strsize];	//真实姓名
////	char title[strsize];	//头衔	
////	char bopname[strsize];	//秘密姓名	
////	int perferce;			//标记
////};
////void menu()
////{
////	cout << "Benevolent Order of programmer Report:" << endl;
////	cout << "a. display by name" << "\t\t" << "b. display by title" << endl;
////	cout << "c. display by bopname" << "\t\t" << "d. display by perferce" << endl;
////}
////int main()
////{
////	bop people[3] = {
////		{"于良浩","公鸡","浩",0},
////		{"喜羊羊","羊","渣男",2},
////		{"沸羊羊","狗","添狗",2},
////	};
////	char choice;
////	while (1)
////	{
////		menu();
////		cout << "Enter your choice: ";
////		cin >> choice;
////		switch (choice)
////		{
////		case 'a':
////			for (int i = 0; i < 3; i++)
////			{
////				cout << people[i].fullname << endl;
////			}
////			break;
////		case 'b':
////			for (int i = 0; i < 3; i++)
////			{
////				cout << people[i].title << endl;
////			}
////			break;
////		case 'c':
////			for (int i = 0; i < 3; i++)
////			{
////				cout << people[i].bopname << endl;
////			}
////			break;
////		case 'd':
////			for (int i = 0; i < 3; i++)
////			{
////				if (people[i].perferce == 0)
////				{
////					cout << people[i].fullname << endl;
////				}
////				else if (people[i].perferce == 1)
////				{
////					cout << people[i].title << endl;
////				}
////				else if (people[i].perferce == 2)
////				{
////					cout << people[i].bopname << endl;
////				}
////				else
////				{
////					continue;
////				}
////			}
////			break;
////		case 'q':cout << "Bye!" << endl;
////			goto end;
////		}
////	}
////end:;
////	return 0;
////}
//
//
//
//////5.
////const float demo1 = 0.1;
////const float demo2 = 0.15;
////const float demo3 = 0.2;
////const float sum0 = 0;
////const float sum1 = 10000*0.1;
////const float sum2 = 20000*0.15+sum1;
////
////int main()
////{
////
////	while (1)
////	{
////		float price = 0;
////		int income = 0;
////		cout << "请输入你的收入:";
////		cin >> income;
////		
////		if (income > 0)
////		{
////			if (income <= 5000 && income >= 0)
////			{
////				price = sum0;
////				cout << "所得税: " << price << endl;
////			}
////			else if (income > 5001 && income <= 15000)
////			{
////				price = (income - 5000) * demo1 + sum0;
////				cout << "所得税: " << price << endl;
////			}
////			else if (income > 15001 && income <= 35000)
////			{
////				price = (income - 15000) * demo2 + sum1;
////				cout << "所得税: " << price << endl;
////			}
////			else if (income > 35000)
////			{
////				price = (income - 35000) * demo3 + sum2;
////				cout << "所得税: " << price << endl;
////			}
////		}
////		else if (income < 0)
////			goto end;	//负数
////		else
////			goto end;	//非数字
////	}
////end:;
////	return 0;
////}
//
//
//
//6
//struct donation
//{
//	string name;	//捐献者姓名
//	double money;	//捐款
//};
//int main()
//{
//	cout << "请输入捐献者的数量:";
//	int count;
//	(cin >> count).get();	//最后会有一个换行符存在
//
//	//动态分配数组
//	donation* Don = new donation[count];
//	cout << "请输入具体信息:"<<endl;
//	for (int i = 0; i < count; i++)
//	{
//		cout << "请输入第" << i + 1 << "人的名字:";
//		getline(cin, Don[i].name);
//		cout << "请输入第" << i + 1 << "人的款项: ";
//		(cin >> Don[i].money).get();
//	}
//	cout << endl << "重要捐款人:" << endl;
//	int fg = 0;
//	for (int i = 0; i < count; i++)
//	{
//		if (Don[i].money >= 10000)
//		{
//			cout << Don[i].name << "\t\t" << Don[i].money << endl;
//			fg++;
//		}
//	}
//	if (fg == 0)
//	{
//		//没有10000以上的人
//		cout << "None!" << endl;
//	}
//	cout << "其他捐献者:" << endl;
//	for (int i = 0; i < count; i++)
//	{
//		if (Don[i].money < 10000)
//		{
//			cout << Don[i].name << "\t\t" << Don[i].money << endl;
//		}
//	}
//	delete []Don;
//	return 0;
//}
//





//7
//int main()
//{
//	string ch;
//	int count1 = 0, count2 = 0, other = 0;
//	cout << "请输入单词:";
//	while ((cin >> ch).get()&& ch!="q")
//	{
//		if (isalpha(ch[0]))
//		{
//			switch (ch[0])
//			{
//			case 'a':
//			case 'e':
//			case 'i':
//			case 'o':
//			case 'u':
//				count1++;
//				break;
//			default:
//				count2++;
//				break;
//			}
//		}
//		else
//		{
//			other++;
//		}
//	}
//	cout << "元音字母:" << count1 << endl;
//	cout << "辅音字母:" << count2 << endl;
//	cout << "其他字母:" << other << endl;
//
//
//	return 0;
//}




//8
//int main()
//{
//	ifstream inFile;
//	string name;
//	cout << "请输入文件名称:";
//	getline(cin, name);
//	inFile.open(name);
//	if (!inFile.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		exit(EXIT_FAILURE);
//	}
//	int count = 0;
//	char ch;
//	//逐字符读取
//	while (inFile.get(ch)/* && inFile.good()*/)
//	{
//		++count;
//		cout.put(ch);
//		if (inFile.eof())
//			break;
//	}
//	cout <<endl<<count << endl;
//	inFile.close();
//	return 0;
//}
//


//9
struct donation
{
	string name;	//捐献者姓名
	double money;	//捐款
};
int main()
{
	ifstream inFile;
	inFile.open("9.txt");
	if (!inFile.is_open())
	{
		cout << "文件打开出错" << endl;
		exit(1);
	}
	int Num;
	(inFile >> Num).get();	//把值赋值给Num;
	
	donation* Don = new donation[Num];
	//在文件读取信息
	for (int i = 0; i < Num; i++)
	{
		getline(inFile, Don[i].name);	//名字
		(inFile >> Don[i].money).get();	//捐款
	}

	for (int i = 0; i < Num; i++)
	{
		cout << Don[i].name << " " << Don[i].money << endl;
	}
	cout << endl << "重要捐款人:" << endl;
	int fg = 0;
	for (int i = 0; i < Num; i++)
	{
		if (Don[i].money >= 10000)
		{
			cout << Don[i].name << "\t\t" << Don[i].money << endl;
			fg++;
		}
	}
	if (fg == 0)
	{
		//没有10000以上的人
		cout << "None!" << endl;
	}
	cout << "其他捐献者:" << endl;
	for (int i = 0; i < Num; i++)
	{
		if (Don[i].money < 10000)
		{
			cout << Don[i].name << "\t\t" << Don[i].money << endl;
		}
	}

	inFile.close();
	delete[]Don;
	return 0;
}





//ceshi 
//int main()
//{
//    string str;
//    cout << "cin的测试：" << endl;
//    cin >> str;
//    cout << str << endl;
//    /*
//    当我输入 woaini ylh 时，str第一次打印空格前的输入woaini 
//    但是，缓冲区还保存着上一次的输入，因此下一次打印会直接输出ylh
//    */
//    cin >> str;
//    cout << str << endl;
//    return 0;
//}

//int main()
//{
//    string str;
//    cout << "cin的测试：" << endl;
//    cin >> str;
//    cout << str << endl;
//    /*
//    当我输入 woaini ylh 时，str第一次打印空格前的输入woaini
//    但是，缓冲区还保存着上一次的输入，因此下一次打印会直接输出ylh 
//    解决方法:  
//    */
//    //清除直到空行的全部内容，实现单个词的输入
//    while ((cin.get()) != '\n')
//        continue;       //cin.sync清除缓冲区无法使用 
//    cin >> str;
//    cout << str << endl;
//
//    return 0;
//}

//
//void main()
//{
//    char ch;
//    char ch1[10], ch2[10];
//    cout << "输入两个字符串：" << endl;
//    cin >> ch1;
//    cin >> ch2;
//    cout << "两个字符串分别为：" << endl;
//    cout << ch1 << endl;
//    cout << ch2 << endl;
//    cin.get(ch);
//    cout << (int)ch << endl; //输出10，为最后一个enter输入
//}