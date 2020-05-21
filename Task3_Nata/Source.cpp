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
    std::uniform_real_distribution<> dis(0, 20);


    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (abs(dis(gen) - dis(gen)) <= 10) {
            count++;
        }
    }
    printf("Probability: %.4f%", (double)count / 1000);
}