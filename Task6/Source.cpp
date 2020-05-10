#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <random>


using namespace std;

// размер бака
const int n = 1000;
// интенсивность потока
const double a = 0.3;

double test() {
	random_device rd;
	mt19937 gen(rd());
	int count = 0;
	double t = 0;
	while (count < 900) {
		double r = generate_canonical<double, 10>(gen);
		double d = -1 / a * log(r);
		t = t + d;
		count++;
	}
	return t;
}

int main() {

	srand(time(nullptr));
	double t = 0;
	double result = 0;
	int q = 1000;
	while (q--) {
		result += 0.001 * test();
	}
	cout << "Result, with lambda = 0.3 and capacity of trash can 1000 - " << result;
}