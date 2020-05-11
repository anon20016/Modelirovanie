#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <random>


using namespace std;

// Величина для экспотенциального распределения 1
// Время доступности самолета 1

double test() {
	random_device rd;
	mt19937 gen(rd());
	std::exponential_distribution<> d(1);

	// Вычисление двух независимых экспотенциальных величин, времени для пушек
	double m = min(d(gen), d(gen));
	if (m > 1) {
		return -1;
	}
	else {
		return m;
	}
}

int main() {
	double s = 0;
	int k = 0;
	for (int i = 0; i < 1000; i++) {
		double r = test();
		if (r == -1) {
			k++;
		}
		else {
			s += r;
		}
	}
	cout << "Parametrs: lambda = 1, time of airplane 1" << endl;
	cout << "Everage time = " << s / 1000 << endl << "didn't shot down " << k << " times.";
	
}