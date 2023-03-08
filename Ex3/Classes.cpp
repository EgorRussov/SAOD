#include <iostream>
#include "Complex.h"

int main()
{
    Complex a(1,2), b = 3;
    Complex c = a / a;
    Complex d = a.Conjugate();
    std::cout << a << ',' << c << ',' << d << endl;
    Complex v[4]{ 1,2, Complex(2, 3) };
    for( Complex i : v){
        std::cout << i << " ";
    }
    std::cout << endl;
    Complex* pc;
    pc = new Complex;
    pc = new Complex(1);
    pc = new Complex(1,2);
    std::cout << pc;
    Complex* arr = new Complex[3];
    delete pc;
    delete [] arr;

}

