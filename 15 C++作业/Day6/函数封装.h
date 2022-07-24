

#ifndef FUNC_H_
#define FUNC_H_
#include <iostream>

class func
{
	using PF = void (*)();
private:
	PF pf;
public:
	func(PF pf_fun_) :pf(pf_fun_) {}

	void operator()()
	{
		pf();
		
	}
};

void Text()
{
	std::cout << "º¯Êýµ÷ÓÃ" << std::endl;
}

#endif