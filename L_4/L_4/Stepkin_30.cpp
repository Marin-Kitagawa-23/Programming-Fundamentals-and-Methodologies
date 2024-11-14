#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int max_up_r(int** a, int l) {
	int max_el = a[0][0];
	for (int i = 0; i < l; i++) {
		for (int j = i; j < l; j++) {
			if (a[i][j] > max_el) {
				max_el = a[i][j];
			}
		}
	}
	return max_el;
}

void sortirovka(int** a, int l) {
	for (int i = 0; i < l; i++) {
		if (i % 2 != 0) {
			for (int j = 0; j < l; j++) {
				for (int k = 0; k < l - 1; k++) {
					if (a[i][k] > a[i][k + 1]) {
						int b = a[i][k]; // создали дополнительную переменную
						a[i][k] = a[i][k + 1]; // меняем местами
						a[i][k + 1] = b; // значения элементов
					}
				}
			}
		}
		else {
			for (int j = 0; j < l; j++) {
				for (int k = l; k > 0; k--) {
					if (a[i][k] > a[i][k - 1]) {
						int b = a[i][k]; // создали дополнительную переменную
						a[i][k] = a[i][k - 1]; // меняем местами
						a[i][k - 1] = b; // значения элементов
					}
				}
			}
		}
	}
}

int main() {
	int** matrix;
	int n;
	setlocale(LC_ALL, ".1251");
	srand(time(NULL));
	cout << "Введите число n количестов строк и столбцов КВАДРАТНОЙ матрицы \n";
	cin >> n;
	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	int sposob, flag = 0;
	cout << "Если хотите ввести числа сами то введите 1, если сгенерировать то введите 0\n";
	cin >> sposob;
	if (sposob == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
		flag++;
	}
	else if (sposob == 0) {
		int start, end;
		cout << "Введите ограничение гирерируемых чисел (начало, конец):\n";
		cin >> start >> end;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = rand() % (end - start) + start;
			}
		}
		flag++;
	}
	else {
		cout << "Не верно введённ способ ввода\n";
		return 0;
	}
	cout << "Получившаяся матрица:";
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout << setw(5) << matrix[i][j];
		}
	}
	cout << endl << "Наибольший элемент правого верхнего треугольника матрицы" << endl << max_up_r(matrix, n);
	sortirovka(matrix, n);
	cout << endl;
	cout << "Получившаяся матрица после сортировки:";
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout << setw(5) << matrix[i][j];

		}
	}
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}