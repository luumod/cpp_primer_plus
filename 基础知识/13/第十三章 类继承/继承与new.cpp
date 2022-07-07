#include <iostream>
#include <conio.h>
#include "继承与动态内存分配.h"


/*
派生类不使用new: 
	默认析构函数 
	默认复制构造函数
	默认赋值运算符
派生类使用new:
	定义显示析构函数: 自动调用基类的析构函数,因此只需管理其自身即可
	定义复制构造函数: 访问自身的数据 并且调用基类的复制构造函数来访问基类的成员: 
*/

int main()
{
	using std::cout;
	using std::endl;

	baseDMA shirt{"于良浩",99};
	lackDMA ballon{ "王吉虎","是帅哥",65};
	hasDMA map{ "蔡联淇","是我妮",33};
	cout << "baseDMA: " << shirt << endl;
	cout << "lackDMA: " << ballon << endl;
	cout << "hasDMA: " << map << endl;
	lackDMA ballon2{ ballon };	//复制构造
	cout << "ballon2: " << ballon2 << endl;
	//赋值运算符
	hasDMA map2;
	map2 = map;
	cout << map2 << endl;

	return 0;
}
/*
当基类和派生类都是用new时,都要使用相对应的基类方法来处理基类元素
析构函数: 
	自动完成
复制构造函数:
	在派生类的构造函数的成员初始化列表中调用基类的复制构造函数
赋值运算符:
	在派生类的赋值运算符里使用作用域解析运算符显式调用基类的赋值运算符
*/



/*
总结：
	1. 默认构造函数: 应该自己设置显示默认构造函数
	2. 复制构造函数: 深度复制
		1. 将新对象初始化为另一个同类对象
		2. 按值将对象传递给函数
		3. 函数按值返回对象
		4. 编译器生成临时对象
	3. 赋值运算符: 对象的初始化和赋值
*/

//接受基类引用参数的函数可以接受派生类


