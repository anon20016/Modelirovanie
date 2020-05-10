#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>


using namespace std;

int main() {
	srand(time(nullptr));

	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < 1000; i++) {
		int f = rand();
		int s = rand() % f;
		a[(s * 10) / f]++;
	}
	int ok = 1;
	int mx_delta = 0;
	cout << "Result :" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "[" << 0.1 * i << " - " << 0.1 * (i + 1) << "] = " << a[i] << endl;
		mx_delta = max(mx_delta, 100 - a[i]);
	}
	cout << "The maximum difference between 100 and count of numbers in segment is " << mx_delta;
}	