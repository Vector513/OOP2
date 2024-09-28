#include "complex.h"

Complex::Complex()
{
	this->re = 0;
	this->im = 0;
}

Complex::Complex(double re)
{
	this->re = re;
}

Complex::Complex(double re, double im)
{
	this->re = re;
	this->im = im;
}

Complex::~Complex() {}

double Complex::mod() const
{
	return sqrt(re * re + im * im);
}

double Complex::arg() const
{
	return asin(im / mod());
}

Complex Complex::pow(double exponent) const
{
	return Complex{ std::pow(mod(), exponent) * std::cos(arg() * exponent), std::pow(mod(), exponent) * std::sin(arg() * exponent)};
}

Complex pow(const Complex& base, double exponent) {
	return base.pow(exponent);
}

Complex sqrt(const Complex& base) 
{
	return base.pow(0.5);
}

std::ostream& operator << (std::ostream& output, const Complex& complex)
{
	output << complex.re;

	if (complex.im > 0) {
		output << " + " << complex.im << "i";
	}
	else if (complex.im < 0) {
		output << " - " << complex.im << "i";
	}

	return output;
}

std::istream& operator >> (std::istream& input, Complex& complex) 
{
	input >> complex.re >> complex.im;

	return input;
}

Complex& Complex::operator = (const Complex& other)
{
	if (this != &other) {
		re = other.re;
		im = other.im;
	}
	return *this;
}

Complex Complex::operator + (const Complex& other) const
{
	return Complex{ re + other.re, im + other.im };
}

Complex Complex::operator - (const Complex& other) const
{
	return Complex{ re - other.re, im - other.im };
}

Complex Complex::operator * (const double coef) const
{
	return Complex{ re * coef, im * coef };
}

Complex operator * (double coef, const Complex& other) 
{
	return Complex{ other.re * coef, other.im * coef };
}

Complex Complex::operator * (const Complex& other) const
{
	return Complex{ re * other.re - im * other.im, re * other.im + im * other.re };
}

Complex Complex::operator / (const double coef) const
{
	return Complex{ re / coef, im / coef };
}

Complex Complex::operator / (const Complex& other) const
{
	return Complex{ (re * other.re + im * other.im) / (other.re * other.re + other.im * other.im), (other.re * im - re * other.im) / (other.re * other.re + other.im * other.im) };
}

Complex Complex::operator - () const
{
	return Complex{ -re, -im };
}

Complex& Complex::operator += (const Complex& other) 
{
	re += other.re;
	im += other.im;

	return *this;
}

Complex& Complex::operator -= (const Complex& other)
{
	re -= other.re;
	im -= other.im;

	return *this;
}

Complex& Complex::operator *= (const double coef)
{
	re *= coef;
	im *= coef;

	return *this;
}

Complex& Complex::operator *= (const Complex& other)
{
	re = re * other.re - im * other.im;
	im = re * other.im + im * other.re;

	return *this;
}

Complex& Complex::operator /= (const double coef)
{
	re /= coef;
	im /= coef;

	return *this;
}

Complex& Complex::operator /= (const Complex& other)
{
	re = (re * other.re + im * other.im) / (other.re * other.re + other.im * other.im);
	im = (other.re * im - re * other.im) / (other.re * other.re + other.im * other.im);

	return *this;
}

bool Complex::operator == (const Complex& other) const
{
	return (re == other.re && im == other.im);
}

bool Complex::operator != (const Complex& other) const 
{
	return !(*this == other);
}

bool Complex::operator > (const Complex& other) const 
{
	if (mod() > other.mod()) {
		return true;
	}
	return false;
}

bool Complex::operator >= (const Complex& other) const 
{
	if (mod() > other.mod()) {
		return true;
	}
	else if (mod() == other.mod()) {
		if (arg() >= other.arg()) {
			return true;
		}
	}
	return false;
}

bool Complex::operator < (const Complex& other) const
{
	if (mod() < other.mod()) {
		return true;
	}
	return false;
}

bool Complex::operator <= (const Complex& other) const
{
	if (mod() < other.mod()) {
		return true;
	}
	else if (mod() == other.mod()) {
		if (arg() <= other.arg()) {
			return true;
		}
	}
	return false;
}