#include <iostream>
using namespace std;
int a = 10;

int a1=10;
int a2=20;
static int a3=30;

void local(void)
{
	cout << "&a1= " << &a1 << " " << "&a2= " << &a2 << " " << "&a3= " << &a3 << endl;
}