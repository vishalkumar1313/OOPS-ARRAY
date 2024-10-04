#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array
{
public:
    Array() = default;
    ~Array() noexcept = default;

    class Helper
    {
    public:
        Helper(Array *ptr, int index) : ptr(ptr), index_1(index) {}

        class InnerHelper
        {
        public:
            InnerHelper(Helper *ptr, int index) : hlp(ptr), index_2(index) {}

            operator int();
            InnerHelper &operator=(int val);
            InnerHelper &operator=(const InnerHelper &par);

        private:
            Helper *hlp;
            int index_2;
        };

        InnerHelper operator[](int index) { return {this, index}; }

    private:
        Array *ptr;
        int index_1;
    };

    Helper operator[](int index) { return {this, index}; }
    friend std::ostream &operator<<(std::ostream &os, const Array &rhs);

private:
    int arr[2][3]{{10, 20, 30}, {40, 50, 60}};
};

#endif // ARRAY_H
