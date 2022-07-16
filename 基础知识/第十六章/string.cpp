#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cctype>
#include <memory>	//智能指针

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

	one += "于良浩";
	cout << one << endl;

	two = "对不起 这才是";
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
//string 输入
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
	//以':'为分隔符号 读取到':' 为止  换行符也会被视为常规字符
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
拼字游戏
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

	cout << "你想玩一个拼字母游戏吗? <y/n>";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		//随机抽取一个字母
		string target = wordlist[std::rand() % NUM];
		int lengh = target.size();
		string attempts(lengh, '-');
		string badchars;
		int guesses = 6;
		cout << "猜我选中了那个单词? 它有" << lengh << "个字符长,并且你有"
			<< guesses << "次机会.\n";
		cout << "你即将猜测的单词: " << attempts << endl;
		while (guesses > 0 && attempts != target)
		{
			char letter;
			cout << "猜一个字母: ";
			cin >> letter;
			/*
			检查玩家是否在以前输入了这个字母
			*/
			if (badchars.find(letter) != string::npos
				|| attempts.find(letter) != string::npos)
			{
				cout << "你已经猜出了这个字母,请再次输入";
				continue;
			}
			//如果没有find到letter 则返回 -1 
			int loc = target.find(letter);
			//string::npos 的值为 -1  所以 如果loc等于string::npos
			//表明单词没有这个字母
			if (loc == string::npos)
			{
				cout << "不~~~ 输入错误!!!\n";
				--guesses;
				//输入错误  添加单词到错误的string中
				badchars += letter;
			}
			else
			{
				cout << "牛逼  输入正确\n";
				/*
				输入正确  添加单词到正确的string中
				*/
				attempts[loc] = letter;
				loc = target.find(letter, loc + 1);
				/*
				一直寻找这个字母  知道到达单词结尾没有出现这个字母为止
				*/
				while (loc != string::npos)
				{
					attempts[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "你的输入单词: " << attempts << endl;
			if (attempts != target)
			{
				if (badchars.length() > 0)
				{
					cout << "错误的输入序列: " << badchars << endl;
				}
				cout <<"#" << guesses << ": 错误的猜测.\n";
			}
		}
		if (guesses > 0)
		{
			cout << "正确! \n";
		}
		else
		{
			cout << "对不起 你猜错了 正确答案: " << target << ".\n";
		}
		cout << "继续玩吗? <y/n>";
		cin >> play;
		play = tolower(play);
	}
	cout << "Bye!" << endl;
	return 0;
}
#elif 0
/*
capacity 返回分配给字符串的内存块的大小
reserve  请求内存块的最小长度
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