#include <iostream>
#include "��ҵ.hpp"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    char userName[20];
    char passWord[7];
    Input(userName, passWord);
    cout << endl;
    if (Login(userName, passWord) == 1)
    {
        //��¼�ɹ�
           std::cout << "��½�ɹ�! ��ӭ�� " << userName << std::endl;
    }
    else
    {
        //��ӡ�û������������   
        std::cout <<userName<<": δ��ѯ�����û�! �������" << std::endl;
    }
    return 0;
}