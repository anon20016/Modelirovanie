#include <iostream>
#include <set>
#include <time.h>
#include <map>

using namespace  std;

int test() {
	set<int> a;
	int c = 0;
	while (a.size() < 9) {
		a.insert(rand() % 9);
		c++;
	}
	return c;
}

int main() {
	srand(time(nullptr));
	map<double, double> a;
	for (int i = 0; i < 1000; i++) {
		a[test()] += 1;
	}
	double result = 0;
	for (auto i : a) {
		result += i.first * (i.second / 1000.0);
	}
	cout << "result: " << result;
}