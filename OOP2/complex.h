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
	friend ostream& operator<<(ostream& output, const Complex& complex);
	friend istream& operator >> (istream& input, Complex& complex);
	Complex& operator = (const Complex& other);
	Complex operator + (const Complex& other) const;
	Complex operator - (const Complex& other) const;
	Complex operator * (const double coef) const;
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
};