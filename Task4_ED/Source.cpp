#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <vector>

using namespace std;

double f(double x) {
	return x * x;
}

int main() {
	srand(time(nullptr));
	int e[6] = { 10, 20, 50, 100, 1000, 10000 };
	for (auto n : e) {
		vector<double> points;
		for (int i = 0; i < n; i++) {
			// ���������� ��������� ����� �� ��������� [0, 1]
			int y = rand() + 1;
			int x = rand() % y + 1;
			// ��������� �������� ������� � ��������� �����
			points.push_back((double)x / y);
		}
		sort(points.begin(), points.end());
		// ������� ������� ��� �������� �������
		double p = 0;
		for (int i = 0; i < points.size() - 1; i++) {
			p += (points[i + 1] - points[i]) * ((f(points[i]) + f(points[i + 1])) / 2);
		}
		cout << "Result for " << n << " attempts is " << p << endl;

	}
}