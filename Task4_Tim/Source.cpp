#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <vector>
#include <random>

using namespace std;
//
// 0 0 5
// 0 7 6
//
bool ispointincircle(double x, double y, double xc, double yc, double r) {
    // ������� ��������� ����������� �� ����� ����������
    return (x - xc) * (x - xc) + (y - yc) * (y - yc) <= r * r;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    // � ���� ������ �� ���� ������� ���������� � ���� �����������
    // x1 y1 r1
    // x2 y2 r2
    // ������� ������������� � ������� ���������� ��� ���������� ���, ��� ��� �������� ������ ��������������.
    // ������� �����-����� ��������� ������� �����������.
    double x1, x2, y1, y2, r1, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    double xmin = min(x1 - r1, x2 - r2);
    double xmax = max(x1 + r1, x2 + r1);

    // ��������� ���������� ����� ��������������.
    double ymin = min(y1 - r2, y2 - r2);
    double ymax = max(y1 + r2, y2 + r2);
    
    // ���������� ��� ������ ��������� ����� ������ ��������������
    std::uniform_real_distribution<> d1(xmin, xmax);
    std::uniform_real_distribution<> d2(ymin, ymax);

    // ���������� ������������
    double s = 0;
    vector<double> r;
    for (int i = 0; i < 10000; i++) {
        double x = d1(gen);
        double y = d2(gen);
        if (ispointincircle(x, y, x1, y1, r1) and ispointincircle(x, y, x2, y2, r2)) {
            s++;
        }
    }
    cout << "Square: " << ((xmax - xmin) * (ymax - ymin)) * s / 10000;
    

}