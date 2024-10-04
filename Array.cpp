#include "Array.h"

std::ostream &operator<<(std::ostream &os, const Array &rhs)
{
    os << "array =\t[";
    for (int i = 0; i < 2; i++)
    {
        os << (i ? "\t [" : "[");
        for (int j = 0; j < 3; j++)
        {
            os << rhs.arr[i][j] << (j < 2 ? ", " : "");
        }
        os << (i < 1 ? "],\n" : "]");
    }
    os << "]\n";

    return os;
}

Array::Helper::InnerHelper::operator int()
{
    std::cout << "read\n";
    return hlp->ptr->arr[hlp->index_1][index_2];
}

Array::Helper::InnerHelper &Array::Helper::InnerHelper::operator=(int val)
{
    std::cout << "write\n";
    hlp->ptr->arr[hlp->index_1][index_2] = val;
    return *this;
}

Array::Helper::InnerHelper &Array::Helper::InnerHelper::operator=(const InnerHelper &par)
{
    std::cout << "read\n";
    std::cout << "write\n";
    hlp->ptr->arr[hlp->index_1][index_2] = par.hlp->ptr->arr[par.hlp->index_1][par.index_2];
    return *this;
}
