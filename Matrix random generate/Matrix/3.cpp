#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, ".1251");
	int **matrix;
	const int n_max = 10;
	int n, m;
	cin >> n >> m;
	matrix = new int* [n] {};
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m] {};
	}
	int start, end, sum_1 = 0;
	cin >> start >> end;
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < m; j++) {
			matrix[i][j] = rand() % (end - start) + start;
			cout << setw(5) << matrix[i][j];
			if (i == j) {
				sum_1 += matrix[i][j];
			}
		}
	}
	int sum = 0;
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			sum = sum + matrix[i][j];
		}
	}
	cout << "sum = " << sum << endl;
	cout << endl;
	cout << sum_1;
	return 0;
}