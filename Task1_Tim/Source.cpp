#include <iostream>

using namespace  std;

double f(double x, double a, double b) {
	return a * x - b * x * x;
}

double calc(double a, double b, double t, double time = 1) {
	double dt = 0.001;
	double cur = 0;
	while (cur < time) {
		double func = f(t, a, b);
		t += dt * func;
		cout << cur << " " << t << endl;
		cur += dt;
	}
	return t;
}

int main() {
	double a = 5;
	double b = 3;

	// First and second case
	//double x0 = a / b - 1;	//	x0 < a/b
	double x0 = a / b + 3;      //  x0 > a/b
	calc(a, b, x0);
}