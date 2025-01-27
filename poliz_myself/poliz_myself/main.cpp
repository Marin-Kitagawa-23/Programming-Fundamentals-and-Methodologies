#include<fstream>
#include<iostream>
#include<string>

using namespace std;

	struct Item {
		Item* Next;
		char Info;
		Item(char current) : Info(current), Next(nullptr) {};
	};

	Item* top = nullptr;

	void push(char const &current) {
		Item* p = new Item(current);
		p->Next = top;
		top = p;
	}

	char pop() {
		if (top == nullptr) {
			throw "Top is ampty";
		}
		char current = top -> Info;
		Item* p = top;
		top = top->Next;
		delete p;
		return current;
	}

	char show() {
		return top->Info;
	}

	int ozenka(char const& x) {
		if (x == '/' or x == '*') {
			return 2;
		}
		else {
			return 1;
		}
	}

int main() {
	ifstream in("Input.txt");
	ofstream out("Output.txt");
	if (!in) {
		throw "File is not open";
	}
	if (!in.peek()) {
		throw "File is empty";
	}
	char current;
	while (in >> current) {
		if (isdigit(current)) {
			out << current << " ";
		}
		else if (current == '(') {
			int status = 0;
			while (in >> current and current != ')') {
				if (isdigit(current)) {
					out << current << " ";
				}
				else {
					if (status == 0) {
						push(current);
					}
					else {
						if (top != nullptr) {
							if (ozenka(show()) < ozenka(current)) {
								push(current);
							}
							else {
								while (top != nullptr) {
									out << pop() << " ";
								}
								push(current);
							}
						}
						else { push(current); }
					}
				}
			}
			while (top != nullptr) {
				out << pop() << " ";
			}
		}
		else {
			if (top != nullptr) {
				if (ozenka(show()) < ozenka(current)) {
					push(current);
				}
				else {
					while (top != nullptr) {
						out << pop() << " ";
					}
					push(current);
				}
			}
			else { push(current); }
		}
	}
	while (top != nullptr) {
		out << pop() << " ";
	}
	return 0;
}