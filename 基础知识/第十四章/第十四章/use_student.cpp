#include <iostream>
#include <vector>
#include <string>
#include "student包含与私有继承.h"
#include "公有继承与虚基类.h"
using std::cin;
using std::cout;
using std::endl;


/*
包含对象成员的类
*/
#if 0
void set(Student& sa, int n);
const int pupils = 3;
const int quizzes = 5;
int main()
{
	Student ada[pupils] =
	{//使用显式的构造函数
		Student(quizzes),Student(quizzes),Student(quizzes)
	};

	for (int i = 0; i < pupils; i++)
	{
		set(ada[i], quizzes);
	}
	cout << "\nStudent List: \n";
	for (int i = 0; i < pupils; i++)
	{
		cout << endl << ada[i];
		cout << "Average: " << ada[i].Average() << endl;
	}
	cout << "Done! \n";
	return 0;

}
void set(Student& sa, int n)
{
	cout << "Please enter the student name: ";
	getline(cin, sa);
	cout << "Please enter " << n << "quiz scores; " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> sa[i];
	}
	while (cin.get() != '\n')
		;
}
#endif

/*
私有继承
*/
#if 0
void set(Student& sa, int n);
const int pupils = 3;
const int quizzes = 5;
int main()
{
	Student ada[pupils] =
	{//使用显式的构造函数
		Student(quizzes),Student(quizzes),Student(quizzes)
	};

	for (int i = 0; i < pupils; i++)
	{
		set(ada[i], quizzes);
	}

	cout << "\nStudent List: \n";
	for (int i = 0; i < pupils; i++)
	{
		cout << ada[i].Name() << endl;
	}
	cout << "\nResult: \n";
	for (int i = 0; i < pupils; i++)
	{
		cout << endl << ada[i];
		cout << "Average: " << ada[i].Average() << endl;
	}
	cout << ada[1].min() << endl;
	cout << "Done! \n";
	return 0;

}
void set(Student& sa, int n)
{
	cout << "Please enter the student name: ";
	getline(cin, sa);
	cout << "Please enter " << n << "quiz scores; " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> sa[i];
	}
	while (cin.get() != '\n')
		;
}
#endif

/*
使用包含来建立has_a关系 
如果新类需要访问原有的类的保护成员 或者重新定义虚函数 使用私有继承
*/

/*
保护继承
*/


/*
using声明  只适用于继承  使得基类的方法在派生类外面可用
*/


/*
多重继承
*/
#if 0
const int LIM = 4;
int main()
{
	Waiter bob{ "于良浩",314L,5 };
	Singer bev{ "王吉虎",522L,3 };
	Waiter w_temp;
	Singer s_temp;

	//Worker 指针
	Worker* pw[LIM] = { &bob,&bev,&w_temp,&s_temp };

	for (int i = 2; i < LIM; i++)
	{
		pw[i]->Set();
	}
	for (int i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		cout << endl;
	}

	return 0;
}

#endif


/*
多重继承完善版本
*/
const int SIZE = 5;
int main()
{
	//Worker* lol[SIZE];

	//for (int i = 0; i < SIZE; i++)
	//{
	//	char choice;
	//	cout << "请输入种类: " << endl;
	//	cout << "w. waiter	 s.singer "
	//		<< "t.singer waiter	q.quit" << endl;
	//	cin >> choice;
	//	while (std::strchr("wstq",choice)==NULL)
	//	{
	//		cout << "请输入种类: " << endl;
	//		cout << "w. waiter	 s.singer "
	//			<< "t.singer waiter	q.quit" << endl;
	//		cin >> choice;
	//	}
	//	if (choice == 'q')
	//		break;
	//	switch (choice)
	//	{
	//	case 'w':
	//		lol[i] = new Waiter;
	//		break;
	//	case 's':
	//		lol[i] = new Singer;
	//		break;
	//	case 't':
	//		lol[i] = new SingerWaiter;
	//		break;
	//	}
	//	cin.get();
	//	lol[i]->Set();	//输入信息
	//}

	//cout << "这是你的输入信息: " << endl;
	//for (int i = 0; i < SIZE;i++)
	//{
	//	lol[i]->Show();
	//	cout << endl;
	//}
	//for (int i = 0; i < SIZE; i++)
	//{
	//	delete lol[i];
	//}
	//cout << "Bye!" << endl;

	Waiter one{ "基类",66,22 };
	Singer two{ "歌手",23 };
	SingerWaiter three{ "作曲家",23,99 };
	SingerWaiter four{ one,5 };

	one.Show();
	two.Show();
	three.Show();
	return 0;
}



/*
1. 混合使用虚基类和非虚基类
2. 虚基类和支配
	同名派生类的名称优于基类的名称
*/