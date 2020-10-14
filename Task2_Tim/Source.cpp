#include <iostream>

using namespace  std;

const double l = 1;
const double m = 0.01;

double fx(double x, double y) {
	return y;
}
double fy(double x, double y, double k, double b, double t) {
	return -k * y - x * x * x + b * cos(t);
}


void calc(double x, double y, double k, double b, double time = 5) {
	double dt = 0.01;
	double cur = 0;
	while (cur < time) {
		x += dt * fx(x, y);
		y += dt * fy(x, y, k, b, cur);
		printf("%.3f %.3f\n", x, y);
		cur += dt;
	}
}

int main() {
	//calc(-1, 10, 0.1, 10, 100);
	calc(-1, 10, 0.1, 13.4, 100);
}