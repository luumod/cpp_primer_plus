#include <iostream>
#include <string>
#include <functional>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <ranges>
#include <iterator>
#include <algorithm>

/*
函数符：
*/
#if 0
template <class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T& t) :cutoff(t) {}
	bool operator()(const T& v)
	{
		return v > cutoff;
	}
};
void outint(int n)
{
	std::cout << n << " ";
}
int main()
{
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100);
	int vals[10] = { 50,60,70,80,90,100,110,120,130,140 };

	list<int> ya(vals, vals + 10);
	list<int> es(vals, vals + 10);

	cout << "旧list: \n";
	for_each(ya.begin(), ya.end(), outint);
	cout << endl;
	for_each(es.begin(), es.end(), outint);
	cout << endl;

	ya.remove_if(f100);					//声明对象
	es.remove_if(TooBig<int>(200));		//匿名对象

	cout << "最终list: \n";
	for_each(ya.begin(), ya.end(), outint);
	cout << endl;
	for_each(es.begin(), es.end(), outint);
	cout << endl;

	return 0;
}

#elif 0
/*
预定义的函数符
transform : 
	一:	四个参数 
		ostream_iterator<double,char> out(cout," "); 
		transform(p.begin(),p.end(),out,sqrt);
		1. 2. 指定容器区间的迭代器 3.目标输出迭代器  4. 一个默认的函数符 sqrt(接受一个参数)
	二: 五个参数
		transform(p.begin(),p.end(),q.begin(),out,mean);
		1.2. 3. 两个迭代器的区间范围 4.目标输出迭代器  5. mean 接受两个参数 返回 两数平均值
#include <functional> 中使用 plus<>类 来完成常规的相加运算
*/

/*
自适应函数符和函数适配器:
	1. 自适应生成器
	2. 自适应一元函数
	3. 自适应二元函数
	4. 自适应谓词
	5. 自适应二元谓词
函数自适应的原因:
	1. 具有表示参数类型和返回类型的typedef成员 
		result_type 
		first_argument_type 
		second_argument_type
*/
const int NUM = 5;
void show(double& x)
{
	std::cout << x << " ";
}
int main()
{
	using std::vector;
	using std::cout;
	using std::ostream_iterator;

	double a[NUM] = { 1,2,3,4,5 };
	double b[NUM] = { 1,4,7,2,5 };

	vector<double> val1(NUM);
	vector<double> val2(b, b + NUM);

	copy(a, a + NUM, val1.begin());
	
	for_each(val1.begin(), val1.end(), show);
	cout << '\n';
	for_each(val2.begin(), val2.end(), show);
	cout << '\n';

	/*
	这个功能很牛逼  使用系统自带的函数符直接完成对应的操作
		P711页

		plus : 相加
		minus : 相减
		......
	*/
	ostream_iterator<double, char> out(cout, " ");
	std::plus<double> add;
	std::minus<double> mlu;
	double y = add(1, 2);
	cout << y << '\n';
	std::transform(val1.begin(), val1.end(),val2.begin(), out, std::plus<double>());
	cout << '\n';
	std::transform(val1.begin(), val1.end(), val2.begin(), out, std::minus<double>());
	//	std::transform(val1.begin(), val1.end(),val2.begin(), out, add);

	return 0;
}
#elif 0
void show(double);
const int NUM = 6;
int main()
{
	using namespace std;

	double arr1[NUM] = { 1,2,3,4,5,6 };
	double arr2[NUM] = { 7,8,9,4,5,6 };

	vector<double> gr1(arr1, arr1 + NUM);
	vector<double> gr2(arr2, arr2 + NUM);

	cout.setf(ios_base::fixed);
	cout.precision(1);

	cout << "gr1: \n";
	for_each(gr1.begin(), gr1.end(), show);
	cout << endl;
	cout << "gr2: \n";
	for_each(gr2.begin(), gr2.end(), show);
	cout << endl;

	/*
	transform函数的两个迭代器的相加 复制到新迭代器
	*/
	vector<double> sum(NUM);	//数组容器
	transform(gr1.begin(), gr1.end(), gr2.begin(), sum.begin(), plus<double>());
	cout << "Sum: \n";
	for_each(sum.begin(), sum.end(), show);
	cout << endl;

	/*
	transform函数的一个迭代器每个元素乘以2.5 复制到新迭代器
	将自适应二元函数转换为自适应一元函数
	*/
	vector<double> prod(NUM);
	transform(gr1.begin(), gr1.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
	cout << "prod: \n";
	for_each(prod.begin(), prod.end(), show);
	cout << endl;

	/*
	lambda 表达式
	*/
	return 0;
}


void show(double v)
{
	std::cout.width(6);
	std::cout << v << " ";
}



#endif