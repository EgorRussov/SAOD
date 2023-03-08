#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
public:
	double Re, Im;
	Complex(double re = 0, double im=0) {
		Re = re;
		Im = im;
	}
	Complex operator +(const Complex& c)const
	{
		return Complex(Re + c.Re, Im + c.Im);
	}
	Complex operator -(const Complex& c)const
	{
		return Complex(Re - c.Re, Im - c.Im);
	}
	Complex operator *(const Complex& c)const
	{
		return Complex(Re * c.Re - Im * c.Im, Re * c.Im + c.Re * Im);
	}
	Complex operator /(const Complex& c)const
	{
		return Complex((Re * c.Re + Im * c.Im)/(c.Re*c.Re + c.Im*c.Im), (c.Re * Im - Re * c.Im)/(c.Re * c.Re + c.Im * c.Im));
	}
	Complex Conjugate() {
		return Complex(Re, -Im);
	}
	double Mod() {
		return double(sqrt(pow(Re,2) + pow(Im, 2)));
	}
	double Arg() {
		if (Mod() == 0) return 0;
		if (Re > 0) return atan(Im / Re);
		if (Re < 0) {
			if (Im >= 0) return acos(-1) + atan(Im / Re);
			else return -acos(-1) + atan(Im / Re);
		}
		else {
			if (Im > 0) return acos(0);
			if (Im < 0) return -acos(0);
		}
	}
};
inline ostream& operator << (ostream& o, const Complex& c)
{
	return o << '(' << c.Re << ", " << c.Im << ')';
}


