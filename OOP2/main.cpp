#include "application.h"
#include "Windows.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Complex a(4.0, 6.0), b(2.5, -3.0), c;
	b = a;
	c = a + b;
	cout << a << ' ' << b << ' ' << c;
	
	int d = 0, e = 1, g = 2;
	d += e += g += d;
	cout << d;

	Application app;
	app.run();

	return 0;
}