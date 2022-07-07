
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <array>
#include "模板类.h"
using std::endl;
using std::cout;
using std::cin;

#if 0
int main()
{
	Stack<std::string> st;	//模板类对象
	char ch;
	std::string po;
	cout << "请输入 A 入栈,输入 P 出栈,输入 Q 退出： ";
	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			;
		if (!std::isalpha(ch))
		{
			cout << '\a';
			;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "输入字符串入栈: ";
			cin >> po;
			if (st.isfull())
			{
				std::cout << "栈已满!" << std::endl;
			}
			else
			{
				st.push(po);
			}
			break;
		case 'P':
		case 'p':
			cout << "出栈: ";
			if (st.isempty())
			{
				std::cout << "栈为空!" << std::endl;
			}
			else
			{
				st.pop(po);
				cout << "出栈成功! #" << po << endl;
			}
			break;
		}
		cout << "请输入 A 入栈,输入 P 出栈,输入 Q 退出： ";
	}
	cout << "Bye!\n";
	return 0;
}

#endif


/*
指针栈
*/
#if 0
const int NUM = 10;
int main()
{
	std::srand(std::time(0));
	cout << "请输入栈元素个数: ";
	int stacksize;
	cin >> stacksize;

	//创建一个自定义大小的指针栈对象
	Stack<const char*> st{ stacksize };	

	const char* in[NUM] =
	{
		" 1:Hank Gilgamesh" , " 2: Kiki Ishtar" ,
		" 3: Betty Rocker" ," 4: Ian Flagranti ",
		" 5: wolfgang Kibble" , "6: Portia Koop",
		"7:Joy Almondo"," 8: xaverie Paprika" ,
		"9: Juan Moore", "10: Misha Mache"
	};

	const char* out[NUM];

	int processed = 0;
	int nextin = 0;
	while (processed < NUM)
	{
		if (st.isempty())
		{
			//从in数组压入栈
			st.push(in[nextin++]);
		}
		else if (st.isfull())
		{
			//从out数组弹出
			st.pop(out[processed++]);
		}
		else if (std::rand() % 2 && nextin < NUM)
		{
			// 0 1 随机入栈
			st.push(in[nextin++]);	
		}
		else
		{
			//出栈
			st.pop(out[processed++]);
		}
	}
	for (int i = 0; i < NUM; i++)
	{
		cout << out[i] << endl;
	}
	cout << "Bye!" << endl;
	return 0;
}
#endif 


/*
模板数组
*/
#if 0
int main()
{
	ArrayTP<int, 10> sums;	// int sums[10]
	ArrayTP<double, 10> aves;	// double sums[10]
	ArrayTP < ArrayTP<int , 5>,10> twodee;	// int sums[10][5]

	for (int i = 0; i < 10; i++)
	{
		sums[i] = 0;
		for (int j = 0; j < 5; j++)
		{
			twodee[i][j] = (i + 1) * (j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 10;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout.width(2);
			cout << twodee[i][j] << " ";
		}
		cout << ": sum= ";
		cout.width(3);
		cout << sums[i] << ", average= " << aves[i] << endl;
	}
	cout << "Done!\n";

	return 0;
}
#endif 

/*
多个类型参数
*/
#if 0
int main()
{
	Pair<double, int> a;
	Pair<std::string, int> rating[4] =
	{
		Pair<std::string,int>{"于良浩",666},
		Pair<std::string,int>{"王吉虎",333},
		Pair<std::string,int>{"蔡联淇",888},
		Pair<std::string,int>{"徐吉海",999},
	};
	//类数组的长度  数组的总大小/每个元素的大小
	int joints = sizeof(rating) / sizeof(Pair<std::string, int>);
	cout << "Rating:\t Eatrc:" << endl;
	for (int i = 0; i < joints; i++)
	{
		cout << rating[i].first() << " \t"
			<< rating[i].first() << endl;
	}
	//修改某一个对象
	rating[3].first() = "我被修改了!";
	rating[3].second() = 6666666;
	cout << rating[3].second() << " \t"
		<< rating[3].first() << endl;
	return 0;
}
#endif
/*
默认类型模板参数
*/


/*
模板的具体化:
	1. 隐式实例化
	2. 显式实例化: 
		声明类时使用template来指出所需类型  
		template class ArrayTP<string,int>  
	3. 显式具体化
		针对特定类型的定义
		template <> class Sort<const char* >
	4.部分具体化
		
*/



/*
成员模板
*/
#if 0
int main()
{
	Beta<double> guy{ 5.0,6 };
	guy.show();
	cout << guy.blab(10, 5.3) << endl;

	return 0;
}
#endif


/*
模板参数
*/
#if 0
int main()
{
	//指定一个模板类
	Crab<Stack> one;
	int ni;
	double nb;
	cout << "输入整数和浮点数 0和0退出:";
	while (cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if (!one.push(ni, nb))
		{
			break;
		}
	}
	//从栈里弹出元素 后进先出
	while (one.pop(ni, nb))
	{
		cout << ni << ", " << nb << endl;
	}
	return 0;
}

#endif

/*
模板类和友元
	1. 非模板友元
*/
#if 0
int main()
{
	cout << "No object declared: ";
	counts();
	HasFriend<int> hf(10);
	cout << "Then: ";
	counts();
	HasFriend<int> hf2(11);
	cout << "Then: ";
	counts();
	HasFriend<int> hf3(110);
	cout << "Then: ";
	counts();
	HasFriend<double> hf4(110.110);
	cout << "Then: ";
	counts();

	reports(hf);
	reports(hf2);
	reports(hf3);
	reports(hf4);

	return 0;
}
#endif 

//约束模板友元函数
#if 0
int main()
{
	//counts 需要提供具体化参数类型
	counts<int>();
	HasFrinedT<int> hf(10);
	HasFrinedT<int> hf2(11);
	HasFrinedT<int> hf3(110);
	HasFrinedT<double> hf4(110.110);

	//reports不需要
	report(hf);
	report(hf2);
	report(hf3);
	report(hf4);
	cout << "counts<int>: ";
	counts<int>();
	cout << "counts<double>: ";
	counts<double>();
	return 0;
}
#endif 

//非约束模板友元函数
//
int main()
{
	ManyFriend<int> hf1(10);
	ManyFriend<int> hf2(20);
	ManyFriend<double> hf3(10.12);
	cout << "hf1, hf2: ";
	show2(hf1, hf2);
	cout << "hf2, hf3: ";
	show2(hf2, hf3);
	return 0;
}


/*
模板别名
*/

template <typename T>
using arrtype = std::array<T, 12>;

int main()
{
	arrtype<double> one;
	arrtype<int> two;
	arrtype<std::string> three;

	return 0;
}