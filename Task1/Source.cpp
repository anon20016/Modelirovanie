#include <iostream>

using namespace  std;

const double n = 1.4;
const double o = 20;
const double mk = 0.13;
const double ms = 0.01;
const double tk = 90;
const double ts = 20;
const double l = 0.03;
const double s = 0.02;
const double c = 4180;

double f(double x, double m) {
	return -n * s * (x - o) / (l * c * m);
}

double calc(double m, double t, double time = 600) {
	double dt = 0.001;
	double cur = 0;
	while (cur < time) {
		double func = f(t, m);
		t += dt * func;
		cur += dt;
	}
	return t;
}

double tmix(double m1, double m2, double t1, double t2) {
	if (t1 < t2) {
		swap(t1, t2);
		swap(m1, m2);
	}
	return (m1 * t1 + m2 * t2) / (m1 + m2);
}

int main() {
	double tA = calc(mk + ms, tmix(mk, ms, tk, ts));
	double tV = tmix(mk, ms, calc(mk, tk), ts);

	cout << "Anatolyi: " << tA << endl << "Vladimir: " << tV;
}