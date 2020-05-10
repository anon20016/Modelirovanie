#include <iostream>

using namespace  std;

double fx(double x) {
	return -x;
}
double fy(double y) {
	return y;
}

void calc(double x, double y, double time = 5) {
	double dt = 0.01;
	double cur = 0;
	while (cur < time) {
		x += dt * fx(x);
		y += dt * fy(y);
		printf("%.3f %.3f\n", x, y);
		cur += dt;
	}
}

int main() {
	calc(-100, 100);
	calc(100, -100);
	calc(-100, -100);
	calc(100, 100);
}