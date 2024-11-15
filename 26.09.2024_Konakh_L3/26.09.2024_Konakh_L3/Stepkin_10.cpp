#include <iostream>

using namespace std;

void sum_2z(int a[], int b) {
	int sum = 0;
	for (int i = 0; i < b; i++) {
		if (a[i] > 9 and a[i] < 100 or a[i] < -9 and a[i] > -100) {
			sum += a[i];
		}
	}
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
		int proiz = 1;
		for (int i = i_f + 1; i < i_l; i++) {
			proiz *= a[i];
		}
		cout << proiz << endl;
	}
}

void last(int a[], int b) {
	int N;
	cout << "Input N\n";
	cin >> N;
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
}




int main() {
	const int n = 20;
	int arr[n];
	int len, sposob;
	srand(time(NULL));
	cout << "Input lenght:\n";
	cin >> len;
	if (len > n) {
		cout << "Error";
	}
	cout << "Input (input-method) if keyboard input 1 else 0:\n";
	cin >> sposob;
	if (sposob == 1) {
		cout << "Input array:\n";
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
	}
	else {
		long long start, end;
		cout << "input diaposon (start , end):\n";
		cin >> start >> end;
		for (int i = 0; i < len; i++) {
			arr[i] = rand() % (end - start + 1) + start;
			cout << arr[i] << " ";
			cout << endl;
		}
	}
	sum_2z(arr, len);
	proizv(arr, len);
	last(arr, len);
}