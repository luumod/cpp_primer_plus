#include "point.h"

int clever_ptr::operator*()
{		
	return *n;
}

int clever_ptr::operator[](int i)
{
	return n[i];
}



std::ostream& operator<<(std::ostream& os, clever_ptr& n)
{
	os << &n;
	return os;
}
