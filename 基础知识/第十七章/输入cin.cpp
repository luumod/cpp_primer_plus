#include <iostream>
#include <exception>
using namespace std;
/*
��״̬�� ���� 1  ��� 0
	�����򷵻� 1
	eofbit
	badbit
	failbit

	eof
	bad
	fail
	rastate  ������״̬
	exceptions
	clear
	setstate
*/

#if 0

int main()
{
	cin.exceptions(ios_base::failbit);
	cout << "��������: ";
	int input;
	int sum = 0;
	
	try
	{
		while (cin >> input)
		{
			sum += input;
		}
	}
	catch (ios_base::failure& bf)
	{
		cout << bf.what() << endl;
		cout << "O! the horror!\n";
	}
	/*
	����������  ��������һ�������޷�����
	*/
	
	/*cout << "����: ";
	cin >> a;
	cout << a << endl;*/
	int a;
	cin.clear();		//����������״̬Ϊ����
	while (!isspace(cin.get()))
		;
	cin >> a;

	cout << "�������һ������: " << input << endl;
	cout << "Sum= " << sum << endl;
	return 0;
}

#elif 1

/*
>>					//�����հ�
cin.get(char*)		//�����հ�
cin.get()			//�����հ�
*/

#endif // 1
