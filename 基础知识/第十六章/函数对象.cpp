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
��������
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

	cout << "��list: \n";
	for_each(ya.begin(), ya.end(), outint);
	cout << endl;
	for_each(es.begin(), es.end(), outint);
	cout << endl;

	ya.remove_if(f100);					//��������
	es.remove_if(TooBig<int>(200));		//��������

	cout << "����list: \n";
	for_each(ya.begin(), ya.end(), outint);
	cout << endl;
	for_each(es.begin(), es.end(), outint);
	cout << endl;

	return 0;
}

#elif 0
/*
Ԥ����ĺ�����
transform : 
	һ:	�ĸ����� 
		ostream_iterator<double,char> out(cout," "); 
		transform(p.begin(),p.end(),out,sqrt);
		1. 2. ָ����������ĵ����� 3.Ŀ�����������  4. һ��Ĭ�ϵĺ����� sqrt(����һ������)
	��: �������
		transform(p.begin(),p.end(),q.begin(),out,mean);
		1.2. 3. ���������������䷶Χ 4.Ŀ�����������  5. mean ������������ ���� ����ƽ��ֵ
#include <functional> ��ʹ�� plus<>�� ����ɳ�����������
*/

/*
����Ӧ�������ͺ���������:
	1. ����Ӧ������
	2. ����ӦһԪ����
	3. ����Ӧ��Ԫ����
	4. ����Ӧν��
	5. ����Ӧ��Ԫν��
��������Ӧ��ԭ��:
	1. ���б�ʾ�������ͺͷ������͵�typedef��Ա 
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
	������ܺ�ţ��  ʹ��ϵͳ�Դ��ĺ�����ֱ����ɶ�Ӧ�Ĳ���
		P711ҳ

		plus : ���
		minus : ���
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
	transform��������������������� ���Ƶ��µ�����
	*/
	vector<double> sum(NUM);	//��������
	transform(gr1.begin(), gr1.end(), gr2.begin(), sum.begin(), plus<double>());
	cout << "Sum: \n";
	for_each(sum.begin(), sum.end(), show);
	cout << endl;

	/*
	transform������һ��������ÿ��Ԫ�س���2.5 ���Ƶ��µ�����
	������Ӧ��Ԫ����ת��Ϊ����ӦһԪ����
	*/
	vector<double> prod(NUM);
	transform(gr1.begin(), gr1.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
	cout << "prod: \n";
	for_each(prod.begin(), prod.end(), show);
	cout << endl;

	/*
	lambda ���ʽ
	*/
	return 0;
}


void show(double v)
{
	std::cout.width(6);
	std::cout << v << " ";
}



#endif