#include <iostream>
#include <vector>
#include <valarray>
#include <array>
#include <algorithm>
#include <ranges>
#include <functional>
#include <initializer_list>

/*
这三种有什么区别?
	vector： (STL)
		面向容器的操作 
	valarray:
		面向数值计算
	array：  (STL)
		替代内置数组
*/


#if 0

/*

三种方法的简单示例
*/
void show(double& x)
{
	std::cout << x << " ";
}
int main()
{
	using namespace std;
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	vector<double> ve1(10), ve2(10), ve3(10);
	array<double, 10> a1, a2, a3; 
	valarray<double> va1(x,sizeof(x)/sizeof(x[0])), va2(10), va3(10);
	
	/*
	三种方式的赋值
	*/
	copy(x, x + 10, ve1.begin());
	copy(x, x + 10, a2.begin());
	//声明时即初始化

	/*
	三种方式的显式
	*/
	// vector :
	ostream_iterator<double, char> out(cout, " ");
	copy(ve1.begin(), ve1.end(), out);
	cout << endl;
	// array :
	copy(a1.begin(), a1.end(), out);

	/*
	前两个对象的值相加到第三个
	*/
	// 对于STL 类的 :  都可以
	transform(ve1.begin(), ve1.end(), ve2.begin(), ve3, plus<double>());
	transform(ve1.begin(), ve1.end(), ve2.begin(), ve3, plus<double>());
	// 对于valarray类 :
	va3 = va1 + va2;	//直接相加


	/*
	值扩大2.5倍 :
	*/
	//STL方法： 
	transform(ve1.begin(), ve1.end(), ve1.begin(), bind1st(multiplies<double>(), 2.5));
	//valarray: 
	va1 = 2.5 * va1;

	/*
	计算对数:
	*/
	//transform(ve1.begin(), ve1.end(),ve3.begin(),log);
	va1 = log(va2);
	va1 = va1.apply(log);

	/*
	C++11接受valarray对象的begin和end  不过是作为友元函数实现的
	应该这样使用 ： begin(va1),end(va1)
	*/
	return 0;
}
#elif 0
/*
vector 和  valarray 的比较
*/

int main()
{
	using namespace std;
	vector<double>data;
	double temp;

	cout << "请输入数字: <负数或者零退出>: \n";
	while (cin >> temp && temp > 0)
	{
		data.push_back(temp);
	}
	//元素排序
	sort(data.begin(), data.end());

	int size = data.size();
	valarray<double> numbers(size);
	for (int i = 0; i < size; i++)
	{
		numbers[i] = data[i];
	}

	//直接计算
	valarray<double> sq_rts(size);
	sq_rts = sqrt(numbers);			
	valarray<double> result(size);
	result = numbers + 2.0 * sq_rts;

	cout.setf(ios_base::fixed);
	cout.precision(5);
	/*
	打印
	*/
	//可以直接for循环打印
	cout << "vector data: \n";
	copy(data.begin(), data.end(), ostream_iterator<double, char>(cout, " "));
	cout << endl;
	cout << "valarray numbers: \n";
	copy(begin(result),end(result), ostream_iterator<double, char>(cout, " "));
	cout << "\nDone!" << endl;
	return 0;
}
#elif 0

/*
数组索引slice
*/

const int SIZE = 10;
int main()
{
	using namespace std;
	valarray<int> a(SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		a[i] = i;
	}
	valarray<int> b(a[slice(0, 6, 1)]);
	for (int i = 0; i < 6; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}

#elif 1
/*
模板 initializer_list  初始化列表将STL容器初始化为一系列的值
*/
double sum(std::initializer_list<double> il);
double average(const std::initializer_list<double>& ril);
int main()
{
	using std::cout;

	cout << "List 1: sum= " << sum({ 2,3,4 }) << ",ave= " << average({ 2,3,4 }) << '\n';
	std::initializer_list<double> d1{ 1.1,2.2,3.3,4.4,5.5,6.6 };
	cout << "List 2: sum= " << sum(d1) << ",ave= " << average(d1) << '\n';
	d1 = { 9.9,6.6,9.9,8.8,2.2,3.3 };
	cout << "List 3: sum= " << sum(d1) << ",ave= " << average(d1) << '\n';

	return 0;
}

double sum(std::initializer_list<double> il)
{
	double tot = 0;
	for (auto p = il.begin(); p != il.end(); p++)
	{
		tot += *p;
	}
	return tot;
}

double average(const std::initializer_list<double>& ril)
{
	double tot = 0;
	int n = ril.size();
	double ave = 0;
	if (n > 0)
	{
		for (auto p = ril.begin(); p != ril.end(); p++)
		{
			tot += *p;
		}
		ave = tot / n;
	}
	return ave;
}



#endif