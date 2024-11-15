#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream f1("Input_1.txt");
	ifstream f2("Input_2.txt");
	ofstream fall("Output.txt");
	int a1 , a2 ;
	if (!f1) {
		cout << "File Input_1 not open\n";
		return 0;
	}
	if (!f2) {
		cout << "File Input_2 not open\n";
		return 0;
	}
	if (!(f1 >> a1)) {
		a1 = INT_MAX;
	}
	if (!(f2 >> a2)) {
		a2 = INT_MAX;
	}
	while (a1 != INT_MAX or a2 != INT_MAX) {
		if (a1 < a2) {
			fall << a1 << " ";
			if (!(f1 >> a1)) {
				a1 = INT_MAX;
				continue;
			}
		}
		else {
			fall << a2 << " ";
			if (!(f2 >> a2)) {
				a2 = INT_MAX;
				continue;
			}
		}
	}
	f1.close();
	f2.close();
	fall.close();
	cout << "File Output.txt had been changed\n";
	return 0;
}