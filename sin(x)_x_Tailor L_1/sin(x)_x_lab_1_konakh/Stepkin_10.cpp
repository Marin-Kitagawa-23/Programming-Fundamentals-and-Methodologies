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
	cout << "«гачение напианной фунцкии: " << left << setw(10) << sum << "\t" << "«начение встроеной фунции C++: " << left << setw(10) << (sin(x_f) / x_f) << endl;
	return 0;
}

int main() {
	long double a, b, h, eps, x, xel;
	setlocale(LC_ALL, "RU");
	cout << "¬ведите границы отрезка a и b ([a, b]):\n";
	cin >> a >> b;
	cout << "¬ведите шаг с которым будет измен€тьс€ переменна€ х\n";
	cin >> h;
	cout << "¬ведите значение эпсилон дл€ ограничени€ количеств знаков после зап€той\n";
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