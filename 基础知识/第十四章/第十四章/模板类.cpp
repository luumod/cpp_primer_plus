
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <array>
#include "ģ����.h"
using std::endl;
using std::cout;
using std::cin;

#if 0
int main()
{
	Stack<std::string> st;	//ģ�������
	char ch;
	std::string po;
	cout << "������ A ��ջ,���� P ��ջ,���� Q �˳��� ";
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
			cout << "�����ַ�����ջ: ";
			cin >> po;
			if (st.isfull())
			{
				std::cout << "ջ����!" << std::endl;
			}
			else
			{
				st.push(po);
			}
			break;
		case 'P':
		case 'p':
			cout << "��ջ: ";
			if (st.isempty())
			{
				std::cout << "ջΪ��!" << std::endl;
			}
			else
			{
				st.pop(po);
				cout << "��ջ�ɹ�! #" << po << endl;
			}
			break;
		}
		cout << "������ A ��ջ,���� P ��ջ,���� Q �˳��� ";
	}
	cout << "Bye!\n";
	return 0;
}

#endif


/*
ָ��ջ
*/
#if 0
const int NUM = 10;
int main()
{
	std::srand(std::time(0));
	cout << "������ջԪ�ظ���: ";
	int stacksize;
	cin >> stacksize;

	//����һ���Զ����С��ָ��ջ����
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
			//��in����ѹ��ջ
			st.push(in[nextin++]);
		}
		else if (st.isfull())
		{
			//��out���鵯��
			st.pop(out[processed++]);
		}
		else if (std::rand() % 2 && nextin < NUM)
		{
			// 0 1 �����ջ
			st.push(in[nextin++]);	
		}
		else
		{
			//��ջ
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
ģ������
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
������Ͳ���
*/
#if 0
int main()
{
	Pair<double, int> a;
	Pair<std::string, int> rating[4] =
	{
		Pair<std::string,int>{"������",666},
		Pair<std::string,int>{"������",333},
		Pair<std::string,int>{"�����",888},
		Pair<std::string,int>{"�켪��",999},
	};
	//������ĳ���  ������ܴ�С/ÿ��Ԫ�صĴ�С
	int joints = sizeof(rating) / sizeof(Pair<std::string, int>);
	cout << "Rating:\t Eatrc:" << endl;
	for (int i = 0; i < joints; i++)
	{
		cout << rating[i].first() << " \t"
			<< rating[i].first() << endl;
	}
	//�޸�ĳһ������
	rating[3].first() = "�ұ��޸���!";
	rating[3].second() = 6666666;
	cout << rating[3].second() << " \t"
		<< rating[3].first() << endl;
	return 0;
}
#endif
/*
Ĭ������ģ�����
*/


/*
ģ��ľ��廯:
	1. ��ʽʵ����
	2. ��ʽʵ����: 
		������ʱʹ��template��ָ����������  
		template class ArrayTP<string,int>  
	3. ��ʽ���廯
		����ض����͵Ķ���
		template <> class Sort<const char* >
	4.���־��廯
		
*/



/*
��Աģ��
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
ģ�����
*/
#if 0
int main()
{
	//ָ��һ��ģ����
	Crab<Stack> one;
	int ni;
	double nb;
	cout << "���������͸����� 0��0�˳�:";
	while (cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if (!one.push(ni, nb))
		{
			break;
		}
	}
	//��ջ�ﵯ��Ԫ�� ����ȳ�
	while (one.pop(ni, nb))
	{
		cout << ni << ", " << nb << endl;
	}
	return 0;
}

#endif

/*
ģ�������Ԫ
	1. ��ģ����Ԫ
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

//Լ��ģ����Ԫ����
#if 0
int main()
{
	//counts ��Ҫ�ṩ���廯��������
	counts<int>();
	HasFrinedT<int> hf(10);
	HasFrinedT<int> hf2(11);
	HasFrinedT<int> hf3(110);
	HasFrinedT<double> hf4(110.110);

	//reports����Ҫ
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

//��Լ��ģ����Ԫ����
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
ģ�����
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