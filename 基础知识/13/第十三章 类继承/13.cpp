#include <iostream>
//#include "tabtan.h"
#include "�������.h"
using std::cout;
using std::cin;
using std::endl;

//����  ��ͨ�̳�
#if 0
int main()
{
	/*using std::cout;
	TablenTennusPlay Play1{ "chuck","wodjf",true };
	TablenTennusPlay Play2{ "aewef","okkksof",false };
	Play1.Name();
	if (Play1.HasTable())
	{
		cout << ": has a table,\n";
	}
	else
	{
		cout << ": hasn't a table.\n";
	}
	Play2.Name();
	if (Play2.HasTable())
	{
		cout << ": has a table,\n";
	}
	else
	{
		cout << ": hasn't a table.\n";
	}*/



	return 0;
}
#endif

#if 0
void Show(const TablenTennusPlay& t);
//������
int main()
{
	using std::cout;
	TablenTennusPlay Play1{ "chuck","wodjf",true };
	TablenTennusPlay Play2{ "aewef","okkksof",false };
	RatedPlay rplayer1{ 111,"������","�ٺٺ�",true };

	/*
	�������ú�ָ�붼�����ڲ�������ʽ����ת���������ָ�����������
	��ֻ�����ڵ��û��෽��  ������������������ķ���
	��֮�������������ָ�������ָ�����
	*/
	TablenTennusPlay* p = &rplayer1;
	TablenTennusPlay& q = rplayer1;
	Play1.Name();
	if (Play1.HasTable())
	{
		cout << ": has a table,\n";
	}
	else
	{
		cout << ": hasn't a table.\n";
	}
	rplayer1.Name();
	if (rplayer1.HasTable())
	{
		cout << ": has a table,\n";
	}
	else
	{
		cout << ": hasn't a table.\n";
	}
	RatedPlay rplayer2{ rplayer1 };
	rplayer2.Name();
	cout << rplayer2.Rating() << std::endl;

	rplayer1.ResetRating(99);
	Play1.ResetTable(9199);
	cout << rplayer1.HasTable() << endl;
	Show(Play1);
	Show(rplayer1);

	return 0;
}
void Show(const TablenTennusPlay& t)
{
	cout << t.HasTable() << endl;
}
#endif

/*
��̬���м̳�: ͬһ�������ڻ��������������Ϊ��ͬ
	�������������¶������ķ���
	ʹ���鷽��
*/


//��̬�̳�
/*
���д���
*/
#if 0
int main()
{
	Brass Piggy{ "Piggy",300000,4000 };
	//�˴��������������һ�����캯��
	//������������һ���������  ʣ��Ĭ�ϲ���Ϊ�������������
	BrassPlus Hoggy{ "Hoggy",33200,3500};	
	//BrassPlus Hoggy{ "Hoggy",331000,3500 };
	//��ʾ�˻���Ϣ
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;

	cout << "��Hoggy�˻�����1000��Ԫ��\n";
	Hoggy.Deposit(1000);
	cout << "������� : $ " << Hoggy.Balance() << endl;
	cout << "��Piggy�˻���ȡ��3800��Ԫ:\n";
	Piggy.WithDraw(3800);
	cout << "Piggy�ʻ����: $" << Piggy.Balance() << endl;
	cout << "��Hoggy�˻�ȡ4200��Ԫ:\n";
	Hoggy.WithDraw(4200);
	Hoggy.ViewAcct();

	return 0;
}
#endif

/*
��ʾ�鷽������Ϊ
*/

#if  0

const int CLIENTS = 4;
int main()
{
	//ָ������ ����ʾ��̬��
	Brass* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "������˿�����: ";
		getline(cin, temp);
		cout << "�������˺�: ";
		cin >> tempnum;
		cout << "���������: ";
		cin >> tempbal;
		cout << "������ 1 �����������; 2 �������������� ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			;
		if (kind == '1')
		{
			//��������
			p_clients[i] = new Brass{ temp,tempnum,tempbal };
		}
		else
		{
			double tempmax, temprate;
			cout << "�������������: ";
			cin >> tempmax;
			cout << "������������: ";
			cin >> temprate;
			//����������
			p_clients[i] = new BrassPlus{ temp,tempnum,tempbal,tempmax,temprate };
		}
		while (cin.get() != '\n')
			;
	}
	cout << "\n";
	/*
	��̬��:
		��������Ա��Brass  ����Brass::ViewAcct����
		��������Ա��BrassPlus  ����BrassPlus::ViewAcct����
	*/
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}

	cout << "Done! " << endl;
	return 0;
}
#endif //  0

/*
��̬����
��̬����
*/

/*
����ǿ��ת��
����ǿ��ת��
*/

/*
���Ա���������ڶ�̬����
*/

/*
1. ���캯�����ܶ���Ϊ�麯��
2. ���������ڶ�̬������Ӧ�ö���Ϊ�麯��  �ڻ���
3. ��Ԫ�����������Ա ��˲�������Ϊ���
4. �������¶����麯�� ����ɵĽ��ᱻ���� ����ʵ������
	1. �������������¶����麯���Ļ���ֻ���������ͷ����仯 ���ɷ��ػ������û�ָ���Ϊָ�����������ú�ָ��
	2. �������麯�����ڶ������ ������������Ӧ���¶������л���汾 ����ٶ����������ĸ��汾
*/

/*
����: protected  
�ڻ����൱��˽��private  ���������൱�ڻ����public
*/



/*
�������: 
	���������кܶ๲ͬ�� �������ǵ���Ϊȴ�кܴ�Ĳ�ͬ ��˿��Զ���һ�� ABC����������������������еõ���ͬ�ص�
	ע��:  ����ABC�������������������к����麯��������������� =0 ��ʹ���Ϊ ���麯��  ����������һ�������ĳ������
*/




/*
�������ʵ��
*/

const int CLIENTS = 4;
int main()
{
	//ָ������ ����ʾ��̬��
	AcctABC* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "������˿�����: ";
		getline(cin, temp);
		cout << "�������˺�: ";
		cin >> tempnum;
		cout << "���������: ";
		cin >> tempbal;
		cout << "������ 1 �����������; 2 �������������� ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			;
		if (kind == '1')
		{
			//����������
			p_clients[i] = new Brass(temp,tempnum,tempbal);
		}
		else
		{
			double tempmax, temprate;
			cout << "�������������: ";
			cin >> tempmax;
			cout << "������������: ";
			cin >> temprate;
			//����������
			p_clients[i] = new BrassPlus{ temp,tempnum,tempbal,tempmax,temprate };
		}
		while (cin.get() != '\n')
			;
	}
	cout << "\n";
	/*
	��̬��:
		��������Ա��Brass  ����Brass::ViewAcct����
		��������Ա��BrassPlus  ����BrassPlus::ViewAcct����
	*/
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}

	cout << "Done! " << endl;
	return 0;
}
