

#include "point.h"
using std::cout;
using std::endl;
#include <memory>

#if 0
int main()
{
	int* q = new int[5];
	clever_ptr p = new int[5]{ 11,22,33,44,55 };
	clever_ptr n(new int(99));

	std::cout << n<<endl ;
	std::cout << *n <<endl;
	

	for (int i = 0; i < 5; i++)
	{
		cout << p[i] << endl;
	}

	return 0;
}
#endif 