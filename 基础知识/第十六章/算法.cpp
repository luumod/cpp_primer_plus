
#include "函数对象.cpp"
/*
算法函数:
	模板 
	迭代器区间
copy: 常规数组->vector->list->set
*/

/*
算法组:
	#include <algorithm>
	1. 非修改式序列操作
		对区间的每个元素修改  不改变内容 find for_each
	2. 修改式序列操作
		可以改变内容 transform random_shuffle copy
	3. 排序和相关操作
		sort
	#include <numeric>
	4. 通用数字运算
		vector的数字操作
*/

/*
算法的分类特征:
	就地算法: sort
	复制算法: copy  返回一个目标位置的迭代器
	两种都有: transform
*/
#if 0
/*
字符串的全排列
*/
int main()
{
	using namespace std;

	string letters;
	long count = 0;
	cout << "请输入字符串: (quit退出):" << '\n';
	while (cin >> letters && letters != "quit")
	{
		cout << "原字符串: " << letters << endl;
		sort(letters.begin(), letters.end());
		cout << letters << endl;
		while (next_permutation(letters.begin(), letters.end()))
		{
			count++;
			cout << letters << endl;
		}
		cout << count << endl;
		cout << "请输入字符串: (quit退出):" << '\n';
	}
	cout << "Done! "<< endl;
	return 0;
}

#elif 0

void show(int);
const int NUM = 10;
int main()
{
	using namespace std;
	int ar[NUM] = { 1,2,3,4,4,6,7,4,9,10 };

	list<int> la(ar, ar + NUM);
	list<int> lb(la);

	cout << "原始的la链表元素: \n";
	for_each(la.begin(),la.end(),show);
	cout << endl;

	/*
	链表的remove方法: 链表删除所有为4的节点
	*/
	//remove容器方法
	la.remove(4);
	cout << "删除之后的la链表: \n";
	for_each(la.begin(), la.end(), show);
	cout << endl;

	/*
	不使用list的成员函数remove  
	----使用接受区间和删除值的remove函数: ---
	但是并不会自动调整长度 
	它将没被删除的元素放在开始位置
	因此返回一个指向超尾的迭代器
	*/
	list<int>::iterator last;
	//remove函数
	last = remove(lb.begin(), lb.end(), 4);
	cout << "删除之后的lb链表: \n";
	for_each(lb.begin(), lb.end(), show);
	cout << endl;

	/*
	last为删除后的指向超尾的迭代器
	在使用erase指向last 到lb.end() 表示删除没用的元素 得到结果 
	*/
	lb.erase(last, lb.end());
	cout << "lb链表使用erase之后: \n";
	for_each(lb.begin(), lb.end(), show);
	cout << endl;


	return 0;
}
void show(int x)
{
	std::cout << x << " ";
}



#elif 1

using namespace std;
char toLower(char ch)
{
	return tolower(ch);
}
string& ToLower(string& st);
void display(const string& s);

int main()
{
	vector<string> words;
	cout << "输入单词: (quit 退出):\n";
	string input;
	while (cin >> input && input != "quit")
	{
		words.push_back(input);
	}
	cout << "你的输入: \n";
	for_each(words.begin(), words.end(), display);

	/*
	将矢量中的单词复制(插入迭代器)到set集合中 
	集合自动对内容排序  无需调用sort 
	集合只允许同一个键出现一次  无需调用unique
	set： 把每个单词转换为小写
	*/
	set<string> wordset;
	insert_iterator<set<string>> temp(wordset, wordset.begin());
	transform(words.begin(), words.end(),
		temp, ToLower);
	cout << "小写单词: \n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;


	/*
	map：count:一个区间与一个值  返回这个值在区间中出现的次数
	使用vector来提供区间 使用set对象来提供单词列表
	map的特性 : 将键作为索引来访问存储的值
	*/	map<string, int> wordmap;
	set<string>::iterator si;
	//具体找到某个单词
	for (si = wordset.begin(); si != wordset.end(); si++)
	{
		//count再从vector容器中找出所有与之匹配的单词
		wordmap[*si] = count(words.begin(), words.end(), *si);
	}

	cout << "每个单词出现的次数: \n";
	for (si = wordset.begin(); si != wordset.end(); si++)
	{
		cout << *si << ": " << wordmap[*si] << endl;
	}
	return 0;
}

string& ToLower(string& st)
{
	/*
	*    string对象也可以使用STL函数
	复制算法的transform函数  覆盖其本身
	*/
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}

void display(const string& s)
{
	cout << s << " ";
}

#endif


