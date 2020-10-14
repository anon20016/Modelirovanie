#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <random>


using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	std::exponential_distribution<> d(0.8);

	// Подсчет идет в минутах. Интенсивность потока 0.8 звонков в минуту.
	double week = 10080;
	double cur = 0;
	vector<int> count(1000);
	while (cur < week){
		double r = d(gen);
		cur += r;
		if (r * 100 >= 1000) {
			continue;
		}
		count[(int)(r * 100)]++;
	}
	// Значения функции распределенения, шаг 0,01 на интервале от 0 до 10.
	for (double i = 0; i < 1000; i++) {
		printf("[%.3f, %.3f] = %d\n", i / 100, (i + 1) / 100, count[i]);
	}

}