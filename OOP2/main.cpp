#include "application.h"
#include "Windows.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Complex a(4.0, 6.0), b(2.5, -3.0), c, d(4, 5.8);
	b = a;
	c = a + b;
	double h = 8.3;
	c = c * h;
	cout << a << ' ' << b << ' ' << c << (d < a) << (d > a) << (a >= a) << (b > b);

	Application app;
	app.run();

	return 0;
}