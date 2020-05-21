#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <vector>
#include <random>

using namespace std;

// Разность между событиями в пуассоновском потоке - экспотенциальные величины
// lambda1 = 0.2
// lambda2 = 0.4

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
	vector<int> first;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] % 2 == 0) {
			first.push_back(a[i]);
		}
	}
	map<int, int> m;
	vector<int> r;
	for (int i = 0; i < first.size() - 1; i++) {
		r.push_back(first[i + 1] - first[i]);
		m[first[i + 1] - first[i]]++;
	}
	for (auto i : m) {
		cout << i.first << ' ' << i.second << endl;
	}
	
	
}