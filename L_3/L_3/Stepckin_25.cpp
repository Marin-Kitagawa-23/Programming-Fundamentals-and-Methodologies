#include <iostream>

using namespace std;

void sum_2z(int a[], int b) {
	long long sum = 0;
	for (int i = 0; i < b; i++) {
		if (a[i] > 9 and a[i] < 100 or a[i] < -9 and a[i] > -100) {
			sum += a[i];
		}
	}
	cout << "Сумма двухзначных чисел равна: \n";
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
		cout << "Произведение чисел между первым и последним положительным числом: \n";
		cout << "Недостаточно положительных чисел для выпонения !";
		cout << endl;
		return 0;
	}
	else {
		long long proiz = 1;
		for (int i = i_f + 1; i < i_l; i++) {
			proiz *= a[i];
		}
		cout << "Произведение чисел между первым и последним положительным числом: \n";
		cout << proiz << endl;
	}
	return 0;
}

void last(int a[], int b) {
	cout << "Введите число N\n";
	double N;
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		cout << "Введите количество чисел:\n";
		cin >> N;
		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // очищаем весь мусор, который остался в потоке после извлечения
		if (std::cin.gcount() > 1) { // если мы очистили более одного символа
			cout << "Try again:\n";
			continue;
		}
		else if (N - (int)N != 0) {
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cout << "Try again:\n";
			continue;
		}
		else // если всё хорошо, то возвращаем a
			break;
	}
	cout << "Все числа больше N по модулю были удалены и заменены нулями: \n";
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
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		cout << "Введите количество чисел:\n";
		double a;
		cin >> a;
		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // очищаем весь мусор, который остался в потоке после извлечения
		if (std::cin.gcount() > 1) { // если мы очистили более одного символа
			cout << "Try again:\n";
			continue;
		}
		else if (a - (int)a != 0 or a >= n_get) {
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cout << "Try again:\n";
			continue;
		}
		else // если всё хорошо, то возвращаем a
			return int(a);
	}
}

int getValue1(int n_get)
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		double a;
		cout << "Введите КОНЕЦ ограничения гинерируемых чисел:\n";
		cin >> a;
		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // очищаем весь мусор, который остался в потоке после извлечения
		if (std::cin.gcount() > 1) { // если мы очистили более одного символа
			cout << "Try again:\n";
			continue;
		}
		else if (a - (int)a != 0 or a < n_get) {
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cout << "Try again:\n";
			continue;
		}
		else // если всё хорошо, то возвращаем a
			return int(a);
	}
}

int getValue()
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		double a;
		cout << "Если хотите сами ввести числа — введите 1 иначе введите любое другое целое:\n";
		cin >> a;
		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // очищаем весь мусор, который остался в потоке после извлечения
		if (std::cin.gcount() > 1) { // если мы очистили более одного символа
			cout << "Try again:\n";
			continue;
		}
		else if (a - (int)a != 0) {
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cout << "Try again:\n";
			continue;
		}
		else // если всё хорошо, то возвращаем a
			return int(a);
	}
}

int getValue3()
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		double a;
		cout << "Введите число:\n";
		cin >> a;
		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // очищаем весь мусор, который остался в потоке после извлечения
		if (std::cin.gcount() > 1) { // если мы очистили более одного символа
			cout << "Try again:\n";
			continue;
		}
		else if (a - (int)a != 0) {
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cout << "Try again:\n";
			continue;
		}
		else // если всё хорошо, то возвращаем a
			return int(a);
	}
}

int getValue2()
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		double a;
		cout << "Введите НАЧАЛО ограничения гинерируемых чисел:\n";
		cin >> a;
		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Try again:\n";
			continue;
		}
		cin.ignore(32767, '\n'); // очищаем весь мусор, который остался в потоке после извлечения
		if (std::cin.gcount() > 1) { // если мы очистили более одного символа
			cout << "Try again:\n";
			continue;
		}
		else if (a - (int)a != 0) {
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cout << "Try again:\n";
			continue;
		}
		else // если всё хорошо, то возвращаем a
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
		cout << "Сгенерированные числа: \n";
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