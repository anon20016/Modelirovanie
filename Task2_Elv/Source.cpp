#include <iostream>

using namespace  std;

const double l = 1;
const double m = 0.01;

double fx(double x, double y, double a, double b, double dt) {
	return y;
}
double fy(double x, double y, double a, double b, double dt) {
	return -a * y + 0.5 * x * (1 - x * x) + b * cos(0.8 * dt);
}


void calc(double x, double y, double a, double b, double time = 5) {
	double dt = 0.001;
	double cur = 0;
	while (cur < time) {
		x += dt * fx(x, y, a, b, cur);
		y += dt * fy(x, y, a, b, cur);
		printf("%.3f %.3f\n", x, y);
		cur += dt;
	}
}

int main() {
	//calc(-10, 10, 0.15, 0.1);
	//calc(-10, 10, 0.15, 0.2);

	calc(-1, 10, 0.15, 0.3);



}