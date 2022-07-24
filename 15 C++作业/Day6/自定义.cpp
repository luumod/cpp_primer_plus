#include "自定义.h"

于良浩::于良浩(const 于良浩& n)
{
    this->num = n.num;
}

void 于良浩::print() const
{
    std::cout << num << std::endl;
}

于良浩 于良浩::operator+(const 于良浩& n)
{
    this->num += n.num;
    return *this;
}

于良浩 于良浩::operator-(const 于良浩& n)
{
    return 于良浩(num - n.num);
}

于良浩 于良浩::operator*(const 于良浩& n)
{
    return 于良浩(num * n.num);
}

于良浩 于良浩::operator/(const 于良浩& n)
{
    return 于良浩(num / n.num);
}

于良浩 于良浩::operator=(const 于良浩& n)
{
    this->num = n.num;
    return *this;
}

于良浩 于良浩::operator+=(const 于良浩& n)
{
    this->num += n.num;
    return *this;
}

于良浩 于良浩::operator-=(const 于良浩& n)
{
    this->num -= n.num;
    return *this;
}

于良浩 于良浩::operator*=(const 于良浩& n)
{
    this->num *= n.num;
    return *this;
}

于良浩 于良浩::operator/=(const 于良浩& n)
{
    this->num /= n.num;
    return *this;
}

于良浩 operator+(int i, const 于良浩& n)
{
    return 于良浩(i + n.num);
}

于良浩 operator-(int i, const 于良浩& n)
{
    return 于良浩(i - n.num);
}

于良浩 operator*(int i, const 于良浩& n)
{
    return 于良浩(i * n.num);
}

于良浩 operator/(int i, const 于良浩& n)
{
    return 于良浩(i / n.num);
}
