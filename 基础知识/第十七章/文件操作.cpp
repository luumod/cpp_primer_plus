#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
using namespace std;

/*
�ļ���д
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
	���ļ���ȡ
	*/
	ifstream fin;
	fin.open(file_name, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "��������ļ�����: " << endl;
		while (fin.read((char*)&p1, sizeof(p1)))
		{
			cout << setw(20) << p1.name << ": "
				<< setprecision(0) << setw(12) << p1.population << setprecision(2)
				<< setw(6) << p1.g << endl;
		}
		fin.close();
	}

	/*
	д���ļ�
	*/
	ofstream fout(file_name,
		ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << "�ļ���ʧ��" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "��������: ";
	cin.get(p1.name, 20);
	while (p1.name[0] != '\0')
	{
		eatline();
		cout << "����population: ";
		cin >> p1.population;
		cout << "����g: ";
		cin >> p1.g;
		eatline();
		fout.write((char*)&p1, sizeof(p1));
		cout << "��������: (�س��˳�)";
		cin.get(p1.name, 20);
	}
	fout.close();

	/*
	���ļ���ȡ
	*/
	fin.clear();		//�����״̬

	fin.open(file_name,
		ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "��������ļ�����: " << endl;
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
�����ȡ
*/

/*
ͬʱʹ�� ios_base::in | ios_base::out | ios_base::binary

�ƶ���ʽ: 
	seekg: �ƶ�����ָ��
	seekp: �ƶ����ָ�� 

	ios_base::beg  ios_base::cur  ios_base::end
	streampos:  �ļ��еľ���λ��  ���ֽ�Ϊ��λ

	��鵱ǰָ���λ��: tellg  tellp����һ����ʾ��ǰλ�õ�streamposֵ
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
	�ɶ���д�ļ�
	*/
	finout.open(file_name, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	if (finout.is_open())
	{
		/*
		�ƶ�����ָ�뵽�ļ���ͷ
		*/
		finout.seekg(0);	
		cout << "�����ļ�������: " << endl;
		/*
		finout.read((char*)&p1,sizeof(p1))	���ļ����ȡ��Ϣ
		*/
		while (finout.read((char*)&p1, sizeof(p1)))
		{
			//���ÿ����С����λ��
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
			cerr << "��ȡ�ļ�ʧ��" << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << "���ļ�ʧ��" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "��������Ҫ�޸ĵ���Ϣ���: ";
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "����������" << endl;
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof(p1);
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "��λ�ļ�λ��ʧ��" << endl;
		exit(EXIT_FAILURE);
	}

	finout.read((char*)&p1, sizeof(p1));
	cout << "���˵���Ϣ: " << endl;
	cout << ct++ << ": " << setw(LIM) << p1.name
		<< setprecision(0) << setw(12) << p1.population
		<< setprecision(3) << setw(12) << p1.g << endl;
	if (finout.eof())
	{
		finout.clear();
	}
	cout << "����������: ";
	cin.get(p1.name, LIM);
	eatline();
	cout << "������population: ";
	cin >> p1.population;
	cout << "������ g: ";
	cin >> p1.g;
	eatline();
	/*
	��λ���ָ���λ��
	*/
	finout.seekp(place);
	/*
	���ļ�д����Ϣ
	*/
	finout.write((char*)&p1, sizeof(p1)) << flush;
	if (finout.fail())
	{
		cerr << "��Ϣд���ļ�ʧ��" << endl;
		exit(EXIT_FAILURE);
	}


	ct = 0;
	/*
	���¶�λ������ָ����ļ�ͷ
	*/
	finout.seekg(0);
	cout << "�����ļ�������: " << endl;
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
��ʱ�ļ�
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
	��string�����������istringstream
	*/
	string is = "wodjaowdadawd adwad ad���޴� ���޴�";
	istringstream instr(is);
	string word;
	while (instr >> word)
	{
		cout << word << endl;
	}

	return 0;
}
#endif