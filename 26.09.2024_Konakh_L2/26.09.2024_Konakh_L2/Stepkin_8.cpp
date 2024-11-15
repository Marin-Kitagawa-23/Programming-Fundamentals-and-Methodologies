#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

int main() {

    string s;
    setlocale(LC_ALL, "RU");
    cout << "���������� ������� ����������� ����� N:" << endl;
    cin >> s;

    long long n = s.size();

    vector<int> numb(n);
    unordered_map<int, int> equalCounter;
    for (int i = 0; i < n; i++) {
        numb[i] = s[i] - '0';
        equalCounter[numb[i]]++;
    }

    vector<long long> fact(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    // ������� ���������� �������� ������� ��, ��� ������ �� i
    long long ost = fact[n];
    for (const auto& i : equalCounter) {
        ost /= fact[i.second];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        // ������������ ������
        for (auto& j : equalCounter) {
            if (j.first > numb[i]) {
                ans += ost / (n - i) * equalCounter[j.first];
            }
        }

        // �������� ost
        ost /= n - i;
        ost *= equalCounter[numb[i]];
        equalCounter[numb[i]]--;
    }

    cout <<"���������� ����� ������� N, ��������� �� ��� �� ���� � ��� �� ���������� �����:\n" << ans;
    return 0;
}