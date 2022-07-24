#include "�Զ���.h"

������::������(const ������& n)
{
    this->num = n.num;
}

void ������::print() const
{
    std::cout << num << std::endl;
}

������ ������::operator+(const ������& n)
{
    this->num += n.num;
    return *this;
}

������ ������::operator-(const ������& n)
{
    return ������(num - n.num);
}

������ ������::operator*(const ������& n)
{
    return ������(num * n.num);
}

������ ������::operator/(const ������& n)
{
    return ������(num / n.num);
}

������ ������::operator=(const ������& n)
{
    this->num = n.num;
    return *this;
}

������ ������::operator+=(const ������& n)
{
    this->num += n.num;
    return *this;
}

������ ������::operator-=(const ������& n)
{
    this->num -= n.num;
    return *this;
}

������ ������::operator*=(const ������& n)
{
    this->num *= n.num;
    return *this;
}

������ ������::operator/=(const ������& n)
{
    this->num /= n.num;
    return *this;
}

������ operator+(int i, const ������& n)
{
    return ������(i + n.num);
}

������ operator-(int i, const ������& n)
{
    return ������(i - n.num);
}

������ operator*(int i, const ������& n)
{
    return ������(i * n.num);
}

������ operator/(int i, const ������& n)
{
    return ������(i / n.num);
}
