#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <vector>
#include <random>

using namespace std;

// Разность между событиями в пуассоновском потоке - экспотенциальные величины
// lambda1 = 0.1
// lambda2 = 0.3

int main() {
	random_device rd;
	mt19937 gen(rd());
	exponential_distribution<> d1(0.1);
	exponential_distribution<> d2(0.3);

	vector<int> a;
	int c1 = 0;
	int c2 = 0;

	for (int i = 0; i < 100; i++) {
		a.push_back(c1 += d1(gen));
		a.push_back(c2 += d2(gen));
	}
	sort(a.begin(), a.end());
	map<int, int> m;
	for (int i = 0; i < a.size() - 1; i++) {
		m[a[i + 1] - a[i]]++;
	}
	for (auto i : m) {
		cout << i.first << '\t' << endl;
	}
	cout << endl;
	for (auto i : m) {
		cout << i.second << '\t' << endl;
	}
}