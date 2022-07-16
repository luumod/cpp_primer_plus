#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <set>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

/*
��һ��  ��ת�ַ���
*/
//������������ַ�
#if 0
bool is_input_ok(const std::string& s);
int main()
{
	std::string input;
	std::string temp;
	cout << "�������ַ���,�ж����Ƿ��ǻ���,��ֻ������Сд��ĸ�����������Ķ����˳�):\n";
	while (cin >> input)
	{
		temp = input;
		if (is_input_ok(input))
		{
			reverse(input.begin(), input.end());
			if (temp == input)
			{
				cout << "�ǻ��Ĵ� : " << input << endl;
			}
			else
			{
				cout << "���ǻ��Ĵ�: " << temp << endl;
			}
		}
		else
			;
		cout << "�������ַ���,�ж����Ƿ��ǻ���,��ֻ������Сд��ĸ�����������Ķ����˳�):\n";
	}

	return 0;
}

bool is_input_ok(const std::string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (islower(s[i]))
		{
			//���о���Сд
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}



#elif 0
/*
�ڶ���
*/
//����������ַ�
std::string is_input_ok(const std::string& s);
int main()
{
	std::string input;
	std::string dest;
	std::string temp;
	cout << "�������ַ���,�ж����Ƿ��ǻ���,��ֻ������Сд��ĸ�����������Ķ����˳�):\n";
	while (getline(cin,input))
	{
		//����һ��ƴ�Ӻõ����ձȽϵ��ַ���
		dest = is_input_ok(input);
		//���ɱȽ���ʱ�ַ���
		temp = dest;
		reverse(dest.begin(), dest.end());
		if (temp == dest)
		{
			cout << "�ǻ��Ĵ� : " << temp << endl;
		}
		else
		{
			cout << "���ǻ��Ĵ�: " << temp << endl;
		}
		cout << "�������ַ���,�ж����Ƿ��ǻ���,��ֻ������Сд��ĸ�����������Ķ����˳�):\n";
	}
	
	return 0;
}

std::string is_input_ok(const std::string& s)
{
	std::string temp;
	for (int i = 0; i < s.size(); i++)
	{
		//�����ո�������
		if (isspace(s[i]) || ispunct(s[i]))
		{
			continue;
		}
		//��ʱ�ַ���ƴ��
		temp += tolower(s[i]);
		
	}
	return temp;
}



#elif 0

/*
ʹ���ļ���ȡ���ʵĲµ�����Ϸ
*/

int main()
{
	using std::string;
	using std::vector;
	using std::tolower;
	std::srand(time(0));

	string temp;			//�ļ���ȡ�ַ���
	vector<string>  str;	//����
	std::ifstream in_file;
	in_file.open("word.txt");
	if (!in_file.is_open())
	{
		cout << "�ļ���ʧ��!" << endl;
		exit(EXIT_FAILURE);
	}
	
	while (in_file >> temp)
	{
		str.push_back(temp);
	}
	//�ļ���ȡ���
	char play;

	cout << "������һ��ƴ��ĸ��Ϸ��? <y/n>";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		//�����ȡһ����ĸ
		string target = str[std::rand() % str.size()];
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
				cout << "#" << guesses << ": ����Ĳ²�.\n";
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
��дһ��С�ӿ�
*/
int reduce(long ar[], int n);
void print(long ar[], int n);
int main()
{
	using std::list;

	long ar[]{ 1L,2L,4L,4L,5L,6L,4L,8L,5L,10L };

	/*
	��ʼ��listֵ
	*/

	int size = reduce(ar, sizeof(ar) / sizeof(ar[0]));
	cout << "����� ʣ��" << size << "��Ԫ��" << endl;
	print(ar, size);

	return 0;
}
int reduce(long ar[], int n)
{
	/*
	���������
	*/
	//124445568 10
	std::sort(ar, ar + n);

	/*
	ɾ���ظ���ֵ
	*/
	return static_cast<int>(std::unique(ar, ar + n) - ar);
	//unique����ɾ�����ָ��β�ĵ����� ����ȥ�׵�ַ ǿ������ת��Ϊint
}
void print(long ar[], int n)
{
	//��ӡ����
	copy(ar, ar + n, std::ostream_iterator<long, char>(cout, " "));
	cout << endl;
}

#elif 0

/*
ģ�庯��
*/

template <typename T>
int reduce(T ar[], int n);
template <typename T>
void print(T ar[], int n);
int main()
{
	using std::list;

	long ar[]{ 1L,2L,4L,4L,5L,6L,4L,8L,5L,10L };
	std::string str[]{ "abcd","okodw","bvdh","ncid","dfei","dfei","zkfeo","plda" };


	int size1 = reduce(ar, sizeof(ar) / sizeof(ar[0]));
	cout << "����� long ʣ��" << size1 << "��Ԫ��" << endl;
	print(ar, size1);


	int size2 = reduce(str, sizeof(str) / sizeof(str[0]));
	cout << "����� string ʣ��" << size2 << "��Ԫ��" << endl;
	print(str, size2);

	return 0;
}
template <typename T>
int reduce(T ar[], int n)
{
	/*
	���������
	*/
	//124445568 10
	std::sort(ar, ar + n);

	/*
	ɾ���ظ���ֵ
	*/
	return static_cast<int>(std::unique(ar, ar + n) - ar);
	//unique����ɾ�����ָ��β�ĵ����� ����ȥ�׵�ַ ǿ������ת��Ϊint
}
template <typename T>
void print(T ar[], int n)
{
	//��ӡ����
	copy(ar, ar + n, std::ostream_iterator<T, char>(cout, " "));
	cout << endl;
}

#elif 0

/*
�¿�Ƭ��Ϸ
*/

using namespace std;

vector<int> lotto(int yuandian, int choice);
int main()
{
	vector<int> winner;
	int yuandian, choice;
	while (cin >> yuandian >> choice && choice <= yuandian)
	{
		cout << "��Ʊ��" << yuandian << "��Բ��" << choice << "��ѡ��.\n";
		winner = lotto(yuandian, choice);
		copy(winner.begin(), winner.end(), ostream_iterator<int, char>(cout, " "));
		cout << endl;
	}


	return 0;
}
vector<int> lotto(int yuandian, int choice)
{
	vector<int> temp(yuandian);
	vector<int> num(choice);

	for (int i = 0; i < yuandian; i++)
	{
		temp[i] = i + 1;
	}
	//�������������ϴ�Ʋ���
	random_shuffle(temp.begin(), temp.end());
	//copy(temp.begin(), temp.end(), ostream_iterator<int, char>(cout, " "));
	cout<<endl;
	//���µ����ݷ����vector ����ԭ��������
	/*
	��temp������ѡ��ǰchoice��Ԫ�� ��ֵ��num���� ������
	*/
	num.assign(temp.begin(), temp.begin() + choice);
	return num;
}


#elif 0

/*
�����ɶ�
*/
int main()
{
	/*
	set��Ĭ�ϲ������ݾ��Զ������ 
	*/
	using namespace std;
	set<string> Mat;
	set<string> Pat;
	string name;

	cout << "Mat ��������������ǵ���Ϣ: (quit�˳�)\n";
	while (getline(cin, name) && name != "quit")
	{
		Mat.insert(name);	//�������������
	}
	cout << "�������!\n";
	cout << "Pat ��������������ǵ���Ϣ: (quit�˳�)\n";
	while (getline(cin, name) && name != "quit")
	{
		Pat.insert(name);	//�������������
	}
	cout << "�������!\n";

	cout << "Mat ��������: \n";
	copy(Mat.begin(), Mat.end(), ostream_iterator<string, char>(cout, " "));
	cout << endl;
	cout << "Pat ��������: \n";
	copy(Pat.begin(), Pat.end(), ostream_iterator<string, char>(cout, " "));

	cout << endl;
	list<string> all;
	set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(),	ostream_iterator<string, char>(cout, " "));
	for (auto x : all)
	{
		cout << x << " ";
	}
	return 0;
}

#elif 0

/*
��������������������ٶȱȽ�
*/

const long size[3] = { 100000,500000,2000000};
void Sort(long n)
{
	using namespace std;
	srand(time(0));
	vector<int> vi0(n);
	for (auto x : vi0)
	{
		x = rand() % 5000+1;
	}
	vector<int> vi(vi0);
	list<int> li(n);

	copy(vi0.begin(), vi0.end(), li.begin());

	time_t start1, end1;
	time_t start2, end2;

	start1 = clock();
	sort(vi.begin(), vi.end());
	end1 = clock();
	cout << "sort����: " << static_cast<double>(end1 - start1) / CLOCKS_PER_SEC << endl;

	start2 = clock();
	li.sort();
	end2 = clock();
	cout << "sort����: " << static_cast<double>(end2- start2) / CLOCKS_PER_SEC << endl;

	cout << "-------------------\n";
	time_t start3, end3;
	copy(vi0.begin(), vi0.end(), li.begin());
	start3 = clock();
	//��li�����ݸ��Ƶ�vi
	copy(li.begin(), li.end(), vi.begin());
	//��vi����
	sort(vi.begin(), vi.end());
	//����ٸ��Ƶ�li��
	copy(vi.begin(), vi.end(), li.begin());
	end3 = clock();
	cout << "list���ݸ��Ƶ�vector����,��vector������ٸ��ƻ�list: " <<
		static_cast<double>(end3 - start3) / CLOCKS_PER_SEC << endl;
}
int main()
{
	for (int i = 0; i < 3; i++)
	{
		Sort(size[i]);
	}
	return 0;
}

/*
����: 
	sort�����ٶ� > list��vector���໥���� > list��sort����
*/
#elif 1

using namespace std;

struct Review
{
	std::string title;
	int rating;
	double price;
};
void menu()
{
	cout << "------------�鼮����-------------:\n";
	cout << "-----------1.ԭʼ˳����ʾ---------\n";
	cout << "-----------2.��ĸ˳����ʾ---------\n";
	cout << "-----------3.��������˳����ʾ-----\n";
	cout << "-----------4.��������˳����ʾ-----\n";
	cout << "-----------5.�۸�����˳����ʾ-----\n";
	cout << "-----------6.�۸���˳����ʾ-----\n";
	cout << "-----------0.�˳�-----------------\n";
}

bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);   //�������������������;
bool betterThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);  //�������������������;
bool worseprice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);  //���ݼ۸������������;
bool betterprice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2); //���ݼ۸����������;
bool FillReview(shared_ptr<Review>& rr);
void ShowReview(const shared_ptr<Review>& rr);
shared_ptr<Review> make_Return_ptr();
int main()
{
	vector<shared_ptr<Review>> books;
	shared_ptr<Review> temp(new Review);
	while (FillReview(temp))
	{
		books.push_back(temp);
		temp = make_Return_ptr();
	}
	vector<shared_ptr<Review>> Res(books);
	cout << "��Ϣ�������! " << endl;
	for_each(Res.begin(), Res.end(), ShowReview);
	int choice;
	if (books.size() >= 1)
	{

		while (1)
		{
			system("cls");
			menu();
			cout << "��ѡ����Ĳ���: \n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "ԭʼ˳����ʾ\n";
				for_each(Res.begin(), Res.end(), ShowReview);
				break;
			case 2:
				cout << "��ĸ˳����ʾ\n";
				sort(Res.begin(), Res.end());
				for_each(Res.begin(), Res.end(), ShowReview);
				break;
			case 3:
				cout << "��������˳����ʾ\n";
				sort(Res.begin(), Res.end(), worseThan);
				for_each(Res.begin(), Res.end(), ShowReview);
				break;
			case 4:
				cout << "��������˳����ʾ\n";
				sort(Res.begin(), Res.end(), betterThan);
				for_each(Res.begin(), Res.end(), ShowReview);
				break;
			case 5:
				cout << "�۸�����˳����ʾ\n";
				sort(Res.begin(), Res.end(), worseprice);
				for_each(Res.begin(), Res.end(), ShowReview);
				break;
			case 6:
				cout << "�۸���˳����ʾ\n";
				sort(Res.begin(), Res.end(), betterprice);
				for_each(Res.begin(), Res.end(), ShowReview);
				break;
			case 0:
				goto end;
				break;
			default:
				break;
			}
		}
	}
	else
	{
		cout << "����" << endl;
	}
end:;
	cout << "�ټ�\n" << endl;
	return 0;
}
shared_ptr<Review> make_Return_ptr()
{
	return shared_ptr<Review>(new Review);
}

bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else
		return false;
}

//�������������������
bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

//�������������������
bool betterThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->rating > r2->rating)
		return true;
	else
		return false;
}

//���ݼ۸������������
bool worseprice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}

//���ݼ۸����������
bool betterprice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->price > r2->price)
		return true;
	else
		return false;
}

bool FillReview(shared_ptr<Review>& rr)
{
	std::cout << "�����鼮������: <quit�˳�>";
	std::getline(std::cin, rr->title);
	if (rr->title == "quit")
	{
		return false;
	}
	std::cout << "�����鼮�ķ���: ";
	std::cin >> rr->rating;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		;
	std::cout << "�������鼮�۸�: ";
	std::cin >> rr->price;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		;

	return true;
}
void ShowReview(const shared_ptr<Review>& rr)
{
	std::cout << rr->rating << ": " << rr->title<<": " <<rr->price << std::endl;
}


#endif