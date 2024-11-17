#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int** matrix_1;
	int** matrix_2;
	int** matrix_12;
	int n;
	setlocale(LC_ALL, ".1251");
	cout << "Введите количесвто строк для треугольных матриц\n";
	cout << "Также заданное число будет являтся количеством строк и столбцов для квадратной матрицы\n";
	cin >> n;
	if (n < 1) {
		cout << "Неверно введено количество строк";
		return 0;
	}
	matrix_1 = new int* [n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			matrix_1[i] = new int[j + 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			matrix_1[i][j] = n - i;
		}
	}
	cout << endl << "Первая треугольная матрица:\n";
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j <= i; j++) {
			cout << left << setw(5) << matrix_1[i][j];
		}
	}
	matrix_2 = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix_2[i] = new int[n - i];
	}
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n - i; j++) {
		matrix_2[i][j] = i + 1;
	}
}
cout << endl << "Вторая треугольная матрица:\n";
for (int i = 0; i < n; i++) {
	cout << endl;
	for (int j = 0; j < n - i; j++) {
		cout << left << setw(5)<< matrix_2[i][j];
	}
}
matrix_12 = new int* [n];
for (int i = 0; i < n; i++) {
	matrix_12[i] = new int[n];
}
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		matrix_12[i][j] = 0;
	}
}
for (int i = 0; i < n; i++) {
	for (int j = 0; j <= i; j++) {
		matrix_12[i][j] += matrix_1[i][j];
	}
}
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n - i; j++) {
		matrix_12[i][j] += matrix_2[i][j];
	}
}
cout << endl << "Итоговая Квадратная матрица:\n";
for (int i = 0; i < n; i++) {
	cout << endl;
	for (int j = 0; j < n; j ++){
		cout << left << setw(5) << matrix_12[i][j];
}
}
for (int i = 0; i < n; i++) {
	delete[] matrix_1[i];
	delete[] matrix_2[i];
	delete[] matrix_12[i];
}
delete[] matrix_1;
delete[] matrix_2;
delete[] matrix_12;
return 0;
}