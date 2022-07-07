#include <iostream>
#include <string>
#include "��ϰ��.h"
using std::cin;
using std::cout;
using std::endl;

#if 0
Wine::Wine() {}

Wine::Wine(const char* l, int y, const int* yr, const int* bot)
{
	label = l;
	year = y;
	year_and_bottles.Set(ArrayInt(yr, y), ArrayInt(bot, y));

}

Wine::Wine(const char* l, int y)
{
	label = l;
	year = y;
	//�����鴫������Ա����  ����Ϊy
	year_and_bottles.Set(ArrayInt(y), ArrayInt(y));

}

void Wine::GetBottles()
{
	//�����ڴ���һ������ 
	ArrayInt yr(year);
	ArrayInt bot(year);

	cout << "������" << year << "����ݺ�ƿ��:" << endl;
	for (int i = 0; i < year; i++)
	{
		cout << "�������: ";
		cin >> yr[i];
		cout << "����ƿ��: ";
		cin >> bot[i];
	}
	cout << "�������!\n";
	year_and_bottles.Set(yr, bot);
}

std::string& Wine::Label()
{
	return label;
}

int Wine::sum()
{
	return year_and_bottles.Sum();
}

void Wine::Show() const
{
	cout << "����: " << label << endl;
	cout << "\t���\tƿ��:\n";
	year_and_bottles.Show(year);
}
#endif 


/*
˽�м̳�
*/
#if 0
Wine::Wine() {}

Wine::Wine(const char* l, int y, const int* yr, const int* bot)
	:std::string(l)
{
	PairArray::operator=(PairArray(ArrayInt(yr,y), ArrayInt(bot,y)));
	year = y;

}

Wine::Wine(const char* l, int y)
	:std::string(l)
{
	PairArray::operator=(PairArray(ArrayInt(y), ArrayInt(y)));
	year = y;

}

void Wine::GetBottles()
{
	//�����ڴ���һ������ 
	ArrayInt yr(year);
	ArrayInt bot(year);

	cout << "������" << year << "����ݺ�ƿ��:" << endl;
	for (int i = 0; i < year; i++)
	{
		cout << "�������: ";
		cin >> yr[i];
		cout << "����ƿ��: ";
		cin >> bot[i];
	}
	cout << "�������!\n";
	PairArray::operator=(PairArray(yr, bot));
}

std::string& Wine::Label()
{
	//
	return (std::string&)*this;
}

int Wine::sum()
{
	return PairArray::Sum();
}

void Wine::Show() const
{
	cout << "����: " << (const std::string&)*this << endl;
	cout << "\t���\tƿ��:\n";
	PairArray::Show(year);
}


#endif


#if 0
void Worker::Set()
{
	cout << "Enter worker's name: ";
	std::getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
	return;
}

void Worker::Show() const
{
	cout << "����: " << endl;
	cout << "Worker name: " << fullname << " ";
	cout << "Worker ID: " << id << endl;
	return;
}
#endif

#if  0
Person::~Person()
{}

void Person::Data() const
{
	cout << "��: " << fname <<endl;
	cout << "��: " << lname << endl;

}

void Person::Get()
{
	cout << "��������: ";
	std::getline(cin, fname);
	cout << "��������: ";
	std::getline(cin, lname);
}

/*
ǹ����
*/
void GunsLinger::Data() const
{
	cout << "ǹ�Ŀ̺���: " << num << endl;
}

void GunsLinger::Get()
{
	cout << "������ǹ�Ŀ̺���: ";
	cin >> num;
	while (cin.get() != '\n')
		continue;
}

double GunsLinger::Draw() const
{
	return double(rand() % 5 + 1);	//����ǹ�ֵİ�ǹʱ��
}

//��ʽǹ����Ϣ
void GunsLinger::Show() const
{
	cout << "ǹ�ֵ���Ϣ: ";
	Person::Data();
	Data();
}

//����ǹ����Ϣ
void GunsLinger::Set()
{
	cout << "������ǹ�ֵ���Ϣ: ";
	Person::Get();
	Get();
}

/*
�˿�����
*/
void PokerPlayer::Data() const
{
	cout << "�˿��Ƶ���: " << Draw() << endl;
}

double PokerPlayer::Draw() const
{
	return double(rand() % 52 + 1);
}

void PokerPlayer::Set()
{
	cout << "�����˿���ҵ���Ϣ: ";
	Person::Get();

}

void PokerPlayer::Show()const
{
	cout << "�˿���ҵ���Ϣ: ";
	Person::Data();
	Data();
}


/*
������
*/
void BadDude::Data() const
{
	GunsLinger::Data();
	PokerPlayer::Data();
	cout << "������ǹ��ʱ����: " << Gdraw() << endl;
	cout << "��һ���˿�����: " << Cdraw() << endl;
}

void BadDude::Get()
{
	GunsLinger::Get();
}

double BadDude::Gdraw() const
{
	//���ذ�ǹ��ʱ��
	return GunsLinger::Draw();
}

double BadDude::Cdraw() const
{
	//������һ���˿��� 
	return PokerPlayer::Draw();
}

void BadDude::Set()
{
	cout << "���뻵������Ϣ: " << endl;
	Person::Get();
	Get();
}

void BadDude::Show() const
{
	cout << "������Ϣ: ";
	Person::Data();
	Data();
}

#endif