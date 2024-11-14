#include <fstream>	
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int getValue(int n_get)
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
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
		else if (a - (int)a != 0 or a > n_get or a < 0) {
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cout << "Try again:\n";
			continue;
		}
		else // ���� �� ������, �� ���������� a
			return int(a);
	}
}
int main() {
	vector <string> questions;
	vector <int> answers;
	string s;
	int k, correctAnswers = 0;
	ifstream fin1("input.txt");
	if (!fin1) {
		cout << "ERROR";
		return 0;
	}
	cout << "Write number of questions:\n";
	k = getValue(20);
	while (getline(fin1,s,'#')) {
		questions.push_back(s);
		getline(fin1, s, '#');
		answers.push_back(stoi(s));
	}
	srand(time(NULL));
	for (int i = 1; i <= k; i++)
	{
		int h = rand() % (questions.size());
		cout<<i<<". "<< questions[h];
		questions.erase(questions.begin()+h);
		cout << "Write answer(Number): ";
		int AnswerNumber;
		cin >> AnswerNumber;
		if (AnswerNumber == answers[h]) {
			cout << "True"<<endl;
			correctAnswers++;
		}
		else {
			cout << "False"<<endl;
		}
		answers.erase(answers.begin() + h);
		cout << endl;
	}
	cout << "Number of correct Answers: " <<correctAnswers<<endl;
	cout << "Number of incorrect Answers: " <<(k - correctAnswers)<<endl;
	fin1.close();
}