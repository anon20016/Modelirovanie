#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <vector>
#include <random>

using namespace std;

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    // Инициализация генераторов
    std::normal_distribution<> dx(0, 30);
    std::normal_distribution<> dy(0, 60);

    vector<double> r(7);
    for (int i = 0; i < 1000; i++) {
        int k = 0;
        for (int j = 0; j < 6; j++) {
            double x = dx(gen);
            double y = dy(gen);
            // Проверка попадания снаряда в цель
            if (abs(x) <= 30 && abs(y) <= 75) {
                k++;
            }
        }
        r[k]++;
    }

    // Подсчет матожидания по формуле
    double m = 0;
    for (int i = 0; i < 7; i++) {
        m += i * r[i] / 1000;
    }
   
    printf("M = %.3f\n", m);

}