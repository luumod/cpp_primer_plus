#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cctype>
#include <memory>	//����ָ��

using std::cout;
using std::cin;
using std::endl;
using std::string;

// string 
#if 0
int main()
{
	string one{ "abcdefg" };
	cout << one << endl;

	string two{ 20,'#' };
	cout << two << endl;

	string three{ one };
	cout << three << endl;

	one += "������";
	cout << one << endl;

	two = "�Բ��� �����";
	three[0] = 'P';

	string four;
	four = two + three;
	cout << four << endl;

	char alls[] = "Alldawd daw d wadwa wadagr ";
	string five{ alls,20 };
	cout << five << "!\n";

	string six{ alls + 5,alls + 20 };
	cout << six << endl;

	string seven{ &five[6],&five[10] };
	cout << seven << endl;

	string eight{ four,7,16 };
	cout << eight << endl;
	return 0;
}
#elif 0
//string ����
int main()
{
	std::ifstream fin;
	fin.open("tobuy.txt");
	if (fin.is_open() == false)
	{
		std::cerr << "Can not open file.Bye.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	//��':'Ϊ�ָ����� ��ȡ��':' Ϊֹ  ���з�Ҳ�ᱻ��Ϊ�����ַ�
	std::getline(fin, item, ':');
	while (fin)
	{
		++count;
		cout << count << ": " << item << endl;
		std::getline(fin, item, ':');
		item.length();
	}
	cout << "Done!\n";
	fin.close();
	return 0;
#elif 0
/*
ƴ����Ϸ
*/
const int NUM = 26;
const string wordlist[NUM] =
{ "apiary", "beetle", "cereal", "danger", "ensign", "florid", "garage", "health", "insult", "jackal", "keeper", "loaner", "manage", "nonce", "onset", "plaid", "quilt", "remote", "stolid", "train", "useful", "valid", "whence", "xenon", "yearn", "zippy"
};
int main()
{
	using std::tolower;
	std::srand(time(0));
	char play;

	cout << "������һ��ƴ��ĸ��Ϸ��? <y/n>";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		//�����ȡһ����ĸ
		string target = wordlist[std::rand() % NUM];
		int lengh = target.size();
		string attempts(lengh, '-');
		string badchars;
		int guesses = 6;
		cout << "����ѡ�����Ǹ�����? ����" << lengh << "���ַ���,��������"
			<< guesses << "�λ���.\n";
		cout << "�㼴���²�ĵ���: " << attempts << endl;
		while (guesses > 0 && attempts != target)
		{
			char letter;
			cout << "��һ����ĸ: ";
			cin >> letter;
			/*
			�������Ƿ�����ǰ�����������ĸ
			*/
			if (badchars.find(letter) != string::npos
				|| attempts.find(letter) != string::npos)
			{
				cout << "���Ѿ��³��������ĸ,���ٴ�����";
				continue;
			}
			//���û��find��letter �򷵻� -1 
			int loc = target.find(letter);
			//string::npos ��ֵΪ -1  ���� ���loc����string::npos
			//��������û�������ĸ
			if (loc == string::npos)
			{
				cout << "��~~~ �������!!!\n";
				--guesses;
				//�������  ��ӵ��ʵ������string��
				badchars += letter;
			}
			else
			{
				cout << "ţ��  ������ȷ\n";
				/*
				������ȷ  ��ӵ��ʵ���ȷ��string��
				*/
				attempts[loc] = letter;
				loc = target.find(letter, loc + 1);
				/*
				һֱѰ�������ĸ  ֪�����ﵥ�ʽ�βû�г��������ĸΪֹ
				*/
				while (loc != string::npos)
				{
					attempts[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "������뵥��: " << attempts << endl;
			if (attempts != target)
			{
				if (badchars.length() > 0)
				{
					cout << "�������������: " << badchars << endl;
				}
				cout <<"#" << guesses << ": ����Ĳ²�.\n";
			}
		}
		if (guesses > 0)
		{
			cout << "��ȷ! \n";
		}
		else
		{
			cout << "�Բ��� ��´��� ��ȷ��: " << target << ".\n";
		}
		cout << "��������? <y/n>";
		cin >> play;
		play = tolower(play);
	}
	cout << "Bye!" << endl;
	return 0;
}
#elif 0
/*
capacity ���ط�����ַ������ڴ��Ĵ�С
reserve  �����ڴ�����С����
*/
int main()
{
	using namespace std;
	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";
	cout << "Size: " << endl;
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;

	cout << "Capacity: " << endl;
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;

	empty.reserve(50);
	cout << "Capacity after empty.reserve(50): "
		<< empty.capacity() << endl;
	return 0;
}
#elif 
#endif