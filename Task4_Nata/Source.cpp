#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <vector>
#include <random>

using namespace std;

// Решение задачи с параметрами:
// (5, 2)
// (7, 3)
// (8, 5)

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(5, 2);
    std::normal_distribution<> d2(7, 3);
    std::normal_distribution<> d3(8, 5);

    double s = 0;
    vector<double> r;
    for (int i = 0; i < 1000; i++) {
        vector<double> a;
        a.push_back(d1(gen));
        a.push_back(d2(gen));
        a.push_back(d3(gen));
        sort(a.begin(), a.end());
        s += a[1];
        r.push_back(a[1]);
    }
    double m = s / 1000;
    double d = 0;
    for (int i = 0; i < r.size(); i++) {
        d += (r[i] - m) * (r[i] - m);
    }
    printf("M = %.3f\n", m);
    printf("d = %.3f\n", d / 1000);

}