//��C++ �Ӻ����ķ�ʽʵ��ģ���¼ 
// _getch() ����
//
//�Լ���ͷ�ļ�
#include <conio.h>
const int SIZE = 12;
void Input(char* userName, char* passWord)
{
	char str;
	int i = 0;
	std::cout << "-------��¼ϵͳ-------" << std::endl;
	std::cout << "�������û���: " << " ";
	std::cin >> userName;
	std::cout << "����������: " << " ";
	while (i <= SIZE)
	{
		str = _getch();
		if (str == '\r')
		{
			break;				//�س�ȷ������
		}
		passWord[i++] = str;
		_putch('*');			//���벻�ɼ�
	}
	passWord[i] = '\0';
	//��¼ʵ�����벻�ɼ��� ��������ʱ��Ҫ���ɼ� _getch ���ַ����ַ���
}
int  Login(char* username, char* passWord, const char* root = "1173012900", const char* pass = "12345")
{
	if (!strcmp(username, root))
	{
		std::cout << root<<" ���ڵ�¼..." << std::endl;
		_sleep(2000);
		if (!strcmp(passWord, pass))
		{
			return 1;
		}
	}
	return 0;
	//�Ƚ���֤    
}