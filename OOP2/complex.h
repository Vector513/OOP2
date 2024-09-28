#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

class Complex
{
private:
	double re = 0;
	double im = 0;
public:
	Complex();
	Complex(double re);
	Complex(double re, double im);
	~Complex();
	double mod() const;
	double arg() const;
	Complex pow(double exponent) const;
	friend Complex pow(const Complex& base, double exponent);
	friend Complex sqrt(const Complex& base);
	friend std::ostream& operator<<(std::ostream& output, const Complex& complex);
	friend std::istream& operator >> (std::istream& input, Complex& complex);
	//friend Complex sqrt(const C);
	Complex& operator = (const Complex& other);
	Complex operator + (const Complex& other) const;
	Complex operator - () const;
	Complex operator - (const Complex& other) const;
	Complex operator * (const double coef) const;
	friend Complex operator * (double coef, const Complex& other);
	Complex operator * (const Complex& other) const;
	Complex operator / (const double coef) const;
	Complex operator / (const Complex& other) const;
	Complex& operator += (const Complex& other);
	Complex& operator -= (const Complex& other);
	Complex& operator *= (const double coef);
	Complex& operator *= (const Complex& other);
	Complex& operator /= (const double coef);
	Complex& operator /= (const Complex& other);
	bool operator == (const Complex& other) const;
	bool operator != (const Complex& other) const;
	bool operator > (const Complex& other) const;
	bool operator >= (const Complex& other) const;
	bool operator < (const Complex& other) const;
	bool operator <= (const Complex & other) const;
};