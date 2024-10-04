#include "Array.h"

#include <iostream>

#define line(msg) std::cout << "------------------------" #msg "-------------------------\n";

int main()
{
    Array obArr;

    int k = obArr[0][1]; // read
    line();
    obArr[0][1] = 999; // write
    line();
    obArr[1][0] = obArr[0][1]; // read/write

    std::cout << obArr << "k = " << k << '\n';

    return 0;
}
