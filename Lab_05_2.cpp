// Lab_05_2

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);

int main()
{
	const double PI = 4 * atan(1.);
	double xp, xk, x, dx, eps, a = 0, R = 0, s = 0;
	int n = 0;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "-----------------------------------------" << endl;
	cout << "|" << setw(6) << "x " << "  |"
		<< setw(10) << "acos(x)" << " |"
		<< setw(7) << "S " << "    |"
		<< setw(5) << "n " << " |"
		<< endl;
	cout << "-----------------------------------------" << endl;

	x = xp;
	while (x <= xk)
	{
		s = S(x, eps, n, s);

		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << acos(x) << " |"
			<< setw(10) << setprecision(5) << PI / 2 - (x + s) << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-----------------------------------------" << endl;

	return 0;
}

double S(const double x, const double eps, int& n, double s)
{
	n = 1;
	double a = (x * x * x) / (2. * 3);
	s = a;
	do
	{
		n++;
		a = A(x, n, a);
		s += a;
	} while (fabs(a) >= eps);
	return s;
}

double A(const double x, const int n, double a)
{
	double R = ((2.0 * n - 1) / (2.0 * n)) * ((2.0 * n - 1) / (2.0 * n + 1)) * pow(x, 2);
	a *= R;
	return a;
}