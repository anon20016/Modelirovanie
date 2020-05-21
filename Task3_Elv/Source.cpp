#include <iostream>
#include <set>
#include <time.h>
#include <map>
#include <vector>

using namespace  std;

string take(vector<string> &a) {
	int t = rand() % a.size();
	string p = a[t];
	a.erase(a.begin() + t);
	return p;
}

int main() {
	srand(time(nullptr));

	int N = 1000;
	int ok = 0;
	while (N--) {
		vector<string> a = { "white", "white", "white", "blue", "blue", "blue", "red", "red", "red" };

		if (take(a) == "white" && take(a) == "blue" && take(a) == "red") {
			ok++;
		}
	}
	cout << "Result: " << (double)ok / 1000;
}