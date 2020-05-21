#include <iostream>
#include <set>
#include <time.h>
#include <map>
#include <vector>
#include <random>

using namespace  std;


int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(10, 1);
    std::normal_distribution<> d2(20, 5);
    std::normal_distribution<> d3(5, 1);

    
	int t = 40;
    double count = 0;
    for (int i = 0; i < 1000; i++) {
        if (d1(gen) + d2(gen) + d3(gen) >= t) {
            count++;
        }
    }
    cout << "Student will be late for lessons with a probability of " << (count / 1000) * 100 << "%";
}