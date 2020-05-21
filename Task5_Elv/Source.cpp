#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>


using namespace std;

// Генерируем точку в кубе R*R*R и проверяем на принадлежность обоим цилиндрам.
int main() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 2);

	// Радиус цилидра
	double R = 1.0;
	int c = 0;	
	for (int i = 0; i <= 10000; i++) {
		double x = -1.0 + dis(gen);
		double y = -1.0 + dis(gen);
		double z = -1.0 + dis(gen);
		if (x * x + y * y <= R * R) {
			if (y * y + z * z <= R * R) {
				c++;
			}
		}
	}

	cout << "Calculated for R = 1\n";
	printf("Result: %.3f\n", (double)c / 10000 * 8);
	printf("16 * R * R * R / 3 = %.3f\n", (double)16 * R * R * R / 3);

}