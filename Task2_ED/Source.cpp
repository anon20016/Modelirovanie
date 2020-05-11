#include <iostream>

using namespace  std;

const double l = 1;
const double m = 0.01;

double fx(double x, double y) {
	return -y - x * (x * x + y * y - 1);
}
double fy(double x, double y) {
	return x - y * (x * x + y * y - 1);
}


void calc(double x, double y, double time = 5) {
	double dt = 0.01;
	double cur = 0;
	while (cur < time) {
		x += dt * fx(x, y);
		y += dt * fy(x, y);
		printf("%.3f %.3f\n", x, y);
		cur += dt;
	}
}

int main() {
	calc(-3, 3);	
	calc(3, -3);
	calc(-3, -3);
	calc(3, 3);
}