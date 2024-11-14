#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// ������� ��� �������������� ������ � ������ �������
string to_lower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// ������� ��� ��������, ������� �� ������ ������ �� ��������� ����
bool is_word(const string& str) {
    for (char c : str) {
        if (!isalpha(c) || !isalpha(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

int main() {
    string input_filename = "input.txt";
    string output_filename = "output.txt";
    setlocale(LC_ALL, ".1251");

    // ���� ������������ ����� ���������� K
    int K;
    cout << "������� ����������� ���������� ���������� K: ";
    cin >> K;

    // ��������� ���� ��� ������
    ifstream input_file(input_filename);
    if (!input_file.is_open()) {
        cerr << "�� ������� ������� ���� " << input_filename << endl;
        return 1;
    }

    // ������� ��� �������� ������� ����
    unordered_map<string, int> word_count;
    string word;

    // ������ ����� � ��������� ����
    while (input_file >> word) {
        // ������� �������, �� ���������� ���������� �������
        string cleaned_word = "";
        for (char c : word) {
            if (isalpha(c)) {
                cleaned_word += c;
            }
        }

        // ���� ����� ������� ������ �� ��������� ����, �������� ��� � ������� ��������
        if (is_word(cleaned_word)) {
            cleaned_word = to_lower(cleaned_word);
            word_count[cleaned_word]++;
        }
    }

    input_file.close();

    // ��������� ������ ��� ����������
    vector<pair<string, int>> sorted_words;
    for (const auto& entry : word_count) {
        if (entry.second >= K) {
            sorted_words.push_back(entry);
        }
    }

    // ���������� �� �������� �������
    sort(sorted_words.begin(), sorted_words.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
        });

    // ��������� ���� ��� ������
    ofstream output_file(output_filename);
    if (!output_file.is_open()) {
        cerr << "�� ������� ������� ���� " << output_filename << endl;
        return 1;
    }

    // ���������� ��������� � ����
    for (const auto& entry : sorted_words) {
        output_file << entry.first << " " << entry.second << endl;
    }

    output_file.close();
    cout << "��������� ������� ������� � ���� " << output_filename << endl;

    return 0;
}
