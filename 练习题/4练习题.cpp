#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

//1.
//struct My
//{
//	string fname;
//	string lname;
//	char let;
//	int age;
//};
//int main()
//{
//	My info;
//	cout << "What is you first name? ";
//	getline(cin,info.fname);
//	cout << "What is you last name? ";
//	getline(cin, info.lname);
//	cout << "What letter grade do you deserve? ";
//	cin >> info.let;
//	cout << "What is you age? ";
//	cin >> info.age;
//
//	cout << "Name: " << info.lname << ", " << info.fname << endl;
//	cout << "Grade: " << info.let << endl;
//	cout << "Age: " << info.age << endl;
//
//	return 0;
//}



//2.





//3.
//int main()
//{
//	string name[2];
//	cout << "Enter your first name:";
//	getline(cin, name[0]);
//	cout << "Enter your last name:";
//	getline(cin, name[1]);
//
//	cout << "Here is the infomation in a string: ";
//	cout << name[0] << ", " << name[1] << endl;
//	return 0;
//}


//4. ��

//5.
//struct CandyBar
//{
//	string Pw;
//	double kg;
//	int Hl;
//};
//int main()
//{	
//	CandyBar snake{ "Mocha Munch",2.3,350 };
//	cout << snake.Pw << endl;
//	cout << snake.kg << endl;
//	cout << snake.Hl << endl;
//
//
//	return 0;
//}

//6. ��


//7.
//struct Willam
//{
//	string name;
//	double Z;
//	double kg;
//};
//int main()
//{
//	Willam food;
//	cout << "��������:";
//	getline(cin, food.name);
//	cout << "����ֱ��:";
//	cin >> food.Z;
//	cout << "��������:";
//	cin >> food.kg;
//	cout << "����: " << food.name << endl;
//	cout << "ֱ��: " << food.Z << endl;
//	cout << "����: " << food.kg << endl;
//	return 0;
//}



//8.
//struct Willam
//{
//	string name;
//	double Z;
//	double kg;
//};
//int main()
//{
//	Willam* food = new Willam;
//	cout << "��������:";
//	getline(cin, food->name);
//	cout << "����ֱ��:";
//	cin >> food->Z;
//	cout << "��������:";
//	cin >> food->kg;
//	cout << "����: " << food->name << endl;
//	cout << "ֱ��: " << food->Z << endl;
//	cout << "����: " << food->kg << endl;
//	return 0;
//}



//9.
//struct CandyBar
//{
//	string Pw;
//	double kg;
//	int Hl;
//};
//int main()
//{	
//	CandyBar* sa = new CandyBar[3];
//	sa[0] = { "Mocha Munch",2.3,350 };
//	sa[1] = { "wdwjda Munch",22.3,456 };
//	sa[2] = { "dawda Munch",12.3,789 };
//	cout << sa[0].Pw << endl;
//	cout << sa[0].kg << endl;
//	cout << sa[0].Hl << endl;
//	cout << sa[1].Pw << endl;
//	cout << sa[1].kg << endl;
//	cout << sa[1].Hl << endl;
//	cout << sa[2].Pw << endl;
//	cout << sa[2].kg << endl;
//	cout << sa[2].Hl << endl;
//
//	return 0;
//}



//10.
int main()
{
	array<double, 3> score;
	for (int i = 0; i < 3; i++)
	{
		cout << "�������" << i + 1 << "�γɼ�: ";
		cin >> score[i];
	}
	double av_score=0;
	for (int i = 0; i < 3; i++)
	{
		av_score += score[i];
	}
	cout << "��1��: " << score[0] << endl;
	cout << "��2��: " << score[1] << endl;
	cout << "��3��: " << score[2] << endl;
	cout << "ƽ���ɼ�: " << av_score/3 << endl;


	return 0;
}