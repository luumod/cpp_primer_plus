#include <iostream>
#include <vector>
#include <string>
#include "student������˽�м̳�.h"
#include "���м̳��������.h"
using std::cin;
using std::cout;
using std::endl;


/*
���������Ա����
*/
#if 0
void set(Student& sa, int n);
const int pupils = 3;
const int quizzes = 5;
int main()
{
	Student ada[pupils] =
	{//ʹ����ʽ�Ĺ��캯��
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
˽�м̳�
*/
#if 0
void set(Student& sa, int n);
const int pupils = 3;
const int quizzes = 5;
int main()
{
	Student ada[pupils] =
	{//ʹ����ʽ�Ĺ��캯��
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
ʹ�ð���������has_a��ϵ 
���������Ҫ����ԭ�е���ı�����Ա �������¶����麯�� ʹ��˽�м̳�
*/

/*
�����̳�
*/


/*
using����  ֻ�����ڼ̳�  ʹ�û���ķ������������������
*/


/*
���ؼ̳�
*/
#if 0
const int LIM = 4;
int main()
{
	Waiter bob{ "������",314L,5 };
	Singer bev{ "������",522L,3 };
	Waiter w_temp;
	Singer s_temp;

	//Worker ָ��
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
���ؼ̳����ư汾
*/
const int SIZE = 5;
int main()
{
	//Worker* lol[SIZE];

	//for (int i = 0; i < SIZE; i++)
	//{
	//	char choice;
	//	cout << "����������: " << endl;
	//	cout << "w. waiter	 s.singer "
	//		<< "t.singer waiter	q.quit" << endl;
	//	cin >> choice;
	//	while (std::strchr("wstq",choice)==NULL)
	//	{
	//		cout << "����������: " << endl;
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
	//	lol[i]->Set();	//������Ϣ
	//}

	//cout << "�������������Ϣ: " << endl;
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

	Waiter one{ "����",66,22 };
	Singer two{ "����",23 };
	SingerWaiter three{ "������",23,99 };
	SingerWaiter four{ one,5 };

	one.Show();
	two.Show();
	three.Show();
	return 0;
}



/*
1. ���ʹ�������ͷ������
2. ������֧��
	ͬ����������������ڻ��������
*/