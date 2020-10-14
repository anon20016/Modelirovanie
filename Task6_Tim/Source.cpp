#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <random>


using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	std::exponential_distribution<> d(0.8);

	// ������� ���� � �������. ������������� ������ 0.8 ������� � ������.
	double week = 10080;
	double cur = 0;
	vector<int> count(1000);
	while (cur < week){
		double r = d(gen);
		cur += r;
		if (r * 100 >= 1000) {
			continue;
		}
		count[(int)(r * 100)]++;
	}
	// �������� ������� ���������������, ��� 0,01 �� ��������� �� 0 �� 10.
	for (double i = 0; i < 1000; i++) {
		printf("[%.3f, %.3f] = %d\n", i / 100, (i + 1) / 100, count[i]);
	}

}