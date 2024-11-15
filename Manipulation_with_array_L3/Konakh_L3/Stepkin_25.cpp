#include <iostream>

using namespace std;

void sum_2z(int a[], int b) {
	long long sum = 0;
	for (int i = 0; i < b; i++) {
		if (a[i] > 9 and a[i] < 100 or a[i] < -9 and a[i] > -100) {
			sum += a[i];
		}
	}
	cout << "–езультат 1-ой подзадачи\n";
	cout << sum << endl;
}

void proizv(int a[], int b) {
	int i_l = 0, i_f = b;
	for (int i = 0; i < b; i++) {
		if (a[i] > 0) {
			if (i < i_f) {
				i_f = i;
			}
			if (i > i_l) {
				i_l = i;
			}
		}
	}
	if (abs(i_f - i_l) == 1) {
		cout << 0 << endl;
	}
	else {
		long long proiz = 1;
		for (int i = i_f + 1; i < i_l; i++) {
			proiz *= a[i];
		}
		cout << "–езультат 2-ой подзадачи \n";
		cout << proiz << endl;
	}
}

void last(int a[], int b) {
	int N;
	cout << "¬ведите число N\n";
	cin >> N;
	cout << "–езультат 3-ей подзадачи\n";
	for (int i = 0; i < b; i++) {
		if (abs(a[i]) > N) {
			for (int j = i; j < b; j++) {
				a[j] = a[j + 1];
			}
			i--;
			a[b] = 0;
		}
	}
	for (int i = 0; i < b; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}




int main() {
	const int n = 20;
	int arr[n];
	int len, sposob;
	srand(time(NULL));
	setlocale(LC_ALL, "RU");
	cout << "¬ведите количество чисел:\n";
	cin >> len;
	if (len >= n) {
		cout << "¬ведЄнное число выходит за пределы максимального количества чисел !!!";
		return 0;
	}
	cout << "≈сли хотите сами ввести числа Ч введите 1 иначе введите 0:\n";
	cin >> sposob;
	if (sposob == 1) {
		cout << "¬ведите числа:\n";
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
	}
	else {
		long long start, end;
		cout << "¬ведите ограничени€ гинерируемых чисел (в формате: начало конец):\n";
		cin >> start >> end;
		cout << "—генерированные числа: \n";
		for (int i = 0; i < len; i++) {
			arr[i] = rand() % (end - start + 1) + start;
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	sum_2z(arr, len);
	proizv(arr, len);
	last(arr, len);
	return 0;
}