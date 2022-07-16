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
第一题  反转字符串
*/
//不包含多余的字符
#if 0
bool is_input_ok(const std::string& s);
int main()
{
	std::string input;
	std::string temp;
	cout << "请输入字符串,判断其是否是回文,（只能输入小写字母，输入其他的都将退出):\n";
	while (cin >> input)
	{
		temp = input;
		if (is_input_ok(input))
		{
			reverse(input.begin(), input.end());
			if (temp == input)
			{
				cout << "是回文串 : " << input << endl;
			}
			else
			{
				cout << "不是回文串: " << temp << endl;
			}
		}
		else
			;
		cout << "请输入字符串,判断其是否是回文,（只能输入小写字母，输入其他的都将退出):\n";
	}

	return 0;
}

bool is_input_ok(const std::string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (islower(s[i]))
		{
			//所有均是小写
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
第二题
*/
//包含多余的字符
std::string is_input_ok(const std::string& s);
int main()
{
	std::string input;
	std::string dest;
	std::string temp;
	cout << "请输入字符串,判断其是否是回文,（只能输入小写字母，输入其他的都将退出):\n";
	while (getline(cin,input))
	{
		//返回一个拼接好的最终比较的字符串
		dest = is_input_ok(input);
		//生成比较临时字符串
		temp = dest;
		reverse(dest.begin(), dest.end());
		if (temp == dest)
		{
			cout << "是回文串 : " << temp << endl;
		}
		else
		{
			cout << "不是回文串: " << temp << endl;
		}
		cout << "请输入字符串,判断其是否是回文,（只能输入小写字母，输入其他的都将退出):\n";
	}
	
	return 0;
}

std::string is_input_ok(const std::string& s)
{
	std::string temp;
	for (int i = 0; i < s.size(); i++)
	{
		//遇到空格标点跳过
		if (isspace(s[i]) || ispunct(s[i]))
		{
			continue;
		}
		//临时字符串拼接
		temp += tolower(s[i]);
		
	}
	return temp;
}



#elif 0

/*
使用文件读取单词的猜单词游戏
*/

int main()
{
	using std::string;
	using std::vector;
	using std::tolower;
	std::srand(time(0));

	string temp;			//文件读取字符串
	vector<string>  str;	//容器
	std::ifstream in_file;
	in_file.open("word.txt");
	if (!in_file.is_open())
	{
		cout << "文件打开失败!" << endl;
		exit(EXIT_FAILURE);
	}
	
	while (in_file >> temp)
	{
		str.push_back(temp);
	}
	//文件读取完成
	char play;

	cout << "你想玩一个拼字母游戏吗? <y/n>";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		//随机抽取一个字母
		string target = str[std::rand() % str.size()];
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
				cout << "#" << guesses << ": 错误的猜测.\n";
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
编写一个小接口
*/
int reduce(long ar[], int n);
void print(long ar[], int n);
int main()
{
	using std::list;

	long ar[]{ 1L,2L,4L,4L,5L,6L,4L,8L,5L,10L };

	/*
	初始化list值
	*/

	int size = reduce(ar, sizeof(ar) / sizeof(ar[0]));
	cout << "排序后 剩余" << size << "个元素" << endl;
	print(ar, size);

	return 0;
}
int reduce(long ar[], int n)
{
	/*
	数组的排序
	*/
	//124445568 10
	std::sort(ar, ar + n);

	/*
	删除重复的值
	*/
	return static_cast<int>(std::unique(ar, ar + n) - ar);
	//unique返回删除后的指向超尾的迭代器 ，减去首地址 强制类型转换为int
}
void print(long ar[], int n)
{
	//打印数组
	copy(ar, ar + n, std::ostream_iterator<long, char>(cout, " "));
	cout << endl;
}

#elif 0

/*
模板函数
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
	cout << "排序后 long 剩余" << size1 << "个元素" << endl;
	print(ar, size1);


	int size2 = reduce(str, sizeof(str) / sizeof(str[0]));
	cout << "排序后 string 剩余" << size2 << "个元素" << endl;
	print(str, size2);

	return 0;
}
template <typename T>
int reduce(T ar[], int n)
{
	/*
	数组的排序
	*/
	//124445568 10
	std::sort(ar, ar + n);

	/*
	删除重复的值
	*/
	return static_cast<int>(std::unique(ar, ar + n) - ar);
	//unique返回删除后的指向超尾的迭代器 ，减去首地址 强制类型转换为int
}
template <typename T>
void print(T ar[], int n)
{
	//打印数组
	copy(ar, ar + n, std::ostream_iterator<T, char>(cout, " "));
	cout << endl;
}

#elif 0

/*
猜卡片游戏
*/

using namespace std;

vector<int> lotto(int yuandian, int choice);
int main()
{
	vector<int> winner;
	int yuandian, choice;
	while (cin >> yuandian >> choice && choice <= yuandian)
	{
		cout << "彩票有" << yuandian << "个圆点" << choice << "个选择.\n";
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
	//对任意区间进行洗牌操作
	random_shuffle(temp.begin(), temp.end());
	//copy(temp.begin(), temp.end(), ostream_iterator<int, char>(cout, " "));
	cout<<endl;
	//将新的内容分配给vector 覆盖原来的内容
	/*
	在temp容器里选择前choice个元素 赋值给num容器 并返回
	*/
	num.assign(temp.begin(), temp.begin() + choice);
	return num;
}


#elif 0

/*
生日派对
*/
int main()
{
	/*
	set是默认插入数据就自动排序的 
	*/
	using namespace std;
	set<string> Mat;
	set<string> Pat;
	string name;

	cout << "Mat 请输入你的朋友们的信息: (quit退出)\n";
	while (getline(cin, name) && name != "quit")
	{
		Mat.insert(name);	//名字输入进容器
	}
	cout << "输入完成!\n";
	cout << "Pat 请输入你的朋友们的信息: (quit退出)\n";
	while (getline(cin, name) && name != "quit")
	{
		Pat.insert(name);	//名字输入进容器
	}
	cout << "输入完成!\n";

	cout << "Mat 的朋友们: \n";
	copy(Mat.begin(), Mat.end(), ostream_iterator<string, char>(cout, " "));
	cout << endl;
	cout << "Pat 的朋友们: \n";
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
关于链表与数组的排序速度比较
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
	cout << "sort函数: " << static_cast<double>(end1 - start1) / CLOCKS_PER_SEC << endl;

	start2 = clock();
	li.sort();
	end2 = clock();
	cout << "sort方法: " << static_cast<double>(end2- start2) / CLOCKS_PER_SEC << endl;

	cout << "-------------------\n";
	time_t start3, end3;
	copy(vi0.begin(), vi0.end(), li.begin());
	start3 = clock();
	//将li的内容复制到vi
	copy(li.begin(), li.end(), vi.begin());
	//对vi排序
	sort(vi.begin(), vi.end());
	//结果再复制到li中
	copy(vi.begin(), vi.end(), li.begin());
	end3 = clock();
	cout << "list内容复制到vector容器,对vector排序后再复制回list: " <<
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
结论: 
	sort排序速度 > list和vector的相互复制 > list的sort方法
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
	cout << "------------书籍管理-------------:\n";
	cout << "-----------1.原始顺序显示---------\n";
	cout << "-----------2.字母顺序显示---------\n";
	cout << "-----------3.评级升序顺序显示-----\n";
	cout << "-----------4.评级降序顺序显示-----\n";
	cout << "-----------5.价格升序顺序显示-----\n";
	cout << "-----------6.价格降序顺序显示-----\n";
	cout << "-----------0.退出-----------------\n";
}

bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);   //根据评级升序进行排序;
bool betterThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);  //根据评级降序进行排序;
bool worseprice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);  //根据价格升序进行排序;
bool betterprice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2); //根据价格降序进行排序;
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
	cout << "信息输入完毕! " << endl;
	for_each(Res.begin(), Res.end(), ShowReview);
	int choice;
	if (books.size() >= 1)
	{

		while (1)
		{
			system("cls");
			menu();
			cout << "请选择你的操作: \n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "原始顺序显示\n";
				for_each(Res.begin(), Res.end(), ShowReview);
				break;
			case 2:
				cout << "字母顺序显示\n";
				sort(Res.begin(), Res.end());
				for_each(Res.begin(), Res.end(), ShowReview);
				break;
			case 3:
				cout << "评级升序顺序显示\n";
				sort(Res.begin(), Res.end(), worseThan);
				for_each(Res.begin(), Res.end(), ShowReview);
				break;
			case 4:
				cout << "评级降序顺序显示\n";
				sort(Res.begin(), Res.end(), betterThan);
				for_each(Res.begin(), Res.end(), ShowReview);
				break;
			case 5:
				cout << "价格升序顺序显示\n";
				sort(Res.begin(), Res.end(), worseprice);
				for_each(Res.begin(), Res.end(), ShowReview);
				break;
			case 6:
				cout << "价格降序顺序显示\n";
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
		cout << "废物" << endl;
	}
end:;
	cout << "再见\n" << endl;
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

//根据评级升序进行排序
bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

//根据评级降序进行排序
bool betterThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->rating > r2->rating)
		return true;
	else
		return false;
}

//根据价格升序进行排序
bool worseprice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}

//根据价格降序进行排序
bool betterprice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->price > r2->price)
		return true;
	else
		return false;
}

bool FillReview(shared_ptr<Review>& rr)
{
	std::cout << "输入书籍的名称: <quit退出>";
	std::getline(std::cin, rr->title);
	if (rr->title == "quit")
	{
		return false;
	}
	std::cout << "输入书籍的分数: ";
	std::cin >> rr->rating;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		;
	std::cout << "请输入书籍价格: ";
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