#include <iostream>
#include "作业.hpp"

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
        //登录成功
           std::cout << "登陆成功! 欢迎你 " << userName << std::endl;
    }
    else
    {
        //打印用户名和密码错误   
        std::cout <<userName<<": 未查询到此用户! 密码错误" << std::endl;
    }
    return 0;
}