
#include "��������.cpp"
/*
�㷨����:
	ģ�� 
	����������
copy: ��������->vector->list->set
*/

/*
�㷨��:
	#include <algorithm>
	1. ���޸�ʽ���в���
		�������ÿ��Ԫ���޸�  ���ı����� find for_each
	2. �޸�ʽ���в���
		���Ըı����� transform random_shuffle copy
	3. �������ز���
		sort
	#include <numeric>
	4. ͨ����������
		vector�����ֲ���
*/

/*
�㷨�ķ�������:
	�͵��㷨: sort
	�����㷨: copy  ����һ��Ŀ��λ�õĵ�����
	���ֶ���: transform
*/
#if 0
/*
�ַ�����ȫ����
*/
int main()
{
	using namespace std;

	string letters;
	long count = 0;
	cout << "�������ַ���: (quit�˳�):" << '\n';
	while (cin >> letters && letters != "quit")
	{
		cout << "ԭ�ַ���: " << letters << endl;
		sort(letters.begin(), letters.end());
		cout << letters << endl;
		while (next_permutation(letters.begin(), letters.end()))
		{
			count++;
			cout << letters << endl;
		}
		cout << count << endl;
		cout << "�������ַ���: (quit�˳�):" << '\n';
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

	cout << "ԭʼ��la����Ԫ��: \n";
	for_each(la.begin(),la.end(),show);
	cout << endl;

	/*
	�����remove����: ����ɾ������Ϊ4�Ľڵ�
	*/
	//remove��������
	la.remove(4);
	cout << "ɾ��֮���la����: \n";
	for_each(la.begin(), la.end(), show);
	cout << endl;

	/*
	��ʹ��list�ĳ�Ա����remove  
	----ʹ�ý��������ɾ��ֵ��remove����: ---
	���ǲ������Զ��������� 
	����û��ɾ����Ԫ�ط��ڿ�ʼλ��
	��˷���һ��ָ��β�ĵ�����
	*/
	list<int>::iterator last;
	//remove����
	last = remove(lb.begin(), lb.end(), 4);
	cout << "ɾ��֮���lb����: \n";
	for_each(lb.begin(), lb.end(), show);
	cout << endl;

	/*
	lastΪɾ�����ָ��β�ĵ�����
	��ʹ��eraseָ��last ��lb.end() ��ʾɾ��û�õ�Ԫ�� �õ���� 
	*/
	lb.erase(last, lb.end());
	cout << "lb����ʹ��erase֮��: \n";
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
	cout << "���뵥��: (quit �˳�):\n";
	string input;
	while (cin >> input && input != "quit")
	{
		words.push_back(input);
	}
	cout << "�������: \n";
	for_each(words.begin(), words.end(), display);

	/*
	��ʸ���еĵ��ʸ���(���������)��set������ 
	�����Զ�����������  �������sort 
	����ֻ����ͬһ��������һ��  �������unique
	set�� ��ÿ������ת��ΪСд
	*/
	set<string> wordset;
	insert_iterator<set<string>> temp(wordset, wordset.begin());
	transform(words.begin(), words.end(),
		temp, ToLower);
	cout << "Сд����: \n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;


	/*
	map��count:һ��������һ��ֵ  �������ֵ�������г��ֵĴ���
	ʹ��vector���ṩ���� ʹ��set�������ṩ�����б�
	map������ : ������Ϊ���������ʴ洢��ֵ
	*/	map<string, int> wordmap;
	set<string>::iterator si;
	//�����ҵ�ĳ������
	for (si = wordset.begin(); si != wordset.end(); si++)
	{
		//count�ٴ�vector�������ҳ�������֮ƥ��ĵ���
		wordmap[*si] = count(words.begin(), words.end(), *si);
	}

	cout << "ÿ�����ʳ��ֵĴ���: \n";
	for (si = wordset.begin(); si != wordset.end(); si++)
	{
		cout << *si << ": " << wordmap[*si] << endl;
	}
	return 0;
}

string& ToLower(string& st)
{
	/*
	*    string����Ҳ����ʹ��STL����
	�����㷨��transform����  �����䱾��
	*/
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}

void display(const string& s)
{
	cout << s << " ";
}

#endif


