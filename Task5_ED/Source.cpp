#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>


using namespace std;

// Для A и B взято значение 25 в качестве мат ожидания нормального распределения

int main() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::discrete_distribution<> d({ 10, 25, 50, 15 });
	std::normal_distribution<> nd{ 25 };

	vector<double> mas;
	double s = 0;
	for (int i = 0; i < 1000; i++) {
		double c = 10;
		// Генерируем величину C
		switch (d(gen))
		{
		case 1:
			c = 20;
			break;
		case 2:
			c = 30;
			break;
		case 3:
			c = 40;
			break;
		}
		// Герерируем А и B
		double a = nd(gen);
		double b = nd(gen);

		// Сохраняем все величины для подсчета мат ожидения
		mas.push_back((a + b) / c);
		s += (a + b) / c;
	}
	// Подсчет мат ожидания
	double m = s / mas.size();

	// Подсчет дисперсии
	double sd = 0;
	for (int i = 0; i < mas.size(); i++) {
		sd += (m - mas[i]) * (m - mas[i]);
	}

	// Вывод
	cout << "Expected value - " << m << endl;
	cout << "Variance - " << sd / mas.size() << endl;	
}