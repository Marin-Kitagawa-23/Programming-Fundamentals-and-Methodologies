#include <iostream>
#include <exception>
#include <fstream>
#include <string>
using namespace std;
struct StackItem {
	char info;
	StackItem* next;
	StackItem(char x) : info(x), next(nullptr) {}; //конструктор
};

StackItem* top = nullptr; // указатель на вершину стека

void push(const char& x) { // добавление нового элемента в стек
	StackItem* p = new StackItem(x);
	p->next = top;
	top = p;
}

char pop() { // извлечение элемента из стека
	if (top == nullptr) {
		throw "Top is empty!";
	}
	char x = top->info;
	StackItem* p = top->next;
	delete top;
	top = p;
	return x;
}

void deleteStack(StackItem*& top) { // удаление стека
	StackItem* old, * item;
	item = top;
	while (item) {
		old = item;
		item = item->next;
		delete old;
	}
	top = nullptr;
}

int main() {
	ifstream f("Input.txt");
	string s;
	int a, b;
	while (f >> s) {
		for (char c : s) {
			if (isdigit(c)) {
				push(stoi(s));
				break;
			}
			else {
				a = pop();
				b = pop();
				if (c == '+') push(a + b);
				if (c == '-') push(b - a);
				if (c == '*') push(a * b);
				if (c == '/') push(b / a);
			}
		}
	}
	a = pop();
	cout << a;
	deleteStack(top);
	return 0;
}
