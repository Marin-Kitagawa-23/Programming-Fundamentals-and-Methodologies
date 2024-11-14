#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Функция для преобразования строки в нижний регистр
string to_lower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Функция для проверки, состоит ли строка только из латинских букв
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

    // Ввод минимального числа повторений K
    int K;
    cout << "Введите минимальное количество повторений K: ";
    cin >> K;

    // Открываем файл для чтения
    ifstream input_file(input_filename);
    if (!input_file.is_open()) {
        cerr << "Не удалось открыть файл " << input_filename << endl;
        return 1;
    }

    // Словарь для подсчёта частоты слов
    unordered_map<string, int> word_count;
    string word;

    // Чтение файла и обработка слов
    while (input_file >> word) {
        // Убираем символы, не являющиеся латинскими буквами
        string cleaned_word = "";
        for (char c : word) {
            if (isalpha(c)) {
                cleaned_word += c;
            }
        }

        // Если слово состоит только из латинских букв, приводим его к нижнему регистру
        if (is_word(cleaned_word)) {
            cleaned_word = to_lower(cleaned_word);
            word_count[cleaned_word]++;
        }
    }

    input_file.close();

    // Формируем вектор для сортировки
    vector<pair<string, int>> sorted_words;
    for (const auto& entry : word_count) {
        if (entry.second >= K) {
            sorted_words.push_back(entry);
        }
    }

    // Сортировка по убыванию частоты
    sort(sorted_words.begin(), sorted_words.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
        });

    // Открываем файл для записи
    ofstream output_file(output_filename);
    if (!output_file.is_open()) {
        cerr << "Не удалось открыть файл " << output_filename << endl;
        return 1;
    }

    // Записываем результат в файл
    for (const auto& entry : sorted_words) {
        output_file << entry.first << " " << entry.second << endl;
    }

    output_file.close();
    cout << "Частотный словарь записан в файл " << output_filename << endl;

    return 0;
}
