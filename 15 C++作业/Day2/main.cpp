//C++子函数的方式实现二维数组的内存申请和释放
//1.返回值的方式
//2.传参的方式
//3.传参的方式释放内存

#include <iostream>
using std::cout;
using std::endl;

const int ROW = 4;
const int COL = 3;
//1.返回值的方式
int** Return_Value()
{
	int** p = new int* [ROW];		//分配行内存
	for (int i = 0; i < ROW; i++)
	{
		p[i] = new int[COL];		//分配列内存
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			p[i][j] = 1;
		}
	}
	return p;					//返回二维数组
}

//2.传参的方式
int** Transfer_Parameters(int** p)
{
	p = new int* [ROW];		//分配行内存
	for (int i = 0; i < ROW; i++)
	{
		p[i] = new int[COL];		//分配列内存
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			p[i][j] = 2;
		}
	}
	return p;
}

//3.传参的方式释放内存
void Delete(int** p)
{
	for (int j = 0; j < COL; j++)
	{
		delete[]p[j];
	}
	delete[]p;
}

//遍历数组
void Show(int** p)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int** p1 = Return_Value();
	Show(p1);

	cout << endl;
	int** p2 = nullptr;
	p2 = Transfer_Parameters(p2);
	Show(p2);

	Delete(p1);
	Delete(p2);
	return 0;
}