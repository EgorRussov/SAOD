#include <iostream>
#include "Str.h"
int main()
{
    Str s = "hello";
    s += " world!";
    s += " lo";
    std::cout <<s.find("lo", 1) <<" "<< s.find("", 0)<< " " << s.find("o", 11) << std::endl;
}

