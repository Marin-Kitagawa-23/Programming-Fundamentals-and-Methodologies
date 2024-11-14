#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

long double func(long double x_f, long double eps_f) {
	long double sum = 0, change = 1;
	long int n = 2;
	do {
		sum += change;
		change = change * x_f * x_f * -1;
		change = change / n / (n + 1);
		n += 2;
	} while (abs(change) > eps_f);
	cout << "�������� ��������� �������: " << left << setw(10) << sum << "\t" << "�������� ��������� ������ C++: " << left << setw(10) << (sin(x_f) / x_f) << endl;
	return 0;
}

int main() {
	long double a, b, h, eps, x, xel;
	setlocale(LC_ALL, "RU");
	cout << "������� ������� ������� a � b ([a, b]):\n";
	cin >> a >> b;
	cout << "������� ��� � ������� ����� ���������� ���������� �\n";
	cin >> h;
	cout << "������� �������� ������� ��� ����������� ��������� ������ ����� �������\n";
	cin >> eps;
	x = a;
	while (a <= x and x <= b) {
		xel = x;
		if (xel > 0) {
			while (xel > acos(-1)) {
				xel -= acos(-1);
			}
		}
		else {
			while (xel < -acos(-1)) {
				xel += acos(-1);
			}
		}
		if (x != 0) {
			func(abs(xel), eps);
			x += h;
		}
		else {
			x += h;
		}
	}
	return 0;
}