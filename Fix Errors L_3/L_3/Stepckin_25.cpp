#include <iostream>

using namespace std;

void sum_2z(int a[], int b) {
	long long sum = 0;
	for (int i = 0; i < b; i++) {
		if (a[i] > 9 and a[i] < 100 or a[i] < -9 and a[i] > -100) {
			sum += a[i];
		}
	}
	cout << "����� ����������� ����� �����: \n";
	cout << sum << endl;
}

int proizv(int a[], int b) {
	int i_l = 0, i_f = b, flag = 0;
	for (int i = 0; i < b; i++) {
		if (a[i] > 0) {
			flag++;
			if (i < i_f) {
				i_f = i;
			}
			if (i > i_l) {
				i_l = i;
			}
		}
	}
	if (flag == 0 or flag == 1) {
		cout << "������������ ����� ����� ������ � ��������� ������������� ������: \n";
		cout << "������������ ������������� ����� ��� ��������� !";
		cout << endl;
		return 0;
	}
	else {
		long long proiz = 1;
		for (int i = i_f + 1; i < i_l; i++) {
			proiz *= a[i];
		}
		cout << "������������ ����� ����� ������ � ��������� ������������� ������: \n";
		cout << proiz << endl;
	}
	return 0;
}

void last(int a[], int b) {
	cout << "������� ����� N\n";
	double N;
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		cout << "������� ���������� �����:\n";
		cin >> N;
		if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // ������� ���� �����, ������� ������� � ������ ����� ����������
		if (std::cin.gcount() > 1) { // ���� �� �������� ����� ������ �������
			cout << "Try again:\n";
			continue;
		}
		else if (N - (int)N != 0) {
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cout << "Try again:\n";
			continue;
		}
		else // ���� �� ������, �� ���������� a
			break;
	}
	cout << "��� ����� ������ N �� ������ ���� ������� � �������� ������: \n";
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

int getValue(int n_get)
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		cout << "������� ���������� �����:\n";
		double a;
		cin >> a;
		if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // ������� ���� �����, ������� ������� � ������ ����� ����������
		if (std::cin.gcount() > 1) { // ���� �� �������� ����� ������ �������
			cout << "Try again:\n";
			continue;
		}
		else if (a - (int)a != 0 or a >= n_get) {
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cout << "Try again:\n";
			continue;
		}
		else // ���� �� ������, �� ���������� a
			return int(a);
	}
}

int getValue1(int n_get)
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		double a;
		cout << "������� ����� ����������� ������������ �����:\n";
		cin >> a;
		if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // ������� ���� �����, ������� ������� � ������ ����� ����������
		if (std::cin.gcount() > 1) { // ���� �� �������� ����� ������ �������
			cout << "Try again:\n";
			continue;
		}
		else if (a - (int)a != 0 or a < n_get) {
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cout << "Try again:\n";
			continue;
		}
		else // ���� �� ������, �� ���������� a
			return int(a);
	}
}

int getValue()
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		double a;
		cout << "���� ������ ���� ������ ����� � ������� 1 ����� ������� ����� ������ �����:\n";
		cin >> a;
		if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // ������� ���� �����, ������� ������� � ������ ����� ����������
		if (std::cin.gcount() > 1) { // ���� �� �������� ����� ������ �������
			cout << "Try again:\n";
			continue;
		}
		else if (a - (int)a != 0) {
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cout << "Try again:\n";
			continue;
		}
		else // ���� �� ������, �� ���������� a
			return int(a);
	}
}

int getValue3()
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		double a;
		cout << "������� �����:\n";
		cin >> a;
		if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // ������� ���� �����, ������� ������� � ������ ����� ����������
		if (std::cin.gcount() > 1) { // ���� �� �������� ����� ������ �������
			cout << "Try again:\n";
			continue;
		}
		else if (a - (int)a != 0) {
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cout << "Try again:\n";
			continue;
		}
		else // ���� �� ������, �� ���������� a
			return int(a);
	}
}

int getValue2()
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		double a;
		cout << "������� ������ ����������� ������������ �����:\n";
		cin >> a;
		if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // ������� ���� �����, ������� ������� � ������ ����� ����������
		if (std::cin.gcount() > 1) { // ���� �� �������� ����� ������ �������
			cout << "Try again:\n";
			continue;
		}
		else if (a - (int)a != 0) {
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cout << "Try again:\n";
			continue;
		}
		else // ���� �� ������, �� ���������� a
			return int(a);
	}
}



int main() {
	const int n = 20;
	int arr[n];
	srand(time(NULL));
	setlocale(LC_ALL, "RU");
	int len, sposob;
	len = getValue(n);
	sposob = getValue();
	if (sposob == 1) {
		for (int i = 0; i < len; i++) {
			arr[i] = getValue3();
		}
	}
	else {
		long long start, end;
		start = getValue2();
		end = getValue1(start);
		cout << "��������������� �����: \n";
		for (int i = 0; i < len; i++) {
			arr[i] = rand() % (end - start + 1) + start;
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	////sum_2z(arr, len);
	////proizv(arr, len);
	////last(arr, len);
	return 0;
}