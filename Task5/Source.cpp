#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>


using namespace std;
// 
int main() {
	random_device rd{};
	mt19937 gen{ rd() };
	// Нормально распределение попадания
	normal_distribution<double> d( 0 );
	// Нормально респределение с параметром 1 и сигма 2
	normal_distribution<double> s{ 1, 2 };
	double k = 0;
	uniform_real_distribution<double> dis(0, 360);
	for (int i = 0; i < 1000; i++) {
		// Точка попадания
		double x = d(gen);
		double y = d(gen);
		
		// Отклонение
		x += s(gen);
		if (x * x + y * y < 9) {
			k++;
		}
	}
	
	cout << "Result: " << k / 1000;
}